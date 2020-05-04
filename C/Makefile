#uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
#
#info:
#	@echo $(uname_S)
#
#.PHONY: info

main: main.o notebook.o func.o
	gcc -o main -lpthread main.o notebook.o func.o

main.o: main.c
	gcc -c -DPRINT_INFO main.c

notebook.o: notebook.c
	gcc -c notebook.c

func.o: func.c
	gcc -c func.c

# -D 在编译时增加对-D后面的宏的定义
