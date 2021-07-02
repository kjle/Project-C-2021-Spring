#
# 
LOCAL_LIBS = -lsx 

# the object files which the program depends on
OBJS       = main.o vue.o data.o init.o

CellularAutomata : $(OBJS)
	$(CC) -o CellularAutomata $(OBJS)  $(LOCAL_LIBS) -Wall -Wextra -pedantic


# main.o depends on main.c main.h vue.c vue.h data.c data.h init.c init.h
main.o : main.c vue.c vue.h data.c data.h init.c init.h

vue.o : vue.c vue.h data.c data.h init.c init.h

data.o: data.c data.h init.c init.h


init.o : init.c init.h

clean:
	rm -f  $(OBJS) CellularAutomata
