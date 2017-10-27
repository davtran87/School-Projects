
/* 
 * File:   parabolic.cpp
 * Author: David Tran
 * Version: 1.0
 * Purpose: this program will take user input of 3 coordinate points and will
 * display a table of x points and y(x). y(x)=ax^2+bx+c
 * The program uses Cramer's Rule and Lagrange Interpolation to solve the
 * system of equations. For any value of x the program will compute y.
 * Created on March 1, 2017, 10:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*Function Declaration*/
void y(double x1, double y1, double x2, double y2, double x3, double y3, double x);
void lagrange(double x1, double y1, double x2, double y2, double x3, double y3, double x);
/*
 * 
 */
int main(int argc, char** argv) 
{
    double x1,y1,x2,y2,x3,y3;
    cout << "Please ENTER points (Ex. x1 y1 x2 y2 x3 y3): "; // take user input for coordinate points.
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << endl << "Cramers Rule to solve to y= ax^2 +bx +c" << endl;
    y(x1,y1,x2,y2,x3,y3,0); // call to function y().
    cout << "Lagrange Interpolation" << endl;
    lagrange(x1,y1,x2,y2,x3,y3,0); // call to function lagrange.
    return 0;
}

/*
 * This function y() uses Crammer's Rule to solve for y(x)= ax^2+bx+c. First the Function
 * must compute the determinate and then applying the rule gives us the result of y(x).
 * @Param double x1-x3 is x values ranging from 1-3. double y1-y3 is y values ranging from 1-3. 
 * double x is where the first value of x starts.
 * @References: I used 1)"https://www.khanacademy.org/math/algebra-home/alg-matrices/alg-determinants-
 * and-inverses-of-large-matrices/v/finding-the-determinant-of-a-3x3-matrix-method-2"
 * which is a video showing a shortcut on how to calculate determinates.
 * 2) http://www.purplemath.com/modules/cramers.htm which showed me how to apply Cramer's Rule. 
 */
void y(double x1, double y1, double x2, double y2, double x3, double y3, double x)
{
    double z = 1.0, det, detA, detB, detC, a, b, c, xUnit;
    det = ((x1*x1)*x2*z)+(x1*z*(x3*x3))+(z*(x2*x2)*x3)-(z*x2*(x3*x3))-((x1*x1)*z*x3)-(x1*(x2*x2)*z); // calculates the first determinate by using reference 1)
    detA = ((y1)*x2*z)+(x1*z*(y3))+(z*(y2)*x3)-(z*x2*(y3))-((y1)*z*x3)-(x1*(y2)*z); // calculates determinate for A
    detB = ((x1*x1)*y2*z)+(y1*z*(x3*x3))+(z*(x2*x2)*y3)-(z*y2*(x3*x3))-((x1*x1)*z*y3)-(y1*(x2*x2)*z);// calculates determinate for B
    detC = ((x1*x1)*x2*y3)+(x1*y2*(x3*x3))+(y1*(x2*x2)*x3)-(y1*x2*(x3*x3))-((x1*x1)*y2*x3)-(x1*(x2*x2)*y3);// calculates determinate for C
    a = detA/det; // the result of a-c after applying Cramer's Rule. using reference 2)
    b = detB/det;
    c = detC/det;
    xUnit = (x3-x1)/40; // this used to increment x for a uniform distribution
    x = x1 + xUnit; // starting value of x
   

    cout << setw(5) << "x" << setw(5) << "        " << setw(5) << "y(x)" << endl; 
    for(int i=0; i<40; i++) // for loop to compute for 40 different value of x.
    {
        double y = a*(x*x)+ b*x + c; // calculates y= ax^2+bx+c
        cout << setw(5) << x << setw(5) << "      " << setw(5) << y << endl;//display x and y(x)
        x += xUnit; // increment x
    }
    cout << "a = " << a << " b = " << b << " c = " << c << endl << endl; // display a, b ,c coefficients.
}
/*
 * This function lagrange() uses Lagrange to solve for the quadratic a gives same results as Cramer's Rule.
 * @Param double x1-x3 is x values ranging from 1-3. double y1-y3 is y values ranging from 1-3. 
 * double x is where the first value of x starts.
 * @References: I used 1)"http://mathonline.wikidot.com/quadratic-lagrange-interpolating-polynomials"
 * which shows how to apply lagrange interpolation formula.
 */
void lagrange(double x1, double y1, double x2, double y2, double x3, double y3, double x)
{
    double xUnit = (x3-x1)/40; // this used to increment x for a uniform distribution
    x = x1 + xUnit; // starting value of x
    cout << setw(5) << "x" << setw(5) << "        " << setw(5) << "y(x)" << endl;
    for(int i=0; i<40; i++) //loop used to compute 40 values of x.
    {
        double p = y1*(((x-x2)*(x-x3))/((x1-x2)*(x1-x3))) // lagrange interpolation from ref 1)
             + y2*(((x-x1)*(x-x3))/((x2-x1)*(x2-x3)))
             + y3*(((x-x1)*(x-x2))/((x3-x1)*(x3-x2)));

        cout << setw(5) << x << setw(5) << "      " << setw(5) << p << endl;
        
        x += xUnit; // increment x.
    }
}

