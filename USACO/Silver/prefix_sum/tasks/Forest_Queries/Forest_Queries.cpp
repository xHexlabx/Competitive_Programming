#include<bits/stdc++.h>

using namespace std ;

const int Size = 1001 ;

int n , q , a , b , c , d ;

int qs[Size][Size] ;

string row ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){

        cin >> row ;

        for(int j = 1 ; j <= n ; j ++ ){

            if(row[j - 1] == '*') qs[i][j] = 1 ;
            
            qs[i][j] += qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1] ;
        }
    }

    while (q--){
        
        cin >> a >> b >> c >> d ;

        cout << qs[c][d] - qs[c][b - 1] - qs[a - 1][d] + qs[a - 1][b - 1] << '\n' ;

    }
    

    return 0 ;  
}