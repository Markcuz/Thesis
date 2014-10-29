#ifndef MECHANICS_H
#define MECHANICS_H

#include <cstdlib>
#include <math.h>

#define DEFAULT_PARAMETER_WORLD_AIR_DENSITY				1.22521			// ISA 15°C seal level
#define DEFAULT_PARAMETER_WORLD_GRAVITY					9.81268735
#define DEFAULT_PARAMETER_LOTUS_AER_DRAG_COEFF			0.407
#define DEFAULT_PARAMETER_LOTUS_FRONTAL_AREA			1.6
#define DEFAULT_PARAMETER_LOTUS_TYRE_RESISTANCE_COEFF	0.01070
#define DEFAULT_PARAMETER_LOTUS_EFFICIENCY_POWERTRAIN	0.98			// ??? DUMMY VALUE

#define DEFAULT_EPSILON_SPEED							0.1				// [m/s]

struct EffortLogData{
	double dResistance;
	double dResistanceRoll;
	double dResistanceDrag;
	double dResistanceClimb;
	double dEffortAtWheels;
	double dEffortAtWheelsRoll;
	double dEffortAtWheelsDrag;
	double dEffortAtWheelsClimb;
	double dEffortAtWheelsAcceleration;
	double dEffortAccelerationOfPowertrain;
	double dEffortAtEngine;
	EffortLogData(){
		dResistance							= -1.0;
		dResistanceRoll						= -1.0;
		dResistanceDrag						= -1.0;
		dResistanceClimb					= -1.0;
		dEffortAtWheels						= -1.0;
		dEffortAtWheelsRoll					= -1.0;
		dEffortAtWheelsDrag					= -1.0;
		dEffortAtWheelsClimb				= -1.0;
		dEffortAtWheelsAcceleration			= -1.0;
		dEffortAccelerationOfPowertrain		= -1.0;
		dEffortAtEngine						= -1.0;
	}
};


class LotusMechanics{
public:
	LotusMechanics(
		const double dMassOfCar,
		const double dRollingCoefficient = DEFAULT_PARAMETER_LOTUS_TYRE_RESISTANCE_COEFF,
		const double dEfficiencyPowertrain = DEFAULT_PARAMETER_LOTUS_EFFICIENCY_POWERTRAIN,
		const double dAerodynamicDragCoefficient = DEFAULT_PARAMETER_LOTUS_AER_DRAG_COEFF,
		const double dFrontalArea = DEFAULT_PARAMETER_LOTUS_FRONTAL_AREA,
		const double dLocalAirDensity = DEFAULT_PARAMETER_WORLD_AIR_DENSITY,
		const double dLocalGravity = DEFAULT_PARAMETER_WORLD_GRAVITY
		);

	void setEpsilonSpeed(double dSpeed);
	const double getLocalG() const;

	const double cmpEffortAtEngine(const double dAcceleration, const double dSpeedOfCar, const double dSinAlpha, const double dSpeedOfWind = 0.0, EffortLogData* pLogData = NULL) const;
	const double cmpEffortAtEngine(const double dAcceleration, const double dSpeedOfCar, const double dSinAlpha, EffortLogData* pLogData) const;



private:
	double dRollingCoefficient;			// fr
	double dMassOfCar;					// m	[kg]
	double dEfficiencyPowertrain;		// eta	[]
	double dLocalGravity;				// g	[m/s²]
	double dLocalAirDensity;			// rho
	double dAerodynamicDragCoefficient;	// cD
	double dFrontalArea;				// Af
	double dSettingEpsSpeed;

	const double cmpEffortAtWheels(const double dAcceleration, const double dSpeedOfCar, const double dSinAlpha, const double dSpeedOfWind = 0.0, EffortLogData* pLogData = NULL) const;

	// functions that contain formulas
	const double cmpEffortAccelerationOfPowertrain(EffortLogData* pLogData = NULL) const;
	const double cmpResistanceIdealRoll(const double dSinAlpha) const; // mg cos alpha * fr
	const double cmpResistanceIdealDrag(const double dSpeedOfCar, const double dSpeedOfWind) const; // 0.5 rho cD Af (v-vw)^2
	const double cmpResistanceIdealClimb(const double dSinAlpha) const; // mg sin alpha

};

#endif // MECHANICS_H

