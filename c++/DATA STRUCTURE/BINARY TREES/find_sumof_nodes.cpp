// find sum of node at kth level
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

int sumAtk(node* root,int k){
        if(root==NULL){
            return -1;
        }

        queue<node*> q;
        q.push(root);
        q.push(NULL);
        int lvl=0;
        int sum=0;

        while(!q.empty()){
            node* Node=q.front();
            q.pop();

            if(Node!=NULL){
                if(lvl==k){
                    sum+=Node->data;
                }

                if(Node->left){
                    q.push(Node->left);
                }
                if(Node->right){
                    q.push(Node->right);
                }
            }
            else if(!q.empty()){           // at any lvl one node is null but other node have data
                q.push(NULL);
                lvl++;
            }
        }

        return sum;
}

int main(){

    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);


    cout<<sumAtk(root,0)<<endl;
}