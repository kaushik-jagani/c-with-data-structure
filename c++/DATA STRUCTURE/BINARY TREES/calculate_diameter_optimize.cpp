// diameter longest path
// depth of the tree's deepest node
// distance between root node to leaf nodee is called hight of the tree

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

int calculateheight(node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight=calculateheight(root->left);
    int rightHeight=calculateheight(root->right);
    return max(leftHeight,rightHeight)+1;
}

int calDiameter(node* root,int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }

    int leftHeight=0,rightHeight=0;

    int leftDiameter=calDiameter(root->left,&leftHeight);
    int rightDiameter=calDiameter(root->right,&rightHeight);
    int currDiameter=leftHeight+rightHeight+1;

    *height=max(leftHeight,rightHeight)+1;

    return max(currDiameter,max(leftDiameter,rightDiameter));


}

int main(){

    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    cout<<root->left->data<<endl;
    int height=0;
    cout<<calDiameter(root,&height)<<endl;
}