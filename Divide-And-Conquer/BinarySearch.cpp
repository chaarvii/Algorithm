#include<iostream>
using namespace std;

/*Function for Binary Search returns the array index if key is present*/
int BinarySearch(int A[],int l,int h,int key)
{   
    int mid = 0;
    if(l<h)                                             /*search as long as right index is greater than left one*/
    {
        mid = (l+h)/2;
        if(A[mid]>key)                                  /* if the given key is less than the middle element it searches left side array*/
            return BinarySearch(A,l,mid,key);
        else if(A[mid]<key)                             /* if the given key is greater than the middle element it searches right side array*/                             
            return BinarySearch(A,mid+1,h,key);
        else if(A[mid]==key)
            return mid;
    }

    return -1;                                         /*if key not found*/
}

/* Program for testing*/
int main()
{
    /*Binary Search requires a sorted array as input*/
    int A[] = {10,12,14,15,16,18,20,22,26};
    int n = sizeof(A)/sizeof(A[0]);
    int x = BinarySearch(A,0,n,30);
    cout << x << endl;
    int y = BinarySearch(A,0,n,10);
    cout << y << endl;
}
