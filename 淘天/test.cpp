/*
使用C++解决以下问题：
小红定义一个数组是“好数组”，当且仅当满足以下三个条
1.对于1< i <n,有1<ai<m
2.对于1< i <n,保证ai是i的倍数
3.a1 + a2+ ... + an 是n的倍数
现在给你n和m，请你求出满足条件的“好数组”数量。由于答案可能过大，请对10^9+7取模

输入描述
  两个正整数n和m，用空格隔开
  1<=n, m <= 1000
输出描述
  好数组的数量，答案对10^9+7取模
*/
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    int dp[n + 1][m * n + 1];

    for(int i = 1; i <= m; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < m * n + 1; j++) {
            for(int k = i; j - k > 0 && k <= m ;k += i) {
                dp[i][j] += dp[i-1][j-k];
                cout << i << " " << j << " " << k << " : " << dp[i][j] << " added " << dp[i-1][j-k]<< endl;
            }
        }
    }
    long long res = 0;
    for(int j = n; j <= m * n; j+=n) {
        res =  (res + dp[n][j]) % MOD;
        cout << "add " << n << " " << j << " : " << dp[n][j] << endl;
    }

    cout << res << endl;

    return 0;
}
