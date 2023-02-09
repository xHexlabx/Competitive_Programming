#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
bool cmp(pair<ull, int> a, pair<ull, int> b)
{
    return a.second < b.second;
}
const int N = 100001;
class Fenwick
{
public:
    ull fw[2][N];
    void update(int idx, ull val)
    {
        for (; idx < N; idx += (idx & -idx))
        {
            fw[0][idx] += val;
            fw[1][idx]++;
        }
    }
    pair<ull, int> query(int idx)
    {
        ull res = 0;
        int cnt = 0;
        for (; idx > 0; idx -= (idx & -idx))
        {
            res += fw[0][idx];
            cnt += fw[1][idx];
        }
        return {res, cnt};
    }
} fw;
pair<ull, int> arr[N];
int main()
{
    ios_base ::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ull res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + n, cmp);
    for (int i = n - 1; i >= 0; i--)
    {
        auto temp = fw.query(arr[i].first);
        res += temp.first + temp.second * arr[i].first;
        fw.update(arr[i].first, arr[i].first);
    }
    cout << res;
    return 0;
}