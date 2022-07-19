// l=length k=node t=tail(end)
#include"bits/stdc++.h"
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;

}
void insertAtEnd(node* &head,int val){
    node* n=new node(val);

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

int length(node* head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;      //linked list length
}

node* kappend(node* &head,int k){
    node* newhead;
    node* newend;
    node* end=head;

    int l=length(head);
    k=k%l;
    int count=1;

    while(end->next!=NULL){
        if(count==l-k){
            newend=end;
        }
        if(count==l-k+1){
            newhead=end;
        }
        end=end->next;
        count++;
    }
    newend->next=NULL;
    end->next=head;

    return newhead;

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
    insertAtEnd(head,8);


    node* newhead=kappend(head,3);
    display(newhead);

    // display(head);


}