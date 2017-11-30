# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claudiocabral <cabral1349@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 13:13:30 by claudioca         #+#    #+#              #
#    Updated: 2017/11/30 16:14:31 by claudioca        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT			:=	$(LIBFT_PATH)libft.a
LIBFT_FCLEAN := $(LIBFT)_fclean
LIBFT_CLEAN := $(LIBFT)_clean
LIBFT_INCLUDES 	:= $(LIBFT_PATH)includes
LIBFT_OBJ_DIR	:=	$(LIBFT_PATH)objs
LIBFT_OBJS	:=	$(LIBFT_OBJ_DIR)/ft_lstnew.o \
				$(LIBFT_OBJ_DIR)/ft_lstpush_back.o \
				$(LIBFT_OBJ_DIR)/ft_lstdelone.o \
				$(LIBFT_OBJ_DIR)/ft_lstdel.o \
				$(LIBFT_OBJ_DIR)/ft_lstadd.o \
				$(LIBFT_OBJ_DIR)/ft_lstiter.o \
				$(LIBFT_OBJ_DIR)/ft_lstmap.o \
				$(LIBFT_OBJ_DIR)/ft_atoi.o \
				$(LIBFT_OBJ_DIR)/ft_bzero.o \
				$(LIBFT_OBJ_DIR)/ft_puterror.o \
				$(LIBFT_OBJ_DIR)/ft_isalnum.o \
				$(LIBFT_OBJ_DIR)/ft_isalpha.o \
				$(LIBFT_OBJ_DIR)/ft_isascii.o \
				$(LIBFT_OBJ_DIR)/ft_isdigit.o \
				$(LIBFT_OBJ_DIR)/ft_isprint.o \
				$(LIBFT_OBJ_DIR)/ft_itoa.o \
				$(LIBFT_OBJ_DIR)/ft_max.o \
				$(LIBFT_OBJ_DIR)/ft_memalloc.o \
				$(LIBFT_OBJ_DIR)/ft_memccpy.o \
				$(LIBFT_OBJ_DIR)/ft_memchr.o \
				$(LIBFT_OBJ_DIR)/ft_memcmp.o \
				$(LIBFT_OBJ_DIR)/ft_memcpy.o \
				$(LIBFT_OBJ_DIR)/ft_memdel.o \
				$(LIBFT_OBJ_DIR)/ft_memmove.o \
				$(LIBFT_OBJ_DIR)/ft_memset.o \
				$(LIBFT_OBJ_DIR)/ft_putchar.o \
				$(LIBFT_OBJ_DIR)/ft_putchar_fd.o \
				$(LIBFT_OBJ_DIR)/ft_putendl.o \
				$(LIBFT_OBJ_DIR)/ft_putendl_fd.o \
				$(LIBFT_OBJ_DIR)/ft_putnbr_base.o \
				$(LIBFT_OBJ_DIR)/ft_putnbr.o \
				$(LIBFT_OBJ_DIR)/ft_putnbr_fd.o \
				$(LIBFT_OBJ_DIR)/ft_putstr.o \
				$(LIBFT_OBJ_DIR)/ft_putstr_fd.o \
				$(LIBFT_OBJ_DIR)/ft_realloc.o \
				$(LIBFT_OBJ_DIR)/ft_strcapitalize.o \
				$(LIBFT_OBJ_DIR)/ft_strcat.o \
				$(LIBFT_OBJ_DIR)/ft_strchr.o \
				$(LIBFT_OBJ_DIR)/ft_strclr.o \
				$(LIBFT_OBJ_DIR)/ft_strcmp.o \
				$(LIBFT_OBJ_DIR)/ft_strcpy.o \
				$(LIBFT_OBJ_DIR)/ft_strdel.o \
				$(LIBFT_OBJ_DIR)/ft_strdup.o \
				$(LIBFT_OBJ_DIR)/ft_strequ.o \
				$(LIBFT_OBJ_DIR)/ft_striter.o \
				$(LIBFT_OBJ_DIR)/ft_striteri.o \
				$(LIBFT_OBJ_DIR)/ft_strjoin.o \
				$(LIBFT_OBJ_DIR)/ft_strlcat.o \
				$(LIBFT_OBJ_DIR)/ft_strlcpy.o \
				$(LIBFT_OBJ_DIR)/ft_strlen.o \
				$(LIBFT_OBJ_DIR)/ft_strlowcase.o \
				$(LIBFT_OBJ_DIR)/ft_strmap.o \
				$(LIBFT_OBJ_DIR)/ft_strmapi.o \
				$(LIBFT_OBJ_DIR)/ft_strncat.o \
				$(LIBFT_OBJ_DIR)/ft_strncmp.o \
				$(LIBFT_OBJ_DIR)/ft_strncpy.o \
				$(LIBFT_OBJ_DIR)/ft_strnequ.o \
				$(LIBFT_OBJ_DIR)/ft_strnew.o \
				$(LIBFT_OBJ_DIR)/ft_strnstr.o \
				$(LIBFT_OBJ_DIR)/ft_strrchr.o \
				$(LIBFT_OBJ_DIR)/ft_strsplit.o \
				$(LIBFT_OBJ_DIR)/ft_strstr.o \
				$(LIBFT_OBJ_DIR)/ft_strsub.o \
				$(LIBFT_OBJ_DIR)/ft_strtrim.o \
				$(LIBFT_OBJ_DIR)/ft_strupcase.o \
				$(LIBFT_OBJ_DIR)/ft_swap.o \
				$(LIBFT_OBJ_DIR)/ft_quicksort.o \
				$(LIBFT_OBJ_DIR)/ft_tolower.o \
				$(LIBFT_OBJ_DIR)/ft_toupper.o \
				$(LIBFT_OBJ_DIR)/ft_nbr_digits.o

LIBFT_BTREE_OBJS := \
				$(LIBFT_OBJ_DIR)/btree/btree_apply.o \
				$(LIBFT_OBJ_DIR)/btree/btree_apply_by_level.o \
				$(LIBFT_OBJ_DIR)/btree/btree_create_node.o \
				$(LIBFT_OBJ_DIR)/btree/btree_insert_data.o \
				$(LIBFT_OBJ_DIR)/btree/btree_search_item.o

LIBFT_ARRAY_OBJS := \
				$(LIBFT_OBJ_DIR)/array/array.o
