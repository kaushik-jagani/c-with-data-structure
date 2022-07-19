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

// make cycl in linked listt
void makecycle(node* &head,int pos){
    node* temp=head;
    node* startnode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

// deteact cycle  saslu and kachbo algorithem

bool detectcycle(node* &head){
    node* slow=head; //kachbo
    node* fast=head;  //saslu

    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

// remove cycle

void removecycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;           //2node jump togather
    }while (slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next=NULL;
    
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

    // cycle start
    makecycle(head,4);
    cout<<detectcycle(head)<<endl;
    removecycle(head);
    cout<<detectcycle(head)<<endl;
    display(head);


}