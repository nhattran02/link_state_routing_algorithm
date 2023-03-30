# Makefile
# Created on: 30.3.2023
 
CC = g++
CFLAGS = -I./include -I/usr/include/python3.8 -L/usr/lib/python3.8/config-3.8-x86_64-linux-gnu -lpython3.8 

SRCDIR = src
OBJDIR = build

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
 
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(SRCDIR)/*.cpp $^ -o $(OBJDIR)/$(TARGET) $(CFLAGS) 

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
run: 
	./$(OBJDIR)/$(TARGET)
clean:
	rm -f $(OBJDIR)/*.o $(OBJDIR)/*.png $(TARGET)
