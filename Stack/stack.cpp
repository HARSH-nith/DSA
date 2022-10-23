// This is the program to perform stack operations

#include<iostream>
using namespace std;  
#define MAX 1000 //max size for stack
  
class Stack
{
   int top;
   public:
   int myStack[MAX];
  
   Stack() { top = -1; }
   bool push(int x);
   int pop();
   bool isEmpty();
};
   bool Stack::push(int item)
   {
      if (top >= (MAX-1)) {
      cout << "Stack Overflow!!!";
      return false;
   }
else {
   myStack[++top] = item;
   cout<<item<<endl;
   return true;
   }
}
int Stack::pop()
{
   if (top < 0) {
      cout << "Stack Underflow!!";
      return 0;
   }
else {
       int item = myStack[top--];
      return item;
   }
}
bool Stack::isEmpty()
{
   return (top < 0);
}
int main()
{
   class Stack stack;
   cout<<"The Stack Push "<<endl;
   stack.push(1);
   stack.push(2);
   stack.push(3);
   cout<<"The Stack Pop : "<<endl;
   while(!stack.isEmpty())
      {
      cout<<stack.pop()<<endl;
      }
   return 0;
}
