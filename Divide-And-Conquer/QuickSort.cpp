#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std; 

void swap(int* a,int* b)                   // swapping two elements
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)    // partitioning routine 
{
    int pivot = arr[low];                     // uses lower element as the pivot 
    int i = low+1;
    for(int j=low+1;j<=high;j++)   
    {
        if(arr[j]<pivot)
        {
            swap(arr[j],arr[i]);
            i++;
        }
    }
    swap(arr[low],arr[i-1]);
    return i-1;                                // returns the position of pivot in the partitioned array
}

int randompivot(int arr[],int low,int high)       // generating random pivot 
{
    srand(time(NULL)); 
    int random = low + rand() % (high - low); 
  
    // Swap A[random] with A[high] 
    swap(arr[random],arr[low]); 
  
    return partition(arr, low, high); 
}

void quicksort(int arr[], int low,int high)
{   // arr = array to be sorted 
   // low = starting index, high =  ending index
    if (low < high) 
    {
    int p;
    p = randompivot(arr,low,high);         
    quicksort(arr,low,p-1);                    // sort left half
    quicksort(arr,p+1,high);                  //  sort right half
    }
}

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " ";
    cout << endl; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = { 20,6,14,98,100,2,3,6,6,7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    quicksort(arr, 0, n - 1); 
    cout << "Sorted Array "; 
    printArray(arr, n); 
    return 0; 
} 
