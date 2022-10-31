#include<bits/stdc++.h>
using namespace std;

//Deletes middle of stack of size

void deleteMid_util(stack<char>&s , int sizeOfStack , int current)
{
    //if current pointer is half of the size of stack then we are 
    //accessing the middle element of stack

    if(current == sizeOfStack/2)
    {
        s.pop();
        return;

    }

    int x = s.top();
    s.pop();
    current +=1;

    //Call the function recursively

    deleteMid_util(s , sizeOfStack , current);

    //pushing the element except the middle element 
    s.push(x);

}

void deleteMid(stack<char>&s , int sizeOfStack)
{
    deleteMid_util(s , sizeOfStack, 0);

}


int main(){

    stack<char> st;

    //push the elements into the stack
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    st.push('5');
    st.push('6');
    st.push('7');

    deleteMid(st, st.size());

    //printing the stack after deletion of the middle

    while(!st.empty())
    {
        char p = st.top();

        st.pop();
        cout << p << " " ;

    }
    return 0;
}