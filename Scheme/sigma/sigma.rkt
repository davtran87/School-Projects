#lang racket
#|
Author: David Tran
Purpose: To implement a function sigma that computes the
standard deviation of any number of arguments (list).
|#
;Function that computes the sum of the list.
(define sum (lambda(list)
  (if (null? list) 0 (+ (car list) (sum(cdr list))))))

;Function computes the square of a number and returns it.
(define square (lambda(x) (* x x )))

;Function that computes the sum of square of a list and returns it.
(define sumSquared (lambda(list)
  (if (null? list) 0 (+ (square(car list)) (sumSquared(cdr list))))))

;Function that computes the standard deviation
(define sigma (lambda(x . list)
   (sqrt (- (/ (+ x (sumSquared list)) (+ (length list) 1)) (square(/ (+ x (sum list)) (+ (length list) 1)))))))

#|
OUTPUT:
> (sigma 1 2 3 2 1)
0.7483314773547883
> (sigma 1 3 1 3 1 3)
1
> (sigma 1 3)
1
> (sigma 1)
0
> (sigma 1 2 3 4 5 6 7 8 9)
2.581988897471611
> 
|#