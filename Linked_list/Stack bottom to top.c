//Stack printing from bottom to top using recursion when u are given top pointer of linked list.
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}nodetype;
 
void display(nodetype *top){
    while(top!=NULL){
        printf("Element is: %d\n",top->data);
        top=top->next;
    }
}
int isfull(nodetype *top){
    nodetype *p=(nodetype *)malloc(sizeof(nodetype));
    if(p==NULL)
        return 1;
    else  
        return 0;
}

int isempty(nodetype *top){
    if(top==NULL)
        return 1;
    else 
        return 0;
}
nodetype * push(nodetype *top,int data){
    if(isfull(top)){
        printf("Stack overflow\n");
    }
    else{
        nodetype *n=(nodetype *)malloc(sizeof(nodetype));
        n->data=data;
        n->next=top;
        top=n;
        return top;
    }

}
void recursion_display(nodetype *top){
    if(top==NULL){
        return ;
    }
    
    recursion_display(top->next);
    printf("Element is: %d\n",top->data);
}
int main()
{
    nodetype *top=NULL;
    top=push(top,10);
    top=push(top,20);
    top=push(top,30);
    top=push(top,40);
    display(top);
    printf("\nDisplaying stack from bottom to top\n");
    recursion_display(top);
}
