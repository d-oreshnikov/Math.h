#include "my_math.h"
#include <float.h>

// Abs, fabs, ceil, floor, fmod functions
int my_abs(int x) { return (x > 0) ? x : -x; }

long double my_fabs(double x) { return (x > 0) ? x : -x; }

long double my_ceil(double x) {
  return ((x - (int)x) && x > 0.) ? (long double)((int)x + 1)
                                  : (long double)(int)x;
}

long double my_floor(double x) {
  return ((x - (int)x) && x < 0.) ? (long double)((int)x - 1)
                                  : (long double)(int)x;
}

long double my_fmod(double x, double y) {
  long double res = my_fabs(x);
  y = my_fabs(y);
  int i = 1;
  while (res >= y) {
    res = my_fabs(x) - y * i;
    i++;
  }
  return x < 0 ? -res : res;
}

// Pow and sqrt functions

long double my_pow(double base, double ex) {
  long double ans = 0.0;
  if (ex == (int)ex) {
    if (ex < 0) {
      base = 1 / base;
      ex = -ex;
    }
    ans = 1.;
    for (int i = 0; i < ex; i++) {
      ans *= base;
    }
  } else {
    ans = my_exp(ex * my_log(base));
  }
  return ans;
}

long double my_sqrt(double x) { return my_pow(x, 0.5); }

// Exp sin cos tan log and factorial functions

long double my_factorial(int n) {
  long double res = 0.;
  if (n == 0 || n == 1) {
    res = 1.;
  } else if (n > 1) {
    res = n * my_factorial(n - 1);
  }
  return (res);
}

long double my_exp(double x) {
  long double res = 0.L;
  int is_x_negative = 0;
  if (x > DBL_MAX) {
    res = my_INF;
  } else if (x < -DBL_MAX) {
    res = 0;
  } else {
    if (x < 0) {
      is_x_negative = 1;
      x = -x;
    }
    for (int i = 0; i < 500; i += 1) {
      res += my_pow(x, i) / my_factorial(i);
    }
    if (is_x_negative) {
      res = 1 / res;
    }
    if (res > DBL_MAX) {
      res = my_INF;
    }
  }
  return res;
}

long double my_cos(double x) {
  long double res;
  res = 0.L;
  if (my_fabs(x) > DBL_MAX || x != x) {
    res = my_NAN;
  } else {
    x = my_fmod(x, 2 * my_PI);
    for (int i = 0; i < 500; i += 1) {
      res += my_pow(-1, i) * my_pow(x, 2 * i) / my_factorial(2 * i);
    }
  }
  return res;
}

long double my_sin(double x) {
  long double res;
  res = 0.L;
  if (my_fabs(x) > DBL_MAX || x != x) {
    res = my_NAN;
  } else {
    x = my_fmod(x, 2 * my_PI);
    for (int i = 0; i < 500; i += 1) {
      res += my_pow(-1, i) * my_pow(x, 2 * i + 1) / my_factorial(2 * i + 1);
    }
  }
  return res;
}

long double my_tan(double x) {
  long double res;
  res = 0.L;
  if (my_fabs(x) > DBL_MAX || x != x) {
    res = my_NAN;
  } else {
    x = my_fmod(x, 2 * my_PI);
    long double cosx = my_cos(x);
    if (my_fabs(cosx) >= LDBL_MIN) {
      res = my_sin(x) / cosx;
    } else {
      res = my_NAN;
    }
  }
  return res;
}

long double my_log(double x) {
  long double res;
  int is_small = 0;
  res = 0.L;
  if (x < 0 || x != x) {
    res = my_NAN;
  } else if (x > DBL_MAX) {
    res = my_INF;
  } else if (x < DBL_MIN) {
    res = -my_INF;
  } else {
    long double tmp = 0.;
    if (x < 0.01) {
      x = 1 / x;
      is_small = 1;
    }
    while (x > my_E) {
      x = x / my_E;
      tmp += 1.;
    }
    long double y = (x - 1) / (x + 1);
    for (int i = 0; i < 2000; i += 1) {
      res += my_pow(y, 2 * i) / (2 * i + 1);
    }
    res = res * 2 * y;
    res += tmp;
    if (is_small) {
      res = - res;
    }
  }
  return res;
}
long double my_asin(double x) {
  long double res = 0;
  /*
  Base worкable range
  */
  if ((x > -1) && (x < 1) && (x != my_NAN)) {
    res = my_atan(x / my_sqrt(1 - x * x));
  }
  /*
  Special cases
  */
  if ((x < -1) || (x > 1)) {
    res = my_NAN;
  }
  if (x != x) {
    res = my_NAN;
  }
  if (x == (-1)) {
    res = -my_PI / 2;
  }
  if (x == 1) {
    res = my_PI / 2;
  }
  return (res);
}
long double my_acos(double x) {
  long double res = 0;
  /*
  Base worкable range
  */
  if ((x > 0) && (x < 1) && (x != my_NAN)) {
    res = my_atan(my_sqrt(1 - x * x) / x);
  }
  if ((x > -1) && (x < 0) && (x != my_NAN)) {
    res = my_PI + my_atan(my_sqrt(1 - x * x) / x);
  }
  /*
  Special cases
  */
  if (x != x) {
    res = my_NAN;
  }
  if (x < -1 || x > 1) {
    res = my_NAN;
  }
  if ((x) == (-1)) {
    res = my_PI;
  }
  if ((x) == 1) {
    res = 0;
  }
  return (res);
}
long double my_atan(double x) {
  long double res = 0;
  /*
  Base worкable range
  */
  if ((x > -1) && (x < 1) && (x != my_NAN)) {
    for (int i = 0; i < 5000; i++) {
      res += my_pow(-1, i) * my_pow(x, (1 + 2 * i)) / (1 + 2 * i);
    }
  }
  if ((x < -1) || (x > 1)) {
    for (int i = 0; i < 7000; i++) {
      res += my_pow(-1, i) * my_pow(x, (-1 - 2 * i)) / (1 + 2 * i);
    }
    res = my_PI * my_sqrt(x * x) / (2 * x) - res;
  }
  /*
  Special cases
  */
  if ((x) == (-1)) {
    res = -my_PI / 4;
  }
  if ((x) == 1) {
    res = my_PI / 4;
  }
  if (x != x) {
    res = my_NAN;
  }
  if ((x) == (-my_INF)) {
    res = -my_PI / 2;
  }
  if ((x) == my_INF) {
    res = my_PI / 2;
  }
  return (res);
}
