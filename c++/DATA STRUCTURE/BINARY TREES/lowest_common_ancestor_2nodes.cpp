// path change ->point of diverson===lca lowest common ancestor


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

bool getpath(node* root,int key,vector<int> &path){
    if(root==NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data==key){
        return true;
    }

    if(getpath(root->left,key,path)  || getpath(root->right,key,path)){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(node* root,int n1,int n2){
    vector<int> path1,path2;

    if(!getpath(root,n1,path1) || !getpath(root,n2,path2)){
        return -1;
    }

    int pc;  //path change 

    for(pc=0;pc<path1.size()and path2.size();pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    return path1[pc-1];       //last coomon value
}

node* LCA2(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }

    node* leftLca=LCA2(root->left,n1,n2);
    node* rightLca=LCA2(root->right,n1,n2);

    if(leftLca and rightLca){    //both doesnt equal to null
        return root;
    }
    if(leftLca!=NULL){
        return leftLca;
    }
    return rightLca;

}
int main(){
    /*
            1
          2    3
        4    5    6
            7
    */
node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(6);
    root->right->left->left=new node(7);


    int n1=7,n2=6;
    int lca=LCA(root,n1,n2);

    if(lca==-1){
        cout<<"lca doesnt exist"<<endl;
    }
    else{
        cout<<"lca:"<<lca<<endl;
    }


    node* Lca=LCA2(root,n1,n2);

    if(Lca==NULL){
        cout<<"lca doesnt exist"<<endl;
    }
    else{
        cout<<"lca:"<<lca<<endl;
    }
   return 0;
}