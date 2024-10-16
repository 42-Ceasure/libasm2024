
.PHONY:		all, clean, fclean, re

CC		=	nasm

CFLAG	=	-f elf64 -gdwarf

NAME	=	test

SRC		=	ft_strlen.s ft_strcpy.s

SRCDIR	=	./src/
SRCFILL	=	$(addprefix $(SRCDIR), $(SRC))

OBJ		=	$(SRC:.s=.o)
OBJDIR	=	./obj/
OBJFILL	=	$(addprefix $(OBJDIR), $(OBJ))

all:			$(NAME)

$(NAME):		$(OBJFILL) ./obj/main.o
				gcc $^ -o $@

./obj/main.o:
				gcc -c ./src/main.c -o ./obj/main.o

$(OBJDIR)%.o:	$(SRCDIR)%.s
				@mkdir -p $(OBJDIR)
				$(CC) $(CFLAG) $< -o $@

clean:
				rm -rf $(OBJDIR)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all