CC=g++
CFLAGS=-I.
X= argv(1)



${X}.o : ${X}.cpp
	${CC} -c ${X}.cpp
${X}: ${X}.o
	${CC} ${X}.o -o ${X}
