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
  ll n;cin>>n;
  string s;
  cin>>s;
   
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    vector<pair<int, char>> freqList;
    for (auto &entry : freq) {
        freqList.push_back({entry.second, entry.first});
    }
    
    sort(freqList.rbegin(), freqList.rend()); 
    
    string result(n, ' ');
    int idx = 0;
    for (auto &entry : freqList) {
        int count = entry.first;
        char ch = entry.second;
        
        for (int i = 0; i < count; i++) {
            result[idx] = ch;
            idx += 2;
            if (idx >= n) {
                idx = 1; 
            }
        }
    }
    
   
  

    cout << result << endl;



  


}




int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        	cout<<fixed<<setprecision(4);
   
  ll t;cin>>t;while(t--)
   solve();
}