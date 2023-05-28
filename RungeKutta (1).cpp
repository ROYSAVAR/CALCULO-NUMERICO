#include <iostream>
#include <vector>
using namespace std;

float f(float t, float y){
    return 1 + (t - y) * (t - y);
}

void printT(pair<vector<float>, vector<float>> p, int n){
    for(int i = 0; i < n; i++){
        cout<<"y"<<i<<" : "<<p.second[i]<<endl;
    }
}

pair<vector<float>, vector<float>> RungeKutta(float t0, float y0, float h, int n){
    vector<float> ti, yi;
    ti.push_back(t0);
    yi.push_back(y0);
    float k[4]; 

    for(int i = 1; i <= n; i++){
        ti.push_back(h * i);

        k[0] = h * f(ti[i - 1], yi[i - 1]);
        k[1] = h * f(ti[i - 1] + (h / 2), yi[i - 1] + (k[0] / 2));
        k[2] = h * f(ti[i - 1] + (h / 2), yi[i - 1] + (k[1] / 2));
        k[3] = h * f(ti[i - 1] + h, yi[i - 1] + k[2]);

        yi.push_back(yi[i - 1] + (k[0] + 2 * k[1] + 2 * k[2] + k[3]) / 6);
    }

    return make_pair(ti, yi);
} 

int main(){
    float t0 = 2;
    int n = 10;
    float y0 = 1;
    float h = 0.1;
    printT(RungeKutta(t0, y0, h, n), n);
}
