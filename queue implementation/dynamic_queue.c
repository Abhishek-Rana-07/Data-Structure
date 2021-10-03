//Write a program to implement Linear Queue using dynamic Array
#include<stdio.h>
#include<stdlib.h>
int *ENQUEUE(int *a,int *f,int *r)
{
    int *ptr=NULL;
    if(a==NULL)
    {
        ptr=(int *)calloc(1,sizeof(int));
        (*r)+=1;
    }
    else
    {
        ptr=(int *)realloc(a,sizeof(int)*((*r)+1));
        (*r)+=1;
    }
    if(ptr==NULL)
        printf("Memory not assigned\n");
    else{
        if((*r)==0)
            (*f)=0;
        a=ptr;
        printf("Enter the number to inserted\n");
        scanf("%d",&a[(*r)]);
    }
    return a;
}
void DEQUEUE(int *a,int *f,int *r)
{
    if(a==NULL)
        printf("Queue is empty\n");
    else if(*f==*r)
    {
        printf("%d is getting deleted\n",a[(*f)]);
        *f=*r=-1;
    }
    else{
        printf("%d is getting deleted\n",a[(*f)]);
        (*f)+=1;
    }
}
void PEEK(int *a,int *f)
{
    if(a==NULL)
        printf("Queue is empty\n");
    else
        printf("front element of queue is: %d\n",a[(*f)]);
}
void DISPLAY(int a[],int *f,int *r)
{
    if(a==NULL)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is:\n");
        for(int i=(*f);i<=(*r);i++)
            printf("%d\n",a[i]);
    }
}
int main()
{
    int c,front,rear;
    front=rear=-1;
    int *queue=NULL;
    printf("ABHISHEK RANA___20011351__Section B\n");
    do{
        printf("QUEUE OPERATIONS ARE:-\n  1.ENQUEUE\n  2.DEQUEUE\n  3.PEEK\n  4.DISPLAY\n  0.EXIT\n");
        printf("Enter your choice:\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                queue=ENQUEUE(queue,&front,&rear);
                break;
            case 2:
                DEQUEUE(queue,&front,&rear);
                break;
            case 3:
                PEEK(queue,&front);
                break;
            case 4:
                DISPLAY(queue,&front,&rear);
                break;
            case 0:
                return 0;
                break;
            default:
                printf("INVALID CHOICE\n");
        }
    }while(c);
}
