#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

string hash_word(const string& word) {
  string hash = "";
  int count[26] = {0};
  for (char c : word) {
    count[c-'a']+=1;
  }
  for (int i=0; i<26; ++i) {
    hash += string(count[i], 'a'+i);
  }
  return hash;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> hash_to_words;
  for (auto s : strs) {
    hash_to_words[hash_word(s)].push_back(s);
  }
  vector<vector<string>> res;
  for (const auto& [k,v] : hash_to_words) {
    res.push_back(v);
  }
  return res;
}

int main() {
  vector<string> s = {"boy", "ccc", "yob", "oyb"};
  auto r = groupAnagrams(s);
  for (auto i : r) {
    for (auto j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}

