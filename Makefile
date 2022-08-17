CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG
SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
DEPS=$(wildcard src/**/*.h src/*.h)
# Temporary - for debugging
#TARGET=build/shell
TARGET=shell

all: main

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(SOURCES)
	$(CC) -o $(TARGET) $^ $(CFLAGS)

clean:
	rm -rf $(TARGET) $(OBJECTS)
