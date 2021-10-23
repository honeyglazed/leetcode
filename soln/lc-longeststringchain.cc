#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

int longestStrChain(vector<string>& words) {
  int N = words.size();
  int res = 1;
  sort(words.begin(), words.end(), [](string a, string b) { return a.length() < b.length(); });
  // map of the longest chain starting with word -> length
  unordered_map<string, int> lu;
  for (const auto& s : words) {
    lu[s] = 1;
  }
  for (int i=N-1; i>=0; i--) {
    auto w = words[i];
    for (int k=0; k<(int)w.length(); ++k) {
      auto nw = w.substr(0, k) + w.substr(k+1);
      //cout << nw << endl;
      if (lu.find(nw) != lu.end()) {
        lu[nw] = max(lu[nw], lu[w]+1);
      }
    }
  }

  for (const auto& [k,v] : lu) {
    res = max(res, v);
  }
  return res;
}

int main() {
  vector<string> w = {"a", "b", "ba", "bca", "bda", "bdca"};
  vector<string> w2 = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
  cout << longestStrChain(w2);
}

