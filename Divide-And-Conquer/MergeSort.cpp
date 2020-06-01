#include<iostream>
using namespace std;
  
// Merges two subarrays of arr[].  
void Merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int*L = NULL; 
    L = new int[n1];
    int *R = NULL;
    R = new int[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++;
            k++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
            k++;
        }
    } 

        for(;i<n1;i++)
        {
            arr[k] = L[i];
            k++;
        }
        for(;j<n2;j++)
        {
            arr[k] = R[j];
            k++;
        }

    

    delete [] L;
    delete [] R;
    R = NULL;
    L = NULL;
} 
void MergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        MergeSort(arr, l, m); 
        MergeSort(arr, m+1, r); 
  
        Merge(arr, l, m, r); 
    } 
} 

/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<< A[i] << " "; 
    cout << endl;
} 

/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {15, 12, 16, 2, 7, 9}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Given array is << endl; 
    printArray(arr, arr_size); 
  
    MergeSort(arr, 0, arr_size - 1); 
  
    cout << "Sorted array is << endl; 
    printArray(arr, arr_size); 
    return 0; 
} 
