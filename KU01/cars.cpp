#include<bits/stdc++.h>

using namespace std;

int n , x , y , MAX = INT_MIN , cnt = 0; 

int arr[200001] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> x >> arr[i] ;
    }

    for(int i = n ; i >= 1 ; i -- ){
        if(i == n){
            MAX = arr[i] ;
        }
        else {
            if(arr[i] < MAX) {
                cnt ++ ;
            }
            MAX = max(MAX , arr[i]) ;
        }
    }

    cout << cnt ;
    
    return 0 ;
}