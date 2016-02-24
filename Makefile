.PHONY = clean all

CC = gcc
CCFLAGS = -std=c99 -g -Wall -Wextra
EXEC = testlibmtu
OBJS = testlibmtu.o
CFILES = testfunc.c mtu_printFiles.c
OFILES = testfunc.o mtu_printFiles.o

all: ${EXEC}

libmtu.so: ${CFILES}
	${CC} ${CCFLAGS} -fPIC -c ${CFILES}
	${CC} -shared -o libmtu.so ${OFILES}

${EXEC}: libmtu.so testlibmtu.c
	${CC} ${CFLAGS} -o ${EXEC} testlibmtu.c -L. -lmtu

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${EXEC} libmtu.so ${OBJS} ${OFILES}
