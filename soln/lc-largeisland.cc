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

struct DSU {
  vector<int> p; // parent (index -> parent)
  vector<int> size;
  int biggest=0;
  DSU(int n) {
    p = vector<int>(n);
    size = vector<int>(n, 1);
    for (int i=0; i<n; ++i) {
      p[i] = i;
    }
  }
  int find(int x) {
    while (x != p[x]) {
      p[x] = p[p[x]];
      x = p[x];
    }
    return x;
  }

  void connect(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
      if (size[px] < size[py]) {
        p[px] = py;
        size[py] += size[px];
        biggest = max(biggest, size[py]);
      } else {
        p[py] = px;
        size[px] += size[py];
        biggest = max(biggest, size[px]);
      }
    }
  }

  int get_size(int x) {
    return size[x];
  }
};

/* Given a grid, change at most one 0 to a 1 to form the largest island
 *
 *
 *
 */
int largestIsland(vector<vector<int>>& grid) {
  // Add one to the largest island OR
  // Connection 2, 3 or 4 islands together

  // Form all the islands
  int N = grid.size();
  int M = grid[0].size();
  vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
  auto dsu = new DSU(N*M);
  vector<bool> visited(N*M, false);
  for (int r=0; r<N; ++r) {
    for (int c=0; c<M; ++c) {
      if (grid[r][c] == 1) {
        for (auto d : dir) {
          int nr = r + d[0];
          int nc = c + d[1];
          if (nr>=0&&nr<N&&nc>=0&&nc<M&&grid[nr][nc]==1) {
            dsu->connect(r*M+c, nr*M+nc);
          }
        }
      }
    }
  }

  int res = 1;
  for (int r=0; r<N; ++r) {
    for (int c=0; c<M; ++c) {
      if (grid[r][c]==0) {
        unordered_set<int> pn;
        for (auto d : dir) {
          int nr = r + d[0];
          int nc = c + d[1];
          if (nr>=0&&nr<N&&nc>=0&&nc<M&&grid[nr][nc]==1) {
            pn.insert(dsu->find(nr*M+nc));
          }
        }
        int temp = 1;
        for (auto p : pn) {
          temp += dsu->get_size(p);
        }
        res = max(res, temp);
      }
    }
  }
  return res;
}


int main() {
  vector<vector<int>> g = { {1,0}, {1,1} };
  int res = largestIsland(g);
  cout << res << endl;
}

