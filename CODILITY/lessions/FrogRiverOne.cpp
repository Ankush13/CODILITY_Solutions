#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


//correct 100%
int solution2(int x, vector<int> &arr){

	unordered_set<int> count(arr.size());
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] <= x){
			count.insert(arr[i]);
		}
		
		if(count.size() == x) 
			return i;
	}
	
	return -1;	
}

//correct but 27%
int solution(int x, vector<int> &arr){

	vector<int> count(arr.size());
	for(int i = 0; i < arr.size(); i++){
		
		count[arr[i]] = 1;
		cout << endl << "Printing count : " <<endl;
		for(auto it : count){
			cout << it << " ";
		}
		if( arr[i] == x ){
			//why these code of lines are written?
			//answer: The goal is to find the earliest time when the frog can jump to the other side of the river. The frog can cross only when leaves appear at every position across the river from 1 to X (that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves). 
			bool found = true;
			for(int j = 1; j <= x; j++){
				if(count[j] == 0){ found = false;}
			}
			
			if(found){ 
				return i; 
			}
			
			//return i;
		}
	}
	return -1;
}

int main(){

	vector<int> v = {1,3,1,4,3,2,5,4};
	int X =5;
	//cout << "Solution: " << solution(X, v) << endl;
	cout << "Solution: " << solution2(X, v) << endl;

	return 0;
}
