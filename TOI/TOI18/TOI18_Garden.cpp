#include<bits/stdc++.h>

using namespace std;

int arr[200001] ;
int left_lis[200001] , right_lis[200001] ;
int n , q ;

vector<int>lis ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 0  ; i < n ; i ++ ){
        cin >> arr[i] ;
    }

    for(int i = 0  ; i < n ; i ++ ){
        auto it = lower_bound(lis.begin(), lis.end(),arr[i]) ;
        left_lis[i] = it - lis.begin() ;
        if(it == lis.end()){
            lis.push_back(arr[i]) ;
        }
        else {
            *it = arr[i] ;
        }
    }

    lis.clear() ;

    for(int i = n - 1  ; i >= 0  ; i -- ){
        auto it = lower_bound(lis.begin(), lis.end(),arr[i]) ;
        right_lis[i] = it - lis.begin() ;
        if(it == lis.end()){
            lis.push_back(arr[i]) ;
        }
        else {
            *it = arr[i] ;
        }
    }
    while(q -- ){
        int idx ; cin >> idx ;
        cout << min(left_lis[idx], right_lis[idx]) << '\n' ;
    }
    return 0 ;
}