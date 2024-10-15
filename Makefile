
.PHONY:		all, clean, fclean, re

CC		=	nasm

CFLAG	=	-f elf64

NAME	=	test

SRC		=	ft_strlen.s ft_write.s main.s

SRCDIR	=	./src/
SRCFILL	=	$(addprefix $(SRCDIR), $(SRC))

OBJ		=	$(SRC:.s=.o)
OBJDIR	=	./obj/
OBJFILL	=	$(addprefix $(OBJDIR), $(OBJ))

all:			$(NAME)

$(NAME):		$(OBJFILL)
				ld $^ -o $@ -lc -I/lib/x86_64-linux-gnu/libc.so.6

$(OBJDIR)%.o:	$(SRCDIR)%.s
				@mkdir -p $(OBJDIR)
				$(CC) $(CFLAG) $< -o $@

clean:
				rm -rf $(OBJDIR)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all