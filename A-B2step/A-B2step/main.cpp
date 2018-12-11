#include <iostream>

using namespace std;

float f(float t, float y) {
	return t - y;
}

float ExpTrapzd(float t,float w,float h) {
	return w + (h / 2.0)*(f(t, w) + f(t + h, w + h*f(t, w)));
}

float AB2(float t, float w , float wm1, float h) {
	return w + h*((3.0/2.0)*f(t,w) - (1.0/2.0)*f(t-h,wm1));
}

int main() {
	float h = 1.0 / 4.0;
	float a(0), b(1), wm1(0), w,t;
	int c = 1;
	char pause;

	t = a;
	w = ExpTrapzd(t,wm1,h);

	cout << "t" << c << " = " << t << "\t w" << c - 1 << " = " << wm1 << endl;
	for (t = a+h; t < b; t += h) {
		cout << "t" << c << " = " << t << "\t w" << c - 1 << " = " << wm1 << "\tw" << c << " = " << w << endl;
		float tmp = w;
		w = AB2(t,w,wm1,h);
		wm1 = tmp;
		c++;
	}
	cout << "t" << c << " = " << t <<  "\tw" << c << " = " << w << endl;
	cin >> pause;
	return 0;
}