#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) (a).begin(), (a).end()
using ll2 = pair<ll, ll>;

int main(void)
{
    ll n, m;
    cin >> n >> m;
    vector<ll> u(m), v(m);
    for (ll i = 0; i < m; i++)
        cin >> u[i] >> v[i];

    vector<vector<ll>> e2e(n, vector<ll>());
    for (ll i = 0; i < m; i++)
    {
        e2e[u[i] - 1].push_back(v[i] - 1);
        e2e[v[i] - 1].push_back(u[i] - 1);
    }

    vector<ll> search_stack;
    vector<bool> is_step(n);
    ll cnt;
    for (cnt = 0;; cnt++)
    {
        // 終了判定
        bool is_end = true;
        for (ll i = 0; i < n; i++)
        {
            if (!is_step[i])
            {
                is_end = false;
                search_stack.push_back(i);
                is_step[i] = true;
                break;
            }
        }
        if (is_end)
            break;

        // 探索
        for (; search_stack.size();)
        {
            auto now = search_stack.back();
            search_stack.pop_back();

            for (ll i = 0; i < e2e[now].size(); i++)
            {
                if (is_step[e2e[now][i]])
                    continue;
                is_step[e2e[now][i]] = true;

                search_stack.push_back(e2e[now][i]);
            }
        }
    }

    cout << cnt << endl;
    return 0;
}