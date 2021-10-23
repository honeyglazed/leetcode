#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define mod 1000000007

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Item {
  TreeNode *node;
  vector<int> path;
  int curr;
};

/* Given a binary tree, return all root to leaves that sum to targetSum
 *
 *
 *
 */
vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
  vector<vector<int>> res;
  queue<Item> q;
  q.push({root, {root->val}, root->val});
  while (!q.empty()) {
    auto i = q.front();
    q.pop();
    if (i.node->left == nullptr && i.node->right == nullptr &&
        i.curr == targetSum) {
      res.push_back(i.path);
    } else {
      if (i.node->left) {
        auto p = i.path;
        p.push_back(i.node->left->val);
        q.push({i.node->left, p, i.curr + i.node->left->val});
      }
      if (i.node->right) {
        auto p = i.path;
        p.push_back(i.node->right->val);
        q.push({i.node->right, p, i.curr + i.node->right->val});
      }
    }
  }
  return res;
}

int main() { return 0; }
