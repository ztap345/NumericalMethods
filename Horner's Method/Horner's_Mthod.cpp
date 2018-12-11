#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

clock_t b,e;
double dtime;
char pause;

float Horners(vector<float>,float);
float NormalPoly(vector<float>,float);

int main(){
    float input;
    float y,x(100000),s(.001);
    vector<float> inputs;

    cout << "Enter the polynomial coefficients individually starting from the x^n term.\n"
        << "type -999 when finished:\n";

    cin >> input;
    while(input != -999){
        inputs.push_back(input);
        cin >> input;
    }

    cout << "Horner's" << endl;
    cin >> pause;
    b = clock();
    for(float i = -x; i <= x;i+=s){
        y = Horners(inputs,i);
        //if(fmod(i,1000)==0) cout << i << endl;
    }

    e = clock();

    dtime = (e-b)/ CLOCKS_PER_SEC;

    cout << "\n\nUsing Horner's method, it took " << dtime << " seconds." <<"\n\n\n";

    cout << "PaC" << endl;
    cin >> pause;
    b = clock();

   for(float i = -x; i <= x;i+=s){
        y = NormalPoly(inputs,i);
        //if(fmod(i,1000)==0) cout << i << endl;
    }

    e = clock();

    dtime = (e-b)/ CLOCKS_PER_SEC;

    cout << "Using PaC method, it took " << dtime << " seconds." << "\n\n\n";

}

float Horners(vector<float> c,float x){
    int d = c.size();
    float y = c[0];
    for(int i = 1; i<d; i++){
        y = y*x+c[i];
    }
    return y;
}

float NormalPoly(vector<float> c,float x){
    int d = c.size();
    float y = 0;
    for(int i = 0; i<d; i++){
        y += (c[i]*pow(x,d-i-1));
    }
    return y;
}
