#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

struct Node
{
    float coef;
    int exp;
};
typedef Node polynomial;
struct LNode
{
    polynomial data;
    LNode *next;
};
typedef LNode *Link;
void CreateLink(Link &L,int n);
void PrintList(Link L);
void PolyAdd(Link &pc,Link pa,Link pb);
void CopyLink(Link &pc,Link pa);
void PolyMultiply(Link &pc,Link pa,Link pb);
void DestroyLink(Link &L);


void DestroyLink(Link &L)
{
    Link p;
    p=L->next;
    while(p)
    {
        L->next=p->next;
        delete p;
        p=L->next;
    }
    delete L;
    L=NULL;
}
void CreateLink(Link &L,int n)
{
    Link newp;
    L=new LNode;
    L->next=NULL;
    (L->data).exp=-1;

    for(int i=1; i<=n; i++)
    {
        newp=new LNode;
        cout<<"请输入第"<<i<<"项的系数和指数:"<<endl;
        cout<<"系数:";
        cin>>(newp->data).coef;
        cout<<"指数:";
        cin>>(newp->data).exp;
        if(newp->data.exp<0)
        {
            cout<<"您输入有误，指数不允许为负值!"<<endl;
            delete newp;
            i--;
            continue;
        }

        if(newp->data.coef==0)
        {
            cout<<"系数为零，重新输入!"<<endl;
            delete newp;
            i--;
            continue;
        }
            newp->next=L->next;
            L->next=newp;

    }
        if(L==NULL||L->next==NULL)
        cout<<"该一元多项式为空！创建失败！"<<endl;
}

void PrintList(Link L)
{
    Link p;
    if(L==NULL||L->next==NULL)
        cout<<"该一元多项式为空！"<<endl;
    else
    {
        p=L->next;
        if((p->data).coef>0)
        {
            if((p->data).exp==0)
                cout<<(p->data).coef;
            else if((p->data).coef==1&&(p->data).exp==1)
                cout<<"x";
            else if((p->data).coef==1&&(p->data).exp!=1)
                cout<<"x^"<<(p->data).exp;
            else if((p->data).exp==1&&(p->data).coef!=1)
                cout<<(p->data).coef<<"x";
            else cout<<(p->data).coef<<"x^"<<(p->data).exp;
        }
        if((p->data).coef<0)
        {
            if((p->data).exp==0)
                cout<<(p->data).coef;
            else if(p->data.coef==-1&&p->data.exp==1)
                cout<<"-x";
            else if(p->data.coef==-1&&p->data.exp!=1)
                cout<<"-x^"<<p->data.exp;
            else if(p->data.exp==1)
                cout<<p->data.coef<<"x";
            else cout<<(p->data).coef<<"x^"<<(p->data).exp;
        }
        p=p->next;
        while(p!=NULL)
        {
            if((p->data).coef>0)
            {
                if((p->data).exp==0)
                    cout<<"+"<<(p->data).coef;
                else if((p->data).exp==1&&(p->data).coef!=1)
                    cout<<"+"<<(p->data).coef<<"x";
                else if((p->data).exp==1&&(p->data).coef==1)
                    cout<<"+"<<"x";
                else if((p->data).coef==1&&(p->data).exp!=1)
                    cout<<"+"<<"x^"<<(p->data).exp;
                else cout<<"+"<<(p->data).coef<<"x^"<<(p->data).exp;

                if((p->data).coef<0)
                {
                    if((p->data).exp==0)
                        cout<<(p->data).coef;
                    else if(p->data.coef==-1&&p->data.exp==1)
                        cout<<"-x";
                    else if(p->data.coef==-1&&p->data.exp!=1)
                        cout<<"-x^"<<p->data.exp;
                    else if(p->data.exp==1)
                        cout<<p->data.coef<<"x";
                    else cout<<(p->data).coef<<"x^"<<(p->data).exp;
                }
                p=p->next;
            }
        }
        cout<<endl;
    }
}
void CopyLink(Link &pc,Link pa)
{
    Link p,q,r;
    pc=new LNode;
    pc->next=NULL;
    r=pc;
    p=pa;
    while(p->next!=NULL)
    {
        q=new LNode;
        q->data.coef=p->next->data.coef;
        q->data.exp=p->next->data.exp;
        r->next=q;
        q->next=NULL;
        r=q;
        p=p->next;
    }
}
void PolyAdd(Link &pc,Link pa,Link pb)
{
    Link p1,p2,p,pd;
    CopyLink(p1,pa);
    CopyLink(p2,pb);
    pc=new LNode;
    pc->next=NULL;
    p=pc;
    p1=p1->next;
    p2=p2->next;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->data.exp<p2->data.exp)
        {
            p->next=p1;
            p=p->next;
            p1=p1->next;
        }
        else if(p1->data.exp>p2->data.exp)
        {
            p->next=p2;
            p=p->next;
            p2=p2->next;
        }
        else
        {
            p1->data.coef=p1->data.coef+p2->data.coef;
            if(p1->data.coef!=0)
            {
                p->next=p1;
                p=p->next;
                p1=p1->next;
                p2=p2->next;
            }
            else
            {
                pd=p1;
                p1=p1->next;
                p2=p2->next;
                delete pd;
            }
        }
    }
    if(p1!=NULL)
    {
        p->next=p1;
    }
    if(p2!=NULL)
    {
        p->next=p2;
    }
}
void Clear()
{
    system("pause");
    system("cls");
}
void PolyMultiply(Link &pc,Link pa,Link pb)
{
    Link p1,p2,p,pd,newp,t;
    pc=new LNode;
    pc->next=NULL;
    p1=pa->next;
    p2=pb->next;
    while(p1!=NULL)
    {
        pd=new LNode;
        pd->next=NULL;
        p=new LNode;
        p->next=NULL;
        t=p;
        while(p2)
        {
            newp=new LNode;
            newp->next=NULL;
            newp->data.coef=p1->data.coef*p2->data.coef;
            newp->data.exp=p1->data.exp+p2->data.exp;
            t->next=newp;
            t=t->next;
            p2=p2->next;
        }
        PolyAdd(pd,pc,p);
        CopyLink(pc,pd);
        p1=p1->next;
        p2=pb->next;
        DestroyLink(p);
        DestroyLink(pd);
    }
}

