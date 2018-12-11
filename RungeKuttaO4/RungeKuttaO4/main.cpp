#include <iostream>

using namespace std;

float f(float t, float y) {
	return 4*t - 2*y;
}

float RK4(float t, float w, float h) {
	float s1 = f(t, w);
	float s2 = f(t + (h / 2.0), w + (h / 2.0)*s1);
	float s3 = f(t + (h / 2.0), w + (h / 2.0)*s2);
	float s4 = f(t + h, w + h*s3);
	return w + (h / 6.0)*(s1 + 2 * s2 + 2 * s3 + s4);
}

int main() {
	float h = 1.0 / 4.0;
	float a(0), b(1),w(0),t;
	int c = 0;
	char pause;


	for (t = a; t < b; t = t + h) {
		cout << "t" << c << " = " << t << "\tw" << c << " = " << w << endl;
		w = RK4(t,w,h);
		c++;
	}

	cout << "t" << c << " = " << t << "\tw" << c << " = " << w << endl;
	cin >> pause;
	return 0;
}