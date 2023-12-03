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

void solve() {
    string s;
    vector<vector<string>> symbols, a;
    while(getline(cin, s)) {
        // cout << s << nline;
        string delimiter = "|";
        size_t Pos = s.find(delimiter);
        string  temp = (s.substr(0, Pos - 1));
        
        size_t pos;
        string token;
        vector<string> t;
        delimiter = " ";
        while ((pos = temp.find(delimiter)) != string::npos) {
            // accounts for the  space at the end of the first part of the input
            token = temp.substr(0, pos);
            // cout << token << nline;
            t.pb(token);
            temp.erase(0, pos + delimiter.length());
        }
        t.pb(temp);
        symbols.pb(t);
        t.clear();
        
        temp = (s.substr(Pos + 2));
        
        while ((pos = temp.find(delimiter)) != string::npos) {
            // put a comma at the end of the input string
            token = temp.substr(0, pos);
            // cout << token << nline;
            t.pb(token);
            temp.erase(0, pos + delimiter.length());
            if(t.size() == 3)   break;
        }
        t.pb(temp);
        a.pb(t);
    }
    int n = (int)symbols.size();
    cout << "n = " << symbols.size() << nline;

    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        for(auto x : a[i]) {
            int sz = (int)x.size();
            if(sz == 2 || sz == 3 || sz == 4 || sz == 7) {
                ans++;
            }
        }
    }

    cout << "ans = " << ans << nline;
    
    
    // for(auto x : symbols) {
    //     for(auto y : x) cout << y << ch;
    //     cout << nline;
    // }

    // for(int i = 0; i < n; i++) {
    //     for(auto x : symbols[i])   cout << x << ch;
    //     cout << "= ";
    //     for(auto x : a[i])   cout << x << ch;
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