int main()
{
    int n;
    Link L,La=NULL,Lb=NULL;
    cout<<"输入第一个一元多项式的项数:"<<endl;
    cin>>n;
    CreateLink(La,n);
    cout<<"输入第二个一元多项式的项数:"<<endl;
    cin>>n;
    CreateLink(Lb,n);
    if(La==NULL||Lb==NULL)
        {
            cout<<"多项式创建错误，重新选择"<<endl;
            Clear();
        }
            PrintList(La);
            PrintList(Lb);
    int choose;
    cout<<"[1] 将两个一元多项式相加   "<<endl;
    cout<<"[2] 将两个一元多项式相乘   "<<endl;
    cout<<"请选择:";
    cin>>choose;
    switch(choose)
    {
    case 1:
        if(La==NULL||Lb==NULL)
        {
            cout<<"多项式创建错误，重新选择"<<endl;
            Clear();
            break;
        }
        PolyAdd(L,La,Lb);
        cout<<"设相加的两个一元多项式为Ａ和Ｂ则："<<endl;
        cout<<"A的多项式为：";
        PrintList(La);
        cout<<"B的多项式为：";
        PrintList(Lb);
        cout<<"相加后的结果为：";
        PrintList(L);
        Clear();
        DestroyLink(L);
        break;
    case 2:
        if(La==NULL||Lb==NULL)
        {
            cout<<"多项式创建有误，重新选择"<<endl;
            Clear();
            break;
        }
        PolyMultiply(L,La,Lb);
        cout<<"设相乘的两个一元多项式为Ａ和Ｂ则："<<endl;
        cout<<"A的多项式为：";
        PrintList(La);
        cout<<"B的多项式为：";
        PrintList(Lb);
        cout<<"相乘后的结果为：";
        PrintList(L);
        DestroyLink(L);
        Clear();
        break;

    }
    return 0;
}
