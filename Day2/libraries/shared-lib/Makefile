# Compiler/Linker/dynamic linker
CC = gcc
LD = gcc

# flags to compile object files that can be used in a dynamic library
CFLAGS = -fPIC
# on some platforms, use '-fpic' instead.

# Flags to create a dynamic library.
DYNLINKFLAGS = -shared
# on some platforms, use '-G' instead.

# files removal
RM = /bin/rm -f

# library's object files.
LIB_OBJS = util_file.o util_net.o 

# library's archive file
LIB_FILE = libutil.so

# library to use when linking the main program
# the '-L.' option is used to tell the compiler to look for libraries
# in the current directory, as well as the normal system library locations.

#Use -lc to link it against C library, since lib
#depends on the C library.

LIBS = -L. -lutil -lc

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
	$(LD) $(DYNLINKFLAGS) $(LIB_OBJS) -o $(LIB_FILE)

# compile C source files into object files.
%.o: %.c
	$(CC) $(CFLAGS) -c $<


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
