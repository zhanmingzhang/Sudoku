
#FILES = main.o
#CFLAGS = -I

#sudoku : $(FILES) 
#	gcc $(CFLAGS) $(FILES) -lm -o sudoku
#
#main.o: main.c
#	gcc -c -std=c99 main.c


# the compiler: gcc for C program, define as g++ for C++
  CC = gcc

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  # the build target executable:
  TARGET = main1

  all: $(TARGET)

  $(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -lm -std=c99 -o $(TARGET) $(TARGET).c

  clean:
	$(RM) $(TARGET)
