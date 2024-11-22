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
#define testanswer if(test){cout<<"YES"<<endl;}  else {cout<<"NO"<<endl;}
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

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
int countPrimes(int N) {
    if (N < 2) return 0;


    vector<bool> is_prime(N + 1, true);

    is_prime[0] = is_prime[1] = false;


    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {

            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int c = 0;
    ll i=3;
    if(N>=5)c=1;
    while(i<=N){
        if(i+2<=N && is_prime[i] && is_prime[i+2])c++;
        i++;
    }


    return c;
}
void solve(ll j){
    int N;
    cin >> N;

    int num_primes = countPrimes(N);
      cout <<"Case #"<<j<<": "<<num_primes<<endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(4);
    freopen("prime_subtractorization_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll j=0;
    ll t; cin >> t; while(t--)
        {j++;solve(j);}
}
