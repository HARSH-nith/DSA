#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};
 

Node* newNode(int d)
{
    Node* temp = new Node;
    temp->data = d;
    temp->next = NULL;
    return temp;
}
 
// Declaration of Map to keep
// mark of visited Node
map<Node*, bool> vis;
bool flag = 0;
 
// Function to check cycle in Linked
// List
void check(Node* head)
{
    // If head is NULL return ;
    if (head == NULL) {
        flag = 0;
        return;
    }
 
    // Mark the incoming Node as
    // visited if it is not visited yet
    if (!vis[head]) {
        vis[head] = true;
        check(head->next);
    }
 
    // If a visited Node is found
    // Update the flag value to 1
    // and return ;
    else {
        flag = 1;
        return;
    }
}

int main()
{
    
    Node* head = newNode(20);
 
    // Inserting Node in Linked List
    head->next = newNode(4);
    head->next->next = newNode(5);
    head->next->next->next = newNode(10);
 
    // Just to make a cycle
    head->next->next->next->next = head;
 
    // Function that detect cycle in
    // Linked List
    check(head);
 
    // If flag is true, loop is found
    if (flag)
        cout << "Loop detected.";
 
    // If flag is false, No Loop
    // detected
    else
        cout << "No Loop Found.";
    cout << endl;
 
    return 0;
}