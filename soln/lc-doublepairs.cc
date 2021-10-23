#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

bool canReorderDoubled(vector<int>& arr) {
  unordered_map<int, int> count;
  sort(arr.begin(), arr.end());
  for (auto i : arr) {
    if (count.find(i) == count.end()) {
      count[i] = 1;
    } else {
      ++count[i];
    }
  }

  for (int i=0; i<arr.size(); ++i) {
    if (arr[i] > 0 && (arr[i]&1) == 0) {
      if (count.find(arr[i]/2) != count.end() && count[arr[i]/2] > 0) {
        --count[arr[i]];
        --count[arr[i]/2];
      }
    }
    if (arr[i] <= 0) {
      if (count.find(arr[i]*2) != count.end() && count[arr[i]*2] > 0) {
        --count[arr[i]];
        --count[arr[i]*2];
      }
    }
  }
  for (const auto& [k,v] : count) {
    if (v) return false;
  }
  return true;
}

int main() {
  vector<int> a = {4,-2,2,-4};
  // -4, -2, 2, 4
  cout << canReorderDoubled(a);
}

