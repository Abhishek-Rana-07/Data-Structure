// Insertion cases in linked list

#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void display(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node *beginning(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data= data;
    ptr->next=head;
    return ptr;
}

struct Node *inbetween(struct Node *head,int data,int index)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data= data;
    struct Node *p=head;
    int i=0;
    
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    
    ptr->next=p->next;
    p->next=ptr;
    
    return head;
}

struct Node *atend(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data= data;
    struct Node *p=head;
    
    
    while(p->next!=NULL)
    {
        p=p->next;
        
    }
    
    p->next=ptr;
    ptr->next=NULL;
    
    return head;
}

struct Node *insertatnode(struct Node *head,struct Node *q,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data= data;
    
    ptr->next=q->next;
    q->next=ptr;
    
    return head;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    
    head=(struct Node*)malloc(sizeof(struct Node));
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    
    head->data=7;
    head->next=first;
    
    first->data=70;
    first->next=second;
    
    second->data=17;
    second->next=third;
    
    third->data=77;
    third->next=NULL;
    
    display(head);
    printf("\n");
   // head=beginning(head,100);
  // head=inbetween(head,85,1);
   // head=atend(head,96);
   head=insertatnode(head,second,23);
    display(head);

    return 0;
}
