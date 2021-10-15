//Program to implement infix to postfix(incomplete program)
#include<stdio.h>
#define MAX 100
 char stack[100];
 int top=-1;
 void PUSH(char x)
 {
    if(top==MAX-1)
        printf("Stack full!!! cannot insert more\n");
    else
        stack[++top]=x;
 }
 void pop(char x)
 {
    if(top==-1)
       printf("Stack is empty\n");
    else
    {
        if(stack[top]!='(')
            printf(" %c ",stack[top]);
        top--;
    }
 }
int main()
{
    int N,i=0;
    printf("Enter the size of infix expression:\n");
    scanf("%d",&N);
    char IP_string[N];
    printf("Enter the expression\n");
    scanf("%s",IP_string);
    printf("Entered expression is\n");
    printf("%s\n",IP_string);
    while(IP_string[i] !='\0')
    {
        if(IP_string[i]=='+' || IP_string[i]=='-'){
            if(top==-1 || stack[top]=='(')
                PUSH(IP_string[i]);
            else if(stack[top] =='*' ||stack[top]== '/' ||stack[top]=='^')
            {
                pop(stack[top]);
                i--;
            }
            else if(stack[top]=='+' || stack[top]=='-')
            {
                pop(stack[top]);
                i--;
            }
        }
        else if(IP_string[i]=='*' || IP_string[i]=='/')
        {
            if(top==-1 || stack[top]=='(')
                PUSH(IP_string[i]);
            else if(stack[top]=='+' || stack[top]=='-'){
                PUSH(IP_string[i]);
            }
            else if(stack[top]=='^' || stack[top]=='*' || stack[top]=='/'){
                pop(stack[top]);
                i--;
            }
        }
        else if(IP_string[i]=='^')
            PUSH(IP_string[i]);
        else if(IP_string[i]=='(')
            PUSH(IP_string[i]);
        else if(IP_string[i]==')')
        {
            while(top!=-1 && stack[top]!='(')
                pop(stack[top]);
            if(top==-1 || stack[top]!='(')
                printf("\nError ( missing\n");
            else
                pop(stack[top]);
        }
        else
            printf(" %c ",IP_string[i]);
        i++;
    }
    while(top!=-1)
        pop(stack[top]);
    printf("\n");
}
