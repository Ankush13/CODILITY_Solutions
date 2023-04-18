#include<iostream>
#include<stack>
using namespace std;

int solution(string &str){
	stack<char> s;
	for( int i = 0; i < str.length(); i++)
	{
		if(s.empty())
		{
			s.push( str[ i ] );
		}
		
		else if(s.top() == '[' && str[i] == ']' 
		|| s.top() == '{' && str[i] == '}'
		|| s.top() == '(' && str[i] == ')')
		{
		
			s.pop();
		}
		
		else
		{
		
			s.push(str[i]);
		}
	}
	if(s.empty()) return 1;
	return 0;
}

int main(){
	
	string s = "{[()()]}";
	cout << "Ans : " << solution(s) << endl;
	return 0;
}
