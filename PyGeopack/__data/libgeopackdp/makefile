all: obj lib exe

obj:
	gcc -c -fPIC libgeopack.c -o libgeopack.o
	gcc -c -fPIC TraceRoutines.c -o TraceRoutines.o
	gcc -c -fPIC DateTimeTools.c -o DateTimeTools.o
	gcc -c -fPIC ModelField.c -o ModelField.o
	gcc -c -fPIC ConvCoords.c -o ConvCoords.o
	gcc -c -fPIC Tom.c -o Tom.o
	
	gcc -c -fPIC SandhuCoords.c -o SandhuCoords.o
	gfortran -w -c -fPIC -fno-automatic -o T89c.o T89c.f
	gfortran -w -c -fPIC -fno-automatic -o T96.o  T96.f
	gfortran -w -c -fPIC -fno-automatic -o T01_01.o  T01_01.f
	gfortran -w -c -fPIC -fno-automatic -o TS04c.o  TS04c.f
	gfortran -w -c -fPIC -fno-automatic -o wparams.o  wparams.f95
	gfortran -w -c -fPIC -fno-automatic -o Tom96.o  Tom96.f95
	
	g++ -c -fPIC spline.cc -o spline.o
	g++ -c -fPIC libspline.cc -o libspline.o
lib: 
	gfortran -fPIC -fno-automatic -ffree-line-length-none -shared -o libgeopackdp.so Geopack-2008_mkj_dp.f wparams.o T89c.o T96.o T01_01.o TS04c.o TraceRoutines.o DateTimeTools.o ModelField.o ConvCoords.o Tom.o Tom96.o SandhuCoords.o libgeopack.o -lm
	g++ -fPIC -shared -o libspline.so libspline.o spline.o
	
	rm -v *.o

exe:
	gfortran -c test.f95
	gfortran -o test test.o libgeopackdp.so
	gfortran -c testsandhucoords.f95
	gfortran -o testsandhucoords testsandhucoords.o libgeopackdp.so

	rm -v *.o


clean:
	rm -v  *.so
	rm test
	rm testsandhucoords
