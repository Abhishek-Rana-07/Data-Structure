//Linear queue implementataion
#include<stdio.h>
#define MAX 10
void Enqueue(int a[],int *rear,int *front)
{
   if(*rear==MAX-1)
       printf("Queue is full\n");
   else
   {
       *rear+=1;
       if(*rear==0)
            *front=0;
       printf("Enter the element you want to insert\n");
       scanf("%d",&a[(*rear)]);
   }
}
void Dequeue(int a[],int *rear,int *front)
{
    if(*front==-1)
        printf("Queue is Empty\n");
    else if(*front==*rear)
    {
        printf("%d is getting deleted\n",a[*front]);
        *front=*rear=-1;
    }
    else
    {
        printf("%d is getting deleted\n",a[*front]);
        *front+=1;
    }
}
void PEEK(int a[],int *front)
{
    if(*front==-1)
        printf("Queue is empty\n");
    else
        printf("%d is the front element\n",a[(*front)]);
}
void DISPLAY(int a[],int *rear,int *front)
{
    if(*front==-1)
        printf("Queue is Empty\n");
    else
    {
        printf("QUEUE elements are:\n");
        for(int i=(*front);i<=(*rear);i++)
            printf("%d\n",a[i]);
    }
}
int main()
{
   int a[MAX],c=0,rear,front;
   rear=front=-1;
   do
   {
       printf("QUEUE operations are:-\n  1.Enqueue\n  2.Dequeue\n  3.PEEK\n  4.DISPLAY\n  0.EXIT\n");
       printf("Enter your choice:\n");
       scanf("%d",&c);
       
       switch(c)
       {
            case 1:
                Enqueue(a,&rear,&front);
                break;
            case 2:
                Dequeue(a,&rear,&front);
                break;
            case 3:
                PEEK(a,&front);
                break;
            case 4:
                DISPLAY(a,&rear,&front);
                break;
            case 0:
                return 0;
                break;
            default:
                printf("INVALID CHOICE\n");
                break;
       }
   }while(c);
}
