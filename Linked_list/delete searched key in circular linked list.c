//Deletion of searched key value using circular linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}nodetype;
void display(nodetype * head)
{
    nodetype *p=head;
    do{
        printf("Element is: %d\n",head->data);
        head=head->next;
    }
    while(head!=p);
}
nodetype* delete(nodetype* head,nodetype* ptr)
{
    nodetype* temp=head;
    while(temp->next!=ptr)
    {
        temp=temp->next;
    }
    temp->next=ptr->next;
    free(ptr);
    return head;
}
nodetype* delete_at_first(nodetype * head){
    nodetype* temp=head,*p=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;
    free(p);
    return head;
}
nodetype* search(nodetype* head,int k){
    nodetype *temp=head->next;
    while(temp!=head)
    {
        if(k==head->data)
        {
            head=delete_at_first(head);
            return head;
        }
        else if(k==temp->data)
        {
           head= delete(head,temp);
           return head;
        }
        else{
            temp=temp->next;
        }    
    }
    if(temp==head)
    {
        printf("Element not found\n");
    }
    
}
int main()
{
    int key;
    nodetype *head=(nodetype *)malloc(sizeof(nodetype));
    nodetype *second=(nodetype *)malloc(sizeof(nodetype));
    nodetype *third=(nodetype *)malloc(sizeof(nodetype));
    nodetype *fourth=(nodetype *)malloc(sizeof(nodetype));
    
    head->data=10;
    head->next=second;
    
    second->data=20;
    second->next=third;
    
    third->data=30;
    third->next=fourth;
    
    fourth->data=40;
    fourth->next=head;
    
    display(head);
    printf("Enter the number to be searched in linked list:\n");
    scanf("%d",&key);
    head=search(head,key);
    display(head);
    return 0;
    
}
