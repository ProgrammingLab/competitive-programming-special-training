#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) (a).begin(), (a).end()
using ll2 = pair<ll, ll>;

int main(void)
{
    const ll DIVISOR = 998244353;

    // 入力
    ll n, m, k;
    cin >> n >> m >> k;

    // DP表を作成
    // dp[i][j] (i: 要素数, j: 総和)->場合の数
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
    dp[0][0] = 1;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < k; j++)
        {
            for (ll new_item = 1; new_item <= m && j + new_item <= k; new_item++)
            {
                // ちょくちょく余りにして、オーバーフローを防ぐ。mod演算。
                dp[i + 1][j + new_item] += dp[i][j] % DIVISOR;
                dp[i + 1][j + new_item] %= DIVISOR;
            }
        }
    }

    // 出力
    ll pattern_sum = 0;
    for (ll i = 0; i <= k; i++)
    {
        // ちょくちょく余りにして、オーバーフローを防ぐ。mod演算。
        pattern_sum += dp[n][i] % DIVISOR;
        pattern_sum %= DIVISOR;
    }
    cout << pattern_sum << endl;

    return 0;
}