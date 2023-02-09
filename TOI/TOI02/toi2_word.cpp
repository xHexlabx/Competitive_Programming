#include<bits/stdc++.h>
#define vec vector
#define endll '\n'
using namespace std;
int m ,n  ;
bool cmp(string a , string b){
	
	for(int i = 0 ; i < a.length() ; i ++ ){
		if(tolower(a[i]) != tolower(b[i]))return false ;
	}
	return true ;
}
bool is_valid(int x , int y){
	if(x < 0 || y < 0 || x >= m || y >= n)return false ;
	return true ;
}
int main() {
	
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
    cin >> m >> n ;
    
    vec<string>table(m);
    vec<pair<int,int>> line = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
    
    for(int i = 0 ; i < m ; i ++){
    	string temp ; cin >> temp ;
    	table[i] = temp ;
	}
	
	int t ; cin >> t ;
	
	string temp = "";
	int cnt = 0;
	while(t--){
		string word ; cin >> word ;
		cnt = 0;
		for(int i = 0 ; i < m ; i ++){
			for(int j = 0 ; j < n ; j ++){
				
				for(int k = 0 ; k < 8 ; k ++){
					
					temp = "" ;
					for(int p = 0 ; p < word.size() ; p++ ){
						if(!is_valid(i + line[k].first * p, j + line[k].second * p))break ;
						temp += table[i + line[k].first * p][j + line[k].second * p] ;
					}
					if(cmp(word , temp)){
						cout << i <<' '<< j << endll ;
						cnt ++ ;
					}
					if(cnt)break ;
				}
				if(cnt)break;
			}
			if(cnt)break;
		}
		
	}
	
	
    return 0;
}
