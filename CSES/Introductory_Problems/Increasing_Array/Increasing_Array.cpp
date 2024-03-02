#include<bits/stdc++.h>

using namespace std;

int n ;
long long res = 0 ;

stack<int>st ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0); 

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        
        long long x ; cin >> x ;

        if(i == 0){
            st.push(x) ;
        }
        else {
            if(x > st.top()){
                st.pop() ;
                st.push(x) ;
            }
            else {
                res += st.top() - x ;
            }
        }
    }
    
    cout << res ;

    return 0 ;
}