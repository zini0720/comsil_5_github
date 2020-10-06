CC = gcc
target = s191565
objects = main.o printer.o counter.o

$(target): $(objects)
	$(CC) -o $(target) $(objects)

$(objects) : header.h

.PHONY : clean
clean :
	rm $(target) $(objects)
