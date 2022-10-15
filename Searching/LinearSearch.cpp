#include<iostream>
using namespace std;


int LinearSearch(int arr[], int size, int key){
    for(int i = 0 ; i < size ;i++){
        if(arr[i]  == key){
            return i;
        }
    }
}

int main(){

    int even[6] = {2,4,6,8,12,18};
    int odd[5] = {3, 8, 11, 14, 16};

    int evenIndex = LinearSearch(even, 6, 6);

    cout << " Index of 6 is " << evenIndex << endl;

    int oddIndex = LinearSearch(odd, 5, 14);

    cout << " Index of 14 is " << oddIndex << endl;


    return 0;
    






    return 0;
}