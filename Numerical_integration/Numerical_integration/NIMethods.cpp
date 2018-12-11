#include "stdafx.h"
#include"NIMethods.h"
#include<cmath>

double f(double x) {
	return exp(x);
}

double MidPointIntg(double a, double b, int m) {
	double intgVal = 0;
	double h = (b-a) / m;
	double x = a + (h/2);

	while(x<b){
		intgVal += f(x);
		x += h;
	}

	return intgVal * h;

}