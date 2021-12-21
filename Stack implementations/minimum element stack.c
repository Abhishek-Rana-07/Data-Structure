//Q4. Write a C Program implement STACK using array in menu driven form.
#include<stdio.h>
#define MAX 10
void PUSH(int a[],int *top)
{
    if(*top==MAX-1)
        printf("Stack full\n");
    else
    {
        printf("Enter the number to insert\n");
        scanf("%d",&a[++(*top)]);
    }
}
void POP(int a[],int *top)
{
    if(*top==-1)
        printf("Stack empty\n");
    else
    {
        printf("%d is getting deleted\n",a[*top]);
        *top-=1;
    }
}
void PEEK(int a[],int *top)
{
    if(*top==-1)
        printf("Stack empty\n");
    else
    {
        printf("%d is top element\n",a[*top]);
    }
}
void DISPLAY(int a[],int *top)
{
    if(*top==-1)
        printf("Stack empty\n");
    else
    {
        printf("Stack elements are\n");
        for(int i=(*top);i!=-1;i--)
            printf("%d\n",a[i]);
    }
}
void Min(int a[],int *top){
    int M=a[0];
    for(int i=1;i<=(*top);i++){
        if(M>a[i])
             M=a[i];
    }
    printf("The minimum element is : %d",M);
}
int main()
{
    int a[MAX],top=-1,c=0;
    printf("ABHISHEK RANA__20011351___Section B\n");
    do{
        printf("STACK OPERATIONS:-\n  1.PUSH\n  2.POP\n  3.PEEK\n  4.DISPLAY\n  5.Minimum element\n  0.EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&c);
        
        switch(c)
        {
            case 1:
                PUSH(a,&top);
                break;
            case 2:
                POP(a,&top);
                break;
            case 3:
                PEEK(a,&top);
                break;
            case 4:
                DISPLAY(a,&top);
                break;
            case 5:
                Min(a,&top);
                break;
            case 0:
                return 0;
                break;
            default:
                printf("Invalid choice:\n");
        }
    }while(c);
}
