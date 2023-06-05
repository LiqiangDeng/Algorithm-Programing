#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>


using namespace std;

typedef int elemtype;
typedef struct LNode
{
	elemtype data;
	struct LNode *next;
}LNode,*Link;

void CreateList(Link &L,int n)//创建表L
{
    Link p;
    L=new LNode;
    L=(Link)malloc(sizeof(LNode));
    L->next=NULL;
    for(int i=n;i>0;--i)
	{
	    p=new LNode;
	    p=(Link)malloc(sizeof(LNode));
	    cout<<"请输入表中第"<<n-i+1<<"个数字"<<endl;
        cin>>p->data;
        p->next=L->next;L->next=p;
	}
    if(L==NULL||L->next==NULL)
	{cout<<"该表为空！创建失败！"<<endl;exit(-1);}
}
void unions(Link La,Link Lb,Link &Lc)//将表La，Lb中的相同元素存入Lc
{
	Link ha,hb,p;
    ha=La->next;
	hb=Lb->next;
	while(ha!=NULL&&hb!=NULL)
	{
		if(hb->data>ha->data) {ha=ha->next;continue;}
		if(ha->data>hb->data) {hb=hb->next;continue;}
		if(ha->data==hb->data) {p=new LNode;
	    p=(Link)malloc(sizeof(LNode));p->data=ha->data;ha=ha->next;hb=hb->next;
		p->next=Lc->next;Lc->next=p;continue;}
	}
	if(Lc==NULL||Lc->next==NULL)
	{cout<<"两表无交集"<<endl;exit(-1);}
}

void Del(Link &La,Link Lb)//将表La中有的Lb的元素删除
{
	Link ha,hb,q,p;
	ha=La->next;
	hb=Lb->next;
	p=La;
	while(ha!=NULL&&hb!=NULL)
	{
		if(ha->data<hb->data) {ha=ha->next;p=p->next;continue;}
	    if(ha->data>hb->data) {hb=hb->next;continue;}
		if(ha->data==hb->data)
            {
		       q=ha;ha=ha->next;
               p->next=q->next;
               free(q);
               continue;
            }
	}
}
void PrintList(Link L)//输出表L
{
    Link p;
    if(L==NULL||L->next==NULL)
	{cout<<"该表为空！"<<endl;exit(-1);}
    else
	{
		p=L->next;
		cout<<p->data<<"  ";
         p=p->next;
        while(p!=NULL)
        {
             cout<<p->data<<"  ";
             p=p->next;
        }
	}
     cout<<endl;
}
void sort(Link L)//表L的递增排序
{
	LNode *s=L->next,*p;
     while(s->next)
	 {
		 p=s->next;
		 while(p)
		 {
			 if(p->data<s->data)
			 {
				 int t=p->data;
				 p->data=s->data;
				 s->data =t;
			 }
			 p=p->next;
		 }
		 s=s->next;
	 }
}

int main()
{
    cout<<"该程序用于将对A表删去那些既在B表中出现又在C表中出现的元素。"<<endl;
    cout<<"按1，创建各表，并且自动进行相关操作"<<endl;
    cout<<"按0，退出程序"<<endl;
    while(1){
	int a,b,c,s;
	cin>>s;
	if(s==1){
	Link La=NULL,Lb=NULL,Lc=NULL,Ld=NULL;
	cout<<"表A中有多少个元素"<<endl;
	cin>>a;
    CreateList(La,a);
	sort(La);
	cout<<"表A的递增排序为： ";
	PrintList(La);
	cout<<"表B中有多少个元素"<<endl;
	cin>>b;
    CreateList(Lb,b);
	sort(Lb);
	cout<<"表B的递增排序为： ";
	PrintList(Lb);
	cout<<"表C中有多少个元素"<<endl;
	cin>>c;
    CreateList(Lc,c);
	sort(Lc);
	cout<<"表C的递增排序为： ";
	PrintList(Lc);
	Ld=new LNode;
    Ld=(Link)malloc(sizeof(LNode));
    Ld->next=NULL;
    unions(Lb,Lc,Ld);
    sort(Ld);
    Del(La,Ld);
    cout<<"进行相关操作后得到的表A序列： ";
    PrintList(La);
	break;}
	if(s==0)break;
	else
	{
	    cout<<"输入有误,请重新输入"<<endl;continue;
	}}
	return 0;
}

