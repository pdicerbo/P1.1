IEEE Floating Point Arithmetic (exe_ieee)

files: 
prog1.f
prog2.f
prog3.f
Makefile

Objectives:

    * understand the impact of IEEE-compliant compilation on performance and RESULT

Instructions:

   1. Look at the first program: we calculate a two-point average, requiring a division by 2.
   2. Make prog1.f and measure the runtime. ( /bin/time ./prog1 ) 
   3. Now we take the second program prog2.f, calculating a three-point average, requiring a division by 3.
   4. Make prog2.f and measure the runtime of both of them.
   5. How do the runtimes compare? Does the extra addition justify the increase in CPU time ?
   6. Look at the prog3: where is the difference between prog2 and prog3 ? 
   7. Make it and measure runtime.
   8. Make now prog2_O3_unsafe_math and take note of the extra compiler option used. What does it do? (for details: man gfortran)
   9. Measure the runtime of prog2_Ox (with x any compiler optimization option). Compare with prog3 and even with prog1 
   10.Modify prog2.f and prog3.f in order to print out the final average: are they equal ? 
   11. Repeat all the above with another fortran compiler(intel/pgi) and identify the flags for those compiler that play the same role of --funsafe-math-optimizations for gfortran compiler 

 

