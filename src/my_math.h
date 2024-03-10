#ifndef SRC_my_MATH_H_
#define SRC_my_MATH_H_

#define my_E 2.71828182845904523536
#define my_PI 3.14159265358979323846
#define my_INF LDBL_MAX * 1e100
#define my_NAN my_INF - my_INF

// Abs, fabs, ceil, floor, fmod functions
int my_abs(int x);
long double my_fabs(double x);
long double my_ceil(double x);
long double my_floor(double x);
long double my_fmod(double x, double y);

// Pow and sqrt functions
long double my_sqrt(double sqrt);
long double my_pow(double base, double exp);

// Trigonometric and related functions
long double my_factorial(int n);

long double my_exp(double x);
long double my_cos(double x);
long double my_sin(double x);
long double my_tan(double x);
long double my_log(double x);

long double my_atan(double x);
long double my_asin(double x);
long double my_acos(double x);

#endif  // SRC_my_MATH_H_
