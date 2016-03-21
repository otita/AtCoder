#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <climits>

#define XSTR(s) STR(s)
#define STR(s) #s

using namespace std;

int N;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N;
}

bool prime(int n) {
  if (n == 1) {
    return false;
  }
  else if (n == 2) {
    return true;
  }
  else if (!(n & 1)) {
    return false;
  }
  for (int i = 3; i <= n / i; i += 2) {
    if (!(n % i)) {
      return false;
    }
  }
  return true;
}

bool like_prime(int n) {
  if (n == 1) {
    return false;
  }
  int d = n % 10;
  if ((!(d & 1)) || d == 5) {
    return false;
  }
  int sum = d;
  while (n) {
    n /= 10;
    d = n % 10;
    sum += d;
  }
  if (sum % 3) {
    return true;
  }
  return false;
}

int main() {
  input();
  
  if (like_prime(N) || prime(N)) {
    cout << "Prime" << endl;
  }
  else {
    cout << "Not Prime" << endl;
  }
  
  return 0;
}