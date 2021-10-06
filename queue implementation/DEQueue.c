//Write a menu driven program to implement double ended queue.
#include<stdio.h>
#define MAX 10
void Enqueue_r(int q[],int *f,int *r)
{
    if(*r==MAX-1)
        printf("Queue is full\n");
    else
    {
        *r+=1;
        if(*r==0)
            *f=0;
        printf("Enter the nuber to be inserted\n");
        scanf("%d",&q[(*r)]);
    }
}
void Enqueue_f(int q[],int *f,int *r)
{
    if(*f==-1)
    {
        *r=0;*f=0;
        printf("1.Enter the nuber to be inserted\n");
        scanf("%d",&q[(*r)]);
    }
    else if(*f==0)
        printf("No element can be inserted from front\n");
    else{
        *f-=1;
        printf("2.Enter the nuber to be inserted\n");
        scanf("%d",&q[(*f)]);
    }
    
}
void Dequeue_f(int q[],int *f,int *r)
{
    if(*f==-1)
        printf("Queue is empty\n");
    else if(*f==*r)
    {
        printf("%d is getting deleted\n",q[*f]);
        *f=*r=-1;
    }
    else
    {
        printf("%d is getting deleted\n",q[*f]);
        *f+=1;
    }
}
void Dequeue_r(int q[],int *f,int *r)
{
    if(*f==-1)
        printf("Queue is empty\n");
    else if(*f==*r)
    {
        printf("%d is getting deleted\n",q[*r]);
        *f=*r=-1;
    }
    else
    {
        printf("%d is getting deleted\n",q[*r]);
        *r-=1;
    }
}
void Peek(int a[],int *f)
{
    if(*f==-1)
        printf("Queue is empty\n");
    else
        printf("%d is the front element\n",a[(*f)]);
}
void Display(int q[],int *f,int *r)
{
    if(*f==-1)
       printf("Queue is empty\n");
    else
    {
        printf("Queue elemnts are\n");
        for(int i=(*f);i<=(*r);i++)
            printf("%d\n",q[i]);
    }
}
int main()
{
    int queue[MAX];
    int front,rear,c;
    front=rear=-1;
    printf("Abhishek Rana___20011351__Section A\n");
    do{
        printf("DEQueue operations\n  1.Enqueue_r\n  2.Enqueue_f\n  3.Dequeue_f\n  4.Dequeue_r\n");
       printf("  5.Peek\n  6.Display\n  0.Exit\n");
       printf("Enter your choice\n");
       scanf("%d",&c);
       switch(c)
       {
            case 1:
                Enqueue_r(queue,&front,&rear);
                break;
            case 2:
                Enqueue_f(queue,&front,&rear);
                break;
            case 3:
                Dequeue_f(queue,&front,&rear);
                break;
            case 4:
                Dequeue_r(queue,&front,&rear);
                break;
            case 5:
                Peek(queue,&front);
                break;
            case 6:
                Display(queue,&front,&rear);
                break;
            case 0:
                return 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
       }
    }while(c);
}
