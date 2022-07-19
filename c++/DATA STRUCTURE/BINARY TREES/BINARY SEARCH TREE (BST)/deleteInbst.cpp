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
node* inorderSucc(node* root){
    node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
// delete node in BST
node* deleteNode(node* root,int key){
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else{
        if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }
         else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);  //succsor nr root ma set kariya pachhi right tree mathi remove kariyo jya root->right and temp->data ni value same hase
    }
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

     inorder(root);
     cout<<endl;
    root=deleteNode(root,5);
    //    print inorder after delete
    inorder(root);
}