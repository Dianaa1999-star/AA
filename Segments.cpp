#include <bits/stdc++.h>

#define MaxValue 2147483647

using namespace std;

int getMid(int s, int e) {
  return s + (e - s) / 2;
}

void Context( int pos, int value,vector < int > & Segments, int node, int left, int right) {
  int aux;
  if (left == right) {
    aux = value;
    Segments[node] = aux;
    return;
  }
  int m = getMid(left, right);
  if (pos > m) {
    Context(pos, value,Segments,  2 * node + 1, m + 1, right);

  } else {
    Context(pos, value,Segments,  2 * node, left, m);
  }

  if (Segments[2 * node] < Segments[2 * node + 1]) {
    Segments[node] = Segments[2 * node];
  } else {
    Segments[node] = Segments[2 * node + 1];
  }
}
int verify(int start, int right, int end, int left) {
  if (start <= left && right <= end)
    return 1;
  else
    return 0;
}
void Find(int start, int end, vector < int > & Segments, int node, int left, int right, int & Minimum) {
  int ok = verify(start, right, end, left);
  if (ok) {
    if (Segments[node] < Minimum) {
      Minimum = Segments[node];
    }
    return;
  }
  int m = getMid(left, right);
  if (m < end) {
    Find(start, end, Segments, 2 * node + 1, m + 1, right, Minimum);
  }
  if (start <= m) {
    Find(start, end, Segments, 2 * node, left, m, Minimum);
  }
}

int main(int argc,
  const char * argv[]) {
  ifstream f;
  ofstream g;
  g.open(argv[2]);
  f.open(argv[1]);

  int x;
  int y;
  int i;
  i = 1;
  f >> x >> y;
  vector < int > Segments;
  int data;
  Segments.reserve(4 * x);
  while (i <= x) {
    f >> data;
    Context(i, data,Segments, 1, 1, x);
    i++;
  }
  int position, right, left, Minimum;
  int j = 0;
  bool type;
  while (j < y) {
    bool type = false;
    if (type == false) {
      f >> right >> left;
      Minimum = MaxValue;
      Find(right + 1, left + 1, Segments, 1, 1, x, Minimum);
      g << Minimum << "\n";
    }
    j++;
  }
  f.close();
  g.close();
  return 0;
}