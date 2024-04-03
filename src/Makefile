CC = g++ -g -std=c++17
CFLAG = -c -Wall -Werror -Wextra
GCOVFLAG = -fprofile-arcs -ftest-coverage
GTESTFLAGS = -lgtest

all: clean s21_matrix_oop.a test

s21_matrix_oop.o:
	$(CC) $(CFLAG) s21_matrix_oop.cpp -o s21_matrix_oop.o

test.o:
	$(CC) $(CFLAG) test.cpp -o test.o

s21_matrix_oop.a: s21_matrix_oop.o
	ar rcs s21_matrix_oop.a s21_matrix_oop.o

test: clean s21_matrix_oop.a test.o
	$(CC) s21_matrix_oop.a test.o -o test $(GTESTFLAGS)
	./test

gcov_report: clean test.o
	$(CC) $(CFLAG) $(GCOVFLAG) s21_matrix_oop.cpp -o s21_matrix_oop.o
	$(CC) $(GCOVFLAG) s21_matrix_oop.o test.o -o gcov $(GTESTFLAGS)
	./gcov
	lcov -t "gcov_report" -o gcov_report.info -c -d ./
	genhtml -o report gcov_report.info
	open report/index-sort-f.html

clean:
	rm -rf *.a *.o test gcov *.info report *.dSYM *.gc* *.out

check: test
	clang-format -n *.cpp *.h -style=Google
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	cppcheck --enable=all --suppress=missingIncludeSystem *.cpp
	CK_FORK=no leaks --atExit -- test
	rm -rf CPPLINT.cfg
