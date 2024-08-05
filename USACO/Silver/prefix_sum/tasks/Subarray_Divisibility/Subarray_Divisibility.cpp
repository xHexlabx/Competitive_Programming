#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

long long n , res = 0 ;

array<long long , Size> arr , qs ;

map<long long , int> mpp ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    mpp[0] ++ ;

    for(int i = 1 ; i <= n ; i ++ ){
        
        cin >> arr[i] ;
        
        qs[i] += ((arr[i] % n) + (qs[i - 1] % n)) % n ;

        res += mpp[qs[i]] + mpp[n + qs[i]] + mpp[qs[i] - n];

        mpp[qs[i]] ++ ;

    }

    cout << res ;

    return 0 ;
}