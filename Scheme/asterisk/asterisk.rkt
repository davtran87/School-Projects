#lang racket
#|
Author: David Tran
Purpose: To print * depending on given parameters Ex. (line 5) will print *****
also to print * given list as parameter Ex. (histogram '(1 2 3)) will print * on first line and ** on second line
and *** on third line.
|#

;displays * depend on value of n passed to line
(define line (lambda(n)
   (if (< n 1) (display "")
(begin (display '*) (line(- n 1))))))

;displays * depending on the value with in a list new line for every value
(define histogram (lambda(list)
  (if (null? list) (display "")
      (begin (line(car list)) (display "\n") (histogram(cdr list))))))

#|
OUTPUT:
> (line 10)
**********
> (line 2)
**
> (histogram '( 1 2 3))
*
**
***
> (histogram '( 1 2 3 4 5))
*
**
***
****
*****
> 
|#
                    