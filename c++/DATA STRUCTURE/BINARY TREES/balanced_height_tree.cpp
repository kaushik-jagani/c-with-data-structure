//balanced= height of left subtree - height of right subtree
// rotation LL LR RR RL
// absoulte diffrence must be <=1 means ===>>abs(-1)=1
// time complexity O(n^2)

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

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    return max(leftHeight,rightHeight)+1;
}

bool isBalance(node* root){
    if(root==NULL){
        return true;
    }
    if(isBalance(root->left)==false){               //if left subtree is unbalanced means whole tree is unbalanced
        return false;
    }
    if(isBalance(root->right)==false){
        return false;
    }

    int lh=height(root->left);
    int rh=height(root->right);

    if(abs(lh-rh)<=1){
        return true;
    }
    else{
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
    
    if(isBalance(root)){
        cout<<"tree is balance"<<endl;
    }
    else{
        cout<<"tree is not balance"<<endl;

    }


    // creaate 2nd tree
    node* root2=new node(1);
    root2->left=new node(2);
    root2->left->left=new node(3);

    if(isBalance(root2)){
        cout<<"tree is balance"<<endl;
    }
    else{
        cout<<"tree is not balance"<<endl;

    }
}