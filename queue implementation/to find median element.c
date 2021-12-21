/*Q10. Write a C Program implement QUEUE using array in menu driven form.*/

#include<stdio.h>
#define MAX 10
void Enqueue(int a[],int *rear,int *front,int *N)
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
       *N+=1;
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
void Median(int a[],int *front,int N){
    if(*front==-1){
        printf("Queue is empty\n");
    }
    else if(N%2!=0){
        int M=0;
        for(int i=(*front);i<(N/2);i++){
            M++;
        }
        if(M==0)
            return ;
        else{
        printf("Median is: %d\n",a[M]);}
    }
    else{
         int M=0;
        for(int i=(*front);i<(N/2);i++){
            M++;
        }
        printf("Median is: %d  %d\n",a[--M],a[M]);
    }
}
int main()
{
   int a[MAX],c=0,rear,front,N=0;
   rear=front=-1;
   do
   {
       printf("QUEUE operations are:-\n  1.Enqueue\n  2.Dequeue\n  3.PEEK\n  4.DISPLAY\n  0.EXIT\n");
       printf("Enter your choice:\n");
       scanf("%d",&c);
       
       switch(c)
       {
            case 1:
                Enqueue(a,&rear,&front,&N);
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
                Median(a,&front,N);
                printf("Number of elements entered in queue are:\n");
                printf("%d",N);  
                
                return 0;
                break;
            default:
                printf("INVALID CHOICE\n");
                break;
       }
   }while(c);
}
