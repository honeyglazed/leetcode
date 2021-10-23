#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

/* Beautiful Array
 *
 * If we can split n in even and odd parts, any number between an odd and even is guaranteed to satisfy
 * property because odd + even = odd  and (any number) * 2 = odd
 *
 * So we just need to make sure the even and odd parts are also beautiful
 *
 *
 */
vector<int> beautifulArray(int n) {
  vector<int> res = {1};
  while (res.size() < n) {
    vector<int> tmp;
    for (auto i : res) {
      if (2*i-1 <= n) tmp.push_back(2*i-1); // make a new beautiful odd array
    }
    for (auto i : res) {
      if (2*i <= n) tmp.push_back(2*i); // make a new beautiful even array
    }
    res = tmp;
  }
  return res;
}

int main() {
  auto res = beautifulArray(4);
  for (auto i : res) {
    cout << i << ' ';
  }
}

