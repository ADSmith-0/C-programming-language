objects = obj/main.o obj/quicksort.o

calc: $(objects)
	gcc $^ -o quicksort

obj/%.o: src/%.c
	gcc -c $? -o $@
