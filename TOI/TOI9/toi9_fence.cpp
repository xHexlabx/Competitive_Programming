#include<bits/stdc++.h>
using namespace std;
int q = 2 , t , x , y , m , n , dpr[501][501] , dpc[501][501]; 
bitset<501>tree[501] ;
int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);
   
    while(q -- ){
        
        memset(tree,0,sizeof(tree));
        memset(dpr,0,sizeof(dpr));
        memset(dpc,0,sizeof(dpc));
         cin >> m >> n  >> t ;
        while(t -- ){
            cin >> x >> y ;
            tree[x + 1][y + 1] = true ;
        }
        for(int i = 1 ; i <= m ; i ++ ){
            for(int j = 1 ; j <= n ; j ++ ){
                if(!tree[i][j]){
                    dpr[i][j] = 1 + dpr[i][j - 1] ;
                    dpc[i][j] = 1 + dpc[i - 1][j] ;
                }
            }
        }
        int MAX = 0 ;
        for(int i = 1 ; i <= m ; i ++ ){
            for(int j = 1 ; j <= n ; j ++ ){
                if(tree[i][j])continue ;
                int sz = min(dpr[i][j] , dpc[i][j]);
                while(sz ){
                    if(dpr[i - sz + 1][j] >= sz && dpc[i][j - sz + 1] >= sz){
                        MAX = max(MAX , sz);
                        break ;
                    }
                    sz -- ;
                }
            }
        }
        cout << MAX << '\n' ;
    }
    return 0 ;
}