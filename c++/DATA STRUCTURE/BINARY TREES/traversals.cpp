// 3 types traversal 1->inoreder  2->preoder  3->postoder
// l=left node  v=root node  r=right node
// lvr(inorde) 
//vlr (preorder) -->root first
//lrv (postorder) -->root last

#include "bits/stdc++.h"
// #include "tree"
using namespace std;
struct node {
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

void preorder(struct node* root){
    if(root==NULL){           //base condition
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if(root==NULL){           //base condition
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL){           //base condition
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){

    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);

    /*
             1
           /   \
          2     3 
         / \   / \
        4   5 6   7

    */
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);

}