                                     /*formula ab*10^(n/2) + (ad+bc)*10^(n) + bd */
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
                                        
long int KaratsubaMultiplication(int x,int y)                                   /*multiplying two integers using Divide and Conquer paradigm*/
{
    if(x<10||y<10)                                                              /* base case */
        return x*y;
    
    string str_x = to_string(x);
    string str_y = to_string(y);
    int m = str_x.length()>str_y.length()?str_x.length():str_y.length();
    cout << m << endl;
    int n = m/2;

    int dividing_factor = pow(10,n);                                               /*dividing numbers in two halves*/
    int x_left = x/dividing_factor; 
    int x_right = x%dividing_factor;
    int y_left = y/dividing_factor;
    int y_right = y%dividing_factor;

    long int a = KaratsubaMultiplication(x_left,y_left);                            /*computes ab */
    long int b = KaratsubaMultiplication(x_right,y_right);                          /*computes bd */
    long int c = KaratsubaMultiplication(x_left+x_right,y_right+y_left)-a-b;        /*computes ad+bc */

    return (a*pow(10,n*2)+c*pow(10,n)+b);            
}
/* program for testing */
int main()
{
    int a = 1234;
    int b = 5678;
    long int product = KaratsubaMultiplication(a,b);
    cout << product << endl;
}
