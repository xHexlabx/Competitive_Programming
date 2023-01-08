#include<bits/stdc++.h>

using namespace std ;

map<int , long long>mpp ;

long long fac(int n){
    if(n == 0)return 1 ;
    if(mpp[n])return mpp[n] ;
    mpp[n] = n * fac(n - 1);
    return mpp[n] ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    int q ; cin >> q ;
    while(q -- ){
        int n , r ; cin >> n >> r ;
        cout << fac(n) / (fac(n - r) * fac(r)) << '\n' ;
    }
    
    return 0 ;
}