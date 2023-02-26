#include <stdio.h>
#include "s21_math.h"
#include <math.h>

int main() {
    printf("%.18lf\n", log(10000000000000000000000000000000000.));
    printf("%.18Lf", s21_log(10000000000000000000000000000000000.));

    return 0;
}
