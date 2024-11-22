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


ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};


int dfs(int x, int y, vector<vector<char>>& mat, vector<vector<ll>>& v) {
    int m = mat[0].size();
    int n = mat.size();
    vector<pair<int, int>> s;
    s.push_back({x, y});
    v[x][y] = 1;
    vector<pair<int, int>> nb;
    nb.push_back({x, y});
    int a = 0;

    while (!s.empty()) {
        int cx = s.back().F;
        int cy = s.back().S;
        s.pop_back();

        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (mat[nx][ny] == '*') {
                a++;
            } else if (mat[nx][ny] == '.' && !v[nx][ny]) {
                v[nx][ny] = 1;
                s.push_back({nx, ny});
                nb.push_back({nx, ny});
            }
        }
    }

    for (auto& p : nb) {
        v[p.F][p.S] = a;
    }

    return a;
}



void solve(){
   ll n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<char>> mat(n, vector<char>(m));
    rep(i,0,n) {
         rep(j,0,m){
            cin >> mat[i][j];
        }
    }
    
    vector<vector<ll>> visited(n, vector<ll>(m, 0));
 
    rep(i,0,k) {
        int x, y;
        cin >> x >> y;
        x--; y--;  
        
        if (visited[x][y]) {
            cout << visited[x][y] << endl;
        } else {
            cout << dfs(x, y, mat, visited) << endl;
        }
    }

  


}




int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        	cout<<fixed<<setprecision(4);
   
 // ll t;cin>>t;while(t--)
   solve();
}