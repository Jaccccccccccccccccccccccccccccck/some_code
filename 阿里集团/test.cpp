/*
使用c++回答一下问题：
小红想知道由n个"red"交错而成多少种不同的长度为3n的字符串
答案请对10^9-7取模。
所谓n个"red"交错而成，即字符串可以拆分成n个"red"了序列
输入描述：
  输入仅包含一行一个正整数n，其中1 <= n <= 200
输出描述：
  不同的字符串方案数，对10^9-7取模

一个例子是：
输入2，输出5。
2个“red”交错可以组成
redred
rreedd
reredd
rreded
rerded
共五种不同的字符串
*/

#include <iostream>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;
    int dp[n+1][n+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k <=j; k++) {
                // dp[i][j][k-1]
                if(k > 0)
                    dp[i][j][k] = (dp[i][j][k] + dp[i][j][k-1]) % MOD ;
                // dp[i-1][j][k]
                if(i - 1 >= 0 && i - 1 >= j)
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]) % MOD;
                // dp[i][j-1][k]
                if(j - 1 >= 0 && j - 1 >= k)
                    dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k]) % MOD;
                // cout << i << " " << j << " " << k << " : " << dp[i][j][k] << endl;
            }
        }
    }
    cout << dp[n][n][n] << endl;
}