#include<bits/stdc++.h>
using namespace std ;
int n , q ;
long long arr[100001];
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n >> q ;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
        arr[i] += arr[i - 1] ;
    }
    for(int i = n - 1 ; i >= 1 ; i -- ){
        arr[i] = min(arr[i] , arr[i + 1]);
    }
    while(q -- ){
        int l = 0 , r = n , k ; cin >> k ;
        while(l < r){
            int mid = (l + r + 1) >> 1 ;
            if(arr[mid] <= k)l = mid ;
            else r = mid - 1 ;
        }
        cout << l << '\n' ;
    }
    
    return 0 ;
}