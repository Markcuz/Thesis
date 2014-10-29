#include "quaternions.h"

double quat2cosEuX(const double dQuat[4]){
	return cos(quat2euX(dQuat));
}
double quat2sinEuX(const double dQuat[4]){
	return sin(quat2euX(dQuat));
}
double quat2euX(const double dQuat[4]){
	return atan((2.0*dQuat[2]*dQuat[3]+2.0*dQuat[0]*dQuat[1])/(2.0*dQuat[0]*dQuat[0]+2.0*dQuat[3]*dQuat[3]-1.0));
}

double quat2cosEuY(const double dQuat[4]){
	return cos(quat2euY(dQuat));
}
double quat2sinEuY(const double dQuat[4]){
	return 2.0*(dQuat[1]*dQuat[3]-dQuat[0]*dQuat[2]);
}
double quat2euY(const double dQuat[4]){
	return asin(quat2sinEuY(dQuat));
}

double quat2cosEuZ(const double dQuat[4]){
	return cos(quat2euZ(dQuat));
}
double quat2sinEuZ(const double dQuat[4]){
	return sin(quat2euZ(dQuat));
}
double quat2euZ(const double dQuat[4]){
	return atan((2.0*dQuat[2]*dQuat[2]+2.0*dQuat[0]*dQuat[3])/(2.0*dQuat[0]*dQuat[0]+2.0*dQuat[1]*dQuat[1]-1.0));
}
