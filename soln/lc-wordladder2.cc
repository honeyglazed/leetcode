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

struct Item {
  string curr;
  vector<string> path;
  unordered_set<string> used;
  Item(string start): curr(start) {}
};

/* Return the shortest transformation from beginWord to endWord
 *
 *
 *
 */
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
  vector<vector<string>> res;
  unordered_set<string> dict;
  const string alpha = "abcdefghijklmnopqrstuvwxyz";
  for (auto word : wordList) {
    dict.insert(word);
  }
  if (dict.find(endWord) == dict.end()) return res;
  Item start(beginWord);
  start.path.push_back(beginWord);
  start.used.insert(beginWord);
  queue<Item> q; q.push(start);
  int found = false;
  while (!q.empty()) {
    if (found) {
      return res;
    }
    int level = q.size();
    unordered_set<string> to_erase;
    for (int i=0; i<level; ++i) {
      auto item = q.front(); q.pop();
      auto w = item.curr;
      if (w == endWord) {
        res.push_back(item.path);
        found = true;
      }
      for (int p=0; p<item.curr.length(); ++p) {
        for (auto c : alpha) {
          w[p] = c;
          if (dict.find(w) != dict.end() && item.used.find(w) == item.used.end()) {
            auto next = item;
            next.curr = w;
            next.path.push_back(w);
            next.used.insert(w);
            to_erase.insert(w);
            q.push(next);
          }
          w[p] = item.curr[p];
        }
      }
    }
    for (auto e : to_erase) {
      dict.erase(e);
    }
    to_erase.clear();
  }
  return res;
}

int main() {
  vector<string> d = {"hot", "dot", "dog", "lot", "log", "cog"};
  vector<string> d2 = {"hot", "dog"};
  auto res = findLadders("hot", "dog", d2);
  for (auto r : res) {
    for (auto w : r) {
      cout << w << "->";
    }
    cout << endl;
  }
}

