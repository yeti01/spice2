CC = gcc
CFLAGS = -g -O0 -Wno-implicit-int -Wno-implicit-function-declaration -Wno-return-type -Wno-pointer-to-int-cast
FC = gfortran
FFLAGS = -g -O0 -finteger-4-integer-8 -std=legacy -Wno-argument-mismatch 

OBJS = spice.o unix.o

all: spice

spice: $(OBJS)
	$(FC) $(OBJS) -o spice

spice.o: spice.f
	$(FC) -c $(FFLAGS) spice.f -o spice.o 

unix.o: unix.c
	$(CC) $(CFLAGS) -c unix.c -o unix.o

clean:
	rm -f $(OBJS) spice
