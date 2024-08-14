#include<bits/stdc++.h>

using namespace std ;

const int Size = 1e5 + 1 ;
int n ;
double arr[Size] , sum = 0;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0); 

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
        sum += arr[i] ;
    }

    for(int i = 0 ; i < n ; i ++ ){
        if(i == 0)cout << fixed << setprecision(16)<< sum / (n + 1) * 2 << ' ' ;
        else cout << fixed << setprecision(16) << sum / (n + 1) << ' ' ;
    }

    // for(int round = 0 ; round < 100 ; round ++ ){

    //     for(int i = 0 ; i < n ; i ++ ){
    //         arr[(i + 1) % n] += arr[i] / 2.0 ;
    //         arr[i] /= 2.0 ;
    //     }

    //     for(int i = 0 ; i < n ; i ++ ){
    //         cout << arr[i] <<  ' ' ;
    //     }

    //     cout << '\n' ;
    // }

    return 0 ;
}