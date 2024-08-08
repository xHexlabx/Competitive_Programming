#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int n ;

long long arr[Size] ;
long long t ;

int main(){
    
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    
    cin >> n >> t ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
    }

    long long l = 0 , r = 1e18 ;

    while(l < r){

        long long mid = (l + r) >> 1 ;

        long long res = 0 ;

        for(int i = 0 ; i < n ; i ++ ){
            res += mid / arr[i] ;
            if (res >= t)break;
        }

        if (res >= t) r = mid ;
        else l = mid + 1 ;

    }

    cout << l ;

    return 0 ;
}