target = strfunc.o main.o mystrfun.o 

cc=c++

main:${target}
	${cc} ${target} -o main

strfunc.o:strfunc.cpp
	${cc} -c strfunc.cpp

main.o:main.cpp
	${cc} -c main.cpp

mystrfun.o:mystrfun.cpp
	${cc} -c mystrfun.cpp

clean:
	@echo "cleaning"
	rm -f *.o main
