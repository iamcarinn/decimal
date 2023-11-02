#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --trace-children=yes --track-fds=yes --log-file=valgrind.log ./test
FUNCS = $(SOURCES:.c=.o)
SOURCES = funcs_veolashe/s21_from_int_to_decimal.c  funcs_veolashe/s21_from_float_to_decimal.c funcs_veolashe/veolashe_help.c \
funcs_veolashe/s21_from_decimal_to_int.c funcs_veolashe/s21_from_decimal_to_float.c \
funcs_burnette/s21_add.c funcs_burnette/s21_div.c funcs_burnette/s21_help_div.c funcs_burnette/s21_help.c funcs_burnette/s21_mul.c funcs_burnette/s21_sub.c \
funcs_letitiar/s21_help_funcs_letitiar.c funcs_letitiar/s21_is_equal.c funcs_letitiar/s21_is_greater_or_equal.c funcs_letitiar/s21_is_greater.c \
funcs_letitiar/s21_is_less_or_equal.c funcs_letitiar/s21_is_less.c funcs_letitiar/s21_is_not_equal.c \
funcs_nutmegha/s21_truncate.c funcs_nutmegha/s21_floor.c funcs_nutmegha/s21_round.c funcs_nutmegha/s21_negate.c funcs_nutmegha/s21_other_func.c
UNAME = $(shell uname -s)
FLAGS = 

ifeq ($(UNAME), Linux)
	FLAGS += -lcheck_pic -lm -lsubunit -lrt -lpthread
else
	FLAGS += -lcheck	
endif
CFLAGS = -Wall -Werror -Wextra -std=c11

all:  test

%.o:  %.c
		gcc -c $^ -o $@

s21_decimal.a: $(FUNCS)
		ar rc s21_decimal.a $^
		ranlib s21_decimal.a
		rm */*.o

test: 	clean s21_decimal.a
		gcc test.c s21_decimal.a $(FLAGS) $(CFLAGS) -o test
		rm -rf *.o
		./test

gcov_report: clean
		gcc -o test test.c  --coverage $(SOURCES) $(CFLAGS) $(FLAGS) -lcheck -lm
		./test
		lcov -t "a.out" -o test.info -c -d .
		genhtml -o report test.info
		rm *.gcda *.gcno
		open report/index.html


#test.c:
#		cat testcases/testcases_veolashe.c testcases/testcases_burnette.c testcases/testcases_letitiar.c testcases/testcases_nutmegha.c> testcases/testcases.c
#		checkmk testcases/testcases.c>test.c 


clean:  
	rm -fr *.o *.gcda *.gcno .*out *.info *.out *.png *.css report *.a test valgrind.log leaks.info
	rm -rf funcs_*/*.o

rebuild:
		clean
		all
