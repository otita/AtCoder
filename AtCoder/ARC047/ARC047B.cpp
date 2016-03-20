#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
vector<int> x, y;

int distance(int i, int j) {
  return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  string buf;
  getline(in, buf);
  N = atoi(buf.c_str());
  x.reserve(N); y.reserve(N);
  for (int i = 0; i < N; i++) {
    getline(in, buf, ' ');
    x.push_back(atoi(buf.c_str()));
    getline(in, buf);
    y.push_back(atoi(buf.c_str()));
  }
}

int main() {
  input();
  
  for (int i = 0; i < N; i++) {
    int t_x = x[i];
    int t_y = y[i];
    x[i] = t_x + t_y;
    y[i] = t_x - t_y;
  }
  
  int x_min = *min_element(x.begin(), x.end());
  int x_max = *max_element(x.begin(), x.end());
  int y_min = *min_element(y.begin(), y.end());
  int y_max = *max_element(y.begin(), y.end());
  int size = max(x_max - x_min, y_max - y_min);
  
  vector<int> p_x, p_y;
  p_x.push_back(x_max - size / 2);
  p_x.push_back(x_min + size / 2);
  p_y.push_back(y_max - size / 2);
  p_y.push_back(y_min + size / 2);
  
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < N; k++) {
        if (max(abs(x[k] - p_x[i]), abs(y[k] - p_y[j])) != size / 2) {
          goto next;
        }
      }
      cout << (p_x[i] + p_y[j]) / 2 << ' ' << (p_x[i] - p_y[j]) / 2 << endl;
      return 0;
      next:;
    }
  }
  
  return 0;
}