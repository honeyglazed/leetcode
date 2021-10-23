#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

#define ll long long
#define mod 1000000007

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
  int res = 0;
  int diff = 1e7;
  sort(nums.begin(), nums.end());
  for (int i=0; i<(int)(nums.size())-2; ++i) {
    int s = i+1;
    int e = nums.size()-1;
    while (s < e) {
      int t = nums[i] + nums[s] + nums[e];
      if (t == target) return t;
      if (abs(target - t) < diff) {
        res = t;
        diff = abs(target - t);
      }
      if (t > target) {
        --e;
      } else if (t < target) {
        ++s;
      }
    }
  }
  return res;
}

int main() {
  vector<int> nums = {-1,2,1,-4};
  cout << threeSumClosest(nums, 0) << endl;
}

