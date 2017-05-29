##
## Makefile for ok in /home/alexandre/Documents/lib/my_lib/
##
## Made by Alexandre Chamard-bois
## Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
##
## Started on  Fri Apr  7 15:45:41 2017 Alexandre Chamard-bois
## Last update Thu May  4 11:19:30 2017 Alexandre Chamard-bois
##

include ./include/depend.mk

SRC	=				test.c									\

CFLAGS			+=	-I./include

LDFLAGS			=	-L./lib/ -lmy

_OBJ    		=	$(SRC:.c=.o)

OBJ					=	$(patsubst %,$(ODIR)/%,$(_OBJ))

LIB					=	@ make -C ./lib/

NAME				=	ai

all		: mkobj $(NAME)

$(ODIR)/%.o	:	$(SDIR)/%.c
	@ $(CC) $(CFLAGS)	-c -o $@ $<
	@ echo $<

mkobj		:
	@ ./tools/verif_odir

verifodir		:
		@ ./tools/verif_odir

p_flags		:
	@ echo "FLAGS:" $(CYAN) $(CFLAGS) $(WHITE)

success		:
	@ echo $(GREEN) "[success]" $(WHITE)

$(NAME)		:	$(OBJ)
						@ $(LIB)
						@ $(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean		: verifodir
	@ echo -n "nb obj removed: "
	@ echo -en  $(RED)
	@ ls $(ODIR) | wc -w
	@ echo -en $(WHITE)
	@ rm -rf $(ODIR)

fclean		:	clean
	@ echo "removed:"
	@ echo -e $(RED) '\t-' $(NAME) $(WHITE)
	@ rm -f $(NAME)
	@ $(LIB) fclean

re		:	fclean all
