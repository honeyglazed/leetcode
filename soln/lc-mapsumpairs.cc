#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

struct TrieNode {
  int val;
  char c;
  bool is_string;
  unordered_map<char, TrieNode*> n;
  TrieNode(char ch, int v) {
    c = ch;
    val = v;
  }
};

class MapSum {
  public:
    MapSum() {
      root_ = new TrieNode('#', 0);
    }
    void insert(string key, int val) {
      int delta;
      if (key_to_val_.find(key) != key_to_val_.end()) {
        delta = val - key_to_val_[key];
      } else {
        delta = val;
      }
      key_to_val_[key] = val;
      TrieNode* curr = root_;
      for (auto c : key) {
        if (curr->n.find(c) == curr->n.end()) {
          curr->n[c] = new TrieNode(c, 0);
        }
        curr = curr->n[c];
        curr->val += delta;
      }
    }
    int sum(string prefix) {
      TrieNode* curr = root_;
      for (auto c : prefix) {
        if (curr->n.find(c) == curr->n.end()) {
          return 0;
        } else {
          curr = curr->n[c];
        }
      }
      return curr->val;
    }
  private:
    TrieNode* root_;
    unordered_map<string, int> key_to_val_;
};

int main() {
  auto ms = new MapSum();
  ms->insert("apple", 3);
  cout << ms->sum("ap") << endl;
  ms->insert("app", 2);
  cout << ms->sum("ap") << endl;
  ms->insert("apple", 2);
  cout << ms->sum("ap") << endl;
}

