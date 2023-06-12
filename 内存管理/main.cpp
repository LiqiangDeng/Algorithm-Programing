#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
using namespace std;

int i,j,re,m,n,reuse;
void usedprint(int a[]);
int unusedprint(int a[],int b[][2]);
void first(int b[][2]);
void second(int b[][2]);
void third(int b[][2]);
int main()
{
    cout<<"输入给定的内存大小,以K为单位"<<"  ";
    cin>>m;
    re=m;
    cout<<"输入进程的个数"<<"  ";
    cin>>n;
    int memory[200],prog[10],use[200][2];
    for(i=1;i<=n;i++)
    {
        cout<<"输入第"<<i<<"号进程的大小"<<"  ";
        cin>>prog[i];
    }
    for(i=1;i<=n;i++)
    {
        if(re-prog[i]>=0){
        for(j=m-re;j<m-re+prog[i];j++)
        {
            memory[j]=i;
        }
        for(j=m-re+prog[i];j<m;j++)
        {
            memory[j]=0;
        }
        }
        else{
        for(j=m-re;j<m-re+prog[i];j++)
        {
            memory[j]=0;
        }
            cout<<"内存不足"<<endl;break;
        }
        re=re-prog[i];
    }
    usedprint(memory);
    reuse=unusedprint(memory,use);
	int flag,size,code,choose;
	while(1)
	{
		cout<<"进程的分配与回收，分配输入1，回收输入2"<<"  ";
		cin>>flag;
		if(flag==1)
		{
			cout<<"请输入需要分配进程的大小"<<"  ";
			cin>>size;
			cout<<"请选择寻找空闲区的算法，1.最先适应算法、2.最佳适应算法、3.最坏适应算法"<<"  ";
			cin>>choose;
			switch(choose)
			{
			    case 1:
					{
						first(use);
						n++;
						for(i=0;i<reuse;i++)
						{
							if(size<=use[i][1])
							{
								for(int t=use[i][0];t<use[i][0]+size;t++)
								{
									memory[t]=n;
								}
								use[i][0]=0;
								use[i][1]=0;
								break;
							}
							else{cout<<"内存不足"<<endl;}
						}
						usedprint(memory);
                        reuse=unusedprint(memory,use);
						break;
					}
			    case 2:
					{
						second(use);
						n++;
						for(i=0;i<reuse;i++)
						{
							if(size<=use[i][1])
							{
								for(int t=use[i][0];t<use[i][0]+size;t++)
								{
									memory[t]=n;
								}
								use[i][0]=0;
								use[i][1]=0;
								break;
							}
							else{cout<<"内存不足"<<endl;}
						}
						usedprint(memory);
                        reuse=unusedprint(memory,use);
						break;
					}
			    case 3:
					{
						third(use);
						n++;
						for(i=0;i<reuse;i++)
						{
							if(size<=use[i][1])
							{
								for(int t=use[i][0];t<use[i][0]+size;t++)
								{
									memory[t]=n;
								}
								use[i][0]=0;
								use[i][1]=0;
								break;
							}
							else{cout<<"内存不足"<<endl;}
						}
						usedprint(memory);
                        reuse=unusedprint(memory,use);
						break;
					}
			    default:cout<<"输入错误，请重新输入"<<endl;
			}

		}
		else if(flag==2)
		{
			cout<<"请输入需要回收的进程编号"<<"  ";
			cin>>code;
			for(i=0;i<m;i++)
			{
				if(memory[i]==code){memory[i]=0;}
			}
			usedprint(memory);
            reuse=unusedprint(memory,use);
		}
		else{cout<<"输入错误，请重新输入"<<endl;continue;}
	}
    return 0;
}
void usedprint(int a[])
{
    cout<<"当前的进程在内存的存储情况："<<endl;
    int temp=0,num=0;
    for(i=0;i<m;i++)
    {
        if(a[i]!=0)
        {
            if(a[i]!=temp)
            {
                if(num!=0){cout<<num<<"K;"<<endl;}
                num=1;
                cout<<"第"<<a[i]<<"号进程："<<"  "<<"起始："<<i<<"K"<<"  "<<"大小：";
                temp=a[i];
            }
            else{num++;}
        }
    }
    cout<<num<<"K;"<<endl;
}
int unusedprint(int a[],int b[][2])
{
    cout<<"可用表情况："<<endl;
    int flag=0,num=0;
	j=0;
    for(i=0;i<m;i++)
    {
        if(a[i]==0)
        {
            num++;
            if(flag==0){b[j][0]=i;cout<<"空闲区 起始地址："<<b[j][0]<<"K"<<"  ";flag=1;}
        }
        else
        {
            if(num!=0){b[j][1]=num;cout<<"大小："<<b[j][1]<<"K;"<<endl;j++;}
            num=0;flag=0;
        }
    }
    if(num!=0){b[j][1]=num;cout<<"大小："<<b[j][1]<<"K;"<<endl;j++;}
	return j;
}
void first(int b[][2])
{
	int temp1,temp2;
	for(i=0;i<reuse;i++)
	{
		for(j=i;j<reuse;j++)
		{
			if(b[i][0]>b[j][0])
			{
				temp1=b[i][0];temp2=b[i][1];
				b[i][0]=b[j][0];b[i][1]=b[j][1];
				b[j][0]=temp1;b[j][1]=temp2;
			}
		}
	}
}
void second(int b[][2])
{
	int temp1,temp2;
	for(i=0;i<reuse;i++)
	{
		for(j=i;j<reuse;j++)
		{
			if(b[i][1]>b[j][1])
			{
				temp1=b[i][0];temp2=b[i][1];
				b[i][0]=b[j][0];b[i][1]=b[j][1];
				b[j][0]=temp1;b[j][1]=temp2;
			}
		}
	}
}
void third(int b[][2])
{
	int temp1,temp2;
	for(i=0;i<reuse;i++)
	{
		for(j=i;j<reuse;j++)
		{
			if(b[i][1]<b[j][1])
			{
				temp1=b[i][0];temp2=b[i][1];
				b[i][0]=b[j][0];b[i][1]=b[j][1];
				b[j][0]=temp1;b[j][1]=temp2;
			}
		}
	}
}
