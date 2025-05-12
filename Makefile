CC = gcc
CCFLAGS = -g -O0 -Wno-implicit-int -Wno-implicit-function-declaration
FC = gfortran
FFLAGS = -g -O0 -finteger-4-integer-8 -std=legacy

OBJS = spice.o unix.o

all: spice

spice: $(OBJS)
	$(FC) $(OBJS) -o spice

%.o: %.f
	$(FC) -c $(FFLAGS) $*.f -o $*.o 

%.o: %.c
	$(CC) $(CCFLAGS) -c $*.c -o $*.o

clean:
	rm -f $(OBJS) spice
