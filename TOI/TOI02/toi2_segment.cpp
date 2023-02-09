#include<bits/stdc++.h>
#define vec vector
#define endll '\n'
using namespace std;
char decode(string code){
	
	vec<string>check = { " _ | ||_|" ,"     |  |" ," _  _||_ " ," _  _| _|" ,"   |_|  |" ," _ |_  _|" ," _ |_ |_|" ," _   |  |" ," _ |_||_|" ," _ |_| _|"};
	
	for(int i = 0 ; i < 10 ; i ++){
		if(code == check[i]){
			return char(i + '0');
		}
	}
}
int main() {
    int a, b; cin >> a >> b;
	char trash ; scanf("%c" , &trash);
	
	string realnum1 = "";
	string realnum2 = "";
    vec<string>num1(a , "");
    vec<string>num2(b , "");
    int index;
    char temp;
    
    for (int i = 0; i < 3; i++) {
    	index = 0 ;
        string line ; getline(cin , line);
		for(int j = 0 ; j < line.size() ; j ++){
			if( (j + 1) % 4 == 0 ){
				index ++ ;
				continue ;
			}
			num1[index] += line[j];
		}
    }
	for(int i = 0; i < num1.size();i++){
		realnum1 += decode(num1[i]);
	}
	for (int i = 0; i < 3; i++) {
    	index = 0 ;
        string line ; getline(cin , line);
		for(int j = 0 ; j < line.size() ; j ++){
			if( (j + 1) % 4 == 0 ){
				index ++ ;
				continue ;
			}
			num2[index] += line[j];
		}
    }
	for(int i = 0; i < num2.size();i++){
		realnum2 += decode(num2[i]);
	}
	printf( "%lld" , stoi(realnum1) + stoi(realnum2) );
    
    return 0;
}