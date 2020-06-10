// using C++ Vectors
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct point{                // structure for storing x and y coordinates 
    int x;
    int y;
} Point;

float distance(Point a, Point b)    // calculates eucledian distance between two points
{
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
float bruteforce(vector <Point> &P,int size)  // returns the minimum distance between the points
{                                             // used if input array has a size <= 3
    float min = FLT_MAX;
    float dist;
    for(int i=0;i<size;i++)
        for(int j=i+1;j<size;j++)
        {
            dist = distance(P[i],P[j]);
            if(dist<min)
                min = dist;
        }
    return min;
}

float minimum(float x, float y){   //  A utility function to find the distance between the closest points of 
    return x>y?y:x;
}

float splitclosest(vector <Point> &strip,float d)  
//  All points in vector strip are sorted according to 
// y coordinate. They all have an upper bound on minimum distance as d. 
{
    float min = d;
    float dist;
    int n = strip.size();
    // Pick all points one by one and try the next points till the difference 
    // between y coordinates is smaller than d
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n&&(strip[j].y-strip[i].y)<min;j++)
        {
            dist = distance(strip[j],strip[i]);
            if(dist<min)
                min = dist;
        }
    return min;
}
// A recursive function to find the smallest distance. The array Px contains 
// all points sorted according to x coordinates and Py contains all points 
// sorted according to y coordinates
float divideclosest(vector <Point> &Px, vector <Point> &Py,int size)
{
    if(size<=3)                          // if input size less than 3 then use brute force method
        return bruteforce(Px,size);

    int mid = size/2;                   // find the mid point
    Point midpoint = Px[mid];

    vector<Point> Pyl (Py.cbegin(), Py.cbegin() + mid );    // divide y into left and right half 
    vector<Point> Pyr( Py.cbegin() + mid, Py.cend() );
    vector<Point> Pxl( Px.cbegin(), Px.cbegin() + mid );   // divide x into left and right half
    vector<Point> Pxr ( Px.cbegin() + mid, Px.cend() );

    float left_min = divideclosest(Pxl,Pyl,mid);          // computes minimum distance in left half
    float right_min = divideclosest(Pxr,Pyr,size-mid);    // computes minimum distance in right half 

    float min = minimum(left_min,right_min);              // smaller of the two distances 

    vector <Point> strip;
    for(int i=0;i<size;i++)                           // a vector strip that contains points close (closer than d) 
    {                                                 // to the line passing through the middle point 
        if(abs(Py[i].x-midpoint.x)<min)
            strip.push_back(Py[i]);
    }
    return splitclosest(strip,min);                // Finds the closest points in strip.  Returns the minimum of d and closest 
}
bool compareX(Point i1, Point i2)                // required for vector.sort()
{ 
    return (i1.x < i2.x); 
} 
bool compareY(Point i1, Point i2)              // required for vector.sort()
{ 
    return (i1.y < i2.y); 
} 
  

float closest(vector <Point> &P, int n) 
{ 
    vector <Point> Px; 
    vector <Point> Py; 
    for (int i = 0; i < n; i++) 
    { 
        Px.push_back(P[i]); 
        Py.push_back(P[i]);
    } 
    sort(Px.begin(),Px.end(),compareX);
    sort(Py.begin(),Py.end(),compareY);
    // Use recursive function divideclosest to find closest distance. 
    return divideclosest(Px, Py, n); 
} 
// The main function that finds the smallest distance
int main() 
{ 
    vector <Point> P = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
    int n = P.size();
    float dist = closest(P,n);
    cout << "The smallest distance is " << dist;
    return 0; 
} 
