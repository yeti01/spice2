CXX = gcc
CXXFLAGS = -g -O0
FC = gfortran
FFLAGS = -g -O0 -std=legacy

OBJS = spice.o unix.o

all: spice

spice: $(OBJS)
	$(FC) $(OBJS) -o spice

%.o: %.f
	$(FC) -c $(FFLAGS) $*.f -o $*.o 

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $*.c -o $*.o

clean:
	rm -f $(OBJS) spice
