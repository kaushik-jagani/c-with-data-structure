// lca ->lowest common ancestor
// distance between two nodes
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

node* lca(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data ==n1 || root->data==n2){
        return root;
    }

    node* left=lca(root->left,n1,n2);
    node* right=lca(root->right,n1,n2);

    if(left!=NULL and right!=NULL){
        return root;
    }

    if(left==NULL and right==NULL){
        return NULL;
    }
    if(left!=NULL){
        return lca(root->left,n1,n2);
    }
    return lca(root->right,n1,n2);
}

int finddist(node* root,int k,int dist){
    if(root==NULL){
        return -1;
    }

    if(root->data==k){
        return dist;
    }
    int left=finddist(root->left,k,dist+1);
    if(left!=-1){
        return left;
    }

    return finddist(root->right,k,dist+1);

}
int distbtwNodes(node* root,int n1,int n2){
    node* Lca=lca(root,n1,n2);
    
    int d1=finddist(Lca,n1,0);
    int d2=finddist(Lca,n2,0);
    return d1+d2;
}

int main(){

/* example tree
         1
       /   \
      2     3
     /       \
    4         5

*/    

node* root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->right->right=new node(5);

    cout<<distbtwNodes(root,2,5)<<" "<<endl;
}

