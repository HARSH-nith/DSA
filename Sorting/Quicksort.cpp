#include <bits/stdc++.h>
using namespace std;

void swap(int& a,int& b){
    int t=a;
    a=b;
    b=t;
}

int Partition(int* arr,int low,int high){
    int pivot=arr[low];
   
    int i=low,j=high;
    do{
        do{i++;}while(arr[i]<=pivot);
        do{j--;}while(arr[j]>pivot);
    if(i<j){
        swap(arr[i],arr[j]);
    }
    }while(i<j);
    
    swap(arr[low],arr[j]);
    
    return j;
    
}

void Sort(int* arr,int low,int high){
    if(low<high){
  int p=Partition(arr,low,high);
    Sort(arr,low,p);
    Sort(arr,p+1,high);
        
    }
}


void Printarr(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    
int arr[]={3,2,1,4,9,7,6};
int n=sizeof(arr)/sizeof(arr[0]);
Printarr(arr,n);
Sort(arr,0,n);
Printarr(arr,n);


    return 0;
}