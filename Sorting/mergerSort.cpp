#include <iostream>  
using namespace std;  

void merge(int a[],int start,int middle,int last){
    int i=0, j=0, k=start;
    int n1 = middle-start+1;
    int n2 = last-middle;
    int larray[n1], rarray[n2];
    for(int l=0;l<n2;l++){
        rarray[l] = a[middle+1+l];
	}
    for(int l=0;l<n1;l++){
        larray[l] = a[start+l];    
	}
    while(i<n1 && j<n2){
        if(larray[i]<=rarray[j]){
            a[k]=larray[i];
            i++;    
        }
        else{
            a[k]=rarray[j];
            j++;    
        }
        k++;    
    }
    while(i<n1){
        a[k] = larray[i];
        i++;
        k++;    
    }
    while(j<n2){
        a[k]=rarray[j];
        j++;
        k++;    
    }    
}    

void mergeSort(int a[], int start, int last){
    if (start<last){
        int middle=(start+last)/2;
        mergeSort(a,start,middle);
        mergeSort(a,middle+1,last);
        merge(a,start,middle,last);  
    }  
}  
  
  
int main(){
    int n;
    cout<<"Enter Number Of Elements: ";
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
	}
    cout<<"Before sorting"<<endl;
    for (int i=0; i<n;i++){
        cout<<a[i]<<" ";
	}
    cout<<endl;
    mergeSort(a,0,n-1);
    cout<<"After sorting array elements are"<<endl;
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
	}
    return 0;  
}  