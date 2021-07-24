#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define ll long long
#define mod 1000000007

using namespace std;

/* Given an array nums, partition it into two contiguous subarrays `left` and `right` so that
 *  1. Every element in left is less than or equal to every element in right
 *  2. left and right are non-empty
 *  3. left has the smallest possible size
 *
 * Return the size of `left`
 *
 */
int partitionDisjointSuperOptimized(vector<int>& nums) {
  int curr = 0;
  int partition = 0;
  int left_max = nums[0];
  int max_up_to_curr = nums[0];
  while (curr < nums.size()) {
    max_up_to_curr = max(max_up_to_curr, nums[curr]);
    if (nums[curr] < left_max) {
      partition = curr; // we must include all the numbers of 0 .. curr
      left_max = max_up_to_curr;
    }
    ++curr;
  }
  return partition+1;
}
int partitionDisjointOptimized(vector<int>& nums) {
  // let left[i] be the maxmium element from nums 0 .. i (inclusive)
  // let right[i] be the minimum element from nums n-1 .. i (inclusive)
  // the answer is the first i where left[i] <= right[i+1]
  vector<int> left(nums.size(), 0);
  vector<int> right(nums.size(), 0);
  int biggest = nums[0];
  for (int i=0; i<nums.size(); ++i) {
    biggest = max(biggest, nums[i]);
    left[i] = biggest;
  }
  int smallest = nums[nums.size()-1];
  for (int i=nums.size()-1; i>=0; --i) {
    smallest = min(smallest, nums[i]);
    right[i] = smallest;
  }
  for (int i=0; i<nums.size()-1; ++i) {
    if (left[i] <= right[i+1]) {
      return i+1;
    }
  }
  return nums.size()-1;
}
int partitionDisjoint(vector<int>& nums) {
  int smallest = nums[0];
  int smallest_idx = 0;
  for (int i=0; i<nums.size()-1; ++i) {
    if (nums[i] < smallest) {
      smallest = nums[i];
      smallest_idx = i;
    }
  }
  priority_queue<int> left;
  for (int i=0; i<=smallest_idx; ++i) {
    left.push(nums[i]);
  }
  priority_queue<int, vector<int>, greater<int>> right;
  unordered_map<int, int> count;
  for (int i=smallest_idx+1; i<nums.size(); ++i) {
    right.push(nums[i]);
    if (count.find(nums[i]) == count.end()) {
      count[nums[i]] = 1;
    } else {
      count[nums[i]] += 1;
    }
  }
  int start=smallest_idx+1;
  while (right.size() > 0 && left.top() > right.top()) {
    if (count[right.top()] == 0) {
      right.pop();
    } else {
      left.push(nums[start]);
      count[nums[start]] -= 1;
      if (nums[start] == right.top()) {
        right.pop();
      }
      ++start;
    }
  }
  return left.size();
}

int main() {
  vector<int> nums = {29,33,6,4,42,0,10,22,62,16,46,75,100,67,70,74,87,69,73,99};
  cout << partitionDisjointOptimized(nums) << endl;
}

