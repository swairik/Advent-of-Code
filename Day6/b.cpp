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
    vector<int> a(9, 0);
    while(cin >> s) {
        string delimiter = ",";
        string token;
        size_t pos;
        while ((pos = s.find(delimiter)) != string::npos) {
            // put a comma at the end of the input string
            token = s.substr(0, pos);
            // cout << token << nline;
            s.erase(0, pos + delimiter.length());
            a[stoi(token)]++;
        }
    }
    for(auto x : a) cout << x << " ";
    cout << nline;

    int n = (int)a.size();
    int days = 256;
    
    for(int d = 0; d < days; d++) {
        int cnt = 0;
        for(int i = 0; i < 9; i++) {
            if(!i) {
                cnt = a[i];
                a[i] = 0LL;
            }
            else {
                a[i - 1] = a[i];
                a[i] = 0LL; 
            }
        }
        a[6] += cnt;
        a[8] += cnt;
    }
    for(auto x : a) cout << x << ch;
    cout << nline;
    cout << "size = " << accumulate(a.begin(), a.end(), 0LL) << nline;
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
