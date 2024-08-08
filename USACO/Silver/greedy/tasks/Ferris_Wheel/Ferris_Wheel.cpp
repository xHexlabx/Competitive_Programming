#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int arr [Size] ;

int n , x , l , r , res = 0 ;

int main () {

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> x ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
    }

    sort(arr , arr + n) ;

    l = 0 , r = n - 1 ;

    while (l <= r){

        if(l == r){
            res ++ ;
            break ;
        }

        else if (arr[l] + arr[r] <= x){
            l ++ ;
            r -- ;
            res ++ ;
        }
        else {
            r -- ;
            res ++ ;
        }
    }

    cout << res ;

    return 0 ;
}