#include <bits/stdc++.h>

using namespace std;

void fn(int len)
{
    freopen("in.in", "r", stdin);
    string s;
    cin >> s;
    int n = (int)s.size();
    int i = 0, j = 0;
    vector<bool> present(26, false);
    while (j < n)
    {
        while (present[s[j] - 'a'])
        {
            present[s[i++] - 'a'] = false;
        }
        present[s[j++] - 'a'] = true;
        if (j - i == len)
        {
            break;
        }
    }
    cout << j << endl;
}

void firstHalf() //  1282
{
    fn(4);
}

void secondHalf() //  3513
{
    fn(14);
}

int main()
{
    // firstHalf();
    secondHalf();
}