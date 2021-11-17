//Queue implementation using linked list

#include<stdlib.h>
#include <stdio.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *f=NULL;
struct Node *r=NULL;

void display(struct Node *ptr)
{
    printf("printing the elements of\n");
    while(ptr!=NULL)
    {
        printf("element : %d \n",ptr->data);
        ptr=ptr->next;
    }
}

void Enqueue(int val)
{
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL)
    {
        printf("Queue is full\n");
    }  
    else{
        n->data =val;
        n->next =NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    
    }
}

int Dequeue()
{
    int val=-1;
   struct Node *ptr =f;
   if(f==NULL)
   {
       printf("Queue is empty\n");
   }
   else{
       f=f->next;
       val=ptr->data;
       free(ptr);
   }
   return val;
}
int main()
{
   // display(f);
   //printf("Deleted value is : %d\n",Dequeue());
    Enqueue(12);
    Enqueue(89);
    Enqueue(2);
    Enqueue(20);
    display(f);
    printf("Deleted value is : %d\n",Dequeue());
    display(f);
    

    return 0;
}
