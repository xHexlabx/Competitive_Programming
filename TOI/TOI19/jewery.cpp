#include<bits/stdc++.h>

using namespace std ; 

struct jewelry {
    int range , idx ;
};

stack<jewelry>st ;

int n ;
long long ans , dp[1000001];

string s ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> s ;

    for(int i = 1 ; i <= n ; i ++ ){

        int state = 1 ? s[i - 1] == 'T' : 0 ;

        if(state == 1){

            if(i == 1){
                dp[i] = 1 ;
                st.push({1 , 1}) ;
            }
            else {

                jewelry current ;

                if(s[i - 2] == 'T'){
                    current = st.top() ;
                    current.range ++ ;
                    current.idx = i ;

                    st.pop() ;

                }
                else {
                    current = {1 , i} ;
                }

                while(!st.empty() && st.top().range < current.range){
                    st.pop() ;
                }

                if(st.empty()){
                    dp[i] = dp[i - 1] + i ;
                }
                else {
                    dp[i] = dp[i - 1] + i - st.top().idx + current.range - 1 ;
                }

                st.push(current) ;
            }
        }
        else {
            dp[i] = dp[i - 1] ;
        }

        ans += dp[i] ;
    }

    cout << ans ;
    
    return 0 ;
}