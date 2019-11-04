IDIR = ../include
CC = gcc
CFLAGS =-I$(IDIR)

ODIR = ../src
LDIR = ../lib

LIBS = -lm

_DEPS = validar.h guardar.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = validar.o guardar.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	
	$(CC) -c -o $@ $< $(CFLAGS)

deber03: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
