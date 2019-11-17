CC=gcc
CFLAG=-c
OFLAG=-o
TARGETS=add.o sub.o mul.o mean.o

prog: prog.c myhead.h $(TARGETS) 
	$(CC) $(OFLAG) prog prog.c  $(TARGETS)

#using name of the first prerequisite

%.o: %.c
	$(CC) $(CFLAG) $< 	# -o $@     # can also used

clean:
	@rm -f prog *.o
