/*-> linked list is linear data structure
->it is multiple block of memory
->non-contiguous meomry allocation
next is point to the address of next node
*/
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

// insert node at head

void inserAtHead(node* &head,int val){                //head by reffrence aave 6
    node* n=new node(val);                //create new node
    n->next=head;
    head=n;
}

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

// find value in linked list

bool search(node* head,int find){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==find)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

// dosplay linkedlist

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

// delete head node

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;

    delete todelete;        //because of memory lick;
}

// delete node exclude head

void deletion(node* &head,int val){

    if(head==NULL){        //linked list is empty
        return;
    }
    if(head->next==NULL){    //one node present
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    } //this loop travrse before one node  which we want delete
    node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
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


    // cycle end

    // for check start

    // inserAtHead(head,10);
    // display(head);

    // cout<<search(head,5)<<endl;  //0 false
    // cout<<search(head,2)<<endl;  //1 true
    // deletion(head,1);
    // display(head);

    // deleteAtHead(head);
    // display(head);

    // check end 

    // ->start here
    // node* newhead=reverse(head);        -->using itreator
    // display(newhead);

    // node* newhead2=reverseRecursive(head);     //-->using function
    // display(newhead2);
    // end here

    // ->start here
    // int k=2;

    // node* newhead2=reversek(head,k);     //--> slicing reverse
    // display(newhead2);
    // ->end here
}