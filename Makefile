
.PHONY:		all, clean, fclean, re

CC		=	nasm

CFLAG	=	-f elf64

NAME	=	test

SRC		=	main.s ft_strlen.s ft_strcpy.s ft_write.s

SRCDIR	=	./src/
SRCFILL	=	$(addprefix $(SRCDIR), $(SRC))

OBJ		=	$(SRC:.s=.o)
OBJDIR	=	./obj/
OBJFILL	=	$(addprefix $(OBJDIR), $(OBJ))

INC		=	./inc/

all:			$(NAME)

$(NAME):		$(OBJFILL)
				ld $^ -o $@ -lc

$(OBJDIR)%.o:	$(SRCDIR)%.s
				@mkdir -p $(OBJDIR)
				$(CC) $(CFLAG) -I $(INC) $< -o $@

clean:
				rm -rf $(OBJDIR)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all