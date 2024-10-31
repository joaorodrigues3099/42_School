cmake_minimum_required(VERSION 3.13)  # CMake version check
project(42_School)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

add_executable(Libft Common_Core/Libft/libft/ft_atoi.c
        Common_Core/Libft/libft/ft_bzero.c
        Common_Core/Libft/libft/ft_calloc.c
        Common_Core/Libft/libft/ft_isalnum.c
        Common_Core/Libft/libft/ft_isalpha.c
        Common_Core/Libft/libft/ft_isascii.c
        Common_Core/Libft/libft/ft_isdigit.c
        Common_Core/Libft/libft/ft_isprint.c
        Common_Core/Libft/libft/ft_itoa.c
        Common_Core/Libft/libft/ft_lstadd_back_bonus.c
        Common_Core/Libft/libft/ft_lstadd_front_bonus.c
        Common_Core/Libft/libft/ft_lstclear_bonus.c
        Common_Core/Libft/libft/ft_lstdelone_bonus.c
        Common_Core/Libft/libft/ft_lstiter_bonus.c
        Common_Core/Libft/libft/ft_lstlast_bonus.c
        Common_Core/Libft/libft/ft_lstmap_bonus.c
        Common_Core/Libft/libft/ft_lstnew_bonus.c
        Common_Core/Libft/libft/ft_lstsize_bonus.c
        Common_Core/Libft/libft/ft_memchr.c
        Common_Core/Libft/libft/ft_memcmp.c
        Common_Core/Libft/libft/ft_memcpy.c
        Common_Core/Libft/libft/ft_memmove.c
        Common_Core/Libft/libft/ft_memset.c
        Common_Core/Libft/libft/ft_putchar_fd.c
        Common_Core/Libft/libft/ft_putendl_fd.c
        Common_Core/Libft/libft/ft_putnbr_fd.c
        Common_Core/Libft/libft/ft_putstr_fd.c
        Common_Core/Libft/libft/ft_split.c
        Common_Core/Libft/libft/ft_strchr.c
        Common_Core/Libft/libft/ft_strdup.c
        Common_Core/Libft/libft/ft_striteri.c
        Common_Core/Libft/libft/ft_strjoin.c
        Common_Core/Libft/libft/ft_strlcat.c
        Common_Core/Libft/libft/ft_strlcpy.c
        Common_Core/Libft/libft/ft_strlen.c
        Common_Core/Libft/libft/ft_strmapi.c
        Common_Core/Libft/libft/ft_strncmp.c
        Common_Core/Libft/libft/ft_strnstr.c
        Common_Core/Libft/libft/ft_strrchr.c
        Common_Core/Libft/libft/ft_strtrim.c
        Common_Core/Libft/libft/ft_substr.c
        Common_Core/Libft/libft/ft_tolower.c
        Common_Core/Libft/libft/ft_toupper.c
        Common_Core/Libft/libft/libft.h
        Common_Core/Libft/libft/Makefile)

add_executable(Printf
        Common_Core/Printf/ft_printf/ft_itoa.c
        Common_Core/Printf/ft_printf/ft_long_to_hex.c
        Common_Core/Printf/ft_printf/ft_print_chars.c
        Common_Core/Printf/ft_printf/ft_print_n_string.c
        Common_Core/Printf/ft_printf/ft_print_numbers.c
        Common_Core/Printf/ft_printf/ft_printf.c
        Common_Core/Printf/ft_printf/ft_printf.h
        Common_Core/Printf/ft_printf/ft_string_manipulation.c
        Common_Core/Printf/ft_printf/ft_utils.c
        Common_Core/Printf/ft_printf/Makefile
        Common_Core/Printf/ft_printf/ft_printf.c)

add_executable(Noob_Printf
        Common_Core/Printf/noob_ft_printf/ft_put_characters.c
        Common_Core/Printf/noob_ft_printf/ft_put_numbers.c
        Common_Core/Printf/noob_ft_printf/ft_printf.c
        Common_Core/Printf/noob_ft_printf/Makefile)
