#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define ll long long
#define mod 1000000007

using namespace std;

struct Data {
  int r;
  int c;
  int dist;
};

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
  const vector<pair<int, int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
  vector<vector<int>> res = mat;
  vector<vector<bool>> v = vector(mat.size(), vector<bool>(mat[0].size(), false));
  queue<Data> q;
  for (int c=0; c<mat.size(); ++c) {
    for (int r=0; r<mat[0].size(); ++r) {
      if (mat[c][r] == 0) {
        q.push(Data{r, c, 0});
        v[c][r] = true;
      }
    }
  }

  while (!q.empty()) {
    auto d = q.front(); q.pop();
    if (mat[d.c][d.r] == 1) {
      res[d.c][d.r] = d.dist;
    }
    for (auto di : dir) {
      int nr = d.r + di.first;
      int nc = d.c + di.second;
      if (nr >= 0 && nr < mat[0].size() && nc >=0 && nc < mat.size() && !v[nc][nr] && mat[nc][nr] == 1) {
        q.push(Data{nr, nc, d.dist+1});
        v[nc][nr] = true;
      }
    }
  }
  return res;
}


void PrintMatrix(vector<vector<int>> m) {
  for (auto v : m) {
    for (auto i : v) {
      cout << i << ' ';
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> m = {{0,0,0}, {0,1,0}, {1,1,1}};
  auto res = updateMatrix(m);
  PrintMatrix(res);
}

