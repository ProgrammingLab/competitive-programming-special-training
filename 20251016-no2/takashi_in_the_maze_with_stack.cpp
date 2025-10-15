#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) (a).begin(), (a).end()
using ll2 = pair<ll, ll>;

int main(void)
{
    // 入力
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    for (ll i = 0; i < m; i++)
        cin >> a[i] >> b[i];

    // ある交差点からどこの交差点へ繋がっているかを保存する2次元配列を作成。
    vector<vector<ll>> e2e(n, vector<ll>());
    for (ll i = 0; i < m; i++)
    {
        // ここで0スタートのインデックスに揃えている。
        e2e[a[i] - 1].push_back(b[i] - 1);
        e2e[b[i] - 1].push_back(a[i] - 1);
    }

    // ある交差点に行った事があるかを管理する配列（mapを使う事も多い）
    vector<bool> is_step(n);

    // 探索スタック。依存する値が多い場合は、long longじゃなく、pairとかtupleとかを詰め込む事になる。
    vector<ll> search_stack(1);
    search_stack[0] = 0;
    for (; search_stack.size();)
    {
        // スタックの最後の要素を取り出す。
        auto now = search_stack.back();
        search_stack.pop_back();

        // ゴールだった場合の処理
        if (now == n - 1)
        {
            cout << "Yes" << endl;
            return 0;
        }

        // 今の交差点から次に行ける交差点を探す。
        for (ll i = 0; i < e2e[now].size(); i++)
        {
            // 探索済みでないか確認。
            if (is_step[e2e[now][i]])
                continue;
            is_step[e2e[now][i]] = true;

            // 次の候補を探索スタックに加える。
            search_stack.push_back(e2e[now][i]);
        }
    }

    // 全ての探索が終わっても見つからなかった場合。
    cout << "No" << endl;
    return 0;
}