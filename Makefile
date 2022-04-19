OBJS	= server.o stack.o
SOURCE	= server.c stack.c

OUT	= server
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = -lpthread

all: server client

server: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

client: client.o
	$(CC) client.o -o client 

server.o: server.c
	$(CC) $(FLAGS) server.c

stack.o: stack.c
	$(CC) $(FLAGS) stack.c

client.o: client.c
	$(CC) -c client.c

clean:
	rm -f $(OBJS) $(OUT) client *.o