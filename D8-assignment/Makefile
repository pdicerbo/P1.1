CC=gcc
CFLAGS = -Wall
FC=gfortran
FFLAGS = -Wall
LIBS = -lcblas
FLIBS = -lblas

FIRST_OBJS = msub.o first_task.o
SECOND_OBJS = second_task.o cfunc.o

EX = first_task.x second_task.x

.PHONY : all clean

all: $(EX)

c_call_fortran: first_task.x
	./first_task.x

fortran_call_c: second_task.x
	./second_task.x

first_task.x: $(FIRST_OBJS)
	$(CC) $^ $(LIBS) -o $@

second_task.x: $(SECOND_OBJS)
	$(FC) $^ $(FLIBS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

%.o : %.f90
	$(FC) $(FFLAGS) -c $<

print_info:
	$(info objs are: $(OBJS))

clean:
	rm -f *.o *.x
