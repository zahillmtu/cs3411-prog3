CC = gcc
CCFLAGS = -std=c99 -g -Wall -Wextra
EXEC = testlibmtu
OBJS = testlibmtu.o
CFILES = testfunc.c
OFILES = testfunc.o

libmtu.so: ${CFILES}
	${CC} ${CCFLAGS} -fPIC -c ${CFILES}
	${CC} -shared -o libmtu.so ${OFILES}

${EXEC}: libmtu.so
	${CC} ${CFLAGS} -o ${EXEC} testlibmtu.c -L. -lmtu

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${EXEC} libmtu.so ${OBJS} ${OFILES}
