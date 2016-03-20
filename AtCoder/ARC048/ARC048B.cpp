#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

#define XSTR(s) STR(s)
#define STR(s) #s

using namespace std;

int N;
vector<int> Rs, Hs;

int main() {
#ifdef DEBUG
  ifstream in(XSTR(INPUT));
#else
  istream &input = cin;
#endif
  string buf;
  getline(input, buf);
  N = atoi(buf.c_str());
  Rs.reserve(N); Hs.reserve(N);
  int max_r = 0;
  for (int i = 0; i < N; i++) {
    int r, h;
    input >> r >> h;
    if (max_r < r) {
      max_r = r;
    }
    Rs.push_back(r); Hs.push_back(h);
  }
  max_r++;
  int **table = new int * [max_r];
  for (int i = 0; i < max_r; i++) {
    table[i] = new int [3];
    table[i][0] = table[i][1] = table[i][2] = 0;
  }
  for (int i = 0; i < N; i++) {
    table[Rs[i]][Hs[i] - 1]++;
  }
  for (int i = 1; i < max_r; i++) {
    for (int j = 0; j < 3; j++) {
      table[i][j] += table[i - 1][j];
    }
  }
  for (int i = 0; i < N; i++) {
    int win, lose, even;
    win = table[Rs[i] - 1][0] + table[Rs[i] - 1][1] + table[Rs[i] - 1][2] + (table[Rs[i]][(Hs[i]) % 3] - table[Rs[i] - 1][(Hs[i]) % 3]);
    even = table[Rs[i]][Hs[i] - 1] - table[Rs[i] - 1][Hs[i] - 1] - 1;
    lose = N - 1 - win - even;
    cout << win << ' '
         << lose << ' '
         << even << endl;
  }
  for (int i = 0; i < max_r; i++) {
    delete [] table[i];
  }
  delete [] table;
  return 0;
}