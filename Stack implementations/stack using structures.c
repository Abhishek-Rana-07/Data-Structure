//Stack implementation using structures
#include<stdio.h>
#define MAX 10
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
        scanf("%d",&arr[(*top)].data);
    }
}
void POP(stack arr[],int *top)
{
    if(*top==-1)
        printf("stack is empty\n");
    else{
        printf("%d is getting deleted\n",arr[(*top)].data);
        *top-=1;
    }
}
void PEEK(stack arr[],int *top)
{
    if(*top==-1)
        printf("Stack is empty\n");
    else{
        printf("%d is top element\n",arr[(*top)].data);
    }
}
void DISPLAY(stack arr[],int *top)
{
    if(*top==-1)
        printf("Stack empty\n");
    else
    {
        for(int i=(*top); i!=-1; i--)
            printf("%d\n",arr[i].data);
    }
}
int main()
{
    stack arr[MAX];
    int top=-1,c=0;
    do
    {
        printf("Stack operations:\n  1.PUSH\n  2.POP\n  3.PEEK\n  4.DISPLAY\n  0.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&c);
    switch(c)
    {
         case 1:
               PUSH(arr,&top);
               break;
         case 2:
               POP(arr,&top);
               break;
         case 3:
               PEEK(arr,&top);
               break;
         case 4:
               DISPLAY(arr,&top);
               break;
         case 0:
               return 0;
               break;
         default:
               printf("Invalid choice\n");
    }
    }while(c);
}
