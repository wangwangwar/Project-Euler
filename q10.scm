#!/usr/bin/env guile
!#

(load "../SICP-NOTES/ch3-p223-stream.scm")
(load "../SICP-NOTES/ch2.scm")
(use-modules (srfi srfi-41))

(define (sum-primes-under n)
  (stream-fold +
               0
               (stream-filter (lambda (x) (fast-prime-miller-rabin? x 20))
                              (stream-range 3 n 2))))

(define (sum-primes-under2 n)
  (stream-fold +
               0
               (stream-filter prime?
                              (stream-range 3 n 2))))

(print (sum-primes-under2 2000000))
