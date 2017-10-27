
/* 
 * File:   arrayProcessing.cpp
 * Author: David Tran
 * Purpose: The purpose of this program is to remove the 3 largest values and its
 * duplicates from an array and display the new array with the eliminated integers
 * Created on February 27, 2017, 6:52 PM
 * HW Prompt:3. Array processing (elimination of three largest values) (one of many array reduction problems)
The array a(1..n) contains arbitrary integers. Write a function reduce(a,n) that reduces
the array a(1..n) by eliminating from it all values that are equal to three largest different
integers. For example, if a=(9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9) then three largest different
integers are 6,7,9 and after reduction the reduced array will be a=(1,1,1,2,3,3,5), n=7. The
solution should have time complexity O(n).
 */

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
/*Function Declaration*/
void reduce(int a[], int n);

int count = 0; // to keep track of count in new array.
vector <int> elimArray; //vector used to store array with eliminated integers/


/* Main */
int main(int argc, char** argv) 
{
    int array[] = {9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9};
    int numOfInts = sizeof(array)/sizeof(int); // the number of integers in the array
    reduce(array, numOfInts); //call to reduce function
    cout << endl << "The numbers after elimination is: " ;
    for(int i=0; i<count; i++) // loop to print out elements of the new array
    {
        cout << elimArray[i];
    }
    return 0;
}
/*
 * This function takes an array, finds the 3 largest values and removes any
 * duplicates of the 3 largest values.
 * This function compares current index to an array that stores the current highest values.
 * Then it compares the highest values to the array and pushes the elements that are not equal
 * to the 3 highest values into a vector.
 */
void reduce(int a[], int n)
{
    int largeInts[] = {0,0,0}; // array to hold the 3 largest ints.

    cout << "The original numbers is: ";
    for(int i=0; i<n; i++)// loops through the array
    {
        cout << a[i];
        if(a[i] > largeInts[2]) //checks if current int is greater than largeInts[2]
        {
            largeInts[0] = largeInts[1]; //moves integers up the array
            largeInts[1] = largeInts[2];
            largeInts[2] = a[i];
        }
        else if(a[i] > largeInts[1] && a[i] > largeInts[0] && a[i]<largeInts[2])//checks condition for 2nd largest value.
        {
            largeInts[1] = a[i];
        }
        else if(a[i] > largeInts[0] && a[i]<largeInts[1]) //checks condition 3rd largest value
            largeInts[0] = a[i];
        
    }

     for(int i=0; i<n; i++)
     {
         if(a[i] != largeInts[2] && a[i] != largeInts[1] && a[i] != largeInts[0])// checks to see if current int = 3 largest ints
         {
            elimArray.push_back(a[i]);//push elements into the vector if it does not equal the 3 largest.
            count++; //increment count.
         }
     }
 
}
