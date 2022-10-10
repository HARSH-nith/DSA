// function to return minimum and maximum in an array. and make minimum number of comparisons.
#include <iostream>
using namespace std;

int minMax(int arr[], int n)
{
    int min(0), max(0);
    if(arr[0]<arr[1]){
        min = arr[0];
        max = arr[1];
    }
    else{
        max = arr[0];
        min = arr[1];
    }
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {min = arr[i];}                
        if (max < arr[i])
        {max = arr[i];}
    }
    cout<<endl<<"---------------------------------------------"<<endl;
    cout << "the maximum element in array is " << max << endl;
    cout << "the min element in array is " << min << endl<<endl;
}
int main()
{
    int arr[] = {49,8,654,897,6456,47,5494,564,9,4,654,2};
    int n = sizeof(arr)/ sizeof(int);
    minMax(arr, n);
    return 0;
}