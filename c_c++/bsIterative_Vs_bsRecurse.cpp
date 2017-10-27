/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bsIterativeVsRecurse.cpp
 * Author: David Tran
 * Purpose: The purpose of this program is to test the efficiency of binary search
 * using an iterative process and a recursive process. The program times both functions
 * and display the seconds it takes and operations it completes.
 * Reference: Dr. Jozo Slides Procedural Programming Pg. 116-117,
 * consist of Binary Search iterative and recursive functions.
 * Created on March 1, 2017, 2:30 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;
/*Function Declaration*/
int bsRecurse(int a[], int left, int right, int x);
int bsIter(int a[], int n, int x);
double sec(void);

/* Main Function */
int main(int argc, char** argv) {
    int k = 1000, n = 30000, array[n], icount=0, rcount=0; // initialized variables
    double start, end; // variables for timing
    for(int i=0; i<n; i++) // populating the array with elements that equal i.
        array[i] = i; // sorted array
    
    /* Start of Iterative Binary Search*/
    start = sec();
    for(int j=0; j<k; j++) // loop to allow program to run for at least 3 seconds
    {
        for(int i=0; i<n; i++)
        {
            if(bsIter(array,n,i) != i) 
                cout << "\nERROR";
        }
        icount++; // number of iterative operations incremented.
    }
    end = sec(); // end time
    cout << "Time for iterative : " << end-start << "seconds" << endl <<"# of Ops for iterative: " << icount << endl; 

    start = sec();
    for(int j=0; j<k; j++)// loop matching iterative to compare.
    {
        for(int i=0; i < n; i++)
        {
            if(bsRecurse(array,0,n,i) != i) 
                cout << "\nERROR";
        }
        rcount++; // number of recursive operations incremented
    }
    end = sec();// end time for recursive bs.
    cout << "Time for recursive: " << end-start << "seconds" << endl << "# of Ops for recursive: " << rcount;   
    return 0;
}

/*
 * This Function performs binary search iteratively. Basic Binary Search 
 * algorithm.
 * @Param int a[]= array of integers to be searched, int n is the size of array,
 * int x is the value to be searched.
 * @return middle returns the correct value once found.
 */
int bsIter(int a[], int n, int x)
{
    int left, right, middle;
    left =0;
    right = n-1;
    while (left <= right)
    {
        middle = (left+right)/2;
        if(x < a[middle])
            right = middle-1;
        else if(x > a[middle])
            left = middle+1;
        else return middle;
    }
    return -1;
                
}

/*
 * This Function performs binary search iteratively. Basic Binary Search 
 * algorithm.
 * @Param int a[]= array of integers to be searched, int n is the size of array,
 * int x is the value to be searched.
 * @return middle returns the correct value once found.
 */
int bsRecurse(int a[], int left, int right, int x)
{
    int middle;

    middle = (left+right)/2;
    if(left>right)
        return -1;
    if(x < a[middle])
        return bsRecurse(a,left, middle-1, x);
    if(x > a[middle])
        return bsRecurse(a, middle+1, right, x);
    return middle;

                
}
/*Seconds function used to get current time in seconds*/
double sec(void)
{
    return double(clock()/CLOCKS_PER_SEC);
}


