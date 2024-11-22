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
#define MAXN 100001
vector<int> primes(MAXN + 1, 1);

void sieve_of_eratosthenes() {
    // Create a boolean vector to mark primes



    // Starting with the smallest prime
    for (int p = 2; p * p <= MAXN; ++p) {
        // If primes[p] is still true, it is a prime
        if (primes[p]) {
            // Mark all multiples of p as non-prime
            for (int i = p * p; i <= MAXN; i += p)
                primes[i] = false;
        }
    }}




void solve(vl k){
  ll l,r,m;
  cin>>l>>r>>m;

  rep(i,0,m){
    ll q,a,b;
    cin>>q>>a>>b;
    if(q==1){
        auto it=lower_bound(ALL(k),a);
        ll j=it-k.begin();
        if(j+b-1>MAXN){CR(-1);}
      else if(k[j+b-1]>r){CR(-1);}

        else{
            if(b==0){
            if(primes[a]){CR(-1);}
            else {cout<<k[j]-a<<endl;}
            }
           else{   ll x;
            if(j+b>MAXN)x=r;
            else x=k[j+b];
            cout<<min( k[j+b],r)-k[j+b-1]+(r< k[j+b])<<endl;}


        }}

    else{
        auto it=lower_bound(ALL(k),a);
          ll j=it-k.begin();
        if(!primes[a])j--;
        if(j-b+1<0){CR(-1);}
        else if(k[j-b+1]<l){CR(-1);}

        else{
            ll x;
        if(j-b>=0) x=k[j-b];
        else x=l;
            cout<<max( x,l)-k[j-b+1]+1<<endl;}



    }

  }




}




int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        	cout<<fixed<<setprecision(4);
            sieve_of_eratosthenes() ;
            vl k;
           rep(i,2,1e5+1){
            if(primes[i] == 1)k.PB(i);
           }
         //  aff(k);

  ll t;cin>>t;while(t--)
   solve(k);
}
