#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int k=1;
	int i=0;
	int j=0;
	int N=10;
	double a[3][3]={{10,-1,-2},{-1,10,-2},{-1,-1,5}};
	double b[3]={7.2,8.3,4.2};
	double x[3]={0,0,0};
	double y[3]={0};
	double e=0.00001;
	/*cout<<"系数矩阵"<<endl;
	for(int na1=0;na1<3;na1++){
		for(int na2=0;na2<3;na2++){
			cin>>a[na1][na2];
		}
	}
	cout<<"常数项"<<endl;
	for(int nb=0;nb<3;nb++){
		cin>>b[nb];
	}*/
	while(k<=N){
		for(i=0;i<3;i++){
		    double t=0;
		for(j=0;j<3;j++){
			if(j!=i){t=t+a[i][j]*x[j];}
		}
		y[i]=(b[i]-t)/a[i][i];cout<<y[i]<<endl;
		}
		double s1,s2;
        for(i=0;i<3;i++){
            s1=fabs(x[i]-y[i]);
			if(s2<s1){s2=s1;}
		}

	    if(s2<e){
		   for(i=0;i<3;i++){
			cout<<y[i]<<endl;
		   }
		   break;
		}
	    k++;
	    for(i=0;i<3;i++){
		x[i]=y[i];
		}
	}
	return 0;
}