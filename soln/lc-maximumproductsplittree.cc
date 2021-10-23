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
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int getTotal(TreeNode* root) {
  if (!root) {
    return 0;
  } else {
    return root->val + getTotal(root->left) + getTotal(root->right);
  }
}

int res = 0;

int getRes(TreeNode* root, int total) {
  if (!root) {
    return 0;
  }
  if (!root->left && !root->right) {
    return root->val;
  } else {
    int l = getRes(root->left, total);
    int r = getRes(root->right, total);
    int s = l + r + root->val;
    res = max(res, (total-s)*s);
    return s;
  }
}

// Split the binary tree into two subtrees by removing one and edge and maximizing the product of the sums
int maxProduct(TreeNode* root) {
  int total = getTotal(root);
  return getRes(root, total);
}

int main() {
    return 0;
}

