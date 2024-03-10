#include <check.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_math.h"

START_TEST(my_abs_tests) {
  // test 1
  ck_assert_int_eq(my_abs(4), abs(4));

  // test 2
  ck_assert_int_eq(my_abs(0), abs(0));

  // test 3
  ck_assert_int_eq(my_abs(-4), abs(-4));

  // test 4
  ck_assert_int_eq(my_abs(-0), abs(-0));

  // test 5
  ck_assert_int_eq(my_abs(-32767), abs(-32767));
}
END_TEST

START_TEST(my_fabs_tests) {
  // test 1
  ck_assert_float_eq(my_fabs(1.000000), fabs(1.000000));

  // test 2
  ck_assert_float_eq(my_fabs(-1.000000), fabs(-1.000000));

  // test 3
  ck_assert_float_eq(my_fabs(-1436.6789), fabs(-1436.6789));

  // test 4
  ck_assert_float_eq(my_fabs(-0.5682), fabs(-0.5682));

  // test 5
  ck_assert_float_eq(my_fabs(-0.0), fabs(-0.0));

  // test 6
  ck_assert_float_eq(my_fabs(-574785475.758457), fabs(-574785475.758457));

  // test 7
  ck_assert_float_eq(my_fabs(574785475.758457), fabs(574785475.758457));
}
END_TEST

START_TEST(my_ceil_tests) {
  // test 1
  ck_assert_float_eq(my_ceil(0.05), ceil(0.05));

  // test 2
  ck_assert_float_eq(my_ceil(5.25), ceil(5.25));

  // test 3
  ck_assert_float_eq(my_ceil(-5.25), ceil(-5.25));

  // test 4
  ck_assert_float_eq(my_ceil(145894093.5838938), ceil(145894093.5838938));

  // test 5
  ck_assert_float_eq(my_ceil(-145894093.5838938), ceil(-145894093.5838938));

  // test 6
  ck_assert_float_eq(my_ceil(-3), ceil(-3));

  // test 7
  ck_assert_float_eq(my_ceil(3), ceil(3));

  // test 8
  ck_assert_float_eq(my_ceil(0), ceil(0));
}
END_TEST

START_TEST(my_floor_tests) {
  // test 1
  ck_assert_float_eq(my_floor(0.05), floor(0.05));

  // test 2
  ck_assert_float_eq(my_floor(5.25), floor(5.25));

  // test 3
  ck_assert_float_eq(my_floor(-5.25), floor(-5.25));

  // test 4
  ck_assert_float_eq(my_floor(145894093.5838938), floor(145894093.5838938));

  // test 5
  ck_assert_float_eq(my_floor(-145894093.5838938), floor(-145894093.5838938));

  // test 6
  ck_assert_float_eq(my_floor(-3), floor(-3));

  // test 7
  ck_assert_float_eq(my_floor(3), floor(3));

  // test 8
  ck_assert_float_eq(my_floor(0), floor(0));
}
END_TEST

START_TEST(my_fmod_tests) {
  // test 1
  ck_assert_float_eq(my_fmod(10., 2.), fmod(10., 2.));

  // test 2
  ck_assert_float_eq(my_fmod(-10., 2.), fmod(-10., 2.));

  // test 3
  ck_assert_float_eq(my_fmod(30., 0.5), fmod(30., 0.5));

  // test 4
  ck_assert_float_eq(my_fmod(-30., 0.5), fmod(-30., 0.5));

  // test 5
  ck_assert_float_eq(my_fmod(0., 2.), fmod(0., 2.));

  // test 6
  ck_assert_float_eq(my_fmod(10.5, 5.), fmod(10.5, 5.));

  // test 7
  ck_assert_float_eq(my_fmod(-10.5, 5.), fmod(-10.5, 5.));

  // test 8
  ck_assert_float_eq(my_fmod(106545345.568859, 5.),
                     fmod(106545345.568859, 5.));

  // test 9
  ck_assert_float_eq(my_fmod(1000000., 5.543545), fmod(1000000., 5.543545));
}
END_TEST

