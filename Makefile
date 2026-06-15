# ########## COMPILER ##########
CC = gcc

# ########## FOLDERS ##########
EXCRS = problems
# TODO: Find a way to make it easier to add a new problem to the compilation pipeline!
MAIN = src
UNITTEST = unitTest
INCLUDES = -I$(MAIN) \
		   -I$(EXCRS) \
		   -I$(UNITTEST)

# ########## SOURCE FILES ##########
SRCS =	$(EXCRS)/0001/two-sum.c \
		$(EXCRS)/0009/palindrome-number.c \
		$(EXCRS)/0013/roman-to-integer.c \
		$(EXCRS)/0014/longestCommonPrefix.c \
		$(EXCRS)/0020/validParentheses.c \
		$(EXCRS)/0069/sqrt.c
CFILES = src/main.c $(SRCS) $(UNITTEST)/unitTest.c 

# ########## OBJECT FILES ##########
OBJS := $(CFILES:.c=.o)

# ########## APPLICATION NAME ##########
APP = main.exe

# ########## COMPILER FLAGS ##########
CFLAGS = -Wall \
		 -Wextra \
		 -O3 \
		 -std=c23 \
		 -lm \
		 $(INCLUDES)

# ##################################################################################################
.PHONY: all clean rebuild run test

all: $(APP)

$(APP): $(OBJS)
	@echo -e "\n\033[01;32mCreating the application...\033[00m"
#	TODO: Remove the hardcoded 'output.map'
	@$(CC) $(CFLAGS) $(^) -Xlinker -Map=output.map -o $(@)
	@ls $(@) -sh

%.o: %.c %.h
	@echo -e "\n\033[01;33mCompiling the source file: \033[01;32m$(<)\033[00m"
#	@$(CC) $(CFLAGS) $(<) -E > $(<).txt
	$(CC) $(CFLAGS) $(<) -c -o $(@) 
#	@echo "This is $(^:.c=.h)" # Maybe we can use this instead of the several includes (?)

clean:
	@echo -e "\033[01;31mRemoving files:"
#	TODO: Remove the hardcoded 'output.map'
	@rm -rfv $(OBJS) $(APP) output.map
	@echo -en "\033[00m"

run:
	@./$(APP)

rebuild: clean all

test: all run
