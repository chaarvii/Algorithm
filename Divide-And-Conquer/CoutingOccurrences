#include<iostream>
using namespace std;
// program for counting the number of occurrences of a number in a sorrted array
// time complexity = O(logn)
int binary_search_right(int arr[],int low, int high,int key)    // returns the right most occurrence of the element 
{
    int mid;
    if(low>high) 
        return low;                                            // each search is an unsuccessful search as no equality condition
    mid = low + (high-low)/2;                                  // prevents overflow

    if(arr[mid]>key)                            
        return binary_search_right(arr,low,mid-1,key);
    else 
        return binary_search_right(arr,mid+1,high,key);       // searches the right most occurrence whenever arr[mid]==key
}

int binary_search_left(int arr[],int low, int high,int key)   // returns the left most occurrence of the element 
{
    int mid;
    if(low>high) 
        return low;                                           // each search is an unsuccessful search as no equality condition
    mid = low + (high-low)/2;                                 // prevents overflow

    if(arr[mid]<key)
        return binary_search_left(arr,mid+1,high,key);
    else 
        return binary_search_left(arr,low,mid-1,key);        // searches the left most occurrence whenever arr[mid]==key
}

// Program for testing the function
int main()
{
    int arr[] = {1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = binary_search_left(arr,0,n-1,3);
    int j = binary_search_right(arr,0,n-1,3);
    cout << "number of occurences = " << j-i << endl;
}
