CC = gcc
CFLAGS = -Wall -Wextra -I./src
OBJDIR = bin
SRCDIR = src
TARGET = cythonic

all: $(TARGET)

$(TARGET): $(OBJDIR)/interpreter.o $(OBJDIR)/main.o $(OBJDIR)/parser.o $(OBJDIR)/utils.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/interpreter.o: $(SRCDIR)/interpreter.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/main.o: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/parser.o: $(SRCDIR)/parser.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/utils.o: $(SRCDIR)/utils.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
