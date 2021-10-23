#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

/* A monotonic increasing string is a string that is all 1's or all 0's or have 0's followed by 1's
 *
 *
 *
 */
int minFlipsMonoIncr(string s) {
  // for a 1 -> sum of all zeros to the right and sum of all ones to the left
  // for a 0 -> sum of all ones to the left sum of all zeros to the right
  // 0 0 1 1 0
  // 0 0 0 1 2
  // 2 1 1 1 0
  vector<int> ones(s.length(), 0);
  vector<int> zeros(s.length(), 0);
  int start = 0;
  for (int i=0; i<s.length(); ++i) {
    ones[i] = start;
    if (s[i] == '1') ++start;
  }
  start = 0;
  for (int i=(int)s.length()-1; i>=0; --i) {
    zeros[i] = start;
    if (s[i] == '0') ++start;
  }

  int res = s.length();
  for (int i=0; i<s.length(); ++i) {
    res = min(res, ones[i] + zeros[i]);
  }
  return res;
}

// Intuition: a string of size 1 is monotonic - say we already have a monotonic string
// For new incoming character, if its a 1, it remains monotonic
// If its a 0, we can flip it to 1 or keep it a zero and flip all previous 1s to 0
int minFlipsMonoIncr2(string s) {
  int ones_count = 0;
  int flips = 0;
  for (int i=0; i<s.length(); ++i) {
    if (s[i] == '1') {
      ++ones_count;
    } else {
      ++flips;
    }
    flips = min(flips, ones_count);
  }
  return flips;
}
int main() {
  cout << minFlipsMonoIncr("00001000");
}

