#include <iostream>
#include <vector>
using namespace std;

float f(float t, float y){
    return 1 + (t - y) * (t - y);
    //return y*y;
}

void printC(vector<float> y){
    for(int i = 0; i < y.size(); i++){
        cout<<"y"<<i<<" : "<<y[i]<<endl;
    }
}

vector<float> EulerED(float a, float b, int N, float y0){
    float h = (b - a) / N;
    vector<float> y;
    y.push_back(y0);
    float t = a;

    for(int i = 1; i <= N; i++){
        y.push_back(y[i - 1] + h * f(t, y[i - 1]));
        t += h;
    }

    return y;
}
        
int main(){
    float a = 2;
    float b = 3;
    int N = 10;
    float y0 = 1;
    
    vector<float> c = EulerED(a, b, N, y0);
    printC(c);
}

