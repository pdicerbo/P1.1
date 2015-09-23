# This directive is used to tell "make" that the clean and all targets 
# are not real files
.PHONY: clean all

# Select the compiler by commenting and decommenting each line
#FC      = gfortran 
FC       = gfortran
#FC      = pgf90

# Here we define a variable that contains all the executables we would like to build
TARGETS = prog1_O0 prog1 prog1_O3 prog2_O0 prog2_O0 prog2 prog2_O3 prog3_O3 prog2_O3_unsafe_math prog3

# This is a "catch-all" target: $(TARGETS) means: "value of the
# TARGETS variable"
# Since the first target is the one executed by default, typing "make
# all" is the same, in this context, as typing just "make"
all: $(TARGETS)

# This is a typical make rule, it can be interpreted as:
# "'prog1.f' is required to build 'prog1_O0' 
#        (first line: target: requirements)
# To build prog1_O0, do this: '$(FC) -o prog1_O0 -O0 prog1.f'
#        (second line. $@ get expanded to prog1_O0)
prog1_O0: prog1.f
	$(FC) -o $@ -O0 prog1.f

prog1: prog1.f
	$(FC) -o $@ prog1.f

prog1_O3: prog1.f
	$(FC) -o $@ -O3 prog1.f

prog2_O0: prog2.f
	$(FC) -o $@ -O0 prog2.f

prog2_O1: prog2.f
	$(FC) -o $@ -O1 prog2.f

prog2: prog2.f
	$(FC) -o $@ prog2.f

prog2_O3: prog2.f
	$(FC) -o $@ -O3 prog2.f

# The -funsafe-math-optimizations flag is not supported by the PGI
# compiler. Ignore the error at the end of the PGI compilation
prog2_O3_unsafe_math: prog2.f
	$(FC) -o $@ -O3 -funsafe-math-optimizations prog2.f

prog3_O3: prog3.f
	$(FC) -o $@ -O3 prog3.f

prog3: prog3.f
	$(FC) -o $@ prog3.f

# this target has no requirements: each time make it's invoked as "make clean"
# it will remove the old executabes if any
clean:
	/bin/rm -f $(TARGETS)
