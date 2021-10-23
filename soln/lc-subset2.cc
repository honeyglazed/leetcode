#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

void search(vector<vector<int>>& res, vector<int>& nums, vector<int> s, int curr) {
  res.push_back(s);
  for (int i=curr; i<nums.size(); ++i) {
    if (i > curr && i != 0 && nums[i] == nums[i-1]) continue;
    s.push_back(nums[i]);
    search(res, nums, s, i+1);
    s.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());
  search(res, nums, {}, 0);
  return res;
}

// using bitmask
vector<vector<int>> subsets(vector<int>& nums) {
  unordered_set<string> seen;
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());
  for (int i=0; i<(1<<nums.size()); ++i) {
    vector<int> s;
    string hash;
    for (int k=0; k<nums.size(); ++k) {
      if (i&(1<<k)) {
        s.push_back(nums[k]);
        hash += to_string(nums[k]);
      }
    }
    if (seen.find(hash) == seen.end()) {
      res.push_back(s);
      seen.insert(hash);
    }
  }
  return res;
}

int main() {
  vector<int> nums = {1,2,2};
  auto res = subsets(nums);
  for (auto i : res) {
    for (auto j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}

