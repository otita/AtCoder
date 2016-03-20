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

int N;
vector<int> L;
int l_min;

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

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  string buf;
  getline(in, buf);
  N = atoi(buf.c_str());
  L.reserve(N);
  l_min = INT_MAX;
  for (int i = 0; i < N; i++) {
    getline(in, buf);
    int l = atoi(buf.c_str());
    L.push_back(l);
    if (l_min > l) {
      l_min = l;
    }
  }
}

int main() {
  input();

  int cycle = L[0] - l_min;
  for (int i = 1; i < N; i++) {
    int diff = L[i] - l_min;
    cycle = cycle ? diff ? gcd(cycle, diff) : cycle : diff;
  }

  int pow = l_min + (cycle + 1) / 2;
  
  cout << modpow(2, pow, MOD) << endl;
  
  return 0;
}