CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
LDFLAGS=$(shell pkg-config --cflags check --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage

all: my_math.a

my_math.a:
	$(CC) $(CFLAGS) -c my_math.c
	ar rc my_math.a *.o
	ranlib my_math.a

test:
	$(CC) $(CFLAGS) $(LDFLAGS) my_math.c tests.c -lm `pkg-config --cflags --libs check`

gcov_report:
	$(CC) $(CFLAGS) $(LDFLAGS) $(GCOVFLAGS) my_math.c tests.c -o gcov_main -lm `pkg-config --cflags --libs check`
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov*

style_check:
	clang-format -style=Google -n *.h
	clang-format -style=Google -n */*.c

cpk:
	cppcheck *.[h]
	cppcheck */*.[c]

rebuild: clean all