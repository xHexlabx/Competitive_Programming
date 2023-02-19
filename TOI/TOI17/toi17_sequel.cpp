#include<bits/stdc++.h>
using namespace std ;
const int N = 100001 ;
int cluster[320][N],arr[N] ;
void preprocess(){
    for(int i = 1 ; i <= sqrt(N) ; i ++ ){
        for(int j = 1 ; j <= N ; j ++){
            cluster[i][j] += cluster[i][max(0 , j - i)] + arr[j] ;
        }
    }
}
int main () {
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    
    int n , q ; cin >> n >> q ; 
    
    for(int i = 1 ; i <= n ; i ++ )cin >> arr[i] ;
    
    preprocess() ;
    
    while(q -- ){
        int l , m , r ; cin >> l >> m >> r ;
        if(m <= sqrt(n)){
            r = l + (r - l) / m * m ;
            cout << cluster[m][r] - cluster[m][l] + arr[l] << ' ' ;
        }
        else {
            int sum = 0 ;
            for(int i = l ; i <= r ; i += m){
                sum += arr[i] ;
            }
            cout << sum << ' ';
        }
    }
    
    return 0 ;
}