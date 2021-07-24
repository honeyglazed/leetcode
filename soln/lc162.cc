#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

/* LC162: Find Peak Element
 *
 * Given an array, return the element that is strictly greater than its neighbors
 *
 *
 */
int findPeakElement(vector<int>& nums) {
  int l=0; int r=nums.size()-1;
  // 0 1
  // 1 2
  //
  if (nums.size() == 1 ) return 0;
  while (l <= r) {
    int m = l + (r-l)/2;
    if (m==0 && nums[m] > nums[m+1]) return m;
    if (m==nums.size()-1 && nums[m] > nums[m-1]) return m;
    if (m!=0 && m!=nums.size()-1 && nums[m] > nums[m-1] && nums[m] > nums[m+1]) return m;

    if (m==0) l=m+1;
    else if (m==nums.size()-1) r=m-1;
    else if (nums[m-1] > nums[m] && nums[m+1] > nums[m]) l=m+1;
    else if (nums[m+1] > nums[m] && nums[m] > nums[m-1]) l=m+1;
    else if (nums[m-1] > nums[m] && nums[m] > nums[m+1]) r=m-1;
  }
  return -1;
}

int main() {
  vector<int> a = {1, 2, 1, 3, 5, 6, 4};
  vector<int> b = {1, 2};
  cout << findPeakElement(b) << endl;
}

