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

int N, A, B;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N >> A >> B;
}

int main() {
  input();
  
  string winner;
  if (A == B) {
    if (N % (A + 1)) {
      winner = "Takahashi";
    }
    else {
      winner = "Aoki";
    }
  }
  else {
    if (A > B) {
      winner = "Takahashi";
    }
    else {
      if (A >= N) {
        winner = "Takahashi";
      }
      else {
        winner = "Aoki";
      }
    }
  }
  
  cout << winner << endl;

  return 0;
}