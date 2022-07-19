// build tree using combination of two traversal like in + pre or in + post
// in oreder is use for get position of elemente eithe right or left;
// post and pre orders are use for get order of element

#include"bits/stdc++.h"
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

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
        return -1;
}

node* buildtree(int preorder[],int inorder[],int start, int end){
    static int idx=0;

    if(start>end){
        return NULL;
    }

    int curr=preorder[idx];
    idx++;
    node* Node=new node(curr);
    if(start==end){
        return Node;
    }

    int pos=search(inorder,start,end,curr);
    Node->left=buildtree(preorder,inorder,start,pos-1);
    Node->right=buildtree(preorder,inorder,pos+1,end);

    return Node;
}

void inprint(node* root){
    if(root==NULL){           //base condition
        return;
    }
    inprint(root->left);
    cout<<root->data<<" ";
    inprint(root->right);
}

int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    node* root=buildtree(preorder,inorder,0,4);
    inprint(root);


}