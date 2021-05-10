# Makefile

all: build run

run:
	@./covid

build:
	@gcc \
	-g \
	./node/node.c \
	./linked-list/linked_list.c \
	./queue/queue.c \
	./cidadao/cidadao.c \
	./vacinacao/vacinacao.c \
	main.c \
	-o covid
