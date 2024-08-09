#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;
long long n , arr[Size] , sum = 0 ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
    }

    if(n & 1){
        cout << (arr[0] ^ arr[n - 1]) ;
    }
    else {
        
        for(int i = 0 ; i < n ; i ++ ){
            sum ^= arr[i] ;
        }

        cout << sum ;
    }


    return 0 ;
}