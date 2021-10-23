#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <numeric>

#define ll long long
#define mod 1000000007

using namespace std;

class DSU {
  public:
    DSU (int n) {
      p_ = vector<int>(n);
      iota(p_.begin(), p_.end(), 0);
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

  private:
    vector<int> p_;
};

int swimWater(vector<vector<int>>& grid) {
  int rows = grid.size(); int cols = grid[0].size();
  int end = (rows-1)*cols + (cols-1);
  const vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
  vector<int> elevations;
  unordered_map<int, pair<int,int>> elevations_to_cell;
  for (int r=0; r<rows; ++r) {
    for (int c=0; c<cols; ++c) {
      elevations.push_back(grid[r][c]);
      elevations_to_cell[grid[r][c]] = {r,c};
    }
  }
  sort(elevations.begin(), elevations.end());
  DSU uf = DSU(rows*cols);
  for (const auto& e : elevations) {
    auto curr = elevations_to_cell[e];
    for (const auto& d : dir) {
      int nr = curr.first + d.first;
      int nc = curr.second + d.second;
      if (nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc] <= e) {
        uf.connect(curr.first*cols+curr.second, nr*cols+nc);
      }
    }
    if (uf.find(0) == uf.find(end)) {
      return e;
    }
  }
  return -1;
}

int main() {
  vector<vector<int>> g = {{0,2},{1,3}};
  cout << swimWater(g) << endl;
}

