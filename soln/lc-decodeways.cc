#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

inline char convert(string s) {
  return 'A' - 1 + s[0] - '0';
}

bool IsValid(string s) {
  if (s.length() == 1) {
    return (s[0] - '0' >= 1) && (s[0] - '0' <= 9);
  } else {
    if (s[0] - '0' == 1 && s[1] - '0' >= 0 && s[1] - '0' <= 9) {
      return true;
    }
    if (s[0] - '0' == 2 && s[1] - '0' >= 0 && s[1] - '0' <= 6) {
      return true;
    }
  }
  return false;
}

int decode(const string& s, int pos, int size, vector<vector<int>>& memo) {
  //cout << "pos=" << pos << ' ' << "size=" << size << endl;
  //cout << s.substr(pos, size) << endl;
  if (size == 1 && pos == s.size()-1 && IsValid(s.substr(pos, size)))  {
    return 1;
  }
  if (size == 2 && pos == s.size()-2 && IsValid(s.substr(pos, size))) return 1;
  if (memo[pos][size] != -1) {
    return memo[pos][size];
  } else {
    if (IsValid(s.substr(pos, size))) {
      int res = 0;
      if (pos + size < s.length()) {
        res += decode(s, pos+size, 1, memo);
      }
      if (pos + size + 1 < s.length()) {
        res += decode(s, pos+size, 2, memo);
      }
      memo[pos][size] = res;
    } else {
      memo[pos][size] = 0;
    }
    return memo[pos][size];
  }
}

int numDecodings(string s) {
  vector<vector<int>> dp(s.size(), vector<int>(3, -1)); // dp[i][j] is if s starting i and choosing j can be decoded
  return decode(s, 0, 1, dp) + decode(s, 0, 2, dp);
}

int main() {
  cout << numDecodings("226");
}

