CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c11
TEST_FLAGS = -lm -lcheck -lpthread
LDFLAGS =

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

TESTS_SRC = tests/
SRC_TEST = $(wildcard $(TESTS_SRC)*.c)
OBJ_TEST = $(patsubst $(TESTS_SRC)%.c, $(TESTS_SRC)%.o, $(SRC_TEST))

ifeq ($(shell uname), Darwin)
    CFLAGS += -I/opt/homebrew/include -Wno-deprecated-declarations
    LDFLAGS += -L/opt/homebrew/lib
else
    TEST_FLAGS += -lsubunit
endif

all: my_string.a

my_string.a: $(OBJ)
	@ar rc $@ $^
	@ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

tests.a: $(OBJ_TEST)
	@ar rc $(TESTS_SRC)$@ $^
	@ranlib $(TESTS_SRC)$@

coverage:
	$(CC) $(CFLAGS) --coverage -c $(SRC)
	ar rc my_string.a $(OBJ)
	ranlib my_string.a

test: clean coverage tests.a
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage -o $(TESTS_SRC)test $(OBJ_TEST) my_string.a $(TEST_FLAGS)
	$(TESTS_SRC)test

leaks: test
ifeq ($(shell uname -s), Linux)
	valgrind --leak-check=yes $(TESTS_SRC)/test
else
	leaks --atExit -- $(TESTS_SRC)/test
endif
	
clean:
	rm -rf *.o *.a $(TESTS_SRC)*.o $(TESTS_SRC)*.a
	rm -rf *.gcda *.gcno $(TESTS_SRC)*.gcda $(TESTS_SRC)*.gcno
	rm -rf $(TESTS_SRC)test
	rm -rf gcov_report my_string.info

rebuild: clean all

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c *.h  $(TESTS_SRC)*.c $(TESTS_SRC)*.h
	rm -rf .clang-format

gcov_report: test
	lcov -t "my_string" -o my_string.info -c -d .
	genhtml -o gcov_report my_string.info