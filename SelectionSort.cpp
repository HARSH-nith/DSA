#include <iostream>
using namespace std;

void SelectionSort(int input[],int n){
  for(int i=0;i<n-1;i++){
  //find min element in the array
   int min=input[i],minIndex=i;
   for(int j=i+1;j<n;j++){
    if(input[j]<min){
        min=input[j];
        minIndex=j; }
     }
    //Swap
    int temp=input[i];
    input[i]=input[minIndex];
    input[minIndex]=temp;
  }
}
int main(){
cout<<"enter array size"<<endl;
int n;
cin>>n;
int input[n];
cout<<"enter the elements"<<endl;

for(int i=0;i<n;i++){
    cin>>input[i];  }
SelectionSort(input,n);
for(int i=0;i<n;i++){
    cout<<input[i]<<" ";
    }
    cout<<endl;
}
