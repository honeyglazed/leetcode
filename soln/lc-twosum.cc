#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> seen;
  for (int i=0; i<nums.size(); ++i) {
    if (seen.find(target-nums[i]) != seen.end()) {
      return {seen[target-nums[i]], i};
    } else {
      seen[nums[i]] = i;
    }
  }
  return {-1, -1};
}

int main() {
  vector<int> a = {3,3,4};
  vector<int> res = twoSum(a, 6);
  cout << res[0] << ' ' << res[1] << endl;
}

