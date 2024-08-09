#include<bits/stdc++.h>

using namespace std ;

int n , x , res ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){

        cin >> x ;
        res = 1 ;

        int root = sqrt(x) ;

        for(int j = 2 ; j <= root ; j ++ ){

            int div = 0 ;

            while(x % j == 0){
                div ++ ;
                x /= j ;
            }

            res *= (div + 1) ;
        }

        if(x != 1){
            res *= 2 ;
        }

        cout << res << '\n' ;
    }

    return 0 ;
}