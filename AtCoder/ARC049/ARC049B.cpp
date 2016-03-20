#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstdlib>
#include <climits>

#define XSTR(s) STR(s)
#define STR(s) #s

#define MOD 1000000007

using namespace std;

int modpow(long a, int b, int d) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % d;
    }
    a = a * a % d;
    b >>= 1;
  }
  return res;
}

int gcd(int a, int b) {
  int r = max(a, b) % min(a, b);
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return min(a, b);
}

int N;
vector<pair<pair<int, int>, int> > data;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N;
  data.reserve(N);
  for (int i = 0; i < N; i++) {
    int t_x, t_y, t_c;
    in >> t_x >> t_y >> t_c;
    data.push_back(make_pair(make_pair(t_x, t_y), t_c));
  }
}

int main() {
  input();
  
  double l = 0;
  double r = 1000000000;
  double t = 0;
  while (r - l >= 0.0001) {
    double rect[4] = {INT_MIN, INT_MAX, INT_MIN, INT_MAX};
    t = (l + r) / 2;
    for (int i = 0; i < N; i++) {
      double min_x = data[i].first.first - t / data[i].second;
      double max_x = data[i].first.first + t / data[i].second;
      double min_y = data[i].first.second - t / data[i].second;
      double max_y = data[i].first.second + t / data[i].second;
      rect[0] = max(min_x, rect[0]);
      rect[1] = min(max_x, rect[1]);
      rect[2] = max(min_y, rect[2]);
      rect[3] = min(max_y, rect[3]);
      if (rect[0] > rect[1] || rect[2] > rect[3]) {
        break;
      }
    }
    if (rect[0] > rect[1] || rect[2] > rect[3]) {
      l = t;
    }
    else {
      r = t;
    }
  }
  cout << t << endl;
  return 0;
}