#include "lotusmechanics.h"

LotusMechanics::LotusMechanics(const double dMassOfCar, const double dRollingCoefficient, const double dEfficiencyPowertrain, const double dAerodynamicDragCoefficient, const double dFrontalArea, const double dLocalAirDensity, const double dLocalGravity){
	this->dMassOfCar = dMassOfCar;
	this->dRollingCoefficient = dRollingCoefficient;
	this->dEfficiencyPowertrain = dEfficiencyPowertrain;
	this->dAerodynamicDragCoefficient = dAerodynamicDragCoefficient;
	this->dFrontalArea = dFrontalArea;
	this->dLocalAirDensity = dLocalAirDensity;
	this->dLocalGravity = dLocalGravity;

	dSettingEpsSpeed = DEFAULT_EPSILON_SPEED;
}

void LotusMechanics::setEpsilonSpeed(double dSpeed){
	if(dSpeed >= 0.0){
		dSettingEpsSpeed = dSpeed;
	}else{
		dSettingEpsSpeed = -dSpeed;
	}
}

const double LotusMechanics::getLocalG() const{
	return dLocalGravity;
}

const double LotusMechanics::cmpEffortAtEngine(const double dAcceleration, const double dSpeedOfCar, const double dSinAlpha, EffortLogData* pLogData) const{ return cmpEffortAtEngine(dAcceleration, dSpeedOfCar, dSinAlpha, 0.0, pLogData); }
const double LotusMechanics::cmpEffortAtEngine(const double dAcceleration, const double dSpeedOfCar, const double dSinAlpha, const double dSpeedOfWind, EffortLogData* pLogData) const{
	double dResult = cmpEffortAtWheels(dAcceleration, dSpeedOfCar, dSinAlpha, dSpeedOfWind, pLogData)/dEfficiencyPowertrain + cmpEffortAccelerationOfPowertrain(pLogData);
	if(pLogData != NULL) pLogData->dEffortAtEngine = dResult;
	return dResult;
}

const double LotusMechanics::cmpEffortAtWheels(const double dAcceleration, const double dSpeedOfCar, const double dSinAlpha, const double dSpeedOfWind, EffortLogData* pLogData) const{
	double dResult;
	double dResistance;
	double dTemp;
	double dAccelerationForce = dAcceleration*dMassOfCar;

	if(fabsl(dSpeedOfCar) < dSettingEpsSpeed){
		dResistance = 0.0;
	}else{
		dResistance = cmpResistanceIdealRoll(dSinAlpha); // if forumla depends on velocity as well, pass abs(dSpeedCar)
		if(pLogData != NULL) pLogData->dResistanceRoll = dResistance;
		dTemp = cmpResistanceIdealDrag(dSpeedOfCar, dSpeedOfWind);
		dResistance += dTemp;
		if(pLogData != NULL) pLogData->dResistanceDrag = dTemp;
		dTemp = copysign(cmpResistanceIdealClimb(dSinAlpha),dSpeedOfCar);
		dResistance += dTemp;
		if(pLogData != NULL) pLogData->dResistanceClimb = dTemp;
	}
	dResult = (dResistance + dAccelerationForce) * fabsl(dSpeedOfCar);
	if(pLogData != NULL){
		pLogData->dResistance = dResistance;
		pLogData->dEffortAtWheels = dResult;
		pLogData->dEffortAtWheelsAcceleration	= fabsl(dSpeedOfCar) * dAccelerationForce;
		pLogData->dEffortAtWheelsClimb			= fabsl(dSpeedOfCar) * pLogData->dResistanceClimb;
		pLogData->dEffortAtWheelsDrag			= fabsl(dSpeedOfCar) * pLogData->dResistanceDrag;
		pLogData->dEffortAtWheelsRoll			= fabsl(dSpeedOfCar) * pLogData->dResistanceRoll;
	}
	return dResult;
}


const double LotusMechanics::cmpEffortAccelerationOfPowertrain(EffortLogData* pLogData) const{
	double dResult = 0.0; // J w dw   <- w aus RPM
	if(pLogData != NULL) pLogData->dEffortAccelerationOfPowertrain = dResult;
	return dResult;
}

const double LotusMechanics::cmpResistanceIdealRoll(const double dSinAlpha) const{
	return dMassOfCar*dLocalGravity*dRollingCoefficient*cos(asin(dSinAlpha)); // mg cos alpha * fr
}

const double LotusMechanics::cmpResistanceIdealDrag(const double dSpeedOfCar, const double dSpeedOfWind) const{
	return 0.5*dLocalAirDensity*dAerodynamicDragCoefficient*dFrontalArea*(dSpeedOfCar-dSpeedOfWind)*(dSpeedOfCar-dSpeedOfWind); // 0.5 rho cD Af (v-vw)^2
}

const double LotusMechanics::cmpResistanceIdealClimb(const double dSinAlpha) const{
	return dMassOfCar*dLocalGravity*dSinAlpha; // mg sin alpha
}


