#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

int lengthOfLIS(vector<int>& nums) {
  vector<int> longest_up_to(nums.size(), 1);
  // 10 9 2 5 3 7 101 18
  //
  // 1 1 1 2 3 4 5
  int res = 1;
  for (int i=0; i<nums.size(); ++i) {
    for (int j=i; j>=0; --j) {
      if (i == 0) {
        longest_up_to[i] = 1;
      } else {
        if (nums[i] > nums[j]) {
          longest_up_to[i] = max(longest_up_to[i], 1 + longest_up_to[j]);
        }
      }
    }
    res = max(longest_up_to[i], res);
  }
  return res;
}

int main() {
  vector<int> a = {10, 9, 2, 5, 3, 7, 101, 8};
  vector<int> b = {0, 1, 0, 3, 2, 3};
  vector<int> c = {7, 7, 7, 7, 7, };
  cout << lengthOfLIS(a) << endl;
  cout << lengthOfLIS(b) << endl;
  cout << lengthOfLIS(c) << endl;
}
