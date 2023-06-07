#include <iostream>

using namespace std;


int main()
{
    cout<<"输入有多少个村庄"<<endl;
    int n;
    cin>>n;
    if(n==0)return false;
    int arc[n][n];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<"第"<<i<<"个村庄到第"<<j<<"个村庄的距离"<<endl;
            cin>>arc[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout.width(3);
            cout<<arc[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    int u,v,w,D[n][n];
    for(v=1;v<=n;++v)
        for(w=1;w<=n;++w)
    {
        D[v][w]=arc[v][w];
    }
    for(u=1;u<=n;++u)
        for(v=1;v<=n;++v)
           for(w=1;w<=n;++w)
              if(D[v][u]+D[u][w]<D[v][w])
    {
        D[v][w]=D[v][u]+D[u][w];

    }
    for(int v=1;v<=n;v++)
    {
        for(int w=1;w<=n;w++)
        {
            cout.width(3);
            cout<<D[v][w];
        }
        cout<<endl;
    }
    int min[n];
    for(v=1;v<=n;v++)
    {
        min[v]=0;
        for(int w=1;w<=n;w++)
        {
           if(min[v]<D[v][w])
                min[v]=D[v][w];
        }
        cout<<min[v]<<endl;
    }
   int s=1;
   for(int t=1;t<=v;t++)
   {
       if (min[t]<min[s])
       s=t;
   }
    cout<<"第"<<s<<"个村庄符合条件"<<endl;
    return 0;
}
