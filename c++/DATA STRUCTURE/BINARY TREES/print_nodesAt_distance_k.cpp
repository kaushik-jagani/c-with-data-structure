// we can find node either subtree or ancestor 

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

// case1 -> find node at target nodes subtrees

void printSubtreeNode(node* root,int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printSubtreeNode(root->left,k-1);
    printSubtreeNode(root->right,k-1);

}

// case2:- find target nodes using ancestor

int printNodeAtk(node* root,node* target,int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
    printSubtreeNode(root,k);
    return 0;

    }
    // find target on left subtree
    int dl=printNodeAtk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNode(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr=printNodeAtk(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNode(root->left,k-dr-2);
        }
        return 1+dr;
    }

    return -1;
}







int main(){
    /*
            1
          2    3
        4  
    */
node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);

    printNodeAtk(root,root->left,2);

}