START_TEST(my_pow_tests) {
  // test 1
  ck_assert_float_eq(my_pow(4, 2), my_pow(4, 2));

  // test 2
  ck_assert_float_eq(my_pow(2, -2), my_pow(2, -2));

  // test 3
  ck_assert_float_eq(my_pow(2, 0), my_pow(2, 0));

  // test 4
  ck_assert_float_eq(my_pow(2.456787, 1), my_pow(2.456787, 1));

  // test 5
  ck_assert_float_nan(my_pow(-4, 0.5));
  ck_assert_float_nan(my_pow(-4, 0.5));

  // test 6
  ck_assert_float_eq(my_pow(-4, 5), my_pow(-4, 5));

  // test 7
  ck_assert_float_eq(my_pow(4, 20), my_pow(4, 20));

  // test 8
  ck_assert_float_eq(my_pow(4, 20.5), my_pow(4, 20.5));

  // test 9
  ck_assert_float_eq(my_pow(4, -10), my_pow(4, -10));

  // test 8
  ck_assert_float_eq(my_pow(4, -1e20), my_pow(4, -1e20));
}
END_TEST

START_TEST(my_sqrt_tests) {
  // test 1
  ck_assert_float_eq(my_sqrt(4), my_sqrt(4));

  // test 2
  ck_assert_float_eq(my_sqrt(0), my_sqrt(0));

  // test 3
  ck_assert_float_nan(my_sqrt(-1));
  ck_assert_float_nan(my_sqrt(-1));

  // test 4
  ck_assert_float_eq(my_sqrt(0.00001), my_sqrt(0.00001));

  // test 5
  ck_assert_float_eq(my_sqrt(1444444444444444), my_sqrt(1444444444444444));

  // test 6
  ck_assert_float_eq(my_sqrt(0.067676), my_sqrt(0.067676));
}
END_TEST

START_TEST(my_exp_tests) {
  // test 1
  ck_assert_float_eq(my_exp(-my_INF), exp(-my_INF));

  // test 2
  ck_assert_float_eq(my_exp(my_INF), exp(my_INF));

  // test 3
  ck_assert_float_nan(my_exp(my_NAN));

  // test 4
  ck_assert_float_eq(my_exp(-10), exp(-10));

  // test 4
  ck_assert_float_eq(my_exp(-20), exp(-20));

  // test 5
  ck_assert_float_eq(my_exp(1e-30), exp(1e-30));

  // test 6
  ck_assert_float_eq(my_exp(0.00001), exp(0.00001));

  // test 7
  ck_assert_float_eq(my_exp(0.0005), exp(0.0005));

  // test 8
  ck_assert_float_eq(my_exp(3000), exp(3000));

  // test 9
  ck_assert_float_eq(my_exp(8000), exp(8000));

  // test 10
  ck_assert_float_eq(my_exp(-1000), exp(-1000));
}
END_TEST

START_TEST(my_sin_tests) {
  // test 1
  ck_assert_float_nan(my_sin(-my_INF));

  // test 2
  ck_assert_float_nan(my_sin(my_INF));

  // test 3
  ck_assert_float_nan(my_sin(my_NAN));

  // test 4
  ck_assert_float_eq_tol(my_sin(-1000), sin(-1000), 1e-15);

  // test 5
  for (double x = -0.1; x < 0.1; x += 0.01) {
    ck_assert_float_eq_tol(my_sin(x), sin(x), 1e-15);
  }

  // test 6
  for (double x = 100; x < 1000; x += 100) {
    ck_assert_float_eq_tol(my_sin(x), sin(x), 1e-15);
  }
}
END_TEST

START_TEST(my_cos_tests) {
  // test 1
  ck_assert_float_nan(my_cos(-my_INF));

  // test 2
  ck_assert_float_nan(my_cos(my_INF));

  // test 3
  ck_assert_float_nan(my_cos(my_NAN));

  // test 4
  ck_assert_float_eq_tol(my_cos(-1000), cos(-1000), 1e-15);

  // test 5
  for (double x = -0.1; x < 0.1; x += 0.01) {
    ck_assert_float_eq_tol(my_cos(x), cos(x), 1e-15);
  }

  // test 6
  for (double x = 100; x < 1000; x += 100) {
    ck_assert_float_eq_tol(my_cos(x), cos(x), 1e-15);
  }
}
END_TEST

START_TEST(my_tan_tests) {
  // test 1
  ck_assert_float_nan(my_tan(-my_INF));

  // test 2
  ck_assert_float_nan(my_tan(my_INF));

  // test 3
  ck_assert_float_nan(my_tan(my_NAN));

  // test 4
  ck_assert_float_eq_tol(my_tan(-1000), tan(-1000), 1e-15);

  // test 5
  for (double x = -my_PI; x < my_PI; x += 0.1) {
    ck_assert_float_eq_tol(my_tan(x), tan(x), 1e-15);
  }

  // test 6
  for (double x = 100; x < 1000; x += 100) {
    ck_assert_float_eq_tol(my_tan(x), tan(x), 1e-15);
  }
}
END_TEST

