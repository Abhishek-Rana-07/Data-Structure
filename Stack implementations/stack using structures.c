#include<stdio.h>
typedef struct number
{
     int data;
}stack;
void PUSH(stack arr[],int *top)
{
    if(*top==MAX-1)
        printf("Stack is full\n");
    else
    {
        *top+=1;
        printf("Enter the element: ");
        scanf("%d",arr.data[(*top)]);
        printf("\n%d",arr.data[*top]);
    }
}
int main()
{
    stack arr[10];
    int top=-1,MAX=10,c=0;
    do
    {
        printf("Stack operations:\n  1.PUSH\n  2.POP\n   3.PEEK\n  4.DISPLAY\n  0.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&c);
    }
    switch(c)
    {
         case 1:
               PUSH(arr,&top);
               break;
    
    
    }
}
