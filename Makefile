##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Define Makefile's rules used to build libraries, binaries and unit tests
## Author: @lszsrd
##

# Defines compiler's flags, linker's flags and pre-processor macros
CFLAGS					+=	-Wall -Wextra -Wpedantic -Wundef -Wpointer-arith \
							-Wfloat-equal -Wcast-align -Wstrict-prototypes	 \
					 		-Waggregate-return -Wwrite-strings -Winit-self 	 \
							-Wlogical-not-parentheses -Waddress	-Wshadow	 \
							-fpic -iquote include -g
LDFLAGS					+=
CPPGLAGS				+=

# `ftsh` binary part
BINARY_FTSH				:=	ftsh
BINARY_FTSH_SOURCES		:=	$(shell find sources -name '*.c')
BINARY_FTSH_OBJECTS		:=	$(BINARY_FTSH_SOURCES:.c=.o)

# `unit_tests` tests part
TESTS_BINARY			:=	unit_tests
TESTS_SOURCES			:=	$(filter-out sources/ftsh/main.c,				 \
							$(shell find sources -name '*.c')				 \
							$(shell find tests/criterion -name '*.c'))
TESTS_FLAGS				:=  --coverage -L /opt/homebrew/lib -l criterion

# Builds libraries and binaries
all: $(BINARY_FTSH)

# Builds `BINARY_NAME` binary
$(BINARY_FTSH): $(BINARY_FTSH_OBJECTS)
	$(CC) -o $(BINARY_FTSH) $(BINARY_FTSH_OBJECTS) $(LDFLAGS)
	@printf "\e[1;42mSuccessfully built %s\e[0m\n" $(BINARY_FTSH)

# Build and runs unit tests
tests_run: libraries/$(LIB_LIST) libraries/$(LIB_STRTOARRAY)
	$(CC) $(CFLAGS) -o unit_tests $(TESTS_SOURCES) $(LDFLAGS) $(TESTS_FLAGS)
	@printf "\e[1;42mSuccessfully built binary unit_tests\e[0m\n"
	timeout 2m ./unit_tests
	gcovr -e tests -e sources/debug -e sources/ftsh/clear_ast

# Generate a compilation database for clang tooling
compile_flags: fclean
	@echo "-iquote\ninclude" > compile_flags.txt

# Delete junk and temporary files
clean:
	find . -name "*~" -delete -o -name "#*#" -delete -o -name "*.out" -delete
	find . -name "*.gc*" -delete -o -name "*.dSYM" -exec rm -r {} +

# Delete builds' files, binaries and libraries
fclean: clean
	$(RM) $(BINARY_FTSH) $(BINARY_FTSH_OBJECTS)
	$(RM) unit_tests

# Re-build everything needed for this project
re: fclean all

.PHONY: all clean fclean re
