#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) (a).begin(), (a).end()
using ll2 = pair<ll, ll>;

// main以外の関数からも参照するためにグローバルで定義
ll n, m;
// ある交差点からどこの交差点へ繋がっているかを保存する2次元配列を作成。
vector<vector<ll>> e2e;
// ある交差点に行った事があるかを管理する配列（mapを使う事も多い）
vector<bool> is_step;

bool solve_dfs(ll now)
{
    // ゴールだった場合の処理
    if (now == n - 1)
        return true;

    // 今の交差点から次に行ける交差点を探す。
    for (ll i = 0; i < e2e[now].size(); i++)
    {
        // 探索済みでないか確認。
        if (is_step[e2e[now][i]])
            continue;
        is_step[e2e[now][i]] = true; // ここを忘れると、無限にメモリを使って、珍しいエラーが出る（1敗）。

        // 次の候補を探索。関数内部で同じ関数を呼ぶみたいなのを再帰という。
        bool result = solve_dfs(e2e[now][i]);
        if (result)
            return true;
    }

    return false;
}

int main(void)
{
    // 入力
    cin >> n >> m;
    vector<ll> a(m), b(m);
    for (ll i = 0; i < m; i++)
        cin >> a[i] >> b[i];

    // 注意！宣言時にサイズが分かっていなかった配列はここでresizeする必要がある！
    e2e.resize(n, vector<ll>());
    for (ll i = 0; i < m; i++)
    {
        // ここで0スタートのインデックスに揃えている。
        e2e[a[i] - 1].push_back(b[i] - 1);
        e2e[b[i] - 1].push_back(a[i] - 1);
    }
    is_step.resize(n);

    // 交差点0から探索を始める。
    // 実際には一々変数に入れずにそのままぶち込むことが多い。
    bool result = solve_dfs(0);
    cout << (result ? "Yes" : "No") << endl;

    return 0;
}