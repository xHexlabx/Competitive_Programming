#include<bits/stdc++.h>

using namespace std ;

string multi(int x , char c){
    string res = "" ;
    for(int i = 0 ; i < x ; i ++ )res += c ;
    return res ;
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    vector<char>vec ;
    set<char>st ;
    int n ; cin >> n ;
    char x ; 
    for(int i = 0 ; i < n ; i ++ ){
        cin >> x ;
        st.insert(x) ;
    }
    int sz = st.size() ;
    for(auto i : st)vec.push_back(i);

    for(int i = 0 ; i < sz ; i ++ ){
        cout << multi( sz * 2 - 1 - i, ' ') << multi(i * 2 + 1 , vec[i]) ;
        cout << '\n' ;
    }
    for(int i = 0 ; i < sz ; i ++ ){
        cout << multi( sz - 1 - i, ' ') << multi(i * 2 + 1 , vec[i]) << multi( sz - 1 - i, ' ') << ' ' << multi( sz - 1 - i, ' ') << multi(i * 2 + 1 , vec[i]);
        cout << '\n' ;
    }
    return 0 ;
}