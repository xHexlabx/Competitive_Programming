#include<bits/stdc++.h>

using namespace std ;

int t , n , cnt , sum , arr [100];

map <int , int >mpp ;

int main() {

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> t ;

    while (t -- )
    {

        cin >> n ;
        int MAX = INT_MIN ;
        for(int i = 0 ; i < n ; i ++ ){
            cin >> arr[i] ;
            if (i % 2 == 0){
                MAX = max(MAX , arr[i]) ;
            }
        }
        cout << MAX << '\n' ;
    }
    

    return 0 ;
}