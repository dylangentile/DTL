CC = g++
CFLAGS = -Wall -g -std=c++11
# -pipe
INCLUDES = -I../include
LFLAGS = 
#-L../lib
LIBS = 
#-lmylib -lms

SRCS = main.cpp vector.cpp


OBJS = $(SRCS:.c=.o)

MAIN = dtl

.PHONY: depend clean

all:    $(MAIN)
	

$(MAIN): $(OBJS) 
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) *.o *~ $(MAIN)
		$(RM) -r *.dSYM
		$(RM) *.exe 

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it