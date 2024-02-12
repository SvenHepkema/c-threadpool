program: src/threadpool.c src/threadpool.h main.c
	gcc -o $@ src/threadpool.c main.c -g

clean:
	rm program
