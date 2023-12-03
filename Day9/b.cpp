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

bool valid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

int floodfill(vector<string> &a, int i, int j, int n, int m) {
    if(a[i][j] == '9')  return 0;
    char curr = a[i][j];
    a[i][j] = '-';
    int sum = 0;
    for(int k = 0; k < 4; k++) {
        int x = i + X[k];
        int y = j + Y[k];
        if(valid(x, y, n, m) && a[x][y] == (curr + 1) && a[x][y] != '9') {
            // cout << "in = " << curr << ch << a[x][y] << nline;
            // cout << "i = " << i << ch << j << ch << x << ch << y << nline;
            sum += floodfill(a, x, y, n, m);
        }
        // cout << "printing : " << i << ch << j << ch << sum << nline;
    }
    // a[i][j] = curr;
    return sum + 1;
}

void solve() {
    string s;
    vector<string> a;
    while(cin >> s) {
        // cout << s << nline;
        a.pb(s);
    }
    // a = n * m
    int n = (int)a.size();
    int m = (int)a[0].size();
    vector<pii> basin;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool low = true;
            for(int k = 0; k < 4; k++) {
                int x = i + X[k];
                int y = j + Y[k];
                if(valid(x, y, n, m)) {
                    low &= (a[i][j] < a[x][y]);
                }
            }
            if(low) {
                basin.pb({i, j});
            }
        }
    }

    vector<int> ans;

    for(auto x : basin) {
        ans.pb(floodfill(a, x.ff, x.ss, n, m));
        // cout << x.ff << ch << x.ss << nline;
    }
    sort(ans.rbegin(), ans.rend());

    for(auto x : ans)   cout << x << ch;
    cout << nline;

    cout << "cnt = " << (int)basin.size() << nline;
    cout << "ans = " << ans[0] * ans[1] * ans[2] << nline;
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
