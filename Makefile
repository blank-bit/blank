#Makefile

sources = list_main.c list_point-1.c list_point-2.c
target = list
ccflags = -Wall -g -fsanitize=address
CC = gcc

all:
	$(CC) $(sources) $(ccflags) -o $(target)