TARGET=client server stack
CC=gcc
CFLAGS= -Wall -Wextra -g
all: $(TARGET)

client: client.c
	$(CC) $(CFLAGS) client.c -o client -lpthread
server: server.c
	$(CC) $(CFLAGS) server.c -o server -lpthread
stack: stack.c
	$(CC) $(CFLAGS) stack.c -o stack -lpthread
clean:
	$(RM) $(TARGET)		
