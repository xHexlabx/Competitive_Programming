#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int n ;

long long res = 0 , dead_line ;
long long arr[Size] ;

int main () {

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] >> dead_line ;
        res += dead_line ;
    }

    sort(arr , arr + n) ;

    for(int i = 0 ; i < n ; i ++ ){
        res -= (arr[i] * (n - i)) ;
    }

    cout << res ;

    return 0 ;
}