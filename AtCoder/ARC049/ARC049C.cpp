#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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

int N, A, B;
vector<int> x, y, u, v;
void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N >> A;
  x.reserve(A); y.reserve(A);
  for (int i = 0; i < A; i++) {
    int t_x, t_y;
    in >> t_x >> t_y;
    x.push_back(t_x - 1);
    y.push_back(t_y - 1);
  }
  in >> B;
  u.reserve(B); v.reserve(B);
  for (int i = 0; i < B; i++) {
    int t_u, t_v;
    in >> t_u >> t_v;
    u.push_back(t_u - 1);
    v.push_back(t_v - 1);
  }
}

bool priority(const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> > &p2) {
  
}

int main() {
  input();
  
  priority_queue<pair<int, pair<int, int> > > queue;
  
  return 0;
}