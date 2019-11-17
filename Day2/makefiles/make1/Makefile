#
# Makefile for the calculator program.
# Version 2.4
# 14 Sep 2005, vikas karanth <vikaskaranth@gmail.com>
# written to use as make files demo .
# 

TARGET=prog 
OFLAG=-o
CFLAG=-c
CC=gcc

ALL=$(TARGET)

$(ALL): prog.c add.o mean.o mul.o sub.o myhead.h
	$(CC) $(OFLAG) prog prog.c add.o mean.o mul.o sub.o
	@echo "Project is built"

add.o: add.c
	$(CC) $(CFLAG)  add.c

mean.o: mean.c
	$(CC) $(CFLAG)  mean.c

mul.o: mul.c
	$(CC) $(CFLAG)  mul.c

sub.o: sub.c
	$(CC) $(CFLAG)  sub.c

myclean:
	@#see the diff with @ and without @
	@#rm -f prog	
	rm -f add.o
	rm -f mean.o
	@rm -f mul.o
	@rm -f sub.o
