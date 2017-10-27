#lang racket
#|
Author: David Tran
Purpose: Use the trisection method to find the maximum of
a function f(x)
Source: Dr. Jozo Dujmovic Programming Languages Reader pg. 174
|#

(define disp
  (lambda (x n)
    (display (/ (round (* x(expt 10 n))) (expt 10 n )))))

;fmax function that finds the max given f, x1, x2
(define fmax
  (lambda(f x1 x2)
    (cond
      ((< (- x2 x1) 1e-10)
       (display "Maximum: f(")
       (disp (/ (+ x1 x2) 2) 4)
       (display ") = ")
       (disp (f (/ (+ x1 x2) 2)) 4))
      (else (let ((a1 (+ x1 (/ (- x2 x1) 3)))
                  (a2 (- x2 (/ (- x2 x1) 3))))
              (if (< (f a1) (f a2))
                  (fmax f a1 x2)
                  (fmax f x1 a2)))))))
#|
OUTPUT:
> (fmax cos 1 2)
Maximum: f(1) = 0.5403
> (fmax sin 0 0)
Maximum: f(0) = 0
> (fmax sin 1 2)
Maximum: f(3927/2500) = 1.0
> (fmax cos 0 0)
Maximum: f(0) = 1
> (fmax tan 1 2)
Maximum: f(3927/2500) = 25253696228.7681
> (fmax tan 0 0)
Maximum: f(0) = 0
> (fmax tan 1 1)
Maximum: f(1) = 1.5574
>
|#

       