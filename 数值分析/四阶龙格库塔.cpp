#include <iostream>
#include <cmath>

using namespace std;
float func(float x,float y){
  float yd=y-2*x/y;
  return yd;
}

int main()
{
    float x0=0,y0=1,h,N,n;
    n=1;
    cin>>h>>N;
    while(n<=N){
        float x1=x0+h;
        float k1=func(x0,y0);
        float k2=func(x0+h/2,y0+h/2*k1);
        float k3=func(x0+h/2,y0+h/2*k2);
        float k4=func(x1,y0+h*k3);
        float y1=y0+h/6*(k1+2*k2+2*k3+k4);
        cout<<x1<<endl;
        cout<<y1<<endl;
        n++;x0=x1;y0=y1;
    }
    return 0;
}

