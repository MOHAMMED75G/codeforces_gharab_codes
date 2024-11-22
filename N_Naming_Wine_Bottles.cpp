// hi it's me , Enigma
#include <bits/stdc++.h>
#include <string>
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





string base26Encode(uint64_t value) {
    const string charset = "abcdefghijklmnopqrstuvwxyz";  // Only lowercase letters
    string encoded = "";

    while (value > 0) {
        encoded += charset[value % 26];
        value /= 26;
    }

    // Reverse the string because the encoding builds it from least significant to most significant
    reverse(encoded.begin(), encoded.end());
    
    return encoded;
}
string floatToUniqueString(double number) {
    // Scale and convert the float into an integer for consistent hashing
    uint64_t scaled_value = static_cast<uint64_t>(number * 100000000000);  // Scale to handle decimal precision
    return base26Encode(scaled_value);
}
void solve(){
  
   
  unordered_map<double, string> floatToStringMap;
  

  ll n;
  cin>>n;
  vector<double> v;

  rep(i,0,n){
    string str;
    cin>>str;
    str=str.substr(0,str.length()-1);
   // cout<<str<<endl;
     double num; 
   
     stringstream ss(str);
    ss >> num;
      v.PB(num);
  }
 // aff(v);
  
   
    

   for (double num :v) {
        floatToStringMap[num] = floatToUniqueString(num);
    }

     rep(i,0,n){
        cout<<floatToStringMap[v[i]];
        cout<<endl;
        
     }
    



}




int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        	cout<<fixed<<setprecision(10);
   
 // ll t;cin>>t;while(t--)
   solve();
}