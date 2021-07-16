#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

/* Valid Triangle Number
 *
 * Given an integer array nums, return number of triplets that form the sides of a triangle
 *
 *
 */

// Return the index of the smallest element that is greater or equal than v.
// Returns num.size() if no such item exists
// 0 1 2 3
// 1 2 3 3
// s     e v = 4
//     s e
//     s e
//
int search(vector<int>& nums, int l, int v) {
  int s=l;
  int e=nums.size();
  // search interval is [s,e)
  while (s < e) {
    int m = s + (e-s)/2;
    int mv = nums[m];
    if (mv == v) {
      e = m;
    } else if (mv > v) {
      e = m;
    } else if (mv < v) {
      s = m + 1;
    }
  }
  return s;
}
int triangleNumber(vector<int>& nums) {
  // triangle property: the sum of the lengths of ANY two sides must be greater than the 3rd side
  // sort - starting from i, i+1, for i+2 ... n, see if they are valid
  // 
  // Suppose nums is sorted, we pick a,b st b > a
  // c must be greater than both a,b so c+a>b and c+b>a is satisfied.
  // Only need to make sure that a+b > c or c <= a + b
  // We can binary search for indices after b to determine the number of values that satisfy c
  // We find the first element that is greater or equal than a+b - all values after and including this can be excluded
  int count=0;
  sort(nums.begin(), nums.end());
  for (int i=0; i<(int)nums.size()-2; ++i) {
    for (int j=i+1; j<nums.size()-1; ++j) {
      // search for indicies from j+1 ... end
      int r = search(nums, j+1, nums[i]+nums[j]);
      count += (r-j-1);
    }
  }
  return count;
}

// O(n^2) solution
// 0 1 2 3
// 2 3 4 4
int triangleNumberBetter(vector<int>& nums) {
  int count = 0;
  nums.sort();
  // lock the largest side
  for (int k=nums.size()-1; k>1; --k) {
    for (int i=0,j=k-1; i<j) {
      if (nums[i]+nums[j] > k) {
        // nums[j], nums[j] and nums[i] .... nums[j-1] all satisfy
        count += (j-i);
        j--;
      } else {
        i+=1;
      }
    }
  }
}

int main() {
  vector<int> a = {2};
  //cout << triangleNumber(a) << endl;
  cout << (int)a.size() - 2;
  //for (int i=0; i<(a.size()-2); ++i) {
   // cout << "hi";
  //}
}

