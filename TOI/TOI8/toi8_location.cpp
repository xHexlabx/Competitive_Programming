#include<bits/stdc++.h>
#define umap unordered_map 
#define endll '\n' 
#define ll long long 
#define vec vector
#define emb emplace_back
#define pii pair<int , int>
#define pss pair<short , short>
#define mts multiset
#define Debug 1
using namespace std;
int qs[1001][1001] ;
int n , m , k , MAX = INT_MIN;
void solve(){
    memset(qs , 0 , sizeof(qs));
    cin >> m >> n >> k ;
    for(int i = 1 ; i <= m ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> qs[i][j] ;
            qs[i][j] += qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1];
        }
    }
    for(int i = k ; i <= m ; i ++ ){
        for(int j = k ; j <= n ; j ++ ){
            MAX = max(MAX , qs[i][j] - qs[i - k][j] - qs[i][j - k] + qs[i - k][j - k]);
        }
    }
    cout << MAX ;
    return ;
}
int main(){
    //Solved By HexTex 
	
    ios_base::sync_with_stdio(0),cin.tie(0);
    solve();
    return 0 ;
}