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
string to_bin(ll n){
    string ch="";
    ll i = 0;
    while (n>0) {
        char a=n%2+'0';
        ch=a+ch;
        n = n / 2;
        i++;
    }
    return ch;
}
ll binary_search(vl v,ll x){
ll s=0;
ll f=v.size()-1;
while(s<=f){
    ll m=(s+f)/2;
    if(v[m]==x){
        return m;
    }else if(v[m]<x){
        s=m+1;
    }
    else{
        f=m-1;
    }
}
return -1;


}
ll nCr(ll n,ll k)
{
  ll res = 1;

      // Since C(n, k) = C(n, n-k)
      if ( k > n - k )
          k = n - k;

      // Calculate value of
      // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
      for (ll i = 0; i < k; ++i)
      {
          res *= (n - i);
          res /= (i + 1);
      }

      return res;
}
ll ToInt(char ch)
{
  return ch-'0';
}
char ToChar(ll a)
{
  return a+'0';
}
bool pairCompare2(const std::pair<ll, int>& a, const std::pair<ll, int>& b) {
    if (a.first != b.first) {
        return a.first > b.first; // Sort in descending order based on the first key (ll)
    } else {
        return a.second < b.second; // If first keys are equal, sort in increasing order based on the second key (int)
    }
}
bool compar(string s,string c){
     bool test=false;
    rep(i,0,s.size()){
    if ((int)s[i]>(int)c[i]) {test=true;break;}
    else if ((int)s[i]==(int)c[i])continue;
    else break;}
    return test;
}
int isSubstring(string s1, string s2)
{
    int M = s1.size();
    int N = s2.size();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return 1;
    }

    return 0;
}


// Function to calculate nCr (binomial coefficient)
long long bino(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    vector<long long> C(r + 1, 0);
    C[0] = 1; // Base case

    for (int i = 1; i <= n; ++i) {
        for (int j = min(i, r); j > 0; --j) {
            C[j] = C[j] + C[j - 1];
        }
    }
    return C[r];
}
ll add(ll a, ll b){
    return (a + b) % mod;
}
ll sub(ll a, ll b){
    return (a - b + mod) % mod;
}
ll mul(ll a, ll b){
    return (((ll)a%mod) * ((ll)b%mod)) % mod;
}
ll bin_pow(ll n, ll k){
    if(k == 0)return 1;
    if(k == 1)return n;
    if(k % 2 == 1) return mul(n, bin_pow(n, k - 1));
    ll t = bin_pow(n, k / 2);
    return mul(t, t);
}
ll power(ll x , ll y)
{
    return bin_pow(x,y)%MOD;
}
ll mod_inv (ll a)
{
    return power(a,MOD-2);
}
const int MAXN = 200001;
int fact[MAXN];
int inv_fact[MAXN];
ll rev(int x){
    return bin_pow(x, mod - 2);
}
void comb(){
    fact[0] = 1;
    for(int i = 1;i < MAXN;i++){
        fact[i] = mul(i, fact[i - 1]);
    }
    inv_fact[MAXN - 1] = rev(fact[MAXN - 1]);
    for(int i = MAXN - 2;i >= 0;i--){
        inv_fact[i] = mul(inv_fact[i + 1], i + 1ll);
    }
}
int C(int n, int k){
    //C(n, k) = n! / ((n - k)! * k!)
    if(n < k || k < 0)return 0;
    return mul(fact[n], mul(inv_fact[k], inv_fact[n - k]));
}
ll countSubsequences(int n, int x, int k) {
    ll y = n - x; // Number of zeros
    ll minOnes = k / 2+1; // Ceiling of k/2
    long long totalCount = 0;

    for (int i = minOnes; i <= min(x, k); ++i) {
        totalCount =add(totalCount,mul(C(x,i),C( y,k - i)));
      
      
    }

    return totalCount;
}



int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}



void solve() {
    int n;cin>>n;
    vector<int> parent(n + 1, -1);
    queue<int> q;
    parent[1] = 0;
    q.push(1);

    vector<pair<int, int>> edges;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 1; i <= n; ++i) {
            if (i != node && parent[i] == -1) {
                int res = query(node, i);
                if (res == node) {
                    parent[i] = node;
                    edges.push_back({node, i});
                    q.push(i);
                } else if (res == i) {
                    parent[node] = i;
                    edges.push_back({i, node});
                }
            }
        }
    }

     cout << "! ";
    for (const auto& edge : edges) {
        cout << edge.first << " " << edge.second << " ";
    }
    cout << endl;
    cout.flush();
}


int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        	cout<<fixed<<setprecision(4);
   
  ll t;cin>>t;while(t--)
   solve();
}