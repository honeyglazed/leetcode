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

int mincut(string s) {
  // abc --> 4 nodes
  // 0 1 2 3
  // adjacent nodes always connected
  int len = s.size();
  int N = s.size() + 1;
  // DAG
  vector<vector<int>> graph(N);
  for (int i=0; i<N-1; ++i) {
    graph[i].push_back(i+1);
  }

  // find all odd palindromes
  for (int i=1; i<N-1; ++i) {
    int l=i-1; int r=i+2;
    int lc=i-1; int rc=i+1;
    while (lc>=0 && rc<len && s[lc]==s[rc]) {
      graph[l].push_back(r);
      lc-=1;
      rc+=1;
      l-=1;
      r+=1;
    }
  }

  // find all even palindromes
  for (int i=0; i<N-1; ++i) {
    int l=i; int r=i+2;
    int lc=i; int rc=i+1;
    while (lc>=0 && rc<len && s[lc]==s[rc]) {
      graph[l].push_back(r);
      lc-=1;
      rc+=1;
      l-=1;
      r+=1;
    }
  }
  for (int i=0; i<graph.size(); ++i) {
    cout << "node=" << i << " ";
    for (auto v : graph[i]) {
      cout << v << ' ';
    }
    cout << endl;
  }
  int res = N - 1;
  queue<pair<int,int>> q; q.push({0,0});
  vector<bool> v(N, false); v[0] = true;
  while (!q.empty()) {
    auto p = q.front(); q.pop();
    if (p.first == N-1) {
      return p.second - 1;
    } else {
      for (auto nei : graph[p.first]) {
        if (!v[nei]) {
          q.push({nei, p.second+1});
          v[nei] = true;
        }
      }
    }
  }
  return res;
}

int main() {
  cout << mincut("aab");
}

