# Math.h
Implementation of Math.h library on C

## Contents

0. [Information](#information)
1. [Overview of implemated "math.h" functions](#overview-of-implemated-mathh-functions)


## Information

In this project I implement my own version of the standard math.h library in the C programming language. This library implements basic mathematical operations, which are then used in various algorithms.

- Implement basic functions of the math.h [below](#overview-of-implemated-mathh-functions):
- The library must be developed in C language of C11 standard using gcc compiler
- The library code is located in the src folder. 
- Outdated and legacy language constructions and library functions were not used.
- The programs were developed by POSIX.1-2017 standard.
- The program code written in Google style
- A static library (with the my_math.h header file)
- The library was developed according to the principles of structured programming; code duplication were avoided
- Use prefix my_ before each function
- Full coverage of library functions code with unit-tests with the Check library  
- Unit-tests check the results of implementation by comparing them with the implementation of the standard math.h library
- Unit tests cover at least 80% of each function (checked using gcov)
- Makefile for building the library and tests (with the targets all, clean, test, my_math.a, gcov_report)
- The gcov_report target generate a gcov report in the form of an html page. Unit tests run with gcov flags to do this  
- Follow the logic of the standard library (in terms of checks, working with memory and behavior in emergency situations)
- The total verifiable accuracy is 16 significant digits
- Verifiable accuracy of the fractional part is up to 6 decimal places.


## Overview of implemated "math.h" functions

C mathematical operations are a group of functions in the standard library of the C programming language implementing basic mathematical functions. All functions use floating-point numbers in one manner or another. Different C standards provide different, albeit backwards-compatible, sets of functions. Any functions that operate on angles use radians as the unit of angle.

| No. | Function | Description |
| --- | -------- | ----------- |
| 1 | `int abs(int x)` | computes absolute value of an integer value |
| 2 | `long double acos(double x)` | computes arc cosine |
| 3 | `long double asin(double x)` | computes arc sine |
| 4 | `long double atan(double x)` | computes arc tangent |
| 5 | `long double ceil(double x)` | returns the nearest integer not less than the given value |
| 6 | `long double cos(double x)` | computes cosine |
| 7 | `long double exp(double x)` | returns e raised to the given power |
| 8 | `long double fabs(double x)` | computes absolute value of a floating-point value |
| 9 | `long double floor(double x)` | returns the nearest integer not greater than the given value |
| 10 | `long double fmod(double x, double y)` | remainder of the floating-point division operation |
| 11 | `long double log(double x)` | computes natural logarithm |
| 12 | `long double pow(double base, double exp)` | raises a number to the given power |
| 13 | `long double sin(double x)` | computes sine |
| 14 | `long double sqrt(double x)` | computes square root |
| 15 | `long double tan(double x)` | computes tangent |  
