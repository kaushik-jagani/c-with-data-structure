#include"bits/stdc++.h"
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL){

    head->prev=n;
    }

    head=n;
}

void insertAtEnd(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;

}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

void deleteAtHead(node* &head){
    node* todelete=head;

    head=head->next;
    head->prev=NULL;

    delete todelete;

}

void deletion(node* &head,int pos){

    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;

    while(temp!=NULL and count!=pos){
        temp=temp->next;
        count++;
    }
    node* deletenode=temp;
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
    temp->next->prev=temp->prev;
    }

    delete deletenode;

}
int main(){
    node* head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);

    display(head);
    deletion(head,3);
    display(head);
    // deleteAtHead(head);
    deletion(head,1);

    display(head);
}