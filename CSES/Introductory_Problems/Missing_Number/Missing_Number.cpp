#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 ;

int arr[N] , n , x ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> n ;

    for(int i = 0 ; i < n - 1 ; i ++ ){
        cin >> x ;
        arr[x] = true ;
    }

    for(int i = 1 ; i <= n ; i ++ ){
        if(arr[i] == false){
            cout << i ;
            break ;
        }
    }
    
    return 0 ;
}