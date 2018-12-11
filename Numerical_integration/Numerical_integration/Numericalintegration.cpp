// Numericalintegration.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"NIMethods.h"
#include <iostream>
#include <math.h>

# define M_PI           3.14159265358979323846  

using namespace std;

int main()
{
	double a, b, answer; int m; char user = 'Y';
	while (user != 'N' || user != 'n') {
		cout << "Enter in a,b and m : ";
		cin >> a >> b >> m;
		//a = 0; b = M_PI/2;
		//cout << "Enter m: ";
		//cin >> m;

		answer = MidPointIntg(a, b, m);

		cout << answer << endl;
		cout << "Again?(Y=yes,N=no): ";
		cin >> user;
	}
    return 0;
}

