##
## EPITECH PROJECT, 2024
## B-CPE-110-LYN-1-1-secured-gauthier.candelier
## File description:
## Makefile
##
SRC = ./src/my_strlen.c \
	./src/hash.c \
	./src/my_intlen.c \
	./src/power.c \
	./src/hashtable/new_hashtable.c \
	./src/hashtable/ht_insert.c \
	./src/hashtable/ht_dump.c \
	./src/hashtable/ht_search.c \
	./src/hashtable/ht_delete.c \
	./src/hashtable/delete_hashtable.c \
	./src/my_itoa.c \
	./src/my_strdup.c \
	./src/my_strcpy.c \
	./src/my_put_nbr.c \
	./test.c \

OBJ = ${SRC:.c=.o}
CFLAGS = -g3 -Wall -Wextra
NAME = bin_name.a
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}
re: fclean all
