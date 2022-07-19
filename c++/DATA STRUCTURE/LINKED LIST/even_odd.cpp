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

bool find(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void evenAfterOdd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenstart=even;

    while(odd->next!=NULL and even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;

        even->next=odd->next;
        even=even->next;
    }
    
    odd->next=evenstart;    //we assume that the even node is null
    if(odd->next!=NULL){
        even->next=NULL;
        
    }
} 

int main(){

    node* head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    // insertAtEnd(head,7);

    display(head);
    evenAfterOdd(head);
    display(head);

}