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
    int n = (int)s.size();
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '1') {
            ans |= (1 << (n - i - 1));
        }
    }
    return ans;
}

void solve() {
    vector<string> s;
    string t;
    while(cin >> t) {
        s.push_back(t);
    }
    vector<string> o2(s.begin(), s.end());
    for(int i = 0; i < (int)s[0].size() && o2.size() > 1; i++) {
        int z = 0, o = 0;
        for(int j = 0; j < (int)o2.size(); j++) {
            if(o2[j][i] == '1')    o++;
            else    z++;
        }
        vector<string> temp;
        if(o >= z) {
            for(int j = 0; j < (int)o2.size(); j++) {
                if(o2[j][i] == '1')  temp.pb(o2[j]);
            }
        }
        else {
            for(int j = 0; j < (int)o2.size(); j++) {
                if(o2[j][i] == '0')  temp.pb(o2[j]);
            }
        }
        o2 = temp;
    }

    vector<string> co2(s.begin(), s.end());
    for(int i = 0; i < (int)s[0].size() && co2.size() > 1; i++) {
        int z = 0, o = 0;
        for(int j = 0; j < (int)co2.size(); j++) {
            if(co2[j][i] == '1')    o++;
            else    z++;
        }
        vector<string> temp;
        if(o >= z) {
            for(int j = 0; j < (int)co2.size(); j++) {
                if(co2[j][i] == '0')  temp.pb(co2[j]);
            }
        }
        else {
            for(int j = 0; j < (int)co2.size(); j++) {
                if(co2[j][i] == '1')  temp.pb(co2[j]);
            }
        }
        co2 = temp;
    }

    assert((int)o2.size() == 1);
    assert((int)co2.size() == 1);

    int oxygen = convert(o2[0]);
    int carbonDioxide = convert(co2[0]);

    cout << "printing : " << oxygen << ch << carbonDioxide << nline;

    cout << oxygen * carbonDioxide << nline;

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
