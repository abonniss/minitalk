#NAME
NAME = libftprintf.a

#COMPILER
CC = clang

#COMPILER FLAGS
CFLAGS += -Wall
CFLAGS += -Wextra

#ERROR FLAGS
ifneq ($(err), no)
	CFLAGS += -Werror
endif

#DEBUG FLAGS
ifeq ($(debug), 0)
	CFLAGS += -g3
else ifeq ($(debug), 1)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address
else ifeq ($(debug), 2)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -Weverything
endif

#DEBUGS SYMBOLS
DSYM += $(NAME).dSYM 

#INCLUDES 
INCLUDES += includes/

#PATH SOURCES 
PATHSOURCES_LIBFT = srcs/libft/
PATHSOURCES_MINITALK = srcs/minitalk/ 

#SOURCES
SRCS += ft_absolute.c
SRCS += ft_add_prefix.c
SRCS += ft_atoi.c
SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_is_uppercase.c
SRCS += ft_is_lowercase.c
SRCS += ft_itoa.c
SRCS += ft_memalloc.c
SRCS += ft_memccpy.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_split.c
SRCS += ft_strchr.c
SRCS += ft_strcpy.c
SRCS += ft_strdup.c
SRCS += ft_strjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c
SRCS += ft_to_lowercase.c
SRCS += ft_to_uppercase.c
SRCS += ft_str_to_uppercase.c
SRCS += ft_str_to_lowercase.c
SRCS += ft_printf.c
SRCS += ft_ltoabase.c
SRCS += manage_buffer.c
SRCS += state_machine.c
SRCS += conv.c
SRCS += conv_duixx.c

SRCS_MINITALK += client.c
SRCS_MINITALK += server.c


#HEADERS

HEADERS += libftprintf.h

#VPATH

vpath %.c $(PATHSOURCES_LIBFT)
vpath %.c $(PATHSOURCES_MINITALK)
vpath %.h $(INCLUDES)

#OBJS

PATHOBJS = objs/


OBJS += $(patsubst %.c, $(PATHOBJS)%.o, $(SRCS))
OBJS += $(patsubst %.c, $(PATHOBJS)%.o, $(SRCS_MINITALK))


#RULES 

all: $(NAME)

$(NAME): $(PATHOBJS) $(OBJS)
	ar rcs $@ $(OBJS) 
	printf "\033[32mCompilation OK\n\033[0m"

$(OBJS): $(PATHOBJS)%.o: %.c $(HEADERS) Makefile 
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(PATHOBJS): 
	mkdir $@

$(PATHOBJS_BONUS): 
	mkdir $@

clean: 
	$(RM) -R $(OBJS) $(OBJS_BONUS) $(PATHOBJS) $(PATHOBJS_BONUS) $(DSYM)
	printf "Clean OK\n"

fclean: clean 
	$(RM) $(NAME)
	printf "fclean OK\n"

re: fclean
	$(MAKE)

bonus: $(PATHOBJS_BONUS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS) 
	printf "\033[32mCompilation OK\n\033[0m"

test: all 
	$(CC) $(CFLAGS) -I $(INCLUDES) -L ./ -l ftprintf TestPF.c -o Tester
	printf "\033[32mTest OK\n\033[0m"

test_bonus: bonus
	$(CC) $(CFLAGS) -I $(INCLUDES) -L ./ -l ftprintf TestPF.c -o Tester
	printf "\033[32mTest OK\n\033[0m"

.PHONY: clean fclean re all

#.SILENT: 
