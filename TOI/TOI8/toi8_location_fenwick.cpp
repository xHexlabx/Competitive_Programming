#include<bits/stdc++.h>
using namespace std;
class Fenwick2d{
    public :
        long long fw[1001][1001] ;
        void update(int x , int y , int val){
            for(int i = x ; i < 1001 ; i += (i & -i)){
                for(int j = y ; j < 1001 ; j += (j & -j)){
                    fw[i][j] += val ;
                }
            }
        }
        long long query(int x , int y){
            long long res = 0 ;
            for(int i = x ; i > 0 ; i -=(i &-i)){
                for(int j = y ; j > 0 ; j -= (j &-j)){
                    res += fw[i][j] ;
                }
            }
            return res ;
        }
}fw;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    int m , n , k  , val ; cin >> m >> n >> k ;
    long long MAX = INT_MIN ;
    
    for(int i = 1 ; i <= m ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> val ;
            fw.update(i , j , val);
        }
    }
    for(int i = k ; i <= m ; i ++ ){
        for(int j = k ; j <= n ; j ++ ){
            MAX = max(MAX , fw.query(i , j) - fw.query(i - k , j) - fw.query(i , j - k) + fw.query(i - k , j - k));
        }
    }
    cout << MAX ;
    return 0 ;
}