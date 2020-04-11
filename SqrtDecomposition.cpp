#include <bits/stdc++.h>

#include <stdio.h>

using namespace std;

#define MAXN 10000
# define SQRSIZE 100

int arr[MAXN];
int block[SQRSIZE];
int blk_sz;

int query(int l, int r, ofstream & g, int arr[]) {
  int min = 2147483647;
  while (l <= r and l % blk_sz != 0 and l != 0) {
    if (min > arr[l]) {
      min = arr[l];
    }
    l++;
  }
  while (l + blk_sz <= r) {
    if (min > block[l / blk_sz]) {
      min = block[l / blk_sz];
    }
    l = l + blk_sz;
  }
  while (l <= r) {
    if (min > arr[l]) {
      min = arr[l];
    }
    l++;
  }
  return min;
}

void process(int input[], int n, ofstream & g) {
  int blk_idx = 0;
  blk_sz = sqrt(n);
  long long min = 9223372036854775807;
  int size = 0;
  int p = 0;
  while (p <= n) {
    min = 9223372036854775807;
    for (int j = p; j < p + blk_sz; j++) {
      if (min > input[j] && input[j] != 0) {
        block[blk_idx] = input[j];
        min = input[j];
      }
    }
    blk_idx++;
    size++;
    p = p + blk_sz;
  }

}

int main(int argc,
  const char * argv[]) {

  ifstream f;
  ofstream g;
  int stanga, dreapta;
  f.open(argv[1]);
  g.open(argv[2]);
  int x;
  int y;
  int value;
  f >> x >> y;
  for (int i = 1; i <= x; i++) {
    f >> value;
    arr[i] = value;
  }
  process(arr, x, g);

  for (int j = 0; j < y; j++) {
    f >> stanga >> dreapta;
    g << query(stanga + 1, dreapta + 1, g, arr);
    g << "\n";
  }
  return 0;
}