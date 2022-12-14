all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

test1: all
	bin/gauss dane/C dane/bC

test2: all
	bin/gauss dane/D dane/bD

test3: all
	bin/gauss dane/E dane/bE

test4: all
	bin/gauss dane/F dane/bF
