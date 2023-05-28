#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

float f(float x)
{
    return log(x);
}

float dividedDifference(vector<float> x, vector<float> y, int a, int b)
{
    if (a - b == 1)
    {
        return (y[a] - y[b]) / (x[a] - x[b]);
    }
    return (dividedDifference(x, y, a, b + 1) - dividedDifference(x, y, a - 1, b)) / (x[a] - x[b]);
}

float newtonDividedDifference(vector<float> x, vector<float> y, float x_input, int n)
{
    cout<<"Polinomio de Newton : ";
    float result = y[0];

    for (int i = 1; i < n; i++)
    {
        float prod = 1;

        float d = dividedDifference(x, y, i, 0);
        (d >= 0) ? cout << "+" << d : cout << d;

        for(int j=0; j<i; j++)
        {
            cout<<"(x";
            (-x[j] >= 0) ? cout<<"+"<<-x[j]<<")":cout<<-x[j]<<")";

            prod *= (x_input -x[j]);
        }
        result+=d*prod;
    }
    cout<<endl;

    cout<<"Polinomio evaluado en "<<x_input<<" = ";
    return result;
}

int main()
{
    //vector<float> x = {1, 4, 6, 5};
    //vector<float> y;

    vector<float> x = {8, 9, 11};
    vector<float> y = {2.079, 2.197, 2.397};

    //vector<float> x = {1, 0, -3};
    //vector<float> y = {2, 4, -2};


    //for(int i=0; i<x.size(); i++)
      //  y.push_back(f(x[i]));

    float x_input = 10;

    //newtonDividedDifference(x, y, x_input, x.size());
    cout<<newtonDividedDifference(x, y, x_input, x.size())<<endl;
}