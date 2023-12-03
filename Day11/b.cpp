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

vector<int> convert(string s) {
    vector<int> ans;
    for(auto x : s) {
        ans.pb(x - '0');
    }
    return ans;
}

int X[] = {1, -1, 0, 0, 1, 1, -1, -1};
int Y[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool valid(int i, int j) {
    return (i >= 0 && i < 10 && j >= 0 && j < 10);
}

queue<pii> possible(vector<vector<int>> &a) {
    queue<pii> ans;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(a[i][j] == 10) {
                ans.push({i, j});
            } 
        }
    }
    return ans;
}

void inc(vector<vector<int>> &a) {
    for(auto &x : a) {
        for(auto &y : x) {
            y = min(y + 1, 10LL);
        }
    }
}

bool check(vector<vector<bool>> a) {
    bool ans = true;
    for(auto x : a) {
        for(auto y : x) ans &= y;
    }
    return ans;
}

void solve() {
    vector<vector<int>> a;
    string s;
    while(cin >> s) {
        a.pb(convert(s));
    }
    // for(auto x : a) {
    //     for(auto y : x) cout << y << ch;
    //     cout << nline;
    // }

    int n = 10;
    int steps = 1000;
    int ans = 0;
    for(int step = 1; step <= steps; step++) {
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pii> q;
        inc(a);
        q = possible(a);
        // cout << "printing : " << (int)q.size() << nline;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                a[p.ff][p.ss] = 0;
                vis[p.ff][p.ss] = true;
                for(int j = 0; j < 8; j++) {
                    int x = p.ff + X[j];
                    int y = p.ss + Y[j];
                    if(!valid(x, y) || vis[x][y])    continue;
                    a[x][y] = min(10LL, a[x][y] + 1);
                }
            }
            q = possible(a);
        }
        if(check(vis)) {
            ans = step;
            break;
        }
    }
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
