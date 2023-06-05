#include <iostream>
#include <cmath>
using namespace std;
int i,j,track,head,temp,flag,moved,num=0,cmin;
int order[50];
void result(int neworder[]);
int main()
{
    cout<<"输入柱面数"<<"  ";
    cin>>track;
    cout<<"该柱面编号为1-"<<track<<endl;
    cout<<"输入当前磁头位置"<<"  ";
    cin>>head;
    cout<<"输入磁道访问请求序列，输入柱面数加1的值作为结束符"<<endl;
    for(i=0;i<50;i++)
    {
        order[i]=NULL;
    }
    for(i=0;i<50;i++)
    {
        cin>>order[i];
        if(order[i]==track+1){order[i]=NULL;break;}
    }
    for(i=0;i<50;i++)
    {
       if(order[i]!=0){num++;}
    }
    int neworder[num];
    for(i=0;i<num;i++)
    {
        neworder[i]=order[i];
    }
    cout<<"输入调度算法：1.先来先服务，2.最短寻道时间优先，3.电梯算法。"<<" ";
    cin>>flag;
    switch(flag)
    {
    case 1:
        {
            result(neworder);break;
        }
    case 2:
        {
            cmin=fabs(neworder[0]-head);
            for(i=0;i<num;i++)
            {
                if(fabs(neworder[i]-head)<cmin)
                {
                    cmin=fabs(neworder[i]-head);
                    temp=neworder[0];
                    neworder[0]=neworder[i];
                    neworder[i]=temp;
                }
            }
            for(i=0;i<num;i++)
            {
                cmin=fabs(neworder[i+1]-neworder[i]);
                for(j=i+1;j<num;j++)
                {
                    if(fabs(neworder[j]-neworder[i])<cmin)
                    {
                    cmin=fabs(neworder[j]-neworder[i]);
                    temp=neworder[i+1];
                    neworder[i+1]=neworder[j];
                    neworder[j]=temp;
                    }
                }
            }
            result(neworder);break;
        }
    case 3:
        {
            int a[num],b[num],m=0,n=0;
            for(i=0;i<num;i++)
            {
                if(neworder[i]<=head)
                {
                    a[m]=neworder[i];m++;
                }
                else{b[n]=neworder[i];n++;}
            }
            cmin=fabs(a[0]-head);
            for(i=0;i<m;i++)
            {
                if(fabs(a[i]-head)<cmin)
                {
                    cmin=fabs(a[i]-head);
                    temp=a[0];
                    a[0]=a[i];
                    a[i]=temp;
                }
            }
            for(i=0;i<m;i++)
            {
                cmin=fabs(a[i+1]-a[i]);
                for(j=i+1;j<m;j++)
                {
                    if(fabs(a[j]-a[i])<cmin)
                    {
                    cmin=fabs(a[j]-a[i]);
                    temp=a[i+1];
                    a[i+1]=a[j];
                    a[j]=temp;
                    }
                }
            }
            cmin=fabs(b[0]-head);
            for(i=0;i<n;i++)
            {
                if(fabs(b[i]-head)<cmin)
                {
                    cmin=fabs(b[i]-head);
                    temp=b[0];
                    b[0]=b[i];
                    b[i]=temp;
                }
            }
            for(i=0;i<n;i++)
            {
                cmin=fabs(b[i+1]-b[i]);
                for(j=i+1;j<n;j++)
                {
                    if(fabs(b[j]-b[i])<cmin)
                    {
                    cmin=fabs(b[j]-b[i]);
                    temp=b[i+1];
                    b[i+1]=b[j];
                    b[j]=temp;
                    }
                }
            }
            cout<<"输入当前磁头移动方向：1.向地址小的方向，2.向地址大的方向"<<"  ";
            int direction;
            cin>>direction;
            if(direction==1)
            {
                for(i=0;i<m;i++)
                {
                    neworder[i]=a[i];
                }
                for(i=m;i<m+n;i++)
                {
                    neworder[i]=b[i-m];
                }
                result(neworder);break;
            }
            else if(direction==2)
            {
                for(i=0;i<n;i++)
                {
                    neworder[i]=b[i];
                }
                for(i=n;i<m+n;i++)
                {
                    neworder[i]=a[i-n];
                }
                result(neworder);break;
            }
            else{cout<<"输入错误"<<endl;break;}
        }
    default:cout<<"输入错误"<<endl;
    }
    return 0;
}
void result(int neworder[])
{
    cout<<"磁头访问顺序为："<<" ";
    cout<<head<<" ";
    moved=fabs(neworder[0]-head);
    for(i=0;i<num;i++)
    {
        if(i>=1){moved=moved+fabs(neworder[i]-neworder[i-1]);}
        cout<<neworder[i]<<" ";
    }
    cout<<"磁头移动总量："<<moved<<endl;
}
