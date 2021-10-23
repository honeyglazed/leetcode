#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

/* Given non-negative integers n, return the number of integers [0, n] whos binary representations
 * DO NOT contain consecutive ones.
 *
 * f(0) = ?
 * f(1) = 0 1
 * f(2) = 00 10 01
 *
 */
int findIntegers(int n) {
  // The number of ans for a length k binary number is f(k) (kth Fib number)
  // Example k=5 --> 0bXXXXX -> f(5)
  // Break above down as 0b0XXXX and 0b10XXX which is f(4) + f(3)
  // Scan through all bits, if bit is a 1, we can replace it with a zero and add length n valid string after it
  // where n is the number bits after
  //
  // 0b10100 --> 0b0XXXX --> Add f(5)
  //
  //
  // Consider 0b1110 --> 0b0XXX --> [000 - 111] --> f(3)
  //                 --> 0b10XX --> [1000 - 1011] --> f(2)
  //
  // n = 5
  // 0b101 --> f(2) + f(0)
  unordered_map<int, int> fb; // fb[i] is the ith Fib number
  fb[0] = 1;
  fb[1] = 2;
  fb[2] = 3;
  for (int i=2; i<32; ++i) {
    fb[i] = fb[i-1] + fb[i-2];
  }
  int res=0; int k=30; int prev=0;
  while (k>=0) {
    if (n&(1<<k)) {
      res += fb[k];
      if (prev) return res;
      prev = 1;
    } else {
      prev = 0;
    }
    k--;
  }
  return res + 1;
}

int main() {
  cout << findIntegers(5) << endl;
}

