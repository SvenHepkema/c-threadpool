program: src/threadpool.c src/threadpool.h
	gcc -o $@ src/threadpool.c main.c -g

clean:
	rm program
