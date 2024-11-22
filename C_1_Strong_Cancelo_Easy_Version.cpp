// hi it's me , Enigma
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
typedef         vector<ll>vl;
typedef         deque<ll>dq;
typedef         pair<ll,ll>pl;
#define pll pair<long long ,long long >
#define vpl vector<pll >
#define         yes {cout<<"YES"<<endl;}
#define         no {cout<<"NO"<<endl;}
#define         CR(_) {cout<<_<<endl;}
#define endl '\n'
#define testanswer if(test){cout<<"YES"<<endl;}  else {cout<<"NO"<<endl}
#define lfs cout<<fixed<<setprecision(10)
#define cinto(x) cin>>x;v.PB(x)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
#define spa << " " <<
#define F first
#define S second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
#define ar array
const ll MOD = 1e9+7;
const ll mod = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
// freopen("input.txt,"r",stdin);
// freopen("output.txt,"w",stdout);
template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}



void solve() {
    ll n;
    cin >> n;
    vl c(n), f(n), a(n);
    cin >> c >> f >> a;
ll ans=0;
   rep(i,0,n){
    ll h=max(f[i],a[i]);
    ll l=min(f[i],a[i]);
    int d=0;
    if( c[i] <= l )
    {
        d = h - l;
        c[i] += d;
        ans += d;
        h=l;
        if( c[i] <= h )
        {
            ll r=0; 
            if( (h - c[i]) % 3 != 0)r=1;
            ans += (h - c[i]) / 3 * 2 + 1+r;
        }
        else
        {
            d  = ( c[i]-h) / 2;
            d=max(d,0);
            while( c[i] - d <= h + d )
            {
                d--;
            }
            ans-= d;
        }
    }
    else if( c[i] <= h )
    {
            d  = (h-c[i] ) / 2;
            d=max(d,0);
        while( c[i] + d <= h - d )
        {
            d++;
        }
        ans += d;
    }
   
   }
   CR(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) solve();
}