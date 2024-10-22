
.PHONY:		all, clean, fclean, re

NAME		=	libasm.a
TEST		=	main_test

SC			=	nasm
SFLAG		=	-f elf64

CC			=	clang
CFLAG		=	-Wall -Wextra -Werror

SRCS		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCDIRS		=	./lasm_src/
SRCFILS		=	$(addprefix $(SRCDIRS), $(SRCS))

SRCC		=	main.c
SRCDIRC		=	./lasm_test/
SRCFILC		=	$(addprefix $(SRCDIRC), $(SRCC))

OBJDIR		=	./lasm_obj/

OBJS		=	$(SRCS:.s=.o)
OBJFILS		=	$(addprefix $(OBJDIR), $(OBJS))

OBJC		=	$(SRCC:.c=.o)
OBJFILC		=	$(addprefix $(OBJDIR), $(OBJC))

INCLUDE		=	./lasm_inc/

all:			$(NAME)

test:			$(NAME) $(TEST)

$(NAME):		$(OBJFILS)
				@echo creating $(NAME)
				@ar rcs $@ $^

$(TEST):		$(OBJFILC) $(NAME)
				$(CC) $(CFLAG) -L./ -lasm $^ -o $@

$(OBJDIR)%.o:	$(SRCDIRS)%.s
				@mkdir -p lasm_obj
				$(SC) $(SFLAG) $< -o $@

$(OBJDIR)%.o:	$(SRCDIRC)%.c
				@mkdir -p lasm_obj
				$(CC) $(CFLAG) -I $(INCLUDE) -o $@ -c $<

clean:
				rm -rf $(OBJDIR)

fclean:			clean
				rm -rf $(NAME)
				rm -rf $(TEST)

re:				fclean all
