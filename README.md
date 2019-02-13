# C/C++ Assignments

- [Assignment 0 (GCD)](#assignment-0-gcd)

## Assignment 0 (GCD)

### Task 1

Create a file `gcd.c` and write the C function `gcd( ...)` which receives two positive integers a and b and returns the greatest common divisor.The application program interface (API)of the function should be as follows:

```c
int gcd(int a, int b);
```

The `main( )` function reads `a` and `b` from the user, then calls `gcd( )` to compute the greatest common divisor, and finally prints the result. The contents of `main()` are available in the `gcd_main.c` file.

### Task 2

The above program can compute correct GCD only for positive integers. Change the program so that it can compute GCD for arbitrary integers.