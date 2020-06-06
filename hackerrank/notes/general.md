# General Notes and FAQ

- General notes for solving problems on hackerrank

## Why I don't include `using namespace std;`
- Including this will definitely save time, but since I just started learning, I want to not include it so I can remind myself where I am getting some of the functions from. Might be redundant, but for now, it's something I am comfortable with.

## Purpose of `#include <bits/stdc++.h>` on code submissions
> source: https://www.geeksforgeeks.org/bitsstdc-h-c/

- I see this on all the submission files on hackerrank
- This header file is only good for including it for programming contests
- In summary, this is basically a header file that includes every standard library, and it includes a lot of files which you might not need for your program, so including it could increase both the compile time and program size unnecessarily
- It also saves you time so you don't have to remember all the STL of GNU C++ for every function you use
- this is not a standard headfer file for GNU c++ library, so if you use other compiler other than GCC - e.g. MSVC, your code will not compile.
- More information can be found in the source link.
