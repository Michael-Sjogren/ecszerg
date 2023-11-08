
build: clean
	zig cc main.c ./lib/libraylib.a -I ./include -I./

run:build
	./a.out

clean:
	rm -f a.out