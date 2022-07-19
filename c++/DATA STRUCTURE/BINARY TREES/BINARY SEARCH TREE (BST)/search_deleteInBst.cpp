#include"bits/stdc++.h"
using namespace std;

struct node{
    int data;
    node *left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* insertBST(node* root,int val){
    if(root==NULL){
        return new node(val);
    }

    if(val<root->data){
        root->left=insertBST(root->left,val);
    }else{
        root->right=insertBST(root->right,val);
    }

    return root;

}

// search node in BST

node* searchInBst(node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data==val){
        return root;
    }

    if(root->data>val){
        return searchInBst(root->left,val);
    }
    return searchInBst(root->right,val);
}



void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node* root=NULL;
    root=insertBST(root,5);
   insertBST(root,1);
   insertBST(root,3);
   insertBST(root,4);
   insertBST(root,2);
   insertBST(root,7);
   insertBST(root,6);

//    print inorder
    inorder(root);
    if(searchInBst(root,0)==NULL)
    {
        cout<<endl<<"key doesn't exist"<<endl;
    }
    else {
        cout<<"key is exist"<<endl;

    }
}