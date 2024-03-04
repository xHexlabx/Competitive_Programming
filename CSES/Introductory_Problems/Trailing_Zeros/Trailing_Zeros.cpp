#include<bits/stdc++.h>

using namespace std;

int n , res ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> n ;

    for(int current = 5 ; current <= n ; current *= 5){
        res += (n / current) ;
    }
    
    cout << res ;
    
    return 0 ;
}