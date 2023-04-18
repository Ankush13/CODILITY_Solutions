#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//correct but only 8%
int solution(vector<int> &A)
{
	int n = A.size();
	int total = (n+1) * (n+2) / 2;
	for(auto it : A){
			total -= it;
	}

	sort(A.begin(), A.end());
	if(A[0] < total && total < A[A.size()-1]){
		return 1;
	}
	return 0;
}

int solution2(vector<int> &A)
{
	int n = A.size();
	vector<int> visited( n );
//	int total = (n+1) * (n+2) / 2;
	for(int i = 0 ; i < n ; i++){
		if(A[i] < 1 || A[i] > A.size())
			return 0;
		if(visited[A[i]] == true)
			return 0;
		else
			visited[A[i]] = true;
	}
	
	return 1;
}


int solution3(vector<int> &A)
{
	int n = A.size();
	if(A.empty()) return 0;
	sort(A.begin(), A.end());
	
	for(int i = 0; i < n; i++){
		if(A[i] != i+1) return 0;
	}
	
	return 1;
}

int main(){

	vector<int> v = {4, 1, 3, 2};
	//cout << "Solution : " << solution(v) << endl;
	//cout << "Solution : " << solution2(v) << endl;
	cout << "Solution : " << solution3(v) << endl;
	return 0;
}
