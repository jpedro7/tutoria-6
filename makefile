bin: main.c
	gcc -o $@ $< -lpthread

.PHONY:

run: bin
	./$<

clean: bin
	rm $<