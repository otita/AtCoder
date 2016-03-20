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

string S;
int A, B, C, D;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  getline(in, S);
  in >> A >> B >> C >> D;
}

int main() {
  input();
  
  string answer;
  
  int numbers[4] = {A, B, C, D};
  for (int i = 0; i < 4; i++) {
    int from = i ? numbers[i - 1] : 0;
    answer += S.substr(from, numbers[i] - from);
    answer += '"';
  }
  answer += S.substr(numbers[3]);
  cout << answer << endl;
  return 0;
}