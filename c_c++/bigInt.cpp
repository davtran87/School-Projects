
/* 
 * File:   bigInt.cpp
 * Author: David Tran
 * Version: 1.0
 * Created on February 28, 2017, 8:30 PM
 * 
 * Purpose: This program  will take a positive integer from the
 * user and display a big image of the same integer.
 * 
 * HW Prompt:
 * 4. Integer plot function (find a smart way to code big integers)
 * Write a program BigInt(n) that displays an arbitrary positive integer n using big
 * characters of size 7x7, as in the following example for BigInt(170):
   @@   @@@@@@@  @@@@@
  @@@        @@ @@   @@
   @@       @@  @@   @@
   @@      @@   @@   @@
   @@     @@    @@   @@
   @@    @@     @@   @@
 @@@@@@ @@       @@@@@
 */

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
using namespace std;

/* Function Declarations */
void bigInt(string input);
void printBigInt(char inputDigit, int row);

/*Main*/
int main(int argc, char** argv) 
{
    string inputString; // string variable used to take in input.
    cout << "Please Enter A Positive Integer: ";
    cin >> inputString;
    cout << endl;
    bigInt(inputString);// call to bigInt function.
    

    return 0;
}
/*
 * The function bigInt takes in the input string of integers
 * and decides what digits need to be printed.
 * @param input is the user input of an integer.
 */
void bigInt(string input)
{
    for (int i=0; i<7; i++) //used to find out what row of the big int.
    {
        for(int j=0; j<(int)input.size(); j++) // used to find the digit from the input string.
            printBigInt(input[j],i); // call to print function.
        
        cout << "\n";
    }
}

/*
 * The function printBigInt prints the big int given a character
 * The function uses switch() to figure out what big int to print.
 * @param inputDigit is the digit to be printed
 * @param row is used to identify what row of a big int to print.
 */
void printBigInt(char inputDigit, int row)
{
    switch(inputDigit) 
    {
        case '0':
            if(row == 0) cout << "  @@@@@  ";
            if(row == 1) cout << " @@   @@ ";
            if(row == 2) cout << " @@   @@ ";
            if(row == 3) cout << " @@   @@ ";
            if(row == 4) cout << " @@   @@ ";
            if(row == 5) cout << " @@   @@ ";
            if(row == 6) cout << "  @@@@@  ";
            break;
        case '1':
            if(row == 0) cout << "    @@   ";
            if(row == 1) cout << "   @@@   ";
            if(row == 2) cout << "    @@   ";
            if(row == 3) cout << "    @@   ";
            if(row == 4) cout << "    @@   ";
            if(row == 5) cout << "    @@   ";
            if(row == 6) cout << "  @@@@@@ ";
            break;
        case '2':
            if(row == 0) cout << "  @@@@@  ";
            if(row == 1) cout << " @@   @@ ";
            if(row == 2) cout << "      @@ ";
            if(row == 3) cout << "  @@@@@@ ";
            if(row == 4) cout << " @@      ";
            if(row == 5) cout << " @@      ";
            if(row == 6) cout << " @@@@@@@ ";
            break;
        case '3':
            if(row == 0) cout << "  @@@@@  ";
            if(row == 1) cout << " @@   @@ ";
            if(row == 2) cout << "      @@ ";
            if(row == 3) cout << "  @@@@@@ ";
            if(row == 4) cout << "      @@ ";
            if(row == 5) cout << " @@   @@ ";
            if(row == 6) cout << "  @@@@@  "; 
            break;
        case '4':
            if(row == 0) cout << " @@   @@ ";
            if(row == 1) cout << " @@   @@ ";
            if(row == 2) cout << " @@   @@ ";
            if(row == 3) cout << " @@@@@@@ ";
            if(row == 4) cout << "      @@ ";
            if(row == 5) cout << "      @@ ";
            if(row == 6) cout << "      @@ ";
            break;
        case '5':
            if(row == 0) cout << " @@@@@@@ ";
            if(row == 1) cout << " @@      ";
            if(row == 2) cout << " @@      ";
            if(row == 3) cout << " @@@@@@@ ";
            if(row == 4) cout << "      @@ ";
            if(row == 5) cout << " @@   @@ ";
            if(row == 6) cout << "  @@@@@  ";
            break;
        case '6':
            if(row == 0) cout << " @@@@@@  ";
            if(row == 1) cout << " @@   @@ ";
            if(row == 2) cout << " @@      ";
            if(row == 3) cout << " @@@@@@@ ";
            if(row == 4) cout << " @@   @@ ";
            if(row == 5) cout << " @@   @@ ";
            if(row == 6) cout << "  @@@@@  ";
            break;
        case '7':
            if(row == 0) cout << " @@@@@@@ ";
            if(row == 1) cout << "      @@ ";
            if(row == 2) cout << "     @@  ";
            if(row == 3) cout << "    @@   ";
            if(row == 4) cout << "   @@    ";
            if(row == 5) cout << "  @@     ";
            if(row == 6) cout << " @@      "; 
            break;
        case '8':
            if(row == 0) cout << "  @@@@@  ";
            if(row == 1) cout << " @@   @@ ";
            if(row == 2) cout << " @@   @@ ";
            if(row == 3) cout << " @@@@@@@ ";
            if(row == 4) cout << " @@   @@ ";
            if(row == 5) cout << " @@   @@ ";
            if(row == 6) cout << "  @@@@@  ";
            break;
        case '9':
            if(row == 0) cout << "  @@@@@  ";
            if(row == 1) cout << " @@   @@ ";
            if(row == 2) cout << " @@   @@ ";
            if(row == 3) cout << "  @@@@@@ ";
            if(row == 4) cout << "     @@  ";
            if(row == 5) cout << "    @@   ";
            if(row == 6) cout << "   @@    "; 
            break;
    }
}