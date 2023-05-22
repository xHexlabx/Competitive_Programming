
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 6;
const int INF = 1000000;
 
int dist [N + 1][N + 1] = { 
   { 0 , 0 , 0 , 0 , 0 , 0 , 0} ,
   { 0 , 0   , 5  , 6   , INF , INF , INF } ,
   { 0 , 5   , 0  , 9   , 10  , 4   , 7} ,
   { 0 , 6   , 9  , 0   , 4   , 2   , INF} , 
   { 0 , INF , 10 , 4   , 0   , 7   , 3} ,
   { 0 , INF , 4  , 2   , 7   , 0   , INF} , 
   { 0 , INF , 7  , INF , 3   , INF , 0}

};
 
int dp[N + 1][1 << (N + 1)];
 
int solve(int node, int mask)
{

    if (mask == ((1 << node) | 3))
        return dist[1][node];

    if (dp[node][mask] != 0)
        return dp[node][mask];
 
    int res = INF; 

    for (int j = 1; j <= N; j++)

        if ((mask & (1 << j)) && j != node && j != 1)

            res = min(res, solve(j, mask ^ (1 << node)) + dist[j][node]);
    
    return dp[node][mask] = res;
}

int main()
{
    
    int ans = INF;
    
    for (int i = 1; i <= N; i++)ans = min(ans, solve(i, (1 << (N + 1)) - 1) + dist[i][1]);
 
    printf("The cost of most efficient tour = %d", ans);
 
    return 0;
}