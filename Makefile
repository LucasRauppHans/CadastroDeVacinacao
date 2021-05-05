# Makefile

run:
	@./covid

build:
	@gcc \
	-g \
	./product/product.c \
	./node/node.c \
	./linked-list/linked_list.c \
	./queue/queue.c \
	main.c \
	-o covid

all: build run
