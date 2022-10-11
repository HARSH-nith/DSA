/*C++ code for tree traversal using preorder, level-order and postorder techniques
preorder: root -> left subtree -> right subtree
level-order: traverse each level one by one
postorder: left subtree -> right subtree -> root */

#include<bits/stdc++.h>
using namespace std;
//structure of a node in the tree
struct node
{
    int val;
    struct node *left, *right;
    node(int val){
        this->val=val;
        left=right=NULL;
    } 
};

void preorder(struct node *root){
    if(root==NULL)
        return;
    cout<<root->val<<"\t";
    preorder(root->left);
    preorder(root->right);
}

void levelorder(struct node *root){
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        cout<<temp->val<<"\t";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

void postorder(struct node *root){
    if(root==NULL)
        return;
    preorder(root->left);
    preorder(root->right);
    cout<<root->val<<"\t";
}

int main(){
    /*
            0
           / \
          1   2
         / \ / \
        3  4 5  6
    */
    struct node *root= new node(0);
    root->left=new node(1);
    root->right=new node(2);
    root->left->left=new node(3);
    root->left->right=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(6);

    cout<<"\nPreorder traversal: \n";
    preorder(root);

    cout<<"\nLevel-order traversal: \n";
    levelorder(root);

    cout<<"\nPostorder traversal: \n";
    postorder(root);

    return 0;

}
