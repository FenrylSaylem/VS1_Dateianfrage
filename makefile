C = gcc
CFLAGS = -Wall -pedantic -lpthread -std=gnu99
BIN = server client

.PHONY: clean all

all: server client

server:Server.c
		$(C) $(CFLAGS) $^ -o $@

client:Client.c
		$(C) $(CFLAGS) $^ -o $@

clean:
rm	-rf $(BIN) $(OBJ)
