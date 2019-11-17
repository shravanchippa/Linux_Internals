TARGET=prog add mean mul sub
OFLAG=-o
CFLAG=-c
CC=gcc
ALL=$(TARGET)

prog: prog.c myhead.h add.o mean.o mul.o sub.o
	$(CC) $(OFLAG) prog prog.c add.o mean.o mul.o sub.o
add.o: add.c
mean.o: mean.c
mul.o: mul.c
sub.o: sub.c
clean:
	@rm -f prog
	@rm -f add.o
	@rm -f mean.o
	@rm -f mul.o
	@rm -f sub.o
