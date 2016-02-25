.PHONY = clean all

CC = gcc
CCFLAGS = -std=c99 -g -Wall -Wextra
EXEC = testlibmtu
OBJS = testlibmtu.o
CFILES = \
    testfunc.c mtu_printFiles.c mtu_lang.c mtu_pairSum.c \
    mtu_qsort.c mtu_canDivide.c mtu_canNegate.c mtu_writeFileOpen.c
OFILES = \
    testfunc.o mtu_printFiles.o mtu_lang.o mtu_pairSum.o \
    mtu_qsort.o mtu_canDivide.o mtu_canNegate.o mtu_writeFileOpen.o

all: ${EXEC}

libmtu.so: ${CFILES}
	${CC} ${CCFLAGS} -fPIC -c ${CFILES}
	${CC} -shared -o libmtu.so ${OFILES}

${EXEC}: libmtu.so testlibmtu.c
	${CC} ${CCFLAGS} -o ${EXEC} testlibmtu.c -L. -lmtu

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${EXEC} libmtu.so ${OBJS} ${OFILES}
