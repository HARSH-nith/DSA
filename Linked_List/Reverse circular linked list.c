#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;   
};
int main(){
    struct node *tail,*newnode,*current,*prev,*nextnode;
    int choice=1;
    tail=0;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(tail==0){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Do you wanna continue (0,1): ");
        scanf("%d",&choice);
    }
    current=tail->next;
    nextnode=current->next;
    while(current!=tail){
        prev=current;
        current=nextnode;
        nextnode=current->next;
        current->next=prev;
    }
    nextnode->next=tail;
    tail=nextnode;

    printf("The elements in the list are: ");
    do{
        printf("%d ",current->data);
        current=current->next;
    }while(current!=tail->next);
}
