# SPICE VERSION 2G.6

This is SPICE VERSION 2G.6 adapted for use with modern computers.

Two compilers are needed to build the program:

* gcc **or** clang
* gfortran

A `Makefile` is included so that you simply have to run `make` to compile the
sources.

You might test the program by running:

`spice < benchmark.in > benchmark.out`

Notice the "TOTAL JOB TIME" in `benchmark.out`. The computer at Berkeley in 1983
needed 169.07 seconds whereas a laptop does the job in 0.02 seconds.

To get the output as raw data you have to run spice with the argument `-r`. But
unfortunately I found no program to load this file.

`spice -r benchmark.raw < benchmark.in > /dev/null`

I was able to get the code compiled with some modifications several years ago.
But I never solved the issue with the memory management that is used in the
Berkeley code until I found the hint of Tom Russo in the repo of Ethan Mancini.
Thanks for that.

The original sources from Berkeley can be found here:

https://ptolemy.berkeley.edu/projects/embedded/pubs/downloads/spice

## License

Copyright (c) 1985-1991 The Regents of the University of California.  All rights
reserved.

Permission is hereby granted, without written agreement and without license or
royalty fees, to use, copy, modify, and distribute this software and its
documentation for any purpose, provided that the above copyright notice and the
following two paragraphs appear in all copies of this software.

IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT OF
THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF
CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND
THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT,
UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
