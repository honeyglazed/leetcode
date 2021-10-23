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
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int count(TreeNode* root, int v) {
  if (root == nullptr) {
    return 0;
  }
  if (root->val >= v) {
    return 1 + count(root->left, max(v, root->val)) + count(root->right, max(v, root->val));
  } else {
    return count(root->left, max(v, root->val)) + count(root->right, max(v, root->val));
  }
}

int goodNodes(TreeNode* root) {
  return count(root, root->val);
}

int main() {
    return 0;
}

