#include <iostream>
#include <cmath>

using namespace std;
float func(float x){
  x=x+1;
  float y=pow(x,1.0/3);
  cout<<y<<endl;
  return y;
}


int main()
{
    float x0=1.5,e,N,k=1;
    cin>>e>>N;
    while(k<=N){
        float x1=func(x0);
        cout<<k<<"  "<<x1<<endl;
        if(fabs(x1-x0)<e){cout<<x1<<endl;break;}
        k++;x0=x1;
    }
    return 0;
}

