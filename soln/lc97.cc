#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

/* LeetCode 97. Interleaving String
 *
 * Given a string A, B and C. Determine if A and B can be interleaved to form C
 *
 *
 *
 *
 *
 */
bool CanInterleave(const string& s1, const string& s2, const string& s3) {
    // Let dp[i][j] be whether s1[0..i] can interleave with s2[0..j] to form s3 [0..i+j]
    // Base case: dp[0][0] = True
    //            dp[i][0] = True if s1[i] == s3[i] and dp[i-1][0]
    //            dp[0][j] = True if s2[j] == s3[j] and dp[0][j-1]
    //
    // Transisition: if dp[i-1][j] ==> s1[i-1] == s3[i+j-1]
    //               if dp[i][j-1] ==> s2[j-1] == s3[i+j-1]
    vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
    dp[0][0] = true;
    for (int i=1; i<s1.size()+1; ++i) {
        dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    }

    for (int j=1; j<s2.size()+1; ++j) {
        dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
    }

    for (int i=1; i<s1.size()+1; ++i) {
        for (int j=1; j<s2.size()+1; ++j) {
            if (dp[i-1][j]) {
                dp[i][j] = dp[i][j] || (s1[i-1] == s3[i+j-1]);
            }
            if (dp[i][j-1]) {
                dp[i][j] = dp[i][j] || (s2[j-1] == s3[i+j-1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

int main() {
    bool ans = CanInterleave("aabcc", "dbbca", "aadbbbbcac");
    cout << "ans=" << ans << endl;
    return 0;
}

