#include <algorithm>
#include <climits>
#include <iostream>
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

/* Lowest Common Ancestor
 *
 * Given a binary tree, return the LCA of p and q provided they are always in
 * the tree
 *
 *
 */
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (root == nullptr) {
    return nullptr;
  }

  if (root->val == p->val || root->val == q->val) {
    return root;
  }

  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);

  if (left && right) {
    return root;
  }
  if (left)
    return left;
  if (right)
    return right;
  return nullptr; // should not happen if p and q exist
}

int main() {
  TreeNode *root;
  TreeNode *res = lowestCommonAncestor(root, root, root);
}
