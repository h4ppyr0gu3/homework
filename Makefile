homework: homework.c 
	gcc -c homework.c 
	gcc -o homework homework.o -lm
clean: homework.o homework
	rm homework.o homework
histogram: histogram.c
	gcc -c histogram.c 
	gcc -o histogram histogram.o -lm
