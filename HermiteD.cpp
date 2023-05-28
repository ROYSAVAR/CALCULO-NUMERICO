#include <iostream>
#include <vector>

using namespace std;

float f(float x){
    return x;
}

vector<float> zMapping(vector<float> x)
{
    vector<float>z;
    for(int i=0; i<(2*x.size()); i++)
    {
        if(i%2==0)
            z.push_back(x[i/2]);
        else
            z.push_back(x[i-1]);
    }

    return z;
}

float dividedDifference(vector<float>z, vector<float>fz, vector<float> fzp, int a, int b)
{
    if(a-b == 1)
    {
        if(z[a]==z[b])
            return fzp[a];
        else 
            return (fz[a]-fz[b])/(z[a]-z[b]);
    }
    return (dividedDifference(z, fz, fzp, a, b+1) -dividedDifference(z,fz, fzp, a-1, b)) / (z[a]-z[b]);
}

float Hermite(vector<float>x, vector<float>fx, vector<float>fxp, float x_input)
{
    vector<float> z = zMapping(x);
    vector<float> fz = zMapping(fx);
    vector<float> fzp = zMapping(fxp);

    float result = fz[0];
    float product, sum;

    cout<<"Polinomio de Hermite : ";
    for(int i=1; i<z.size(); i++)
    {
        sum = dividedDifference(z, fz, fzp, i, 0);
        (sum>=0) ? cout<<"+"<<sum:cout<<sum;

        product = 1;
        for(int j=0; j<i; j++)
        {
            cout<<"(x";
            (-z[j]>=0) ? cout<<"+"<<-z[j]<<")":cout<<-z[j]<<")";
            product *= (x_input - z[j]);
        }
        result+=sum*product;
    }
    cout<<endl;
    cout<<"Polinomio evaluado en "<<x_input<<" = ";

    return result;
}

int main()
{
    vector<float> p = {8.3, 8.6};
    vector<float> pE = {17.56492, 18.50515};
    vector<float> pD = {3.116256, 3.151762};
    float num = 8.3;

    cout<<Hermite(p, pE, pD, num)<<endl;
}