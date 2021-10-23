#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

int trap(vector<int>& height) {
  // left[i] is the tallest wall to the left of height[i]
  int N = height.size();
  vector<int> left(N);
  vector<int> right(N);
  int max_left = 0;
  for (int i=0; i<N; ++i) {
    left[i] = max_left;
    max_left = max(max_left, height[i]);
  }
  int max_right = 0;
  for (int i=N-1; i>=0; --i) {
    right[i] = max_right;
    max_right = max(max_right, height[i]);
  }
  int res=0;
  for (int i=1; i<N-1; ++i) {
    int d = min(left[i], right[i]);
    if (height[i] < d) {
      res += (d-height[i]);
    }
  }
  return res;
}

int main() {
  vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << trap(a) << endl;
}

