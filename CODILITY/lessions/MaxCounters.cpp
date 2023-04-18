#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


vector<int> solution3(int n, vector<int> &arr){

	int maxi = 0;
	int lastMax = 0;
	vector<int> count(n);
	
	for(int i = 0; i < arr.size(); i++){
		
		if(arr[i] > n){
			lastMax = maxi;
		}
		else{
			count[ arr[i] - 1 ] = max(count[ arr[i] - 1 ], lastMax);
			count[arr[i] - 1]++;
			maxi = max(maxi, count[ arr[i] - 1 ]);
		}
	}
	
	for(int i = 0 ; i < n; i++) {
			count[i] = max(count[i], lastMax);
		}

	for(auto it : count){
		cout << " " << it ;
	}
	
	return count;
}




vector<int> solution2(int n, vector<int> &arr){

	int maxi = 0;
	int lastMax = 0;
	vector<int> count(n);
	
	for(int i = 0; i < arr.size(); i++){
		
		if(arr[i] >= 1 && arr[i] <= n){
			count[ arr[i] - 1 ] = max(count[ arr[i] - 1 ], lastMax);
			count[arr[i] - 1] += 1;
			maxi = max(maxi, count[ arr[i] - 1 ]);
		}
		else if(arr[i] == n+1){
			lastMax = maxi;
		}
	}
	
	for(int i = 0 ; i < count.size(); i++) {
			count[i] = max(count[i], lastMax);
		}

	for(auto it : count){
		cout << " " << it ;
	}
	return count;
}

//I tried 
void solution(int n, vector<int> &arr){
	
	int maxCounter = -1;
	int si = arr.size();
	vector<int> count(n);
	for(int i = 1; i < n; i++){
		int increase = 0;
		if(arr[i] > n ){
			count.clear();
			//cout << "Count size : " << count.size() << endl;
			//cout << "Count MAx : " << maxCounter << endl;
			for(int i = 0; i < n; i++){
				count.push_back(maxCounter);
			}
			//cout << "Count size : " << count.size() << endl;
		}
		else{
			if(count[arr[i]] == maxCounter){
				//cout << "Inside if : " << arr[i] << endl;
				count[arr[i]]++;
				maxCounter = count[arr[i]];
				//cout << "Count curr element: " << count[arr[i]] << endl;
				
			}
			else{	
				//cout << "Inside else : " << arr[i] << endl;
				count[arr[i]] = increase + 1;
				//cout << "Count curr element: " << count[arr[i]] << endl;
				maxCounter = count[arr[i]];
			}
		}
		for(auto it : count){
			cout << it << " ";
		}
			cout << endl;
	}
	
	cout << endl << endl;
	for(auto it : count){
		cout << it << " ";
	}

	
}

int main(){

	vector<int> v = {3,4,4,6,1,4,4};
	int n = v.size();
	int in = 5;
	//solution(in, v);
	//solution2(in, v);
	solution3(in, v);
	for(auto it : v){
		cout << it << " " ;
	}
	
	return 0;
}
