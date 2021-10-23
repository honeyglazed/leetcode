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
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* helper(const vector<int>& nums, int start, int end) {
  int mid = start + (end-start)/2;
  TreeNode* root = new TreeNode(nums[mid]);
  if (mid-1>=start) {
    root->left = helper(nums, start, mid-1);
  }
  if (mid+1<=end) {
    root->right = helper(nums, mid+1, end);
  }
  return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
  TreeNode* root = helper(nums, 0, nums.size()-1);
  return root;
}

int main() {
    return 0;
}

