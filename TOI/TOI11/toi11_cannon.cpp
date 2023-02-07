#include<bits/stdc++.h>
using namespace std;
int arr[1000001] , n , m , k , l ;
int main(){
    ios_base :: sync_with_stdio(0),cin.tie(0);
    
    cin >> n >> m >> k >> l ;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
    }
    while(k -- ){
        int res = 0  , lastr = 0 , idx , idxl ,idxr;
        for(int i = 0 ; i < m ; i ++ ){
            cin >> idx ;
            idxr = upper_bound(arr ,arr + n , idx + l) - arr ;
            idxl = lower_bound(arr ,arr + n , max(lastr , idx - l )) - arr ;
 
            res += idxr - idxl ;
            lastr = idx + l + 1 ;
        }
        cout << res << '\n' ;
    }
    return 0 ;
}