lltest: 10-9.c
	gcc 10-9.c -o lltest

clean:
	rm *~

run:
	./lltest