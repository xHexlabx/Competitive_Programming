#include<bits/stdc++.h>
using namespace std;
struct path {
    int x , y ; vector<int>ans ;
};
int m , n , s ;
bool graph[101][50] ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n >> s >> m ;
    for(int i = 1 ; i <= m ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> graph[i][j] ;
        }
    }
    
    queue<path>q ;
    q.push({0 , s , {}});
    while(!q.empty()){
        auto temp = q.front() ;
        q.pop() ;
        if(m == temp.x){
            for(auto i : temp.ans){
                cout << i << '\n';
            }
            return 0 ;
        }
        for(int i = -1 ; i <= 1 ; i ++ ){
            int nowx = temp.x + 1 , nowy = temp.y + i ;
            if(nowy < 1 || nowy > n)continue ;
            if(graph[nowx][nowy] )continue ;
            graph[nowx][nowy] = true;
            if(i == -1){
                temp.ans.push_back(1);
                q.push({nowx , nowy , temp.ans});
                temp.ans.pop_back();
            }
            if(i == 0){
                temp.ans.push_back(3);
                q.push({nowx , nowy , temp.ans});
                temp.ans.pop_back();
            }
            if(i == 1){
                temp.ans.push_back(2);
                q.push({nowx , nowy , temp.ans});
                temp.ans.pop_back();
            }
        }
    }
    return 0 ;
}