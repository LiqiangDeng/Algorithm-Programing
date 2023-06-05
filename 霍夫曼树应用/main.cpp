#include <iostream>
using namespace std;

struct Huffman
{
	int weight;
	int parent,lchild,rchild;
};

void select(Huffman *ht,int i,int &s1,int &s2)
{
	int j,k;
	k=s1;
	for(j=0;j<i+1;j++)
		if(s1!=j&&j!=s2&&ht[j].parent==0)
		{
			s1=j;break;
		}
    for(j=0;j<i+1;j++)
		if(s2!=j&&s1!=j&&j!=k&&ht[j].parent==0)
		{
			s2=j;break;
		}
	for(j=1;j<=i;j++)
		if(ht[j].weight<ht[s1].weight&&ht[j].parent==0)s1=j;
		if(s1==s2)
		{
           for(j=0;j<i+1;j++)
	    	if(s2!=j&&s1!=j&&j!=k&&ht[j].parent==0)
			{
			s2=j;break;
			}
		}
	for(j=0;j<=i;j++)
		if(ht[j].weight<ht[s2].weight&&ht[j].parent==0&&j!=s1) s2=j;

}
void Huffmancoding(Huffman * ht,char * *&hc,int k)
{
	int m,s1=0,s2=0,start,c,i,f,j;
	char * cd;
	m=2*k-1;
	for(i=k;i<m;i++)
	{
		select(ht,i-1,s1,s2);
		ht[s1].parent=i;
		ht[s2].parent=i;
        ht[i].lchild=s1;
		ht[i].rchild=s2;
		ht[i].weight=ht[s1].weight+ht[s2].weight;
	}
	for(i=0;i<=k-1;i++)
	{
    	cd=new char[k];
        hc[i]=NULL;
		for(j=0;j<k;j++)
		cd[j]=' ';
		start=k-1;
		for(c=i,f=ht[i].parent;f!=0;c=f,f=ht[f].parent)
			if(ht[f].lchild==c) {cd[start--]='0';}
			else cd[start--]='1';
		hc[i]=&cd[start+1];

	}

}
void frequency(int * & w,char str[100],int * & c,int n,int & k)
{
    int i,j,m;
	for(i=0;i<n;i++)
	{
        if(i==0){c[0]=0;continue;}
		for(j=0;j<i;j++)
		   if(str[j]==str[i]){c[i]=c[j];break;}
		if(j==i){c[i]=++k;}
	}
	for(j=0;j<=k;j++)
	{
		for(m=0;m<n;m++)
			if(c[m]==j)w[j]++;
	}

}
int main()
{
	int i=0,m,j,n=0,k=0,l,r=0,t;
	int * w,* c;
	char * *hc;
	char str[100],str1[100];
    Huffman * ht;
	for(i=0;i<100;i++){str[i]=' ';str1[i]=' ';}
    cout<<"输入需要编码的字符串："<<endl;
	cin>>str;
    i=0;
    while(str[i]!=NULL){n++;i++;}
	n--;
    c=new int [n];
	for(i=0;i<n;i++)c[i]=0;
    w=new int [n];
	for(i=0;i<n;i++)w[i]=0;
    frequency(w,str,c,n,k);
    m=2*n-1;
    ht=new Huffman[m];
	hc=new char*[n*sizeof(char*)];
    for(i=0;i<=k;i++)
	{
		ht[i].weight=w[i];
	   ht[i].parent=ht[i].lchild=ht[i].rchild=0;
	}
	for(;i<m;i++)
	{
		ht[i].weight=ht[i].parent=ht[i].lchild=ht[i].rchild=0;
	}
     k++;

	Huffmancoding(ht,hc,k);
	cout<<"各字符及其相应的编码为："<<endl;

	for(i=0;i<n;i++)
	{
		for(l=0;l<i;l++)
		{
			if(c[i]==c[l])break;
		}
		if(l==i)
		{
			cout<<' '<<str[i]<<' ';
            for(j=0;j<n;j++)
			{
			    if(hc[c[i]][j]!='0'&&hc[c[i]][j]!='1')break;
			    else	cout<<' '<<hc[c[i]][j]<<' ';
			}
        }
	}
	cout<<endl;
    i=0;
	cout<<"输入需要解码的编码:"<<endl;
	cin>>str1;
	m=0;
	while(str1[i]!=' '){m++;i++;}
	m--;
    j=0;
	cout<<"译码后为："<<endl;
	while(j<k)
	{
		for(l=0,i=r;l<k,i<=m;i++,l++)
		{

			if(hc[j][l]!='0'&&hc[j][l]!='1')
			{
				r=i;
				for(t=0;t<n;t++)
					if(c[t]==j){cout<<str[t];break;}
			   j=0;
				break;
			}
			if(str1[i]!=hc[j][l]){j++;break;}
		}
	   if((i==m)&&(hc[j][l]=='0'||hc[j][l]=='1'))cout<<"但最后的"<<i-r<<"个字符无法译码。"<<endl;
		if(i==m)break;
	}
return 0;
}
