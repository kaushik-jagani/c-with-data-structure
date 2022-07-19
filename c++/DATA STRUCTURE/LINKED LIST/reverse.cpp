#include"bits/stdc++.h"
using namespace std;

// create node structure

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

// insert node at end

void insertAtEnd(node* &head,int val){
    node* n=new node(val);                //create new node
     
     if(head==NULL){
        head=n;
        return;
     }

     node* temp=head;
     while(temp->next!=NULL){
        temp=temp->next;
     }
     temp->next=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

// reverse linked list using iterator

node* reverse(node* &head){

    // declare pointer
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}


// recursive way to reverse linkedlist

node* reverseRecursive(node* head){

    if(head==NULL || head->next==NULL){                 //linkedlist is null or single node is present
        return head;
    }
    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}


// k node reverse if k=2 then only pair of 2 nodes reverse

node* reversek(node* &head,int k){
    // declare pointer
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL and count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next= reversek(nextptr,k);
    }
    return prevptr;        //prevptr become head at a time

}

int main(){
    node* head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    insertAtEnd(head,7);

    display(head);

    // ->start here
    node* newhead=reverse(head);       // -->using itreator
    display(newhead);

    node* newhead2=reverseRecursive(head);     //-->using function
    display(newhead2);
    // end here

    // ->start here
    int k=2;

    node* newhead3=reversek(head,k);     //--> slicing reverse
    display(newhead3);
    // ->end here
}