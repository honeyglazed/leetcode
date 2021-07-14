#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

/* LC 205: Isomorphic Strings
 *
 * String s and t are isomorphic if all characters in s can be replaced to form t
 *
 *
 *
 */
bool IsIsomorphic(string s, string t) {
  if (s.length() != t.length()) {
    return false;
  }
  // b -> b
  // a -> a
  // d -> a
  unordered_map<char, char> smappings;
  unordered_map<char, char> tmappings;
  for (int i=0; i<s.length(); ++i) {
    if (smappings.find(s[i]) == smappings.end()) {
      if (tmappings.find(t[i]) != tmappings.end()) {
        return false;
      }
      smappings[s[i]] = t[i];
      tmappings[t[i]] = s[i];
    } else {
      if (smappings[s[i]] != t[i]) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  cout << IsIsomorphic("egg", "add") << endl;
  cout << IsIsomorphic("foo", "bar") << endl;
  cout << IsIsomorphic("paper", "title") << endl;
  cout << IsIsomorphic("baba", "baca") << endl;
}

