#include<bits/stdc++.h>

using namespace std ;

struct object {
    int val , pos ;
};

int n , val ;

stack<object> st ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    st.push({0 , 0}) ;

    for(int i = 1 ; i <= n ; i ++ ){

        cin >> val ;
        
        while(st.top().val >= val)st.pop() ;

        cout << st.top().pos << ' ';

        st.push({val , i}) ;

    }
    
    return 0 ;
}