#include<stdio.h>
#include<string.h>  
struct
{
    char ch;
    int pri;
}lpri[5]={{'=',0},{'(',1},{'+',3},{'*',5},{')',6}},rpri[5]={{'=',0},{'(',6},{'+',2},{'*',4},{')',1}};
  
void Change(char *a)
{
    if(*a=='T')
        *a='1';
    else
        *a='0';
}
  
void Transform(char exp[],char a,char b,char c)
{
    int len,i;
    len=strlen(exp);
    for(i=0;i<len;i++)
    {
        if(exp[i]=='a')
            exp[i]=a;
        if(exp[i]=='b')
            exp[i]=b;
        if(exp[i]=='c')
            exp[i]=c;
        if(exp[i]=='&')
            exp[i]='*';
        if(exp[i]=='|')
            exp[i]='+';
    }
}
  
int Lpri(char ch)
{
    int i;
    for(i=0;i<5;i++)
    {
        if(ch==lpri[i].ch)
        {
            return lpri[i].pri;
        }
    }
}
  
int Rpri(char ch)
{
    int i;
    for(i=0;i<5;i++)
    {
        if(ch==rpri[i].ch)
        {
            return rpri[i].pri;
        }
    }
}
  
void expTOpostexp(char exp[],char postexp[])
{     int len,top=-1,t=0,i;
char op[100];
len=strlen(exp);
for(i=0;i<len;)
{
    if(exp[i]=='0'||exp[i]=='1')
    {
        postexp[t++]=exp[i++];
    }
    else
        if(Lpri(op[top])<Rpri(exp[i])||top==-1)
        {
            op[++top]=exp[i++];
        }
        else
            if(Lpri(op[top])>Rpri(exp[i]))
            {
                postexp[t++]=op[top--];
            }
            else
                if(Lpri(op[top])==Rpri(exp[i]))
                {
                    top--;
                    i++;
                }
}
for(i=top;i>-1;i--)
{
    postexp[t++]=op[top--];
}
postexp[t]='\0';
}
  
int Judge(char postexp[])
{
    int top=-1,len,i,num[100],a,b;
    len=strlen(postexp);
    for(i=0;i<len;i++)
    {
        if(postexp[i]=='0'||postexp[i]=='1')
            num[++top]=postexp[i]-'0';
        if(postexp[i]=='+')
        {
            a=num[top--];
            b=num[top];
            num[top]=a+b;
        }
        if(postexp[i]=='*')
        {
            a=num[top--];
            b=num[top];
            num[top]=a*b;
        }
    }
    return num[0];
}
  
int main()
{
    char exp[100],postexp[100];
    char a,b,c;
    while(scanf("%s",exp)!=EOF)
    {
        getchar();
        scanf("%c",&a);
        getchar();
        scanf("%c",&b);
        getchar();
        scanf("%c",&c);
        Change(&a);
        Change(&b);
        Change(&c);
        Transform(exp,a,b,c);
        expTOpostexp(exp,postexp);
        if(Judge(postexp))
            printf("TRUE\n");
        else
            printf("FALSE\n");
    }
    return 0;
}