#include<bits/stdc++.h>

using namespace std ;

struct object {

    long long val , pos ;

};

const int Size = 2e5 + 1 ;

int n , a , b ;

long long qs[Size] , res = LLONG_MIN ;

deque<object>dq ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> a >> b ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> qs[i] ;
        qs[i] += qs[i - 1];
    }

    dq.push_back({0 , 0}) ;

    for(int i = a ; i <= n ; i ++ ){

        while(!dq.empty() && i - dq.front().pos > b ){
            dq.pop_front() ;
        }

        res = max(res , qs[i] - dq.front().val) ;

        while(!dq.empty() && dq.back().val >= qs[i - a + 1]){
            dq.pop_back() ;
        }

        dq.push_back({qs[i - a + 1] , i - a + 1}) ;
    }

    cout << res ;

    return 0 ;
}