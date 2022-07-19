//balanced= height of left subtree - height of right subtree
// rotation LL LR RR RL
// absoulte diffrence must be <=1 means ===>>abs(-1)=1
// less timecomplexity O(n)

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};


bool isBalance(node* root,int* height){
     if(root==NULL){
        return true;
    }
   int lh=0,rh=0;

   if(isBalance(root->left,&lh)==false){
    return false;
   }
   if(isBalance(root->right,&rh)==false){
    return false;
   }

   *height=max(lh,rh)+1;
   if(abs(lh-rh)<=1){
    return true;
   }
   else {
    return false;
   }
   
}

int main(){

    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    int height=0;
    if(isBalance(root,&height)==true){
        cout<<"tree is balance"<<endl;
    }
    else{
        cout<<"tree is not balance"<<endl;

    }


    // creaate 2nd tree
    node* root2=new node(1);
    root2->left=new node(2);
    root2->left->left=new node(3);

    if(isBalance(root2,&height)==true){
        cout<<"tree is balance"<<endl;
    }
    else{
        cout<<"tree is not balance"<<endl;

    }
}