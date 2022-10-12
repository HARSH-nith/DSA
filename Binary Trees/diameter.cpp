//diameter of binary tree in c++
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int check(Node* root,int &mx)
    {
        if(root==NULL)
            return 0;
        int lh=check(root->left,mx);
        int rh=check(root->right,mx);
        mx=max(mx,1+lh+rh);
        return 1+max(lh,rh);
        
    }
    
    int diameter(Node* root) {
        
        int mx=INT_MIN;
        check(root,mx);
        return mx;
    }
};