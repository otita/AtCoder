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

i32 N, M;
vector<i32> a;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N >> M;
  a.resize(M);
  for (i32 i = 0; i < M; i++) {
    in >> a[i];
  }
}

int main() {
  input();
  
  vector<bool> b(N, true);
  vector<i32> c(N, 0);
  i32 idx = 0;
  for (i32 i = M - 1; i >= 0; i--) {
    if (b[a[i] - 1]) {
      b[a[i] - 1] = false;
      c[idx++] = a[i];
    }
  }
  
  for (i32 i = 0; i < N; i++) {
    if (b[i]) {
      c[idx++] = i + 1;
    }
  }

  for (i32 i = 0; i < N; i++) {
    cout << c[i] << endl;
  }
  
  return 0;
}