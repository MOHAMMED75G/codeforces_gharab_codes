// Hi, it's me, Enigma
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
#define endl '\n'
#define testanswer if (test) {cout << "YES" << endl;} else {cout << "NO" << endl;}
#define lfs cout << fixed << setprecision(10)
#define cinto(x) cin >> x;v.PB(x)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
#define spa << " " <<
#define F first
#define S second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define aff(v) for (auto e : v) cout << e << " "; cout << endl;
#define rep(i, n, m) for (ll i = (n); i < (ll)(m); i++)
#define rrep(i, n, m) for (ll i = (ll)(m) - 1; i >= (ll)(n); i--)
#define ar array
const ll MOD = 1e9+7;
const ll mod = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
// freopen("input.txt,"r",stdin);
// freopen("output.txt,"w",stdout);
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}

void solve() {
  int n;cin>>n;
    vector<tuple<int, int, int, int>> v;
    rep(i,0,n)
    {int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    v.PB(MT(x1, y1, x2, y2));
    }
    vector<int>res(n);
    rep(i,0,n)
        {   int x1=get<0>(v[i]),
            y1=get<1>(v[i]),
            x2=get<2>(v[i]),
            y2=get<3>(v[i]);
            
            rep(j,0,n)
            {
                if(j!=i){
            int x11=get<0>(v[j]),
            y11=get<1>(v[j]),
            x22=get<2>(v[j]),
            y22=get<3>(v[j]);
            if((x11>=min(x1,x2) && x11<=max(x1,x2) && y11>=min(y1,y2) && y11<=max(y1,y2))||
                (x22>=min(x1,x2) && x11<=max(x1,x2) && y22>=min(y1,y2) && y11<=max(y1,y2)) ||
                (x22>=min(x1,x2) && x11+x22<=max(x1,x2)&& y11>=min(y1,y2) && y11<=max(y1,y2))||
                (x11>=min(x1,x2) && x11<=max(x1,x2) && y11+y22>=min(y1,y2) && y11+y22<=max(y1,y2)) ) 
                    res[i]++;}}
        }
    sort(ALLR(res)) ;
    cout<<res[0]+1;
            
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(4);

   // ll t;cin >> t;while (t--) 
   solve();
}