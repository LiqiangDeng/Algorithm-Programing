#include <iostream>
#include <strstream>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;
int syn,p,m,n,i,j,point,num,code,fl;
string temp1,temp2,temp3,str;
char ch;
char b[8];
char relation[21][21],a[22][22];
char mark[21]={'S','E','e','T','t','F','i','(','=',')','+','*','$','#','D','W','A','B','>','<','N'};
char input[80];
char *key[2]={"do","while"};
string old[50];
char newed[50];
int compare(char pre, char d);
void scanner();
int main()
{
    stack<string> s1;
    stack<char> s2;
    relation[1][9]=relation[3][2]=relation[5][4]=relation[6][8]=relation[7][1]=relation[10][3]=relation[11][5]=relation[8][1]=relation[13][13]='=';
    relation[3][10]=relation[3][12]=relation[5][11]=relation[5][12]=relation[7][3]=relation[7][5]=relation[7][6]=relation[7][7]=relation[10][5]=relation[10][6]=relation[10][7]=relation[11][6]=relation[11][7]=relation[8][3]=relation[8][5]=relation[8][6]=relation[8][7]=relation[13][0]=relation[13][6]='<';
    relation[4][2]=relation[4][10]=relation[4][12]=relation[5][9]=relation[5][10]=relation[6][4]=relation[6][9]=relation[6][10]=relation[6][11]=relation[6][12]=relation[9][4]=relation[12][2]=relation[12][10]=relation[12][12]=relation[1][13]=relation[2][13]=relation[9][11]=relation[3][13]=relation[4][13]=relation[5][13]=relation[9][13]=relation[6][13]=relation[12][13]=relation[2][9]=relation[4][9]=relation[3][9]='>';
    relation[13][14]=relation[14][6]='<';
    relation[6][15]=relation[5][15]=relation[4][15]=relation[3][15]=relation[2][15]=relation[1][15]='>';
    relation[15][7]=relation[6][18]=relation[6][19]='<';
    relation[18][6]=relation[19][6]=relation[16][13]=relation[20][13]='>';
    relation[17][6]=relation[0][15]=relation[6][9]=relation[7][6]='=';
    for(i=1;i<22;i++)
    {
        a[0][i]=mark[i-1];
    }
    for(j=1;j<22;j++)
    {
        a[j][0]=mark[j-1];
    }
    for(i=1;i<22;i++)
    {
        for(j=1;j<22;j++)
        {
            a[i][j]=relation[i-1][j-1];
        }
    }
//    cout<<"文法G(N):"<<endl;
//    cout<<"N->do S while A"<<endl;
//    cout<<"S->i=E"<<endl;
//    cout<<"E->Te"<<endl;
//    cout<<"e->+Te|$"<<endl;
//    cout<<"T->Ft"<<endl;
//    cout<<"t->*Ft|$"<<endl;
//    cout<<"F->i"<<endl;
//    cout<<"A->"<<"("<<"iBi"<<")"<<endl;
//    cout<<"B-><|>"<<endl;
//    cout<<"简单优先关系矩阵："<<endl;
//    for(i=0;i<22;i++)
//    {
//        for(j=0;j<22;j++)
//        {
//            cout<<a[i][j]<<"  ";
//        }
//        cout<<endl;
//    }
    p=0;
    point=0;
    cout<<"1.输出四元式,2.输出三地址码."<<"  ";
    cin>>fl;
	cout<<"Please input string end with #"<<endl;
	do
	{
		ch=getchar();
		input[p++]=ch;
	}while(ch!='#');
	p=0;
	do
	{
		scanner();
	}while(syn!=0);
//	for(i=0;i<point;i++)
//    {
//        cout<<old[i]<<"   ";
//    }
//    cout<<endl;
//    for(i=0;i<point;i++)
//    {
//        cout<<newed[i]<<"   ";
//    }
    cout<<endl;
    p=0;num=100;
    code=num-99;
	s1.push("#");
	s2.push('#');
	while(!s2.empty())
    {
        char pre = s2.top();
        if(compare(pre,newed[p])==1)
        {
            s1.push(old[p]);
            s2.push(newed[p]);
//            cout<<"移进"<<old[p]<<endl;
        }
        else if(compare(pre,newed[p])==0)
		{
//		    cout<<"归约";
            p--;
            char c=s2.top();
            switch(c)
            {
                case'N':s2.pop();s2.pop();break;
				case'E':s2.pop();if(s2.top()=='=')
						{
							s2.pop();
					        if(s2.top()=='i')
							{
								s2.pop();s2.push('S');
//								cout<<"S->i=E"<<endl;
								strstream ss;ss<<code;ss>>str;
								temp3=s1.top();s1.pop();temp2=s1.top();s1.pop();temp1=s1.top();s1.pop();s1.push("T"+str);
								if(fl==1){cout<<num<<" "<<"("<<temp2<<","<<temp3<<","<<"-"<<","<<temp1<<")"<<endl;num++;code++;break;}
						        if(fl==2){cout<<num<<" "<<temp1<<temp2<<temp3<<endl;num++;code++;break;}
							}
							else {cout<<"error"<<endl;break;}
						}
					    else {cout<<"error"<<endl;break;}

                case'e':s2.pop();if(s2.top()=='T')
						{   s2.pop();
						    if(s2.top()=='+')
                            {
                                s2.pop();s2.push('e');
//                                cout<<"e->+Te|$"<<endl;
                                ;strstream ss;ss<<code;ss>>str;
                                temp3=s1.top();s1.pop();temp2=s1.top();s1.pop();temp1=s1.top();s1.pop();s1.push("T"+str);
                                if(fl==1){cout<<num<<" "<<"("<<temp2<<","<<temp1<<","<<temp3<<","<<s1.top()<<")"<<endl;num++;code++;break;}
						        if(fl==2){cout<<num<<" "<<s1.top()<<"="<<temp1<<temp2<<temp3<<endl;num++;code++;break;}
						    }
						    else{s2.push('E');
//						    cout<<"E->Te"<<endl;
						    strstream ss;ss<<code;ss>>str;
						    temp3=s1.top();s1.pop();temp2=s1.top();s1.pop();temp1=s1.top();s1.pop();s1.push("T"+str);
                            if(fl==1){cout<<num<<" "<<"("<<temp2<<","<<temp1<<","<<temp3<<","<<s1.top()<<")"<<endl;num++;code++;break;}
                            if(fl==2){cout<<num<<" "<<s1.top()<<"="<<temp1<<temp2<<temp3<<endl;num++;code++;break;}
						}}else {cout<<"error"<<endl;break;}

				case't':s2.pop();if(s2.top()=='F')
						{   s2.pop();
						    if(s2.top()=='*')
                            {
                                s2.pop();s2.push('t');
//                                cout<<"t->*Ft|$"<<endl;
                               strstream ss;ss<<code;ss>>str;
                                temp3=s1.top();s1.pop();temp2=s1.top();s1.pop();temp1=s1.top();s1.pop();s1.push("T"+str);
						        if(fl==1){cout<<num<<" "<<"("<<temp2<<","<<temp1<<","<<temp3<<","<<s1.top()<<")"<<endl;num++;code++;break;}
						        if(fl==2){cout<<num<<" "<<s1.top()<<"="<<temp1<<temp2<<temp3<<endl;num++;code++;break;}
						    }
						    else{s2.push('T');
//						    cout<<"T->Ft"<<endl;
						    strstream ss;ss<<code;ss>>str;
						    temp3=s1.top();s1.pop();temp2=s1.top();s1.pop();temp1=s1.top();s1.pop();s1.push("T"+str);
						        if(fl==1){cout<<num<<" "<<"("<<temp2<<","<<temp1<<","<<temp3<<","<<s1.top()<<")"<<endl;num++;code++;break;}
						        if(fl==2){cout<<num<<" "<<s1.top()<<"="<<temp1<<temp2<<temp3<<endl;num++;code++;break;}
						}}else {cout<<"error"<<endl;break;}
				case'i':{s2.pop();
				         s2.push('F');
//				         cout<<"F->i"<<endl;
				         break;}
				case'F':{s2.pop();
					    if(s2.top()=='*')
						{
							s2.pop();
							s2.push('t');
//							cout<<"t->*Ft|$"<<endl;
							break;
						}
						else{s2.push('T');
//						cout<<"T->Ft"<<endl;
						break;}
						}
				case'T':{s2.pop();
					    if(s2.top()=='+')
						{
							s2.pop();
							s2.push('e');
//							cout<<"e->+Te|$"<<endl;
							break;
						}
						else{s2.push('E');
//						cout<<"E->Te"<<endl;
						break;}
						}
                case'>':{s2.pop();s2.push('B');
//                cout<<"B-><|>"<<endl;
                break;}
                case'<':{s2.pop();s2.push('B');
//                cout<<"B-><|>"<<endl;
                break;}
                case'A':{
                           s2.pop();
                           if(s2.top()=='W')
                           {
                               s2.pop();
                               if(s2.top()=='S')
                               {
                                   s2.pop();
                                   if(s2.top()=='D')
                                   {
                                       s2.pop();
                                       s2.push('N');
//                                       cout<<"N->do S while A"<<endl;
                                       strstream ss;ss<<code;ss>>str;
                                       s1.pop();temp3=s1.top();s1.pop();temp2=s1.top();s1.pop();temp1=s1.top();s1.pop();s1.push("T"+str);
						               if(fl==1&&temp2==">"){cout<<num<<" "<<"("<<"j"<<"a"<<","<<temp1<<","<<temp3<<","<<"100"<<")"<<endl;num++;code++;
						               cout<<num<<" "<<endl;num++;break;}
						               if(fl==1&&temp2=="<"){cout<<num<<" "<<"("<<"j"<<"b"<<","<<temp1<<","<<temp3<<","<<"100"<<")"<<endl;num++;code++;
						               cout<<num<<" "<<endl;num++;break;}
						               if(fl==2){cout<<num<<" "<<"if"<<" "<<temp1<<temp2<<temp3<<" "<<"goto 100"<<endl;num++;code++;
						               cout<<num<<" "<<endl;num++;break;}
                                   }
                                   else{cout<<"error"<<endl;break;}
                               }
                               else{cout<<"error"<<endl;break;}
                           }
                           else{cout<<"error"<<endl;break;}
                        }
                case')':{
                           s2.pop();
                           if(s2.top()=='i')
                           {
                               s2.pop();
                               if(s2.top()=='B')
                               {
                                   s2.pop();
                                   if(s2.top()=='i')
                                   {
                                       s2.pop();
                                       if(s2.top()=='(')
                                       {
                                           s2.pop();
                                           s2.push('A');
//                                           cout<<"A->"<<"("<<"iBi"<<")"<<endl;
                                           break;
                                       }
                                       else{cout<<"error"<<endl;break;}
                                   }
                                   else{cout<<"error"<<endl;break;}
                               }
                               else{cout<<"error"<<endl;break;}
                           }
                           else{cout<<"error"<<endl;break;}
                        }
            }
        }
		else{cout<<"关系错误"<<endl;break;}
        p++;
    }
    if(s2.empty())
    {
        cout<<"分析成功"<<endl;
    }else{
        cout<<"分析失败"<<endl;
    }
    return 0;
}
void scanner()
{
	m=0;syn=1;
	for(n=0;n<8;n++)
	{
	    b[n]=NULL;
	}
	ch=input[p++];
	while(ch==' ')
    {
	  ch=input[p++];
    }
	if(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z')))
	{
		while(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))||((ch>='0')&&(ch<='9')))
		{
			b[m++]=ch;
            ch=input[p++];
		}
	    b[m++]='\0';p--;
	 for(n=0;n<2;n++)
	 {
    	 if(strcmp(b,key[n])==0)
	 	 {
		 	if(n==0){newed[point]='D';old[point]=b;}
		 	else{newed[point]='W';old[point]=b;}
		 	point++;syn=10;
		    break;
		 }
	 }
	 if(syn!=10)
	 {
	     old[point]=b;
	     newed[point]='i';
	     point++;
	 }
	}
	else switch(ch)
	{
		case '<':
            old[point]='<';
	        newed[point]='<';
	        point++;
            break;
		case '>':
		    old[point]='>';
	        newed[point]='>';
	        point++;
	        break;
		case '+':
            old[point]='+';
	        newed[point]='+';
	        point++;
            break;
		case '*':
            old[point]='*';
	        newed[point]='*';
	        point++;
            break;
		case '=':
            old[point]='=';
	        newed[point]='=';
	        point++;
            break;
        case '(':
            old[point]='(';
	        newed[point]='(';
	        point++;
            break;
        case ')':
            old[point]=')';
	        newed[point]=')';
	        point++;
            break;
		case'#':
            old[point]='#';
	        newed[point]='#';
	        point++;
	        syn=0;
            break;
//		default:
//			cout<<"输入错误"<<endl;
    }
}

int compare(char pre, char d)
{
    int a=50,b=50;
    for(i=0;i<21;i++)
    {
        if(mark[i]==pre)a=i;
        if(mark[i]==d)b=i;
    }
	if(a==50){return 2;}
    char rel = relation[a][b];
    if(rel=='>'){    return 0;   }
    if(rel=='='||rel=='<'){    return 1;   }
    return 2;
}
