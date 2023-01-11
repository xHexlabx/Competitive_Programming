#include <bits/stdc++.h>
using namespace std;
int n;
void solve(string s)
{
    if (s.length() == n)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                cout << s << ' ';
                s[i] = '1';
                cout << s << ' ';
                s[i] = '0';
                cout << '\n';
            }
        }
    }
    else
    {
        solve(s + '0');
        solve(s + '1');
    }
}
int main()
{
    ios_base ::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    solve("");

    return 0;
}