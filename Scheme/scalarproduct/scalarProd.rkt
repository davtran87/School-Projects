#lang racket

#|
Author: David Tran
Purpose: To compute the scalar product of 2 vectors iteratively using a Do loop
and to compute the scalar product of 2 vectors recursivley.
Source: Dr. Jozo Dujmovic Programming Languages Reader pg. 211
|#

; a) Function for computing the scalar product of 2 vectors iteratively using Do loop.
(define scalarProdIter
 (lambda (v1 v2)
  (if (= (vector-length v1) (vector-length v2)) ; checks if vectors length are equal
   (begin (let ((s 0))
    (do ((i 0 (+ i 1))) ; start of do loop from i = 0 to length of vector
    ((>= i (vector-length v1)) (display s))
    (set! s (+ s (* (vector-ref v1 i) (vector-ref v2 i)))))))
   (display "Error: different size of vectors.")))) ; display error if vector lengths are not equal

; b) Function for computing the scalar product of 2 vectors recursively
(define scalarProdList
    (lambda (list1 list2)
      (cond ((null? (cdr list1)) (* (car list1) (car list2))) ; condition check for empty lists
            (else (+ (* (car list1) (car list2)) ; add the head of each list
                     (scalarProdList (cdr list1) (cdr list2))))))) ; recurse by calling scalarProdList
(define scalarProdRec 
  (lambda (v1 v2)
    (if (= (vector-length v1) (vector-length v2)) ;check if vector length are the same.
           (scalarProdList (vector->list v1) (vector->list v2)) ; call to scalarProdList 
          (display "Error: different size of vectors.")))); display error if vector lengths are not equal

#|
@@@OUTPUT@@@
> (scalarProdIter '#(1 2 3) '#(2 1 1)) 
7
> (scalarProdRec '#(1 2 3) '#(2 1 1))
7
> (scalarProdIter '#(1 2 3) '#(2 1 1 1 1))
Error: different size of vectors.
> (scalarProdRec '#(1 2 3) '#(2 1 1 1 1))
Error: different size of vectors.
> (scalarProdIter '#(1 2 3 2 2) '#(2 1 1 1 1))
11
> (scalarProdRec '#(1 2 3 2 2) '#(2 1 1 1 1))
11
>
|#