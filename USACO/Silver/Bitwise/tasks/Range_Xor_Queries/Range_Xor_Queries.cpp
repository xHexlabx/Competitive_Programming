#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;
int n , q , l , r ;

int arr[Size] , qs[Size];

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
        qs[i] = (qs[i - 1] ^ arr[i]) ;
    }

    while(q -- ){
        cin >> l >> r ;
        cout << (qs[r] ^ qs[l - 1]) << '\n' ;
    }

    return 0 ;
}