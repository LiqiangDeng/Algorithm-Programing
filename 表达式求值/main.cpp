#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

#define Stack_Size 100
#define Stack_Float 100
# define STACKINCREMENT 10
#define TRUE 1
#define FALSE 0
typedef int SElemType;

typedef struct
{
    char elem[Stack_Size];
    int *top;
    int *base;
    int stacksize;
}
Stack_char;
void InitStack(Stack_char&S)
{
    S.base=(SElemType *)malloc(Stack_Size*sizeof(SElemType));
    if(!S.base)exit(FALSE);
    S.top=S.base;
    S.stacksize=Stack_Size;
}
void Push(Stack_char&S,char x)
{
    if(S.top-S.base>=S.stacksize) exit (FALSE);
    *S.top++=x;
}
int Pop(Stack_char&S,char&x)
{
    if(S.top==S.base) exit(FALSE);
    x=*--S.top;
	return x;
}
int GetTop(Stack_char S,char&x)
{
   if(S.top==S.base) return(FALSE);
   x=*(S.top-1);
   return x;
}
char GetTop(Stack_char S)
{
     char x;
     GetTop(S,x);
     return x;
}

void ClearStack(Stack_char&S)
{
    *S.base++ = NULL;
}
int StackLength(Stack_char S)
{
    int i=0,*p;
    p=S.top;
    while(p!=S.base)
    {
        p--;i++;
    }
    return i;
}

typedef struct
{
    float elem[Stack_Float];
    int *top;
    int *base;
    int stacksize;
}
Stack_float;
void InitStack(Stack_float&S)
{
    S.base=(SElemType *)malloc(Stack_Size*sizeof(SElemType));
    if(!S.base)exit(FALSE);
    S.top=S.base;
    S.stacksize=Stack_Size;
}
void Push(Stack_float&S,float e)
{
    if(S.top-S.base>=S.stacksize) exit (FALSE);
    *S.top++=e;
}
int Pop(Stack_float&S,float&e)
{
    if(S.top==S.base) return(FALSE);
    e=*--S.top;
    return e;
}
int GetTop(Stack_float S,float&e)
{
   if(S.top==S.base) return(FALSE);
   e=*(S.top-1);
   return e;
}
float GetTop(Stack_float S)
{
    float x;
    GetTop(S,x);
    return x;
}

void ClearStack(Stack_float&S)
{
    *S.base++ = NULL;
}
int StackLength(Stack_float S)
{
    int i=0,*p;
    p=S.top;
    while(p!=S.base)
    {
        p--;i++;
    }
    return i;
}
char a[7]={ '+','-','*','/','(',')', '#'};
char   p[7][7]=
{
    {'>','>','<','<','<','>','>'},
    {'>','>','<','<','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'<','<','<','<','<','=','@'},
    {'>','>','>','>','@','>','>'},
    {'<','<','<','<','<','@','='}
};


bool Inc(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='#')
        return (TRUE);
    else  return(FALSE);
}

float Execute(float a,char op,float b)
{
    switch(op)
    {
        case'+':return(a+b);break;
        case'-':return(a-b);break;
        case'*':return(a*b);break;
        case'/':return(a/b);break;
        default:cout<<"不能运算";break;
    }
}
char Compare(char x,char ch)
{
    int i,j,k;
    for(i=0;i<7;i++)
    {
        if(x==a[i]) j=i;
        if(ch==a[i]) k=i;
    }
    return p[j][k];
}
Stack_char OPTR;
Stack_float OPND;
void ExpEvaluation()
{
    InitStack(OPTR);
    InitStack(OPND);
	Push(OPTR,'#');
    cout<<"请输入一个表达式串（以#结束）"<<endl;
    char ch;
	int f;
    int w=0,q=0,y;float v,a,b;char x,t;
    ch=getchar();
    while(ch!='#'||GetTop(OPTR)!='#')
    {
        if(!Inc(ch))
        {
			f=atoi(&ch);
			Push(OPND,f);
            ch=getchar();
            while(!Inc(ch))
            {
                float s;
                Pop(OPND,s);
                f=atoi(&ch);
                s=s*10+f;
                Push(OPND,s);ch=getchar();
            }
        }
        else
            switch(Compare(GetTop(OPTR),ch))
        {
            case'<':
            Push(OPTR,ch);ch=getchar();
            break;
            case'=':
            Pop(OPTR,x);ch=getchar();
            break;
            case'>':
            Pop(OPTR,t);Pop(OPND,b);Pop(OPND,a);
            Push(OPND,Execute(a,t,b));
            if(ch=='#') break;
			Push(OPTR,ch);
			ch=getchar();;
            break;
            case'@':
            cout<<"括号不匹配，请关闭程序重试"<<endl;
            ClearStack(OPTR);
            ClearStack(OPND);
            break;

        }
    }
    w=StackLength(OPND);
    q=StackLength(OPTR);
    if(w!=q) exit(FALSE);
    for(y=1;y<w;y++)
    {
        Pop(OPTR,t);Pop(OPND,b);Pop(OPND,a);
        v=Execute(a,t,b);
    }
	v=GetTop(OPND);
    cout<<v<<endl;
}
int main()
{
    ExpEvaluation();
    return 0;
}
