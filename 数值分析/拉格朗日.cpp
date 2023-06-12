#include <iostream>
#include <cmath>

using namespace std;
int main(){
float x,n;
cin>>x>>n;
int a[50],b[50];
for(int i=0;i<n;i++)
{
cin>>a[i]>>b[i];}
float y=0;
for(int k=0;k<n;k++){
float t=1;
for(int j=0;j<n;j++){
if(j!=k) t=(x-a[j])/(a[k]-a[j])*t;}
y=y+t*b[k];
}
cout<<y<<endl;
return 0;
}
