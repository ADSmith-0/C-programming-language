objects = obj/main.o obj/stack.o obj/getop.o obj/getch.o

calc: $(objects)
	gcc $^ -o calc

obj/%.o: src/%.c
	gcc -c $? -o $@
