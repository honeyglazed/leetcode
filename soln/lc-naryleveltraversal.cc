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

class Node {
  public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
      val = _val;
    }

    Node(int _val, vector<Node*> _children) {
      val = _val;
      children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
  vector<vector<int>> res;
  queue<Node*> q; q.push(root);
  while (!q.empty()) {
    int s = q.size();
    vector<int> level(s);
    for (int i=0; i<s; ++i) {
      auto* node = q.front(); q.pop();
      level[i] = node->val;
      for (auto* i : node->children) {
        q.push(i);
      }
    }
    res.push_back(level);
  }
  return res;
}

int main() {
    return 0;
}

