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






void solve(){
ll n;
cin>>n;
  vl v(n);
  ll d,k;
  cin>>d>>k;
  vl o(n+2, 0); 
rep(i,0,k) {
    int l, r;
    cin >> l >> r;
    o[l] += 1;       
    o[r + 1] -= 1;  
}
vector<ll> res(n+1, 0); 
res[0] = 0;
rep(i,1,n+1){
    res[i] = res[i - 1] + o[i]; 
}
ll max_sum = -1, min_sum = INF;
ll max_s = -1, min_s = -1; 
ll cur_sum = 0; 
rep(i,1,d+1) {
    cur_sum += res[i];
}
max_sum = cur_sum;
min_sum = cur_sum;
max_s = 1;
min_s = 1;
rep(i,d+1,n+1) {
    cur_sum += res[i] - res[i - d]; 
    if (cur_sum > max_sum) {
        max_sum = cur_sum;
        max_s = i - d + 1;
    }
    if (cur_sum < min_sum) {
        min_sum = cur_sum;
        min_s = i - d + 1;
    }
}
cout << max_s << " " << min_s << endl;

}




int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        	cout<<fixed<<setprecision(4);
   
  ll t;cin>>t;while(t--)
   solve();
}