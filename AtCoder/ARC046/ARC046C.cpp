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

int N, M;
vector<int> A, B, C, D;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N >> M;
  A.reserve(N); B.reserve(N);
  C.reserve(M); C.reserve(M);
  for (int i = 0; i < N; i++) {
    int a, b;
    in >> a >> b;
    A.push_back(a); B.push_back(b);
  }
  for (int i = 0; i < M; i++) {
    int c, d;
    in >> c >> d;
    C.push_back(c); D.push_back(d);
  }
}

int main() {
  input();
  
  return 0;
}