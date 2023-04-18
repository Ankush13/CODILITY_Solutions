#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> &A)
{
	int sE = 0; // sE - cars going east
	long long int s = 0; 
	for(auto it : A){
		if(it == 0) 
		{
			sE++;
			//cout << "sE : " << sE << endl;
		}
		if(it == 1){
			s = s + sE;
			//cout << "s : " << s << endl;
		}
	}
	
	//The function should return −1 if the number of pairs of passing cars exceeds 1,000,000,000.
	if(s > 1000000000) return -1;
	return s;
}



int main(){

	vector<int> v = {0,1,0,1,1};
	cout << "Solution : " << solution(v) << endl;
	return 0;
}
