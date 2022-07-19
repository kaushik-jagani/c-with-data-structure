// build tree using combination of two traversal like in + post or in + post
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

int search(int inorder[],int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}

node* buildtree(int postorder[],int inorder[],int start, int end){

    static int idx=4;
    if(start>end){
        return NULL;
    }
    int val=postorder[idx];
    idx--;
    
    node* Node= new node(val);

    if(start==end){
        return Node;
    }

    int pos=search(inorder,start,end,val);
    Node->right=buildtree(postorder,inorder,pos+1,end);
    Node->left=buildtree(postorder,inorder,start,pos-1);

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
    int postorde[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    node* root=buildtree(postorde,inorder,0,4);
    inprint(root);


}