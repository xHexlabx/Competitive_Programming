#include <bits/stdc++.h>
#define vec vector
#define umap unordered_map
#define endll '\n'
using namespace std;
int m, n;
bool is_valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= m || y >= n)
        return false;
    return true;
}
struct path
{
    int ox, oy, x, y, t;
};
int main()
{
    ios_base ::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;
    vec<vec<char>> graph(m, vec<char>(n, ' '));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    vec<int> dir = {0, 0, -1, 1};
    vec<vec<bool>> visited(m, vec<bool>(n, false));

    queue<path> q;
    q.push({0, 0, 0, 0, 1});

    while (!q.empty())
    {

        auto temp = q.front();
        q.pop();

        if (visited[temp.x][temp.y])
        {
            cout << temp.t << endll << temp.x + 1 << ' ' << temp.y + 1;
            return 0;
        }
        visited[temp.x][temp.y] = true;

        for (int i = 0; i < 4; i++)
        {
            if (is_valid(temp.x + dir[i], temp.y + dir[3 - i]))
            {
                if (temp.x + dir[i] == temp.ox && temp.y + dir[3 - i] == temp.oy)
                    continue;
                if (i == 0 && (graph[temp.x][temp.y] == 'B' || graph[temp.x][temp.y] == 'R'))
                {
                    q.push({temp.x, temp.y, temp.x + dir[i], temp.y + dir[3 - i], temp.t + 1});
                }
                if (i == 1 && (graph[temp.x + dir[i]][temp.y + dir[3 - i]] == 'B' || graph[temp.x + dir[i]][temp.y + dir[3 - i]] == 'R'))
                {
                    q.push({temp.x, temp.y, temp.x + dir[i], temp.y + dir[3 - i], temp.t + 1});
                }
                if (i == 2 && (graph[temp.x + dir[i]][temp.y + dir[3 - i]] == 'B' || graph[temp.x + dir[i]][temp.y + dir[3 - i]] == 'D'))
                {
                    q.push({temp.x, temp.y, temp.x + dir[i], temp.y + dir[3 - i], temp.t + 1});
                }
                if (i == 3 && (graph[temp.x][temp.y] == 'B' || graph[temp.x][temp.y] == 'D'))
                {
                    q.push({temp.x, temp.y, temp.x + dir[i], temp.y + dir[3 - i], temp.t + 1});
                }
            }
        }
    }
}