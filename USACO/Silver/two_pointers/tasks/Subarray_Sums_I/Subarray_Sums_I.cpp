#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int n , target, res = 0 ;
array<long long , Size> arr ;

int main() {

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> target ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
    }

    int l = 1 , r = 1 ;

    long long sum = 0 ;

    while(r <= n){

        sum += arr[r] ;

        while(sum > target){
            sum -= arr[l] ;
            l ++ ;
        }

        res += (sum == target) ;
        r ++ ;
    
    }

    cout << res ;

    return 0 ;
}