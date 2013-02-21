pp6calculator - A simple command line calculator
================================================
This is the readme for the pp6calculator project.

Authors
-------
- Martin Spangenberg

License
-------
pp6calculator is distributed under the terms of the Boost Software Licence.

Installation
------------
Compile as a standard C++ program.
If using the g++ compiler type "g++ pp6calc.cpp -o {progname}", where {progname} is the name you wish to call the compiled program.

Usage
-----
The calculator first asks for user input to choose an operation to perform. The input The available operations are (enter without parentheses):
(a)  Addition a+b,
(s)  Subtraction a-b,
(m)  Multiplication a*b,
(d)  Division a/b,
(i)  Find intercept of straight line a*x+b with x-axis,
(p)  Solve 2nd degree polynomial a*x^2 + b*x + c = 0,
(v3) Calculate size of 3-vector (a, b, c),
(v4) Calculate size of 4-vector (a, b, c, d) assuming metric (1, -1, -1, -1),
(im) Calculate invariant mass of particle pair using their momenta, masses and their mutual angle.

The program then asks for input variables as a comma separated list. The number of input variables depends on the chosen operation and is specified when prompting for it.