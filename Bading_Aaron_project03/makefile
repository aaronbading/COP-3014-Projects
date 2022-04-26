# Author: Aaron
# Compiler flags:
CC = g++
DEBUG = -g
CFLAGS = $(DEBUG) -c -Wall -std=c++11
LDLIBS =

#CHANGE: What to name the executable
TARGET = main

#CHANGE: Source code files
SOURCES = \
ledger.cpp \
transaction.cpp \
textmenu.cpp\
main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LDLIBS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY : all $(TARGET)

# Must call 'make clean' for cleaning to occur
#	rm -f $(OBJECTS)
clean:
	rm -f *.o

clobber: clean
	rm -f $(TARGET)
