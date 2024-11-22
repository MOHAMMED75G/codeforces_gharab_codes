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



ll sumOfDigits(ll n) {
    ll sum = 0;
    while (n != 0) {
        sum += n % 10; 
        n /= 10;       
    }
    return sum;
}


void solve(){
  ll n,s;
  cin>>n>>s;

  ll l=0;
  ll r=n;
  
  while(l<r){
    ll mid=(l+r)/2;
    ll sum=abs(sumOfDigits(mid)-mid);
  
    if(sum<s){
      l=mid+1;
    }
    else{
      r=mid;
    }
  }
  if(abs(sumOfDigits(l)-l)>=s){
    cout<<n-l+1<<endl;
    return;
  }
  cout<<n-l<<endl;


}




int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        	cout<<fixed<<setprecision(4);
   
 // ll t;cin>>t;while(t--)
   solve();
}