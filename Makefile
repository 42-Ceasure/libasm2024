
.PHONY:		all, clean, fclean, re

NAME		=	libasm.a
TEST		=	main_test

TESTER		=	./test/

SC			=	nasm
CC			=	clang

SFLAG		=	-f elf64
CFLAG		=	-Wall -Wextra -Werror

OBJDIR		=	./obj/

SRCS		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS		=	$(SRCS:.s=.o)
SRCDIRS		=	./proj/src/
INCDIRS		=	./proj/inc/
SRCFILS		=	$(addprefix $(SRCDIRS), $(SRCS))
OBJFILS		=	$(addprefix $(OBJDIR), $(OBJS))

SRCC		=	main.c _len.c _cpy.c _cmp.c _write.c _read.c _dup.c
OBJC		=	$(SRCC:.c=.o)
SRCDIRC		=	./test/src/
INCDIRC		=	./test/inc/
SRCFILC		=	$(addprefix $(SRCDIRC), $(SRCC))
OBJFILC		=	$(addprefix $(OBJDIR), $(OBJC))

all:			$(NAME)

test:			$(NAME) $(TEST)

$(NAME):		$(OBJFILS)
				@echo creating $(NAME)
				@ar rcs $@ $^

$(TEST):		$(OBJFILC) $(NAME)
				$(CC) $(CFLAG) $^ -o $@

$(OBJDIR)%.o:	$(SRCDIRS)%.s
				@mkdir -p $(OBJDIR)
				$(SC) $(SFLAG) $< -o $@

$(OBJDIR)%.o:	$(SRCDIRC)%.c
				@mkdir -p $(OBJDIR)
				$(CC) $(CFLAG) -I $(INCDIRC) -I $(INCDIRS) -o $@ -c $<

clean:
				rm -rf $(OBJDIR)

fclean:			clean
				rm -rf $(NAME)
				rm -rf $(TEST)

re:				fclean all
