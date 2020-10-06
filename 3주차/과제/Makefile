CC = g++ #c++
target = Str
objects = main.o str.o

$(target): $(objects)
	$(CC) -o $(target) $(objects)

$(objects) : str.h

.PHONY : clean
clean :
	rm $(target) $(objects)
