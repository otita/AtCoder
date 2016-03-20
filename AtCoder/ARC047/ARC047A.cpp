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

int N, L;
string S;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  string buf;
  getline(in, buf, ' ');
  N = atoi(buf.c_str());
  getline(in, buf);
  L = atoi(buf.c_str());
  getline(in, S);
}

int main() {
  input();
  
  int tab = 1;
  int crash = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '+') {
      tab++;
      if (tab > L) {
        crash++;
        tab = 1;
      }
    }
    else {
      tab--;
    }
  }
  
  cout << crash << endl;
  
  return 0;
}