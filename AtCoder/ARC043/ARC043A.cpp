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

i32 N, A, B;
vector<i32> S;
u64 sum = 0;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N >> A >> B;
  S = vector<i32>(N, 0);
  for (i32 i = 0; i < N; i++) {
    in >> S[i];
    sum += S[i];
  }
}

#if 0

P * Sum + Q * N = A * N
P * (max - min) = B

#endif

int main() {
  input();
  
  i32 min = *min_element(S.begin(), S.end());
  i32 max = *max_element(S.begin(), S.end());
  
  if (min == max) {
    cout << -1 << endl;
    return 0;
  }
  
  double P = double(B) / double(max - min);
  double ave = double(sum) / double(N);
  double Q = A - P * ave;
  
  printf("%.7lf %.7lf\n", P, Q);
  
  return 0;
}