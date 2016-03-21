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

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

#define MOD 1000000007

// (a * b) % d
u32 modmult(u32 a, u32 b, u32 d) {
  if (a >= d) {
    a %= d;
  }
  if (b >= d) {
    b %= d;
  }
  u64 res;
  if (a >= d / b) {
    u64 upper = a >> 16;
    u64 lower = a & 0xFFFF;
    u64 x = ((b * upper) % d) << 16;
    u64 y = b * lower;
    res = (x + y) % d;
  }
  else {
    res = a * b;
  }
  return u32(res);
}

// (a ^ b) % d
u32 modpow(u32 a, u32 b, u32 d) {
  u64 res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % d;
    }
    a *= a % d;
    b >>= 1;
  }
  return u32(res);
}

u32 N;
vector<u32> D;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N;
  D = vector<u32>(N, 0);
  for (u32 i = 0; i < N; i++) {
    in >> D[i];
  }
}

bool find(u32 i, u32 l, u32 *next) {
  u32 p = D[i] << 1;
  if (D.back() < p) {
    return false;
  }
  u32 r = N - 1;
  while (l <= r) {
    u32 c = (l + r) >> 1;
    if (D[c - 1] < p && D[c] >= p) {
      *next = c;
      break;
    }
    else if (D[c - 1] >= p) {
      r = c - 1;
    }
    else {
      l = c + 1;
    }
  }
  return true;
}

int main() {
  input();

  sort(D.begin(), D.end());

  vector<u32> next(N, 0);
  u32 c = 1;
  for (u32 i = 0; i < N; i++) {
    u32 n;
    if (find(i, c, &n)) {
      next[i] = n;
      c = n;
    }
    else {
      next[i] = N;
    }
  }

  u32 ans = 0;

  cout << ans << endl;
  
  return 0;
}