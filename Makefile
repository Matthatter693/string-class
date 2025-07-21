target = strfuncstat.o mystrfunstat.o mystrfundyn.o strfuncdyn.o
flags = -Iinclude -O3
cc=c++

main:${target}
	ar -rcsv lib/string.a build/strfuncstat.o build/mystrfunstat.o
	${cc} ${flags} -shared build/strfuncdyn.o build/mystrfundyn.o -o lib/string.so
	strip lib/string.so
	strip lib/string.a

strfuncstat.o:src/strfunc.cpp
	${cc} ${flags} -c src/strfunc.cpp -o build/strfuncstat.o

mystrfunstat.o:src/mystrfun.cpp
	${cc} ${flags} -c src/mystrfun.cpp -o build/mystrfunstat.o

strfuncdyn.o:src/strfunc.cpp
	${cc} ${flags} -fPIC -c src/strfunc.cpp -o build/strfuncdyn.o

mystrfundyn.o:src/mystrfun.cpp
	${cc} ${flags} -fPIC -c src/mystrfun.cpp -o build/mystrfundyn.o

build:lib/string.a lib/string.so
	${cc} ${flags} src/main.cpp lib/string.a -o strstat
	${cc} ${flags} src/main.cpp lib/string.so -o strdyn

clean:
	@echo "cleaning"
	rm -f build/*.o strstat strdyn
