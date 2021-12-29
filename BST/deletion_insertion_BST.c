#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}tree;
tree *create(int key){
    tree *ptr=(tree *)malloc(sizeof(tree));
    if(ptr==NULL){
        printf("Memeory not allocated\n");
        return NULL;
    }
    else{
        ptr->data=key;
        ptr->left=NULL;
        ptr->right=NULL;
        return ptr;
    }
}
tree *insert(tree *root,int key){
    if(root==NULL){
        tree *ptr=create(key);
        root=ptr;
    }
    else{
        if(root->data<key){
            root->right=insert(root->right,key);
        }
        else
            root->left=insert(root->left,key);
    }
    return root;
}
void inorder(tree *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
tree *minvalue(tree *node){
    tree *curr=node;
    
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
tree *delete(tree *root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left=delete(root->left,key);
    }
    else if(key>root->data){
        root->right=delete(root->right,key);
    }
    else{
        //node with only one child or no child
        if(root->left==NULL){
            tree *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            tree *temp=root->left;
            free(root);
            return temp;
        }
        
        //node with two children
        //get the inorder successor
        tree *temp=minvalue(root->right);
        
        root->data=temp->data;
        
        root->right=delete(root->right,temp->data);
    }
    return root;
}
int main(){
    tree *head=NULL;
    head=insert(head,70);
    head=insert(head,60);
    head=insert(head,50);
    head=insert(head,90);
    head=insert(head,80);
    head=insert(head,75);
    head=insert(head,85);
    head=insert(head,25);
    head=insert(head,65);
    head=insert(head,15);
    
    inorder(head);
    
    head=delete(head,60);
    printf("\n");
    inorder(head);
}
