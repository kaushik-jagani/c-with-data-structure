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

void intersect(node* &head1,node* &head2, int pos){
    node* temp1=head1;
    pos--;

    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }

    temp2->next=temp1;
}

int intersection(node* &head1,node* &head2){
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    node* ptr1;
    node* ptr2;

    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }

    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL and ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return -1;
}

node* merge(node* &head1,node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;

    while(p1!=NULL and p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }

        p3=p3->next;
    }

    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }

    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }

    return dummyNode->next;
}

node* mergerecursive(node* &head1,node* &head2){
    
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    
    node* result;
    if(head1->data<head2->data){
        result=head1;
        result->next=mergerecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergerecursive(head1,head2->next);
    }

    return result;
}

int main(){

    node* head=NULL;
    node* head2=NULL;
    // insertAtEnd(head,1);
    // insertAtEnd(head,2);
    // insertAtEnd(head,3);
    // insertAtEnd(head,4);
    // insertAtEnd(head,5);
    // insertAtEnd(head,6);
    // insertAtEnd(head2,7);
    // insertAtEnd(head2,8);
    // intersect(head,head2,4);
    // display(head);
    // display(head2);
    // cout<<intersection(head,head2)<<endl;

    // display(head);

    int arr1[]={1,4,5,7};
    int arr2[]={2,3,6};

    for(int i=0;i<4;i++){
        insertAtEnd(head,arr1[i]);
    }
     for(int i=0;i<3;i++){
        insertAtEnd(head2,arr2[i]);
    }
    display(head);
    display(head2);

    // node* newhead=merge(head,head2);
    node* newhead2=mergerecursive(head,head2);

    // display(newhead);
    display(newhead2);

}