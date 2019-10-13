#!/usr/bin/python
# -*- coding: utf-8 -*-
print 'Input 1 for Addition'
print 'Input 2 for Subtraction'
print 'Input 3 for Multiplication'
print 'Input 4 for Division'
print 'Input 5 for finding Factorial of a number'
print 'Input 6 for finding weather a number is prime or not'

x = int(input('\nEnter the value of operation you want to do:-'))

if x <= 0 or x > 6:
    print 'Enter a valid option'
else:

    if x == 1:
        print 'You have selected Addition operation'
        a = int(input('Enter number 1:-'))
        b = int(input('Enter number 2:-'))
        c = a + b
        print c

    if x == 2:
        print 'You have selected Subtraction operation'
        a = int(input('Enter number 1:-'))
        b = int(input('Enter number 2:-'))
        c = a - b
        print c

    if x == 3:
        print 'You have selected Multiplication operation'
        a = int(input('Enter number 1:-'))
        b = int(input('Enter number 2:-'))
        c = a * b
        print c

    if x == 4:
        print 'You have selected Division operation'
        a = int(input('Enter number 1:-'))
        b = int(input('Enter number 2:-'))
        c = a / b
        print c

    if x == 5:
        n = int(input('Enter the number you want factorial for:-'))
        i = 1
        f = 1
        while i <= n:
            f = f * i
            i = i + 1
        print ('Factorial of number', n, 'is', f)

    if x == 6:
        n = \
            int(input('Enter the number you want to check for prime number or not:-'
                ))
        i = 2
        while i <= n - 1:
            if n % i == 0:
                print (n, 'is not prime')
                break
            else:
                i = i + 1
        if i == n:
            print (n, ' is a prime number')
