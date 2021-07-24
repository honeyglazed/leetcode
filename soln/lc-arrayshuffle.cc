#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>

#define ll long long
#define mod 1000000007

using namespace std;

class Cards {
  public:
    explicit Cards(vector<int>& nums) {
      arr_ = nums;
      to_shuffle_ = nums;
    }

    vector<int> reset() {
      return arr_;
    }

    // Yates shuffle - numbers at the back are confirmed
    // Keep picking random numbers between the valid range
    // 1 2 3 4 5 6 7
    // 1 7 3 4 5 6 | 2
    // 1 7 6 4 5 | 3 2
    vector<int> shuffle() {
      for (int i=to_shuffle_.size()-1; i>=1; --i) {
        int j = rand() % (i+1); // generates a number between 0 .. i
        swap(to_shuffle_[i], to_shuffle_[j]);
      }
      return to_shuffle_;
    }
  private:
    vector<int> arr_;
    vector<int> to_shuffle_;
};
int main() {
  vector<int> v = {0,1,2,3,4,5};
  Cards c(v);
  for (int i=0; i<10; ++i) {
    auto ans = c.shuffle();
    for (auto i : ans) {
      cout << i << ' ';
    }
    cout << endl;
  }
}

