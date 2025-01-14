OBJ := $(patsubst %.c,%.o,$(wildcard *.c))

apc: $(OBJ)	
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

clean:
	rm -f *.o apc