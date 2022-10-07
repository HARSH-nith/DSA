#include <bits/stdc++.h>
using namespace std;


class MinHeapNode{
    public:
    char data;
    unsigned int freq;
    MinHeapNode* left,*right;
    MinHeapNode(char data,unsigned int freq){
        this->data=data;
        this->freq=freq;
        left=right=NULL;
        
    }
    
};

void printcodes(struct MinHeapNode* root, string str)
{
 
    if (!root)
        return;
 
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
 
    printcodes(root->left, str + "0");
    printcodes(root->right, str + "1");
    
}
 
struct Compare{
    bool operator()(MinHeapNode* l,MinHeapNode* r){
        return l->freq>r->freq;
    }
};

void HuffmanCodes(char* data,int* freq,int n){
    priority_queue<MinHeapNode*,vector<MinHeapNode*>,Compare> pq;
    for(int i=0;i<n;i++){
        
        pq.push(new MinHeapNode(data[i],freq[i]));
    }
    
    while(pq.size()!=1){
        MinHeapNode* left=pq.top();
        pq.pop();
        MinHeapNode* right=pq.top();
        pq.pop();
        MinHeapNode* top=new MinHeapNode('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        pq.push(top);
        
        
        
    }
    
    printcodes(pq.top(), "");
}


int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    HuffmanCodes(arr, freq, size);
    return 0;
}