#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

/* Given a n-sized array of 0 and 1, divide the array into 3 equal parts [i,j]
 *
 * Part 1 = arr[0] .. arr[i]
 * Part 2 = arr[i+1] .. arr[j-1]
 * Part 3 = arr[j+1] .. arr[n-1]
 *
 *
 */
vector<int> threeEqualParts(vector<int>& arr) {
  // Some observations:
  // Number of 1's must be divisible by 3
  int s = 0;
  for (auto i : arr) {
    if (i == 1) s += i;
  }
  if (s == 0) {
    return {0, (int)arr.size()-1};
  }
  if (s % 3 != 0) {
    return {-1, -1};
  } else {
    int group = s / 3; // number of 1's required in each group
    int s1,s2,s3;
    int count=0;
    for (int i=0; i<arr.size(); ++i) {
      if (arr[i]==1) {
        ++count;
        if (count==1) {
          s1=i;
        }
      }
      if (count==group) {
        s2=i+1;
        break;
      }
    }
    //cout << "s1=" << s1 << endl;
    count = 0;
    for (int i=s2; i<arr.size(); ++i) {
      if (arr[i]==1) {
        ++count;
        if (count==1) {
          s2=i;
        }
      }
      if (count==group) {
        s3=i+1;
        break;
      }
    }
    for (int i=s3; i<arr.size(); ++i) {
      if (arr[i]==1) {
        s3=i;
        break;
      }
    }
    //cout << s1 << ' ' << s2 << ' ' << s3 << endl;
    while (s3<arr.size() && arr[s1] == arr[s2] && arr[s2] == arr[s3]) {
      ++s1; ++s2; ++s3;
    }
    if (s3==arr.size()) {
      return {s1-1, s2};
    } else {
      return {-1, -1};
    }
  }
}

int main() {
  vector<int> a = {1,0,1,0,1};
  vector<int> b = {0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0};
  vector<int> c = {0,1,0,1,1,0,1,1,0,1};
  auto ans = threeEqualParts(c);
  cout << '[' << ans[0] << ',' << ans[1] << ']' << endl;
}

