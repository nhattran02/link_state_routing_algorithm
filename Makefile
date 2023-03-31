# Makefile
# Created on: 30.3.2023
CC = gcc
CFLAGS = -I./include -I/usr/include/python3.8 -L/usr/lib/python3.8/config-3.8-x86_64-linux-gnu -lpython3.8 

SRCDIR = src
OBJDIR = build
 
TARGET = main
OUTPUT = output 

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(SRCDIR)/*.c $^ -o $(OBJDIR)/$(OUTPUT) $(CFLAGS) 
run: 
	./$(OBJDIR)/$(OUTPUT)
clean:
	rm -f $(OBJDIR)/$(OUTPUT)
