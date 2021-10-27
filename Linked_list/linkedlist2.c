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
    int N;
    Node *new_obj=NULL,*temp_ptr=NULL,*head_obj=NULL;
    printf("Enterthe size of linked list\n");
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        new_obj=(Node*)malloc(sizeof(Node));
        scanf("%d",&new_obj->data);
        new_obj->next=NULL;

        if(head_obj==NULL)
        {
            head_obj=temp_ptr=new_obj;
        }
        else
        {
            temp_ptr->next=new_obj;
            temp_ptr=temp_ptr->next;
        }

    }
   
    print(head_obj);
}
