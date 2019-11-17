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

# program's object files
PROG_OBJS = main.o

# program's executable
PROG = prog


# we DO need the option -ldl to include the library
#that loads the DL libraries.

# libraries to link with the program during compile time.
LIBS = -ldl

# shared library files
LIB_FILES = lib1.so lib2.so

# shared libraries object files
LIB_OBJS = lib1.o lib2.o

# top-level rule
all: $(LIB_FILES) $(PROG)

$(PROG): $(PROG_OBJS)
	$(LD) $(LDFLAGS) $(PROG_OBJS) $(LIBS) -o $(PROG)

# create our librarys
lib1.so: lib1.o
	$(LD) $(DYNLINKFLAGS) lib1.o -o $@

lib2.so: lib2.o
	$(LD) $(DYNLINKFLAGS) lib2.o -o $@

# compile C source files into object files.
%.o: %.c
	$(CC) $(CFLAGS) -c $<


# clean everything
clean:
	$(RM) $(PROG_OBJS) $(PROG) $(LIB_OBJS) $(LIB_FILES)

# clean the program and its object files, don't touch the library.
cleanprog:
	$(RM) $(PROG_OBJS) $(PROG)

# clean the library and its object files only
cleanlib:
	$(RM) $(LIB_OBJS) $(LIB_FILES)

# clean the library's object files only
cleanlibobjs:
	$(RM) $(LIB_OBJS)
