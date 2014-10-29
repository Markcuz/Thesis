#ifndef QUATERNIONS_H
#define QUATERNIONS_H
#include <math.h>

double quat2euX(const double dQuat[4]);
double quat2euY(const double dQuat[4]);
double quat2euZ(const double dQuat[4]);

double quat2sinEuX(const double dQuat[4]);
double quat2sinEuY(const double dQuat[4]);
double quat2sinEuZ(const double dQuat[4]);

double quat2cosEuX(const double dQuat[4]);
double quat2cosEuY(const double dQuat[4]);
double quat2cosEuZ(const double dQuat[4]);


#endif // QUATERNIONS_H
