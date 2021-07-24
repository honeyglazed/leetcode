#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

string pushDominos(string dominos) {
  int max_f = 1e6;
  vector<int> forces(dominos.size(), 0);
  int cur_f = max_f;
  bool has_seen_r = false;
  for (int i=0; i<dominos.size(); ++i) {
    if (dominos[i] == '.' && has_seen_r) {
      forces[i] += cur_f;
      --cur_f;
    } else if (dominos[i] == 'R') {
      cur_f = max_f;
      has_seen_r = true;
    } else if (dominos[i] == 'L') {
      has_seen_r = false;
    }
  }

  cur_f = -max_f;
  bool has_seen_l = false;
  for (int i=dominos.size()-1; i>=0; --i) {
    if (dominos[i] == '.' && has_seen_l) {
      forces[i] += cur_f;
      ++cur_f;
    } else if (dominos[i] == 'R') {
      has_seen_l = false;
    } else if (dominos[i] == 'L') {
      cur_f = -max_f;
      has_seen_l = true;
    }
  }

  string res = "";
  for (int i=0; i<forces.size(); ++i) {
    int f = forces[i];
    if (f == 0) {
      res += dominos[i];
    } else if (f > 0) {
      res += 'R';
    } else if (f < 0) {
      res += 'L';
    }
  }
  return res;
}

int main() {
  string d = "L......LR..L.L";
  cout << pushDominos(d) << endl;
}

