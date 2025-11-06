CC = gcc
CFLAGS = -Wall -g -O3 -std=c17 -pipe -Wextra -Wpedantic -march=native
RM = rm -f
TARGET = apm
SOURCES = main.c utils.c
HEADERS = utils.h
OBJECTS = $(SOURCES:.c=.o)
INSTALL = /usr/local/bin

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	sudo cp $(TARGET) $(INSTALL)
	sudo chmod a+rx $(INSTALL)/$(TARGET)

clean:
	$(RM) *.o

