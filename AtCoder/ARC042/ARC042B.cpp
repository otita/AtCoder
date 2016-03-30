#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <cfloat>
#include <cmath>

#define XSTR(s) STR(s)
#define STR(s) #s

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

double x, y;
i32 N;
vector<double> xs, ys;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> x >> y >> N;
  xs.resize(N); ys.resize(N);
  for (i32 i = 0; i < N; i++) {
    in >> xs[i] >> ys[i];
  }
}

int main() {
  input();
  
  double ans = DBL_MAX;
  for (i32 i = 0; i < N; i++) {
    double x1, y1, x2, y2;
    x1 = xs[i]; y1 = ys[i];
    if (i + 1 < N) {
      x2 = xs[i + 1]; y2 = ys[i + 1];
    }
    else {
      x2 = xs[0]; y2 = ys[0];
    }
    double a, b, c;
    a = y1 - y2;
    b = x2 - x1;
    c = - a * x1 - b * y1;
    double d = abs(a * x + b * y + c) / sqrt(a * a + b * b);
    if (d < ans) {
      ans = d;
    }
  }
  printf("%.7lf\n", ans);
  
  return 0;
}