NAME		:=phonebook

CXX			:=c++
STD			:=-std=c++20
WFLAGS		:=-Wall -Wextra -Werror -Wpedantic -Wunreachable-code -Wshadow \
			-Wnull-dereference -Wfloat-equal -Wcast-align -Wformat=2 \
			-Wswitch-enum -Wundef -Wconversion -Wsign-conversion
CXX_WFLAGS	:=-Wold-style-cast

DEFS		:=
DFLAGS		:=
OPTS		:=-O2 -DNDEBUG
LDFLAGS		:=

CXXFLAGS	:=$(STD) $(WFLAGS) $(CXX_WFLAGS) $(DEFS) $(OPTS)
ifeq ($(MAKELEVEL),0)
	MAKEFLAGS	+= --no-print-directory -j$(shell nproc 2>/dev/null || echo 4)
endif

DIR_INC		:=inc/
DIR_SRC		:=src/
DIR_LIB		:=lib/
DIR_OBJ		:=obj/
DIR_DEP		:=dep/
DIR_UTILS	:=utils/

INCS		:=$(addprefix -I, $(DIR_INC) $(DIR_INC)$(DIR_UTILS))
SRCS		:=$(addprefix $(DIR_SRC), phonebook.cpp contact.cpp main.cpp)
SRCS		+=$(addprefix $(DIR_SRC)$(DIR_UTILS), io.cpp)
OBJS		:=$(patsubst $(DIR_SRC)%.cpp, $(DIR_OBJ)%.o, $(SRCS))
DEPS		:=$(patsubst $(DIR_OBJ)%.o, $(DIR_DEP)%.d, $(OBJS))

BLUE		:=\033[1;34m
YELLOW		:=\033[1;33m
GREEN		:=\033[1;32m
RED			:=\033[1;31m
COLOR		:=\033[0m


all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)
	@$(call output)

$(DIR_OBJ)%.o: $(DIR_SRC)%.cpp
	@mkdir -p $(dir $@) $(patsubst $(DIR_OBJ)%, $(DIR_DEP)%, $(dir $@))
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD -MP -MF $(patsubst $(DIR_OBJ)%.o, $(DIR_DEP)%.d, $@) $(INCS)
	@echo "$(GREEN) [+]$(COLOR) compiling $@"

clean:
	@$(call rm_dir,$(DIR_OBJ))

fclean: clean
	@$(call rm_dir,$(DIR_LIB))
	@$(call rm_dir,$(DIR_DEP))
	@$(call rm_file,$(NAME))

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS) $(DEPS)

-include $(DEPS)

define rm_dir
	@if [ -d "$(1)" ]; then \
		rm -rf $(1); \
		echo "$(RED) [-]$(COLOR) removed $(1)"; \
	fi
endef

define rm_file
	@if [ -e "$(1)" ]; then \
		rm -f $(1); \
		echo "$(RED) [-]$(COLOR) removed $(1)"; \
	fi
endef

define output
	echo "$(YELLOW) [✔] $(NAME) created$(COLOR)"
	echo "$(GREEN) [/] usage: $(YELLOW)./$(NAME)$(COLOR)";
endef
