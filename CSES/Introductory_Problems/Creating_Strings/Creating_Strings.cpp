#include<bits/stdc++.h>

using namespace std;

vector<int> vec ;

map<string , bool>visited ;

int cnt = 0 ;

vector<string>answers ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    string word ; cin >> word ;

    sort(word.begin(), word.end()) ;
    
    for(int i = 0 ; i < word.size() ; i ++ )vec.push_back(i) ;

    do {
        
        string ans = "" ;

        for(int i = 0 ; i < word.size() ;i ++ ){
            ans += word[vec[i]] ;
        }
        if(!visited[ans]){
            answers.push_back(ans) ;
            visited[ans] = true ;
            cnt ++ ;
        }
        

    }while(next_permutation(vec.begin(), vec.end())) ;
    
    cout << cnt << '\n' ;

    for(auto i : answers){
        cout << i << '\n' ;
    }
    return 0 ;
}