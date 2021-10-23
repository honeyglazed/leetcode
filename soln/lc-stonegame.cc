#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define mod 1000000007

using namespace std;

// naive
bool play(vector<int> &piles, int total, int s, int e, int curr,
          bool alex_turn) {
  if (s > e) {
    return curr > (total - curr);
  } else {
    bool has_win = false;
    if (alex_turn) {
      has_win |= play(piles, total, s + 1, e, curr + piles[s], false);
      has_win |= play(piles, total, s, e - 1, curr + piles[e], false);

    } else {
      has_win |= play(piles, total, s + 1, e, curr, true);
      has_win |= play(piles, total, s, e - 1, curr, true);
    }
    return has_win;
  }
}

// memo
int play2(vector<int> &piles, int total, int s, int e, int curr, bool alex_turn,
          vector<vector<int>> &lu) {
  if (s > e) {
    return (curr > (total - curr)) ? 1 : 0;
  }
  if (lu[s][e] != -1) {
    return lu[s][e];
  }
  if (alex_turn) {
    lu[s][e] = play2(piles, total, s + 1, e, curr + piles[s], false, lu) |
               play2(piles, total, s, e - 1, curr + piles[s], false, lu);
  } else {
    lu[s][e] = play2(piles, total, s + 1, e, curr, true, lu) |
               play2(piles, total, s, e - 1, curr, true, lu);
  }
  return lu[s][e];
}

// Minmax - Game Theory
// score = score(Alex) - score(Lee)
// Alex wins if score > 0 - Alex tries to increase the score and Lee tries to
// decrease it
bool stoneGame(vector<int> &piles) {
  // let dp[i][j] be the final score for piles[i] ... piles[j]
  vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
  // for Alex: dp[i][j] = max(dp[i+1][j] + piles[i], dp[i][j-1] + piles[j])
  // for Lee: dp[i][j] = min(dp[i+1][j] - piles[i], dp[i][j-1] - piles[j])
  for (int i = 0; i < piles.size(); ++i) {
    dp[i][i] = piles[i];
  }
  bool alex_turn = true;
  for (int d = 1; d < piles.size(); ++d) {
    for (int s = 0; s < int(piles.size() - d); ++s) {
      int e = s + d;
      if (alex_turn) {
        dp[s][e] = max(dp[s + 1][e] + piles[s], dp[s][e - 1] + piles[e]);
      } else {
        dp[s][e] = min(dp[s + 1][e] + piles[s], dp[s][e - 1] + piles[e]);
      }
    }
    alex_turn = !alex_turn;
  }
  return dp[0][piles.size() - 1];
}

int main() {
  vector<int> g = {5, 3, 4};
  cout << stoneGame(g) << endl;
}
