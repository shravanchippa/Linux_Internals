# Compiler/Linker
CC = gcc
LD = gcc

# Archiver and indexer
AR = /usr/bin/ar
RANLIB = /usr/bin/ranlib

# files removal
RM = /bin/rm -f

# library's object files.
LIB_OBJS = util_file.o util_net.o 

# library's archive file
LIB_FILE = libutil.a

# library to use when linking the main program
# the '-L.' option is used to tell the compiler to look for libraries
# in the current directory, as well as the normal system library locations.
LIBS = -L. -lutil

# program's object files
PROG_OBJS = main.o

# program's executable
PROG = prog

# top-level rule
all: $(LIB_FILE) $(PROG)

$(PROG): $(PROG_OBJS)
	$(LD) $(LDFLAGS) $(PROG_OBJS) $(LIBS) -o $(PROG)

# create our library
$(LIB_FILE): $(LIB_OBJS)
	$(AR) rc $(LIB_FILE) $(LIB_OBJS)
	$(RANLIB) $(LIB_FILE)

# compile C source files into object files.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# clean everything
clean:
	$(RM) $(PROG_OBJS) $(PROG) $(LIB_OBJS) $(LIB_FILE)

# clean the program and its object files, don't touch the library.
cleanprog:
	$(RM) $(PROG_OBJS) $(PROG)

# clean the library and its object files only
cleanlib:
	$(RM) $(LIB_OBJS) $(LIB_FILE)

# clean the library's object files only
cleanlibobjs:
	$(RM) $(LIB_OBJS)
