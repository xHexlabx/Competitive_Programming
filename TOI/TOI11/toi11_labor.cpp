#include<bits/stdc++.h>
using namespace std ;
long long arr[1000001] ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0);
    long long m , n , l = 1 , r = 1e12 ; cin >> m >> n ;
    
    for(int i = 0 ; i < m ; i ++ )cin >> arr[i] ;
    while(l < r){
        
        long long sum = 0 ;
        long long mid = (l + r) >> 1 ;
        for(int i = 0 ; i < m ; i ++ ){
            sum += mid / arr[i] ;
            if(sum >= n)break ;
        }
        if(sum >= n)r = mid ;
        else l = mid + 1 ;
    }
    cout << l ;
    return 0 ;
}