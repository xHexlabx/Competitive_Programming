#include<bits/stdc++.h>

using namespace std;

struct hole {
    int depth , length , total_length;
};

stack<hole>st ;

int arr[100001] , n , q , now_depth = 0 , now_length, total_length = 0 , d , l , MAX_depth = 0 ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    st.push({0 , 0}) ;

    cin >> n >> q ;

    int last_length , last_total_length;

    for(int i = 1 ; i <= n + 1 ; i ++ ){

        if(i <= n){
            cin >> d >> l ;
            now_depth += d ;
            now_length = l ;
            total_length += l ;
            MAX_depth = max(MAX_depth , now_depth) ;
            if(st.top().depth > now_depth){
                auto now = st.top() ;
                st.pop() ;
                bool have = false ;
                while(st.top().depth == now.depth && now.depth != 0){
                    last_length = st.top().length ;
                    last_total_length = st.top().total_length ;
                    st.pop() ;
                    have = true ;
                }
                if(have == false){
                    arr[now.depth] = max(arr[now.depth] , now.length) ;
                    // cout << now.length << ' ' ;
                }
                else {
                    arr[now.depth] = max(arr[now.depth] , now.total_length - last_total_length + last_length) ;
                    // cout << now.total_length - last_total_length + last_length << ' ' ;
                }
            }

            st.push({now_depth , now_length , total_length}) ;
        }
        else {      
                auto now = st.top() ;
                st.pop() ;
                while(st.top().depth == now.depth && now.depth != 0){
                    last_length = st.top().length ;
                    last_total_length = st.top().total_length ;
                    st.pop() ;
                }
                arr[now.depth] = max(arr[now.depth] , now.total_length - last_total_length + last_length) ;
        }
        
    }

    arr[0] = INT_MAX ;

    while(q -- ){
        int x ; cin >> x ;
        int l = 0 , r = MAX_depth ; 
        while(l < r){
            int mid = (l + r + 1) >> 1 ;
            if(arr[mid] >= x)l = mid ;
            else r = mid - 1 ;
        }
        cout << l << '\n' ;
    }

   
    return 0 ;
}