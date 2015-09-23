gFC       = gfortran
gCC       = gcc
iFC       = ifort
iCC       = icc

CFLAGS  = $(ABI) $(ARCH)

TARGETS = sum_gfortran.x  sum_intel.x sum_gcc.x sum_icc.x

sum_gfortran.x: sum_numbers.f90
	$(gFC) -o $@ $(ABI) $(ARCH) \
	sum_numbers.f90

sum_intel.x: sum_numbers.f90
	$(iFC) -o $@ $(ABI) $(ARCH) \
	sum_numbers.f90

sum_gcc.x: sum_numbers.c
	$(gCC) -o $@ $(ABI) $(ARCH) \
	sum_numbers.c

sum_icc.x: sum_numbers.c
	$(iCC) -o $@ $(ABI) $(ARCH) \
	sum_numbers.c


all: $(TARGETS)

clean:
	/bin/rm -f $(TARGETS)
	/bin/rm -f *.s *.w2f.f
