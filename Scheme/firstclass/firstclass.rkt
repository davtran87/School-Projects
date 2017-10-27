#lang racket
#|
Author: David Tran
Purpose: To practice and see examples of first class language
Source: Dr. Jozo Dujmovic Programming Languages reader (scheme section).
|#

;Example of anonymous function
(display "Anonymous Function\n")
((lambda (n) (* n n)) 5)

;Example of a named function
(display "\nNamed Function\n")
(define square (lambda(n) (* n n)))
(square 5)

;Example of creating a list of functions and displaying the list
(display "\nFunction List\n")
(define cube (lambda(n) (* n n n)))
(define list '(square cube))
(display list)

;Example of comparing a list of functions and comparing functions using equal? & eq?
(display "\n\nCompare List of Functions\n")
(define list2 '(cube square))
(define list3 '(square cube))
(display list)
(display list2)
(display list3)
(display "\n")
(equal? list list2)
(equal? list list3)
(eq? square cube)
(eq? square square)

;Example of passing functions to another
(display "\nPassing Functions\n")
(cube(square(square 2)))
(cube(square(cube(square 2))))

;Example of returning a function from another function using conditions
(display "\nReturning a function as a result of another function\n")
(define mult2 (lambda(n) (* n 2)))
(define mult3 (lambda(n) (* n 3)))
(define multFunction (lambda(x y)
(cond
  [(equal? x 1) (mult2 y)]
  [(equal? x 2) (mult3 y)])))
(multFunction 1 2)
(multFunction 2 2)

;Example of reading from keyboard
(display "\nRead From Keyboard\n")
(define keyboardRead (read))

;Example of reading from a file
(display "\nRead From File\n")
(define inport (open-input-file "squared.txt"))
(read inport)

#|
@@@ OUTPUT @@@
Anonymous Function
25

Named Function
25

Function List
(square cube)

Compare List of Functions
(square cube)(cube square)(square cube)
#f
#t
#f
#t

Passing Functions
4096
68719476736

Returning a function as a result of another function
4
6

Read From Keyboard
Hello World

Read From File
'(define square (lambda (n) (* n n)))
|#


  