#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
  int M = board.size();
  int N = board[0].size();
  for (int r=0; r<M; ++r) {
    unordered_set<char> has;
    for (int c=0; c<N; ++c) {
      if (board[r][c] == '0') return false;
      if (has.find(board[r][c]) != has.end()) return false;
      has.insert(board[r][c]);
    }
  }

  for (int c=0; c<N; ++c) {
    unordered_set<char> has;
    for (int r=0; r<M; ++r) {
      if (board[r][c] == '0') return false;
      if (has.find(board[r][c]) != has.end()) return false;
      has.insert(board[r][c]);
    }
  }

  // 3 x 3
  for (int i=0; i<9; i+=3) {
    for (int j=0; j<9; j+=3) {
      unordered_set<char> has;
      for (int r=i; r<i+3; ++r) {
        for (int c=j; c<j+3; ++c) {
          if (board[r][c] == '0') return false;
          if (has.find(board[r][c]) != has.end()) return false;
          has.insert(board[r][c]);
        }
      }
    }
  }

  return true;
}

int main() {
    return 0;
}

