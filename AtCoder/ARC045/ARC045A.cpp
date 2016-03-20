#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <climits>
#include <sstream>

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

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  string buf;
  bool first = true;
  while (in >> buf) {
    if (!first) {
      cout << ' ';
    }
    else {
      first = false;
    }
    if (buf == "Left") {
      cout << '<';
    }
    else if (buf == "Right") {
      cout << '>';
    }
    else {
      cout << 'A';
    }
  }
  cout << endl;
}

int main() {
  input();
  
  return 0;
}