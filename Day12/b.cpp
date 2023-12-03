#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lld;

#define fo(n)       for(int i = 0; i < (int)n; i++)
#define rep(i,x,n)  for(auto i = x; i < n; i++)
#define pf          push_front
#define pb          push_back
#define ppf         pop_front
#define ppb         pop_back
#define ff          first
#define ss          second
#define mem0(a)     memset(a,0,sizeof(a))
#define all(v)      v.begin(),v.end()
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define ch          " "
#define nline       "\n"
#define LIGHTS ios_base::sync_with_stdio(false); 
#define OUT cin.tie(NULL);

const int INF  =  1e9 + 20;
const ll INFLL =  2e18 + 20;
const lld pi   =  3.14159265358979323846;

const int MOD  =  1e9 + 7;
const int MAX  =  1e5 + 20;

void usaco(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}

#define int ll

int ans = 0;

map<string, vector<string>> mp;

bool isSmall(string s) {
    bool ok = true;
    for(auto x : s) {
        ok &= (x >= 'a' && x <= 'z');
    }
    return ok;
}

vector<vector<string>> allPaths;

void dfs(string curr, string prev, vector<string> path, bool taken) {    
    if(curr == "end") {
        cout << "start ";
        for(auto x : path) {
            cout << x << ch;
        }
        cout << nline;
        allPaths.pb(path);
        ans++;
        return;
    }
    for(auto x : mp[curr]) {
        if(isSmall(x) && find(path.begin(), path.end(), x) != path.end()) {
            if(!taken) {
                taken = true;
            }
            else {
                continue;
            }
        }
        path.pb(x);
        dfs(x, curr, path, taken);
        path.ppb();
    }
}

void solve() {
    string s;
    while(cin >> s) {
        size_t pos = s.find('-');
        string u = s.substr(0, pos);
        string v = s.substr(pos + 1);
        if(v != "start" && u != "end") {
            mp[u].pb(v);
        }
        if(u != "start" && v != "end") {
            mp[v].pb(u);
        }
        // cout << u << ch << v << nline;
    }
    for(auto [x, y] : mp) {
        cout << x << " : ";
        for(auto t : y) {
            cout << t << ch;
        }
        cout << nline;
    }

    dfs("start", "", {}, false);

    cout << "ans = " << ans << nline;

}      

signed main() {
    LIGHTS OUT;

    // auto start = chrono::high_resolution_clock::now();

    // #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);   
        freopen("out.txt","w",stdout);
    // #endif

    // usaco("");

    int t = 1;
    // cin >> t;

    for(int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";
        // cout << nline;
        solve();
    }

    // auto end = chrono::high_resolution_clock::now();
    // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    // time_taken *= 1e-9;
    // cerr << "time taken: " << fixed << time_taken << setprecision(9) << endl;   
}
