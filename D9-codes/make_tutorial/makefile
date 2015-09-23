CC=gcc
CFLAGS= -Wall
FC=gfortran
FFLAGS= -Wall
LIBS=


call_axpy.x: call_axpy.o axpy.o version.o
	$(CC) call_axpy.o axpy.o version.o $(LIBS) -o call_axpy.x

call_axpy.o: call_axpy.c
	$(CC) $(CFLAGS) -c call_axpy.c

version.o: version.c
	$(CC) $(CFLAGS) -c version.c

axpy.o: axpy.f90
	$(FC) $(FFLAGS) -c axpy.f90



clean:
	rm -f  *.o *.x
