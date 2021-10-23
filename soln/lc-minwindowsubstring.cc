#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

string minWindow(string s, string t) {
  int res = s.length()+1;
  int res_start = 0;
  unordered_map<char, int> need;
  for (char const &i: t) {
    ++need[i];
  }
  int matches = 0;
  int l=0;
  int r=0;
  while (r < s.length()) {
    if (need.find(s[r]) != need.end()) {
      --need[s[r]];
      if (need[s[r]] == 0) ++matches;
    }
    while (l <= r && matches == need.size()) {
      if (r-l+1 < res) {
        res = r-l+1;
        res_start = l;
      }
      if (need.find(s[l]) != need.end()) {
        ++need[s[l]];
        if (need[s[l]] == 1) {
          --matches;
        }
      }
      ++l;
    }
    ++r;
  }
  if (res == s.length()+1) {
    return "";
  }
  return s.substr(res_start, res);
}
int main() {
  cout << minWindow("a", "aa");
}

