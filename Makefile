
.PHONY:		all, clean, fclean, re

CC		=	nasm

CFLAG	=	-f elf64

NAME	=	test

SRC		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

SRCDIR	=	./src/
SRCFILL	=	$(addprefix $(SRCDIR), $(SRC))

OBJ		=	$(SRC:.s=.o)
OBJDIR	=	./obj/
OBJFILL	=	$(addprefix $(OBJDIR), $(OBJ))

all:			$(NAME)

$(NAME):		$(OBJFILL) ./obj/main.o
				gcc $^ -o $@

./obj/main.o:	./src/main.c
				gcc -c ./src/main.c -o ./obj/main.o

$(OBJDIR)%.o:	$(SRCDIR)%.s
				@mkdir -p $(OBJDIR)
				$(CC) $(CFLAG) $< -o $@

clean:
				rm -rf $(OBJDIR)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all