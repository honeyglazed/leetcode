#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
  vector<vector<int>> result;
  for (int i=start; i<(int)nums.size()-2; ++i) {
    if (i!=start && nums[i] == nums[i-1]) continue;
    int l=i+1; int r=nums.size()-1;
    while (l < r) {
      int m = nums[l] + nums[r] + nums[i];
      if (m == target) {
        result.push_back({nums[i], nums[l], nums[r]});
        ++l;
        while (l < nums.size() && nums[l] == nums[l-1]) {
          ++l;
        }
        --r;
        while (r >= 0 && nums[r] == nums[r+1]) {
          --r;
        }
      } else if (m > target) {
        --r;
      } else if (m < target) {
        ++l;
      }
    }
  }
  return result;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());
  for (int i=0; i<(int)nums.size()-3; ++i) {
    if (i!=0 && nums[i]==nums[i-1]) continue;
    auto tmp = threeSum(nums, i+1, target-nums[i]);
    for (auto& t : tmp) {
      t.push_back(nums[i]);
      res.push_back(std::move(t));
    }
  }
  return res;
}

int main() {
  vector<int> b = {-2,-1,-1,1,1,2,2};
  vector<int> a = {1,0,-1,0,-2,2};
  auto res = fourSum(b, 0);
  for (const auto& r : res) {
    for (auto i : r) {
      cout << i << ' ';
    }
    cout << endl;
  }
}

