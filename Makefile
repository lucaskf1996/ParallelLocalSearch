COMPILER=g++
NAME=sequential

main:$(NAME).cpp
	$(COMPILER) -o $(NAME) $(NAME).cpp
