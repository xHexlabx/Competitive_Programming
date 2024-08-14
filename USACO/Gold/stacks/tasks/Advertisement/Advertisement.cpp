#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

struct object {
    long long val , pos ;
};

long long n , val ;

long long arr[Size] ;

long long idx_1[Size] ;
long long idx_2[Size] ;

stack<object> st_1 ;
stack<object> st_2 ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    st_1.push({0 , 0}) ;
    st_2.push({0 , n + 1}) ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
    }

    for(int i = 1 ; i <= n ; i ++ ){
        while(st_1.top().val >= arr[i])st_1.pop() ;
        idx_1[i] = st_1.top().pos ;
        st_1.push({arr[i] , i}) ;
    }

    for(int i = n ; i >= 1 ; i -- ){
        while(st_2.top().val >= arr[i])st_2.pop() ;
        idx_2[i] = st_2.top().pos ;
        st_2.push({arr[i] , i}) ;
    }

    long long res = 0 ;

    for(int i = 1 ; i <= n ; i ++ ){
        res = max(res , arr[i] * (idx_2[i] - idx_1[i] - 1)) ;
    }

    cout << res ;

    return 0 ;
}