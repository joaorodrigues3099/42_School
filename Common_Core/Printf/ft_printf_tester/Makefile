LIBFTPRINTF_DIR = ../
ERROR_LIMIT = 0

SHELL = /bin/sh

# Repeat test indices
TESTS = $(shell for ((i=1;i<=2000;i++)); do echo "$$i "; done)

NAME = tester
LIBTEST = libtest/libtest.a
LIBFTPRINTF = ${LIBFTPRINTF_DIR}/libftprintf.a
LIBFTPRINTF_BONUS = ${LIBFTPRINTF_DIR}/libftprintf_bonus.a

SRC_DIR = ./src
OBJ_DIR = ./obj

SRCS_FILES = main.c \
			 tests.c \
			 get_next_line.c \
			 get_next_line_utils.c \
			 utils.c

HEADERS_FILES = helpers.h
HEADERS = ${addprefix ${SRC_DIR}/, ${HEADERS_FILES}}

SRCS = ${addprefix ${SRC_DIR}/, ${SRCS_FILES}}

OBJS_FILES = ${SRCS_FILES:.c=.o}
OBJS = ${addprefix ${OBJ_DIR}/, ${OBJS_FILES}}

CFLAGS = -Wall -Wextra -g3

PRINTF_FLAGS = ${CFLAGS} -Werror

SANITIZE = -fsanitize=address

UNAME = ${shell uname -s}
ifeq (${UNAME}, Darwin)
	SRCS_FILES := ${SRCS_FILES} malloc_count.c 
endif

CC = clang ${CFLAGS}

export LSAN_OPTIONS=exitcode=30

all: ${NAME}
	@echo ""

nosan: SANITIZE :=
nosan: ${NAME}
	@echo ""

# Default build uses LIBFTPRINTF (base library)
${NAME}: ${LIBFTPRINTF} ${LIBTEST} ${HEADERS} ${OBJS}
	${CC} ${SANITIZE} -L./libtest -L${LIBFTPRINTF_DIR} ${OBJS} -o ${NAME} -ltest -lftprintf -ldl
	mkdir -p files

# Compile the base library
${LIBFTPRINTF}:
	make -C ${LIBFTPRINTF_DIR}

# Compile the bonus library
${LIBFTPRINTF_BONUS}:
	make -C ${LIBFTPRINTF_DIR} bonus

# Compile libtest
${LIBTEST}:
	make -C libtest CFLAGS="${CFLAGS}"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${HEADERS} Makefile
	${CC} -DERROR_LIMIT=${ERROR_LIMIT} -DBUFFER_SIZE=32 -c $< -o $@

# Run
r: run
run:
	./${NAME} 2>myleaks.txt

# Define bonus targets for both sanitized and non-sanitized builds
bonus: _bonus_sanitize ${NAME}

bonusnosan: SANITIZE :=
bonusnosan: _bonus_no_sanitize ${NAME}

# Compile bonus library with and without SANITIZE flag
_bonus_sanitize:
	make CFLAGS="${PRINTF_FLAGS}" -C ${LIBFTPRINTF_DIR} bonus

_bonus_no_sanitize:
	make CFLAGS="${PRINTF_FLAGS}" SANITIZE="" -C ${LIBFTPRINTF_DIR} bonus

# Update linker to use bonus library for bonus builds
${NAME}_bonus: ${LIBFTPRINTF_BONUS} ${LIBTEST} ${HEADERS} ${OBJS}
	${CC} ${SANITIZE} -L./libtest -L${LIBFTPRINTF_DIR} ${OBJS} -o ${NAME} -ltest -lftprintf_bonus -ldl

push:
	git add -A
	git commit -m "chore: automated commit"
	git push

clean:
	@echo cleaning...
	@make -C ./libtest clean
	make -C ${LIBFTPRINTF_DIR} clean
	@${RM} ${OBJS}

fclean: clean
	@make -C ./libtest fclean
	make -C ${LIBFTPRINTF_DIR} fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: ${NAME} ${LIBTEST} ${LIBFTPRINTF} bonus bonusnosan clean fclean re

