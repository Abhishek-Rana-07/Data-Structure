//Program to implement infix to postfix(incomplete program)
#include<stdio.h>
 char stack[100];
 int top=-1;
 void PUSH(char x)
 {
    stack[++top]=x;
    
 }
 void pop(char x)
 {
     top--;
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
            if(top==-1)
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
            if(top==-1)
                PUSH(IP_string[i]);
            else if(stack[top]=='+' || stack[top]=='-'){
                PUSH(IP_string[i]);
            }
            else if(stack[top]=='^' || stack[top]=='*' || stack[top]=='/'){
                pop(stack[top]);
                i--;
            }
        }
        else if(stack[top]=='^')
        {
            if(top==-1)
                PUSH(IP_string[i]);
             else if(stack[top]=='+' || stack[top]=='-'|| stack[top]=='*' || stack[top]=='/'||stack[top]=='^')
                PUSH(IP_string[i]);
        }
        else
            printf("%c",IP_string[i]);
            
        while(top!=-1)
            pop(stack[top]);
            
        i++;
        
    }
}
