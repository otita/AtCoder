#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <climits>

#define XSTR(s) STR(s)
#define STR(s) #s

using namespace std;

#define MOD 1000000007

uint64_t modmult(uint64_t a, uint64_t b, uint64_t d) {
  if (a >= d) {
    a %= d;
  }
  if (b >= d) {
    b %= d;
  }
  uint64_t res;
  if (a >= d / b) {
    uint64_t upper = a >> 16;
    uint64_t lower = a & 0xFFFF;
    uint64_t x = ((b * upper) % d) << 16;
    uint64_t y = b * lower;
    res = (x + y) % d;
  }
  else {
    res = a * b;
  }
  return res;
}

uint64_t modpow(uint64_t a, uint64_t b, uint64_t d) {
  uint64_t res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % d;
    }
    a = a * a % d;
    b >>= 1;
  }
  return res;
}

int N;
vector<uint64_t> B;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N;
  B = vector<uint64_t>(N, 0);
  for (int i = 0; i < N; i++) {
    in >> B[i];
  }
}

int main() {
  input();

  vector<uint64_t> A(N, 0);
  for (int i = 0; i < N; i++) {
    A[B[i]]++;
  }
  
  if (B[0] != 0 || A[0] != 1) {
    cout << 0 << endl;
    return 0;
  }
  uint64_t count = 1;
  uint64_t sum = 1;
  uint64_t comb = 0;
  for (int i = 1; i < N && A[i]; i++) {
    sum += A[i];
    uint64_t t = modpow(modpow(2, A[i - 1], MOD) - 1, A[i], MOD);
    comb += A[i] * (A[i] - 1) / 2;
    count = modmult(count, t, MOD);
    if (count >= MOD) {
      count %= MOD;
    }
  }
  if (sum != N) {
    count = 0;
  }
  else {
    count = modmult(count, modpow(2, comb, MOD), MOD);
  }
  cout << count << endl;
  return 0;
}