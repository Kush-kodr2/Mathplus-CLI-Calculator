#ifndef OPERATIONS_H
#define OPERATION_H
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

// extern declarations (definitions are in calc.c)
extern int day, month, year;
extern long long int_prev_value;
extern float float_prev_value;
extern int last_operation;

int addition(int a);
int subtraction(int a);
long multiplication(int a);
float division();
unsigned long long factorial();
float average(int a);
long long power();
void prime_check();
int digit_sum();
void age_calc();
void leap_yr_check();
void QuadraticEqSolver();

// Function declarations
void flushInput();
void fetchCurrentDate();
void welcomeScreen();
void fakeLoading1();
void fakeLoading2();

#endif 