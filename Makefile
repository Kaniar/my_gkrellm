##
## Makefile for grkfdflflm in /home/kania_r/rendu/cpp_gkrellm
## 
## Made by Romain Kania
## Login   <kania_r@epitech.net>
## 
## Started on  Sat Jan 21 18:15:21 2017 Romain Kania
## Last update Sun Jan 22 09:42:20 2017 Benjamin Dubois
##

NAME	=	mygkrellm

SRCS	=	src/Box.cpp \
		src/ModuleCpu.cpp \
		src/ModuleName.cpp \
		src/text.cpp \
		src/ModuleOS.cpp \
		src/ModuleTime.cpp \
		src/ModuleRam.cpp \
		src/MonitorDisplay.cpp \
		src/sfml.cpp

OBJS	=	$(SRCS:.cpp=.o)

CXXFLAGS=	-W -Wall -Werror -Wextra -std=c++11 -lncurses -lsfml-graphics -lsfml-window -lsfml-system

all:		$(NAME)

$(NAME):	$(OBJS)
		g++ -o $(NAME) $(OBJS) $(CXXFLAGS)

clean:
		rm -rf *~
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
