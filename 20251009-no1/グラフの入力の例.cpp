#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) (a).begin(), (a).end()
using pos = pair<ll, ll>;

int main(void)
{

    ll m, n;
    cin >> m >> n;

    vector<ll> a(m), b(m);
    for (ll i = 0; i < m; i++)
        cin >> a[i] >> b[i];

    vector<vector<ll>> e2e(n, vector<ll>());
    for (ll i = 0; i < m; i++)
    {
        e2e[a[i]].push_back(b[i]);
        e2e[b[i]].push_back(a[i]);
    }

    return 0;
}