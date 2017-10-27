
/* 
 * File:   plateau.cpp
 * Author: David Tran
 * Verson 1.0.
 * Created on March 1, 2017, 1:00 AM
 * Purpose: This program will count the longest consecutive sequence
 * of an identical integer with in an array and print the length of the sequence.
 * 
 * Homework Prompt:
 * 1. Plateau program (max sequence length) (a combinatorial algorithm)
 * The array a(1..n) contains sorted integers. Write a function maxlen(a,n) that returns the
 * length of the longest sequence of identical numbers (for example, if
 * a=(1,1,1,2,3,3,5,6,6,6,6,7,9) then maxlen returns 4 because the longest sequence 6,6,6,6
 * contains 4 numbers. Write a demo main program for testing the work of maxlen. Explain
 * your solution, and insert comments in your program. The solution should have time
 * complexity O(n).
 */

#include <cstdlib>
#include <iostream>

using namespace std;
int maxlen(int a[], int n);


/*
 * Main function
 */
int main() {
    int array[] = {1,1,1,1,1,1,1,1,1,1,1,2,3,3,5,6,6,6,6,6,6,6,6,7,9,9,9,9}; 
    int numOfInts = sizeof(array)/sizeof(int); // the number of integers in the array
    int counts = maxlen(array,numOfInts); // call to maxlen()
    cout << "The longest sequence of integers is: " << counts << endl;
    return 0;
}
/*
 * The function maxlen() traverses through an array counting the length of a sequence
 * of identical integers. Ex. a[1,1,1,2,3] it will return 3.
 * 
 * @param a[] is the array of integers, n is the number of elements/integers in the array.
 * @return maxCount the highest sequence count of identical integers
 */
int maxlen(int a[], int n)
{   
    int maxCount = 0, count = 0; // maxCount stores longest sequence. number stores longest seq integer.
    for(int i=0; i<n; i++) // loop till the end of array.
    {
        if(a[i] == a[i+1] || a[i]==a[i-1]) // checks if element in a[i] = next index or if a[i] = previous index.
            count++;
        
        else if (a[i]!= a[i+1]) // resets counter if a[i] != next.
            count = 0;
     
        if(maxCount < count) // checks if count is greater than max
             maxCount = count; // sets new max if condition met.
    }   
    return maxCount; // return highest count.
}
