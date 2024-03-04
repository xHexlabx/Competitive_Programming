#include<bits/stdc++.h>

using namespace std;

const int Size = 16 ;
int arr[Size] , n ;

void solve(int idx){

    if(idx == n){
        for(int i = 0 ; i < n ; i++){
            cout << arr[i] ;
        }
        cout << '\n' ;
    }
    else {
        arr[idx] = 0 ;
        solve(idx + 1) ;
        arr[idx] = 1 ;
        solve(idx + 1) ;
    }
}
int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    solve(0) ;

    return 0 ;
} 