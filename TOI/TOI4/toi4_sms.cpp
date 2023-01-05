#include<bits/stdc++.h>
#define vec vector 
#define umap unordered_map
#define endll '\n'
using namespace std ;
int main(){
	
	ios_base :: sync_with_stdio(0),cin.tie(0);
	
	vec<char> msg ;
	pair<int,int>pos ;
	int realpos ; int times; 
	vec<vec<char>>phone = { {} ,{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','Q','R','S'},{'T','U','V'},{'W','X','Y','Z'}};
	vec<vec<int>>find_pos = { {1,2,3} , {4,5,6} , {7,8,9} };
	int t ; cin >> t ; --t ;
	int str ; cin >> str ;
	for(int i = 0 ; i < 3 ; i ++)for(int j = 0 ; j < 3 ;j ++)if(find_pos[i][j] == str){
		realpos = --str ;
		pos = {i , j};
		cin >> times ;
	}
	if(realpos == 0){
	}
	else {
		times -- ;
		msg.push_back(  phone[realpos][ times % phone[realpos].size()] );
	}
	while(t--){
		int x , y ; cin >> y >> x >> times ;
		pos.first += x ; pos.second += y ;
		realpos = find_pos[pos.first][pos.second] -1;
		if(realpos == 0 ){
			for(int i = 0 ;  i< times ; i ++){
				msg.pop_back();
				if(msg.size() == 0)break ;
			}
		}
		else {
			times -- ;
			msg.push_back(  phone[realpos][ times % phone[realpos].size()] );
		}
	}
	if(msg.empty()){
		cout << "null";return 0 ;
	}
	for(auto i : msg){
		cout << i ;
	}
	return 0 ;
}