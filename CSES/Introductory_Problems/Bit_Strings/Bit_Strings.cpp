#include<bits/stdc++.h>

using namespace std;

const int Size = 1e6 + 1 ;
const long long mod = 1e9 + 7 ;

long long arr[Size] , n ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    arr[0] = 1 ;

    for(int i = 1 ; i < Size ; i++){
        arr[i] = (arr[i - 1] * 2) % mod ;
    }

    cin >> n ;
    cout << arr[n] ;

    return 0 ;
}