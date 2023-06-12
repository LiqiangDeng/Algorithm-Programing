#include <stdio.h>
#include <stdlib.h>

#define N 10 
float getm(float a[N][N], float x[N], int i, int n)
{
    float m = 0;
    int r;
    for(r=i+1; r<n; r++)
    {
        m += a[i][r] * x[r];
    }
    return m;
}


float getx(float a[N][N], float b[N], float x[N], int i, int n)
{
    float result;
    if(i==n-1) 
        result = float(b[n-1]/a[n-1][n-1]);
    else 
        result = float((b[i]-getm(a,x,i,n))/a[i][i]);

    return result;
}

void main()
{
    
    float a[N][N]; 
    float b[N]; 
    float x[N]; 
    int i,j,k;
    int n=N; 
   
    printf("系数矩阵的大小：\n");
    scanf("%d", &n);
    printf("系数矩阵：\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        scanf("%f", &a[i][j]);
    }
    printf("右端项：");
    for(i=0; i<n; i++)
    {
        scanf("%f", &b[i]);
    }


  
    for(j=0; j<n-1; j++)
    {
        for(i=j+1; i<n; i++)
        {
            float m = (float)(a[i][j]/a[j][j]);
            for(k=j; k<n; k++)
            {
                a[i][k] = a[i][k]-m*a[j][k];
            }
            b[i] = b[i]-m*b[j];
        }
    }

    for(i=n-1; i>=0; i--)
    {
        x[i] = getx(a,b,x,i,n);
    }

    printf("\n\n方程组解\n");
    for(i=0; i<n; i++)
    {
        printf("x%d = %f\n", i+1,x[i]);
    }
}