#include<bits/stdc++.h>

using namespace std ;

vector<int>vec ;
map<int , long long>mpp ;

long long solve(int n){
    if(n == 0)return 1 ;
    if(mpp[n])return mpp[n] ;

    long long res = 0 ;
    for(auto i : vec){
        if(n - i >= 0)res += solve(n - i);
    }
    mpp[n] = res ;
    return mpp[n] ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    int n , m ; cin >> n >> m ;
    
    while(m -- ){
        int val ; cin >> val ;
        vec.push_back(val);
    }
    cout << solve(n);
    
    return 0 ;
}