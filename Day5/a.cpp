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

int convert(string s) {
    int ans = 0;
    for(auto x : s) {
        ans *= 10;
        ans += (x - '0');
    }
    return ans;
}

void solve() {
    string t;
    vector<pii> start, end;
    int prev = 0;
    string x, y;
    int mxX = 0, mxY = 0; 
    while(cin >> t) {
        if(t == "->")   continue;
        // cout << t << nline;
        x = "", y = "";
        int pos = t.find(',');
        x = t.substr(0, pos);
        y = t.substr(pos + 1);
        mxX = max(mxX, convert(x));
        mxY = max(mxY, convert(y));
        if(prev) {
            // take in for the end
            end.pb({convert(x), convert(y)});
        }
        else {
            // take for the start
            start.pb({convert(x), convert(y)});
        }

        prev = !prev;
    }

    // for(int i = 0; i < (int)start.size(); i++) {
    //     cout << start[i].ff << ch << start[i].ss << " -> " << end[i].ff << ch << end[i].ss << nline;
    // }

    cout << "printing : max = " << mxX << ch << mxY << nline;
    
    vector<vector<int>> a(mxY + 1, vector<int>(mxX + 1, 0));

    // plot

    for(int i = 0; i < (int)start.size(); i++) {
        if(start[i].ff == end[i].ff) {
            int y = min(start[i].ss, end[i].ss);
            // cout << "printing : " << start[i].ff << ch << start[i].ss << ch << "y = " << y << nline;
            for(; y <= max(start[i].ss, end[i].ss); y++) {
                // a[start[i].ff][y]++;
                a[y][start[i].ff]++;
                // cout << "pos = " << start[i].ff << ch << y << nline;
            }
        }
        else if(start[i].ss == end[i].ss) {
            int x = min(start[i].ff, end[i].ff);
            // cout << "printing : " << start[i].ff << ch << start[i].ss << ch << "x = " << x << nline;
            for(; x <= max(start[i].ff, end[i].ff); x++) {
                // a[x][start[i].ss]++;
                a[start[i].ss][x]++;
                // cout << "pos = " << x << ch << start[i].ss << nline;
            }
        }
    }

    int ans = 0;

    for(auto x : a) {
        for(auto y : x) ans += (y >= 2);
    }

    cout << ans << nline;

    // for(auto x : a) {
    //     for(auto y : x) cout << y << ch;
    //     cout << nline;
    // }

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
