#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
   int data;
   struct Node *next;
}Node;

void print(Node *ptr)
{
   while(ptr!=NULL)
  {
     printf("Element is: %d\n",ptr->data);
     ptr=ptr->next;
  }
}
int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    head=(Node *)malloc(sizeof(Node));
    second=(Node *)malloc(sizeof(Node));
    third=(Node *)malloc(sizeof(Node));
    fourth=(Node *)malloc(sizeof(Node));
    
    printf("Enter the variables to insert\n");
    scanf("%d",&head->data);
    head->next=second;

    scanf("%d",&second->data);
    second->next=third;
  
    scanf("%d",&third->data);
    third->next=fourth;

    scanf("%d",&fourth->data);
    fourth->next=NULL;

    print(head);
   
    
}
