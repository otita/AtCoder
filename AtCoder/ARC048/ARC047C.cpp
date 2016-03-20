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

int N, K;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N >> K;
}

int main() {
  input();

  vector<int> flags(N, 0);
  int top = (N + K - 1) / K;
  flags[top - 1] = 1;
  
  return 0;
}