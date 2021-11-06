#NAME
CLIENT = client
SERVER = server

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
INCLUDES += includes

#LIB 
PATH_LIB = libftprintf
LIB = $(PATH_LIB)/libftprintf.a
INCLUDES_LIB = $(PATH_LIB)/includes
LIB_NAME = ftprintf 

#PATH_SOURCES 
PATH_SRCS_CLIENT = srcs/client
PATH_SRCS_SERVER = srcs/server


#SOURCES
SRCS_CLIENT += client.c
SRCS_SERVER += server.c


#HEADERS
HEADERS += minitalk.h

#VPATH
vpath %.c $(PATH_SRCS_CLIENT)
vpath %.c $(PATH_SRCS_SERVER)
vpath %.h $(INCLUDES)

#OBJS
PATH_OBJS = objs
OBJS_CLIENT = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS_CLIENT))
OBJS_SERVER = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS_SERVER))

#COLORS PRINT
NC 		= \033[0m
GREEN 	= \033[32m
CYAN 	= \033[36m
RED 	= \033[31m
ONELINE = \e[1A\r


#RULES 

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIB) $(PATH_OBJS) $(OBJS_CLIENT)
	#clang -Wall -Wextra -Werror objs/client.o -L libftprintf -l ftprintf -I includes -I libftprintf/includes -o client
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L $(PATH_LIB) -l $(LIB_NAME) -I $(INCLUDES) -I $(INCLUDES_LIB) -o $@
	printf "$(GREEN)$@ IS READY\n$(NC)"

$(SERVER): $(LIB) $(PATH_OBJS) $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -L $(PATH_LIB) -l $(LIB_NAME) -I $(INCLUDES) -I $(INCLUDES_LIB) -o $@
	printf "$(GREEN)$@ IS READY\n$(NC)"

$(LIB): FORCE
	#make -C libftprintf 
	$(MAKE) -C $(PATH_LIB) 

FORCE: 
	#permet de forcer la réalisationn de la lib

$(OBJS_CLIENT): $(PATH_OBJS)/%.o: %.c $(HEADERS) Makefile
	#clang -Wall -Werror -Wextra -I libftprintf/includes -I includes -c client.c -o objs/client.o
	$(CC) $(CFLAGS) -I $(INCLUDES_LIB) -I $(INCLUDES) -c $< -o $@
	printf "$(CYAN)$< IS COMPILING                                 \n$(NC)"

$(OBJS_SERVER): $(PATH_OBJS)/%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -I $(INCLUDES_LIB) -I $(INCLUDES) -c $< -o $@
	printf "$(CYAN)$< IS COMPILING                                 \n$(NC)"

$(PATH_OBJS):
	mkdir $@

clean:
	$(RM) -R $(PATH_OBJS) $(DSYM)
	printf "$(RED)IT'S CLEAN\n$(NC)"

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	printf "$(RED)$(CLIENT) AND $(SERVER) REMOVED\n$(NC)"

re: fclean
	$(MAKE)

.PHONY: clean fclean re all FORCE 

.SILENT: 
