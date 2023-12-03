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
    vector<string> a;
    while(cin >> s) {
        a.pb(s);
    }

    map<char, int> points;
    points['('] = 1;
    points['['] = 2;
    points['{'] = 3;
    points['<'] = 4;

    vector<int> cnt;

    for(auto x : a) {
        stack<char> st;
        bool possible = true;
        for(auto y : x) {
            if(y == '(')    st.push('(');
            else if(y == '[')   st.push('[');
            else if(y == '{')   st.push('{');
            else if(y == '<')   st.push('<');

            else if(y == ')') {
                if(!st.empty() && st.top() == '(')  st.pop();
                else {
                    // illegal
                    possible = false;
                    break;
                }
            }
            
            else if(y == ']') {
                if(!st.empty() && st.top() == '[')  st.pop();
                else {
                    // illegal
                    possible = false;
                    break;
                }
            }
            else if(y == '}') {
                if(!st.empty() && st.top() == '{')  st.pop();
                else {
                    // illegal
                    possible = false;
                    break;
                }
            }
            else if(y == '>') {
                if(!st.empty() && st.top() == '<')  st.pop();
                else {
                    // illegal
                    possible = false;
                    break;
                }
            }
        }
        if(possible) {
            int ans = 0;
            // cout << "printing : ";// << x << nline;
            while(!st.empty()) {
                // cout << st.top() << ch;
                ans = (ans * 5) + points[st.top()];
                st.pop();
            }
            // cout << nline;
            cnt.pb(ans);
        }
    }

    sort(all(cnt));

    // for(auto x : cnt)   cout << x << nline;

    cout << "ans = " << cnt[(int)cnt.size() / 2] << nline;

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
