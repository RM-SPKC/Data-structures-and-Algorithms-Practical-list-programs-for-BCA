#include<iostream>
#include<cctype>
using namespace std;
char s[20];
int top=-1;
void push(char d)
{
	s[++top]=d;
}
char pop()
{
	if(top==-1)
		return -1;
	else
		return s[top--];
}
int priority(char x)
{
	if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/')
		return 2;
	else if(x=='^')
		return 3;
	else
		return 0;
}
void conversion(char *e,char *postfix)
{
	int i=0,k=-1;
	char x;
	while(e[i]!='\0')
	{
		if(isalnum(e[i]))
			postfix[++k]=e[i];
		else if(e[i]=='(')
			push(e[i]);
		else if(e[i]==')')
        {
            while((x=pop())!='(')
				postfix[++k]=x;
		}
		else
		{
			while(top!=-1 && priority(s[top])>=priority(e[i]))
			{
				postfix[++k]=pop();
			}
			push(e[i]);
		}
		i++;
	}
		while(top!=-1)
		{
			postfix[++k]=pop();
		}
		postfix[++k]='\0';
}
int eval(char *postfix)
{
	int st[20];
	int tp=-1;
	for(int i=0;postfix[i]!='\0';i++)
	{
		if(isdigit(postfix[i]))
		{
			st[++tp]=postfix[i]-'0';
		}
		else
		{
			int b=st[tp--];
			int a=st[tp--];
			switch(postfix[i])
			{
			case '+':
				st[++tp]=a+b;
				break;
			case '-':
				st[++tp]=a-b;
				break;
			case '*':
				st[++tp]=a*b;
				break;
			case '/':
				st[++tp]=a/b;
				break;
			}
		}
	}
	return st[tp];
}
int main()
{
	char exp[20],postfix[20];
	cout<<"\t\t\tINFIX TO POSTFIX EXPRESSION\n";
	cout<<"\t\t\t---------------------------\n";
	cout<<"\n\nEnter the infix expression : ";
	cin>>exp;
	conversion(exp,postfix);
	cout<<"\n\tPostfix Expression : "<<postfix<<endl;
	int r=eval(postfix);
	cout<<"\n\n\tResult : "<<r<<endl;
	return 0;
}
