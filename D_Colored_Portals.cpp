#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
#define pll pair<long long, long long>
#define vpl vector<pll>
#define yes {cout<<"YES"<<endl;}
#define no {cout<<"NO"<<endl;}
#define CR(_) {cout<<_<<endl;}
#define endl '\n'
#define F first
#define S second
#define PB push_back
const ll MOD = 1e9+7;
const ll INF = 1e18;

ll bfs(int s, int e, vector<string>& p, unordered_map<char, vector<int>>& m, int n) {
    vector<int> d(n + 1, numeric_limits<int>::max());
    vector<bool> v(n + 1, false);
    queue<int> q;

    d[s] = 0;
    v[s] = true;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (char c : p[cur]) {
            for (int nei : m[c]) {
                int nd = d[cur] + abs(cur - nei);
                if (!v[nei] || nd < d[nei]) {
                    d[nei] = nd;
                    v[nei] = true;
                    q.push(nei);
                }
            }
        }
    }

    return d[e] == numeric_limits<int>::max() ? -1 : d[e];
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<string> p(n + 1);
    unordered_map<char, vector<int>> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        m[p[i][0]].push_back(i);
        m[p[i][1]].push_back(i);
    }
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        
        if (x == y) {
            CR(0);
            continue;
        }
        
        int mc = abs(x - y);
        bool test = false;
        for (char c : p[x]) {
            if (p[y].find(c) != string::npos) {
                test = true;
                break;
            }
        }
        
        if (test) {
            CR(mc)
            continue;
        }
        
        ll res = bfs(x, y, p, m, n);
        cout << res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(4);
    
    ll t;
    cin >> t;
    while (t--)
        solve();
}
