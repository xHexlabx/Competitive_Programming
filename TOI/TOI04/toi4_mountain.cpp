#include<bits/stdc++.h>
#include<unordered_map>
#define vec vector
#define umap unordered_map
#define endll endl;
using namespace std ;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t ; cin >> t ;
    int m  = INT_MIN ; int n = INT_MIN ;
    vec<pair<int,int>>mount ;
    while(t--){
        int str , h ; cin >> str >> h ;
        mount.push_back( {str , h} );
        if(h > m)m = h ;
        if(2 * h -1  + str > n)n = 2 * h -1  + str;
    }
    vec<string>mountain (m , string(n,'.'));
    int str , h ;
    for(auto i : mount){
        str = i.first ; h = i.second ;
        for(int i = 0 ; i < h ; i++){
            if(mountain[ m-1 - i ][str - 1 + i] == '\\'){
                mountain[ m-1 - i ][str - 1 + i] = 'v';
            }
            else {
                mountain[m - 1 - i][str - 1 + i] = '/';
            }
        }
        for(int i = 0 ; i < h ; i++){
            if(mountain[m - h + i][str + h - 1 + i] == '/'){
                mountain[m - h + i][str + h - 1 + i] = 'v';
            }
            else {
                mountain[m - h + i][str + h - 1 + i] = '\\';
            }
        }
    }
    for(auto i : mount){
        str = i.first ; h = i.second ;
        for(int i = 1 ; i < h ; i++){
            for(int j = 0 ; j < 2 * (h - i) ; j++){
                mountain[m-i][str + j + i - 1] = 'X';
            }
        }
    }
    for(auto i : mountain){
        for(auto j : i){
            cout << j;
        }
        cout << "\n";
    }
    return 0;
}