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
  ll n,w;
  cin>>n>>w;
  vpl v;
  rep(i,0,n){
    ll a;cin>>a;
    v.PB(MP(a,i+1));
  }
  sort(ALL(v));

vl k;
ll ans=0;
  rep(i,0,n){
    ans+=v[i].F;
   
    if(ans>=w/2+w%2  && ans<=w){
     k.PB(v[i].S);
      break;
    
      
    }
   else if(ans>w){
    bool test=false;
    ll r=v[i].S;
     rep(j,i,n){
     if(v[j].F<=w && v[j].F>=w/2+w%2){
         test=true;
         r=v[j].S;
         break;
       }  }
   if(test){
    cout<<1<<endl;
    cout<<r<<endl;
    return;
   }
   else{
    cout<<-1<<endl;
    return;
   }}
  
   
    k.PB(v[i].S);



  }

  cout<<k.size()<<endl;
   sort(ALL(k));
    aff(k);

}




int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        	cout<<fixed<<setprecision(4);
   
  ll t;cin>>t;while(t--)
   solve();
}