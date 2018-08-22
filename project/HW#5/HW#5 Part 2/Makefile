CXX=g++
OBJS=salestax.o headers/functions.o
PROGS=salestax
INCS=-I"./headers"
LIBDIR="./headers"


salestax.o:	salestax.cpp
		${CXX} ${INCS} -c salestax.cpp

salestax:	${OBJS}
		${CXX} -L${LIBDIR} -ltax ${OBJS} -o salestax

clean:
		rm ${OBJS} ${PROGS}
