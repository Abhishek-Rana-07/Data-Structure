#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}nodetype;
void insert(nodetype **hd,nodetype **tal,int val)
{
    nodetype *p=(nodetype *)malloc(sizeof(nodetype));
    if(p==NULL)
    {
        printf("Memory not allocated\n");
    }
    else{
        p->data=val;
        p->next=NULL;
        if(*tal==NULL)
        {
            *tal=p;
            *hd=p;
            p->prev=NULL;
        }
        else{
            (*tal)->next=p;
            p->prev=(*tal);
            (*tal)=p;
        }
    }
}
void forward_print(nodetype *head)
{
    printf("The contents of linked list are\n");
    while(head!=NULL)
    {
        printf("Element is: %d\n",head->data);
        head=head->next;
    }
    printf("\n");
}
void reverse_print(nodetype * tail)
{
    printf("The contents of linked list are\n");
    while(tail!=NULL)
    {
        printf("Element is: %d\n",tail->data);
        tail=tail->prev;
    }
    printf("\n");
}
void delete_node(nodetype **hd,nodetype **tal,int key)
{
    nodetype *temp=*hd;
    int pos=1;
    while((temp->data!=key)&&(temp->next!=NULL))
    {
        temp=temp->next;
        pos++;
    }
    if((temp->next==NULL)&&(temp->data != key))
         printf("\nkey is not found\n");
    else{
        printf("\nkey %d is found in node %d",key,pos);
        if(temp==*hd)
        {
            *hd=(*hd)->next;
            (*hd)->prev=NULL;
        }
        else if(temp==*tal)
        {
            *tal=(*tal)->prev;
            (*tal)->next ==NULL;
        }
        else{
            (temp->prev)->next=temp->next;
            (temp->next)->prev=temp->prev;
        }
        free(temp);
    }
}
int main()
{
    nodetype *head=NULL, *tail=NULL;
    int c,key,num;
    do{
        printf("                 MENU\n");
        printf("To insert a number .......opt1\n");
        printf("To print head to tail .......opt2\n");
        printf("To print tail to head.......opt3\n");
        printf("To search a key.......opt4\n");
        printf("Enter your choice\n");
        scanf("%d",&c);

        switch(c){
            case 1:
                 printf("Enter the number to inserted\n");
                 scanf("%d",&num);
                 insert(&head,&tail,num);
                 break;
            
            case 2:
                if(head==NULL)
                    printf("\n Link list is empty\n");
                else
                    forward_print(head);
                break;
            
            case 3:
                if(tail==NULL)
                    printf("\nLink list is empty\n");
                else
                    reverse_print(tail);

                break;

            case 4:
                printf("Enter the key to be searched\n");
                scanf("%d",&key);
                delete_node(&head,&tail,key);
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(c);
    return 0;
}
