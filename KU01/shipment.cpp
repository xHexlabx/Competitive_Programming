#include<bits/stdc++.h>

using namespace std;

int a1[301] , a2[301] , b1[301] , b2[301] ;
int n , k ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> n >> k ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> a1[i] ;
    }

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> a2[i] ;
    }

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> b1[i] ;
    }

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> b2[i] ;
    }

    sort(a1 + 1 , a1 + 1 + n) ;
    sort(a2 + 1 , a2 + 1 + n) ;
    sort(b1 + 1 , b1 + 1 + n) ;
    sort(b2 + 1 , b2 + 1 + n) ;

    
    int MIN = INT_MAX ;

    for(int num_a = max(0 , k - n) ; num_a <= min(n , k) ; num_a ++ ){
        int num_b = k - num_a ;

        int MAX = INT_MIN ;

        for(int i = 1 ; i <= num_a ; i ++ ){
            MAX = max(MAX , a1[i] + b1[num_a - i + 1]) ;
            
        }
        for(int i = 1 ; i <= num_b ; i ++ ){
            MAX = max(MAX , a2[i] + b2[num_b - i + 1]) ;
        }

        MIN = min(MIN , MAX) ;
    }
    cout << MIN ;

    return 0 ;
}