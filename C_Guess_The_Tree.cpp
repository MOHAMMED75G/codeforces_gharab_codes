#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
typedef vector<ll> vl;
typedef deque<ll> dq;
typedef pair<ll, ll> pl;
#define pll pair<long long, long long>
#define vpl vector<pll>
#define yes {cout << "YES" << endl;}
#define no {cout << "NO" << endl;}
#define CR(_) {cout << _ << endl;}
#define testanswer if(test){cout<<"YES"<<endl;} else {cout<<"NO"<<endl;}
#define lfs cout << fixed << setprecision(10)
#define cinto(x) cin >> x; v.PB(x)
#define ALL(a)  (a).begin(), (a).end()
#define ALLR(a)  (a).rbegin(), (a).rend()
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define F first
#define S second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define aff(v) for(auto e : v) cout << e << " "; cout << endl;
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
#define ar array
const ll MOD = 1e9+7;
const ll mod = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v) cin >> it;
    return istream;
}

void solve() {
    const ll M = 1004;
    bool vis[M];
    ll pr[M];
    ll n; cin >> n;

    rep(i, 1, n + 1) vis[i] = false;
    vis[1] = true;

    rep(i, 2, n + 1) {
        if (!vis[i]) {
            stack<pair<ll, ll>> st;
            st.push({1, i});

            while (!st.empty()) {
                auto [u, v] = st.top();
                st.pop();

                cout << "? " << u <<" "<< v << endl;
                ll x; cin >> x;

                if (x == u || x == v) {
                    pr[v] = u;
                    vis[v] = true;
                    break;
                }

                if (!vis[x]) st.push({u, x});
                st.push({x, v});
            }
        }
    }

    cout << "! ";
    rep(i, 2, n + 1) {
        cout << i <<" "<< pr[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(4);
    ll t; cin >> t; while(t--) solve();
}
