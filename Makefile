# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 14:04:31 by sunhkim           #+#    #+#              #
#    Updated: 2022/09/22 15:27:32 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_containers_test

SRCS			= ./tests/main.cpp \
					./tests/ft_test.cpp \
					./tests/vector_test.cpp \
					./tests/vector/v_t_1.cpp \
					./tests/vector/v_t_2.cpp \
					./tests/vector/v_t_3.cpp \
					./tests/vector/v_t_4.cpp\
					./tests/stack_test.cpp \
					./tests/stack/s_t_1.cpp \
					./tests/stack/s_t_2.cpp \
					./tests/map_test.cpp \
					./tests/map/m_t_1.cpp \
					./tests/map/m_t_2.cpp \
					./tests/map/m_t_3.cpp \
					./tests/map/m_t_4.cpp 
OBJS			= $(SRCS:.cpp=.o)

INCS			= ./tests/test.hpp

CXX				= clang++
CXXFLAGS		= -Wall -Wextra -Werror --std=c++98

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -I $(INCS) -o $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re