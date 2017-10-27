#lang racket
#|
Author: David Tran
File: matrix.rkt
Purpose: to create a program that reads in a matrix from a file and is able to display
a specific row or column. The program shall be able to take in 2 different file containing
matrices and perform matrix multiplication and outputing the results to another file.
Source: Dr. Jozo Dujmovic Programming Languages Reader pg. 218-219
|#

;Read matrix from file
(define (read-matrix filename)
  (let* ((inport (open-input-file filename))
         (nrow (read inport))
         (ncol (read inport))
         (mat (make-vector nrow)))
    (do ((i 0 (add1 i)))
      ((>= i nrow) (close-input-port inport) mat)
      (let ((row (make-vector ncol)))
        (do ((j 0 (add1 j)))
          ((>= j ncol) (vector-set! mat i row))
          (vector-set! row j (read inport)))))))

;Display components of the given vector
(define (display-vector v)
  (do ((i 0 (add1 i)))
    ((>= i (vector-length v)) (display ""))
    (display (vector-ref v i)) (display " ")))

;Return i-th row of a matrix
(define (ro filename i)
  (define mat (read-matrix filename))
  (vector-ref mat i))

;Display i-th row of a matrix
(define (row filename i)
  (display-vector (ro filename (- i 1))))

;Return j-th col of a matrix
(define (co filename j)
  (define mat (read-matrix filename))
  (define nrow (vector-length mat))
  (define column (make-vector nrow))
  (do ((i 0 (add1 i)))
    ((>= i nrow) column)
    (vector-set! column i (vector-ref (vector-ref mat i) j))))

;Display j-th col of a matrix
(define (col filename j)
  (display-vector (co filename (- j 1))))

;Return dot product
(define (dot-product v1 v2)
  (do ((i 0 (add1 i)) (sum 0 (+ sum (* (vector-ref v1 i)
                                       (vector-ref v2 i)))))
    ((>= i (vector-length v1)) sum)))

;Function performs matrix multiplication on 2 matrices in seperate files
(define (mmul f1 f2 f3)
  (define m1 (read-matrix f1))
  (define m2 (read-matrix f2))
  (define nrow (vector-length m1))
  (define ncol (vector-length m2))
  (define outport (open-output-file f3))
  (display nrow outport) (display " " outport)
  (display ncol outport) (newline outport)
  (do ((i 0 (add1 i)))
    ((>= i nrow) (close-output-port outport) (display ""))
    (let ((row (make-vector ncol)))
      (do ((j 0 (add1 j)))
        ((>= j ncol) (display-vector row) (newline) (newline outport))
        (vector-set! row j (dot-product (ro f1 i) (co f2 j)))
        (display (vector-ref row j) outport) (display " " outport)))))

#|
@@@OUTPUT@@@
> (row "matrix1.dat" 2)
4 5 6 
> (row "matrix2.dat" 2)
1 2 3 
> (col "matrix1.dat" 2)
2 5 
> (col "matrix2.dat" 2)
2 2 2 
> (mmul "matrix1.dat" "matrix2.dat" "matrix3.dat")
6 12 18 
15 30 45
|#



