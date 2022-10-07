#include <iostream>
using namespace std;

// Class for Linked List Node.
class Node
{
public:
   // Variable to store data of the node.
   int data;
   // Pointer to the next node.
   Node *next;
   // Pointer to the previous Node.
   Node *previous;
};

// Function to print the list.
void printLinkedList(Node *head)
{
   Node *temp = head;
   while (temp != NULL)
   {
       cout << temp->data << "  ";
       temp = temp->next;
   }
   cout << endl;
}

// Function to reverse a doubly-linked List in groups of size K.
Node *reverseDLLSectionOfGivenSize(Node *head, int k)
{
   Node *start = head;
   Node *newTail = new Node();
   Node *temp = newTail, *ptr;
   int x = k;
   
   // We'll loop through the group and insert the elements at the start of the new doubly-linked List.
   while (start != NULL && x--)
   {
       // Creating the new node and copying the data of the current node.
       ptr = new Node();
       ptr->data = start->data;
       
       // Next we insert this at the beginning of the new doubly-linked list.
       temp->previous = ptr;
       ptr->next = temp;
       
       // Updating the new head.
       temp = temp->previous;
       
       // Incrementing to the next node.
       start = start->next;
   }
   
   // We store the value of ‘NEW_HEAD’ now.
   Node *newHead = ptr;
   
   // And we have the ‘NEW_TAIL’ of the new List.
   newTail = newTail->previous;
   
   // If we've not finished the list. We recurse to reverse the next Group, and NEW_HEAD (next group) will be stored in the next of the NEW_TAIL.
   if (start != NULL)
   {
       newTail->next = reverseDLLSectionOfGivenSize(start, k);
   }
   
   // ELse we point the ‘NEW_TAIL’ next to ‘NULL’.
   else
   {
       newTail->next = NULL;
   }
   
   // Return the updated ‘HEAD’ node.
   return newHead;
}

int main()
{
   int n, x, k;
   cout << "Enter the number of elements in doubly-Linked List: ";
   cin >> n;
   Node *head = new Node();
   Node *temp = head;
   cout << " Enter the elements: ";
   // Creating the Doubly-linked list.
   for (int i = 0; i < n; i++)
   {
       cin >> x;
       Node *ptr = new Node();
       ptr->data = x;
       temp->next = ptr;
       ptr->previous = temp;
       temp = ptr;
   }
   
   head = head->next;
   cout << "Enter the group size K: ";
   cin >> k;
   
   // Printing the doubly-linked List before reversal.
   cout << "Before Reversal: ";
   printLinkedList(head);
   
   // Calling the function to reverse the doubly-linked list in groups of size K.
   Node *newHead = reverseDLLSectionOfGivenSize(head, k);
   
   // Printing the doubly-linked list after reversal.
   temp = newHead;
   cout << "After Reversal: ";
   printLinkedList(newHead);
   
   return 0;
}