#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>

#define ll long long
#define mod 1000000007

using namespace std;

class DSU {
  unordered_map<int, int> p_;
  public:
    DSU(vector<int> n) {
      for (auto i : n) {
        p_[i] = i;
      }
    }

    void connect(int x, int y) {
      int px = find(x);
      int py = find(y);
      if (px != py) {
        p_[px] = py;
      }
    }

    int find(int x) {
      while (x != p_[x]) {
        p_[x] = p_[p_[x]];
        x = p_[x];
      }
      return x;
    }

    unordered_map<int, vector<int>> groups() {
      unordered_map<int, vector<int>> res;
      for (const auto& [k,_] : p_) {
        res[find(k)].push_back(k);
      }
      return res;
    }
};

vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
  int max_r = matrix.size(); int max_c = matrix[0].size();
  vector<int> ranks(max_r + max_c, 0);

  unordered_map<int, vector<pair<int,int>>> value_to_cord;
  set<int> vals;

  for (int r=0; r<matrix.size(); ++r) {
    for (int c=0; c<matrix[0].size(); ++c) {
      vals.insert(matrix[r][c]);
      value_to_cord[matrix[r][c]].push_back({r,c});
    }
  }

  vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size()));

  // DSU nodes are rows and cols, row = row, col = col + max_r
  // There is a connection between rows and cols for each number
  for (auto v : vals) {
    auto cords = value_to_cord[v]; // all the (row, col) that share the same number v
    vector<int> nodes;
    // Create all the row col nodes
    for (auto p : cords) {
      nodes.push_back(p.first);
      nodes.push_back(p.second + max_r);
    }
    DSU d = DSU(nodes);
    // Connect rows and cols that share same number
    for (auto p : cords) {
      d.connect(p.first, p.second + max_r);
    }

    // get a mapping of row/col -> all connected row/cols
    auto g = d.groups();
    for (const auto& [k,v] : g) {
      int max_rank = 0;
      for (auto i : v) {
        max_rank = max(max_rank, ranks[i]);
      }
      for (auto i : v) {
        ranks[i] = max_rank + 1;
      }
    }
    for (auto p : cords) {
      res[p.first][p.second] = ranks[p.first];
    }
  }

  return res;
}

int main() {
  vector<vector<int>> m = {{20,-21,14}, {-19,4,19}, {22,-47,24}, {-19,4,19}};
  matrixRankTransform(m);
}

