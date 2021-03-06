OBJECTS= main.o draw.o display.o matrix.o
CFLAGS= -Wall
LDFLAGS= -lm
CC= gcc

run: all
	./main

all: $(OBJECTS)
	$(CC) -g -o main $(OBJECTS) $(LDFLAGS)

main.o: main.c display.h draw.h ml6.h matrix.h
	$(CC) -c main.c

draw.o: draw.c draw.h display.h ml6.h matrix.h
	$(CC) $(CFLAGS) -c draw.c

display.o: display.c display.h ml6.h matrix.h stb_image_write.h
	$(CC) $(CFLAGS) -c display.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

clean:
	rm *.o *~