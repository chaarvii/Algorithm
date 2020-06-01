/*C++ program for counting versions of an array using Merge Sort*/

#include<iostream>
using namespace std;

int split_merge_count (int arr[],int l,int mid, int h)
{ 
    int i, j, k; 
    int n1 = mid - l + 1; 
    int n2 =  h - mid; 
    int inv_count = 0;
  
    /* create temp arrays */
    int*L = NULL; 
    L = new int[n1];
    int *R = NULL;
    R = new int[n2]; 
  cout << l <<" " << mid << " " << h << endl;
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1+ j]; 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] < R[j]) 
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
            inv_count= inv_count + (mid-i+1);
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
    return inv_count;
} 

int MergeSort(int arr[],int l,int h)
{
    int mid=0,inversions=0;
    if(l<h)
    {
        mid = (l+h)/2;
        inversions+= MergeSort(arr,l,mid);
        inversions+= MergeSort(arr,mid+1,h);
        inversions+= split_merge_count(arr,l,mid,h);
        
    }
    return inversions;
}
int main() 
{ 
    int arr[] = { 1, 20, 6, 4, 5,30 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = MergeSort(arr,0,n-1); 
    cout << " Number of inversions are " << ans; 
    return 0; 
} 
