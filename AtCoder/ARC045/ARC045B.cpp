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

using namespace std;

class RMQ {
  int _n;
  int *_data;
  int *_lazy;
  bool _greater;
  void _lazy_update(int k) {
    if (_lazy[k]) {
      _data[k] += _lazy[k];
      if (k * 2 + 2 < 2 * _n - 1) {
        _lazy[k * 2 + 1] += _lazy[k];
        _lazy[k * 2 + 2] += _lazy[k];
      }
      _lazy[k] = 0;
    }
  }
public:
  RMQ(int n, bool greater = false) {
    _n = 1;
    while (_n < n) _n <<= 1;
    _data = new int [2 * _n - 1];
    _lazy = new int [2 * _n - 1];
    _greater = greater;
    for (int i = 0; i < 2 * _n - 1; i++) {
      _data[i] = 0;
      _lazy[i] = 0;
    }
    for (int i = 0; i < _n - n; i++) {
      _data[2 * _n - 2 - i] = greater ? INT_MIN : INT_MAX;
    }
  }
  ~RMQ() {
    delete [] _data;
    delete [] _lazy;
  }
  void add(int k, int v) {
    k += _n - 1;
    _data[k] += v;
    while (k) {
      k = (k - 1) / 2;
      _data[k] = _greater ?
      max(_data[k * 2 + 1], _data[k * 2 + 2]) :
      min(_data[k * 2 + 1], _data[k * 2 + 2]);
    }
  }
  void add(int a, int b, int v, int k = 0, int l = 0, int r = INT_MAX) {
    if (r > _n) r = _n;
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      _lazy[k] += v;
      _lazy_update(k);
    }
    else {
      _lazy_update(k);
      add(a, b, v, k * 2 + 1, l, (l + r) / 2);
      add(a, b, v, k * 2 + 2, (l + r) / 2, r);
      _data[k] = _greater ?
                 max(_data[k * 2 + 1], _data[k * 2 + 2]) :
                 min(_data[k * 2 + 1], _data[k * 2 + 2]);
    }
  }
  int query(int a, int b, int k = 0, int l = 0, int r = INT_MAX) {
    if (r > _n) r = _n;
    _lazy_update(k);
    if (r <= a || b <= l)
      return _greater ? INT_MIN : INT_MAX;
    if (a <= l && r <= b)
      return _data[k];
    int lval = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int rval = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return _greater ?
    max(lval, rval):
    min(lval, rval);
  }
};

int N, M;
vector<int> s, t;

void input() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &in = cin;
#endif
  in >> N >> M;
  s.reserve(M); t.reserve(M);
  for (int i = 0; i < M; i++) {
    int ss, tt;
    in >> ss >> tt;
    s.push_back(ss - 1);
    t.push_back(tt - 1);
  }
}

int main() {
  input();
  
  RMQ rmq(N);
  for (int i = 0; i < M; i++) {
    rmq.add(s[i], t[i] + 1, 1);
  }

  int k = 0;
  vector<int> answer;
  answer.reserve(M);
  for (int i = 0; i < M; i++) {
    if (rmq.query(s[i], t[i] + 1) > 1) {
      k++;
      answer.push_back(i + 1);
    }
  }
  cout << k << endl;
  for (int i = 0; i < k; i++) {
    cout << answer[i] << endl;
  }
  
  return 0;
}