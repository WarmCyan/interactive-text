CC=cosmocc


hello: hello.c
	$(CC) -o hello hello.c


it: it.c
	$(CC) -o it it.c
	


.PHONY: clean
clean:
	-rm hello
	-rm it
	-rm *.elf
	-rm *.dbg
