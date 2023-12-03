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

int fn(string s) {
    int ans = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        ans = ans * 10 + (s[i] - '0');
    }
    return ans;
}

vector<int> convert(string s) {
    vector<int> ans;
    string temp = "";
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] != ',') temp += s[i];
        else {
            ans.pb(fn(temp));
            temp = "";
        }
    }
    ans.pb(fn(temp));
    return ans;
}

bool check(vector<vector<int>> &a, int t) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(a[i][j] == t) {
                a[i][j] = -1;
                break;
            }
        }
    }
    for(int i = 0; i < 5; i++) {
        if(count(a[i].begin(), a[i].end(), -1) == 5) {
            return true;
        }
    }
    for(int j = 0; j < 5; j++) {
        int cnt = 0;
        for(int i = 0; i < 5; i++) {
            if(a[i][j] == -1)   cnt++;
        }
        if(cnt == 5)    return true;
    }
    return false;
}

void solve() {
    string s;
    cin >> s;
    // cout << s << nline << nline;

    vector<int> numbers = convert(s);

    vector<vector<vector<int>>> a;
    int t;
    while(cin >> t) {
        vector<vector<int>> temp;
        rep(i, 0, 5) {
            vector<int> temp2;
            rep(j, 0, 5) {
                if(!i && !j) {
                    
                }
                else {
                    cin >> t;
                }
                temp2.pb(t);
            }
            temp.pb(temp2);
        }
        a.pb(temp);
    }
    int n = 0;
    bool done = false;
    int mat = -1;
    for(; n < (int)numbers.size() && !done; n++) {
        for(int j = 0; j < (int)a.size(); j++) {
            if(check(a[j], numbers[n])) {
                done = true;
                mat = j;
                break;
            }
        }
        if(done)    break;
    }
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(a[mat][i][j] != -1)  sum += a[mat][i][j];
        }
    }
    cout << "printing : " <<  sum << ch << numbers[n] << nline;
    cout << sum * numbers[n] << nline;

    // for(auto x : a) {
    //     for(auto y : x) {
    //         for(auto z : y) cout << z << ch;
    //         cout << nline;
    //     }
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
