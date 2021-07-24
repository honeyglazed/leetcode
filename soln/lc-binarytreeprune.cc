#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool prune(TreeNode* root) {
  if (!root) {
    return false;
  }

  bool left = prune(root->left);
  bool right = prune(root->right);

  if (!left) root->left = nullptr;
  if (!right) root->right = nullptr;

  if (root->val != 1) {
    return (left || right);
  } else {
    return true;
  }
}

TreeNode* pruneTree(TreeNode* root) {
  bool res = prune(root);
  if (!res) {
    return nullptr;
  } else {
    return root;
  }
}

int main() {
    return 0;
}

