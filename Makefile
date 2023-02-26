# add module names here
TARGETS+=s21_sin
TARGETS+=s21_log
TARGETS+=s21_exp
TARGETS+=s21_floor
TARGETS+=s21_ceil
TARGETS+=s21_sqrt
TARGETS+=s21_cos
TARGETS+=s21_tan
TARGETS+=s21_atan
TARGETS+=s21_pow_int
TARGETS+=s21_fabs
TARGETS+=s21_asin
TARGETS+=s21_acos
TARGETS+=s21_pow
TARGETS+=s21_abs
TARGETS+=s21_fmod
##############   DO NOT CHANGE BELOW   #############################
CFLAGS=-Wall -Werror -Wextra -std=c11
COMMON_SRC=common/common.c
TEST_SRC=unit_tests/s21_math_unit_tests.c
BUILD_DIR=build/
TARGETS_SRC=$(foreach tgt, $(TARGETS), $(addsuffix .c, $(tgt)/$(tgt)))
TARGETS_TESTS_SRC=$(addprefix unit_tests/, $(addsuffix _test.c, $(foreach tgt, $(TARGETS), $(tgt)/$(tgt))))
TARGETS_OUTPUT=$(addprefix $(BUILD_DIR), $(TARGETS_SRC:.c=.o))
TARGETS_TESTS_OUTPUT=$(addprefix $(BUILD_DIR), $(TARGETS_TESTS_SRC:.c=.o))
LIBS=-lcheck

all: s21_math.a

s21_math.a: $(TARGETS_SRC:.c=.o) $(COMMON_SRC:.c=.o)
	ar rc $@ $(TARGETS_OUTPUT) $(BUILD_DIR)$(COMMON_SRC:.c=.o)
	ranlib $@

test: s21_math.a $(TARGETS_TESTS_SRC:.c=.o)
	gcc $(CFLAGS) $(LIBS) s21_math.a $(TEST_SRC) $(TARGETS_TESTS_OUTPUT) -o s21_math_test

test_debug: CFLAGS += -g
test_debug: s21_math.a debug.c
	gcc $(CFLAGS) s21_math.a debug.c -o debug

leaks_test: CFLAGS += -fsanitize=address -g
leaks_test: test

gcov_report: CFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	./s21_math_test
	lcov -t "report" -o report.info -c -d .
	genhtml -o "html_report" report.info
	open html_report/index.html

%.o: %.c
	mkdir -p $(BUILD_DIR)$(@D)
	gcc $(CFLAGS) -c $< -o $(BUILD_DIR)$@

clean:
	-rm libs21_math.a
	-rm s21_math_test
	-rm -rf $(BUILD_DIR)
	-rm s21_math_unit_tests.gcda
	-rm s21_math_unit_tests.gcno
	-rm -rf s21_math_test.dSYM
	-rm debug
	-rm -rf html_report
	-rm report.info
	-rm debug.dSYM