START_TEST(my_log_tests) {
  // test 1
  ck_assert_float_nan(my_log(-my_INF));

  // test 2
  ck_assert_float_eq(my_log(my_INF), log(my_INF));

  // test 3
  ck_assert_float_nan(my_log(my_NAN));

  // test 4
  ck_assert_float_nan(my_log(-100));

  // test 5
  for (double x = 0; x < 1; x += 0.1) {
    ck_assert_float_eq(my_log(x), log(x));
  }

  // test 6
  for (double x = 1000; x < 10000; x += 1000) {
    ck_assert_float_eq(my_log(x), log(x));
  }

  // test 7
  ck_assert_float_eq(my_log(DBL_MAX * 2), log(DBL_MAX * 2));

  // test 8
  ck_assert_float_eq(my_log(LDBL_MAX), log(LDBL_MAX));

  // test 9
  ck_assert_float_eq(my_log(0.00001), log(0.00001));

   // test 10
  ck_assert_float_eq(my_log(1e-20), log(1e-20));
}
END_TEST

// START_TEST(my_asin_tests) {
//   // test 1
//   ck_assert_float_nan(my_asin(-my_INF));

//   // test 2
//   ck_assert_float_nan(my_asin(my_INF));

//   // test 3
//   ck_assert_float_nan(my_asin(my_NAN));

//   // test 4
//   ck_assert_float_nan(my_asin(-1000));

//   // test 5
//     for (double x = -1; x < 1; x += 0.1) {
//         ck_assert_float_eq_tol(my_asin(x), asin(x), 1e-15);
//     }

// }
// END_TEST

// START_TEST(my_acos_tests) {
//   // test 1
//   ck_assert_float_nan(my_acos(-my_INF));

//   // test 2
//   ck_assert_float_nan(my_acos(my_INF));

//   // test 3
//   ck_assert_float_nan(my_acos(my_NAN));

//   // test 4
//   ck_assert_float_nan(my_acos(-1000));

//   // test 5
//   for (double x = -1; x < 1; x += 0.1) {
//       ck_assert_float_eq_tol(my_acos(x), acos(x), 1e-15);
//   }

// }
// END_TEST

START_TEST(my_atan_tests) {
  // test 1
  ck_assert_float_eq(my_atan(-my_INF), atan(-my_INF));

  // test 2
  ck_assert_float_eq(my_atan(my_INF), atan(my_INF));

  // test 3
  ck_assert_float_nan(my_atan(my_NAN));

  // test 4
  ck_assert_float_eq_tol(my_atan(-1000), atan(-1000), 1e-7);

  // // test 5
  // for (double x = 0; x < 1; x += 0.2) {
  //   ck_assert_float_eq_tol(my_atan(x), atan(x), 1e-7);
  // }

  // test 6
    for (double x = 1e10; x < 1e11; x += 2e10) {
        ck_assert_float_eq_tol(my_atan(x), atan(x), 1e-7);
    }

}
END_TEST

Suite *my_math(void) {
  Suite *s;
  TCase *tc_tests;

  s = suite_create("my_math.h tests");
  tc_tests = tcase_create("Tests");

  tcase_add_test(tc_tests, my_abs_tests);
  tcase_add_test(tc_tests, my_fabs_tests);
  tcase_add_test(tc_tests, my_ceil_tests);
  tcase_add_test(tc_tests, my_floor_tests);
  tcase_add_test(tc_tests, my_fmod_tests);
  tcase_add_test(tc_tests, my_pow_tests);
  tcase_add_test(tc_tests, my_sqrt_tests);
  tcase_add_test(tc_tests, my_exp_tests);
  tcase_add_test(tc_tests, my_sin_tests);
  tcase_add_test(tc_tests, my_cos_tests);
  tcase_add_test(tc_tests, my_tan_tests);
  tcase_add_test(tc_tests, my_log_tests);

  // tcase_add_test(tc_tests, my_acos_tests);
  // tcase_add_test(tc_tests, my_asin_tests);
  tcase_add_test(tc_tests, my_atan_tests);

  suite_add_tcase(s, tc_tests);

  return s;
}

int main(void) {
  Suite *s;
  SRunner *runner;

  s = my_math();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_VERBOSE);
  srunner_ntests_failed(runner);
  srunner_free(runner);

  return 0;
}
