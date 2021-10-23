#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

string addStrings(string num1, string num2) {
  string res = "";
  int carry = 0;
  if (num1.length() > num2.length()) swap(num1, num2);
  reverse(num1.begin(), num1.end());
  reverse(num2.begin(), num2.end());
  for (int i=0; i<num1.length(); ++i) {
    int s = (num1[i] - '0') + (num2[i] - '0') + carry;
    if (s >= 10) {
      carry = 1;
      s -= 10;
    } else {
      carry = 0;
    }
    res += ('0' + s);
  }
  int n = num1.length();
  for (int i=n; i<num2.length(); ++i) {
    int s = (num2[i] - '0') + carry;
    if (s >= 10) {
      carry = 1;
      s -= 10;
    } else {
      carry = 0;
    }
    res += ('0' + s);
  }
  if (carry) {
    res += ('1');
  }
  reverse(res.begin(), res.end());
  return res;
}

string addStrings2(string num1, string num2) {
  int i = num1.length() - 1;
  int j = num2.length() - 1;
  string res = "";
  int carry = 0;
  while (i>=0 || j>=0 || carry) {
    int sum = 0;
    if (i>=0) {
      sum += (num1[i] - '0');
      --i;
    }
    if (j>=0) {
      sum += (num2[j] - '0');
      --j;
    }
    sum += carry;
    carry = sum / 10;
    res += ('0' + (sum % 10));
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  cout << addStrings2("999", "11");
}

