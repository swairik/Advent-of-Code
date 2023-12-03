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

vector<int> fn(vector<string> &a) {
    
}

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

    for(int i = 0; i < n; i++) {
        vector<string> signals = fn(symbols[i]);
    }

    int ans = 0;
    // for(auto x : a) {
    //     int temp = 0;
    //     for(auto y : x) {
    //         sort(y.begin(), y.end());
    //         for(int i = 0; i < 10; i++) {
    //             if(signals[i] == y) {
    //                 temp = (temp * 10) + i;
    //                 cout << "y = " << y << ch << temp << nline;
    //                 break;
    //             }
    //         }
    //     }
    //     cout << "temp = " << temp << nline;
    //     ans += temp;
    // }
    cout << ans << nline;

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
