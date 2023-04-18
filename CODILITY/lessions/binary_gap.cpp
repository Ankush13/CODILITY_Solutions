//Find the longest sequence of zeros in binary representation of an integer

#include<iostream>
#include<vector>
using namespace std;

/*
void convert(int n){
	
	long long bin = 0;
	int rem = 0, i = 1;
	
	while( n != 0 ){
		rem = n % 2;
		n = n / 2;
		bin = bin + rem * i;
		i = i * 10;
	}
	
	int count0 = 0;
	
	while (bin > 0) {
 
		// If current bit is 1
		if (bin & 1) {
		    continue;
		}
	 
		// If current bit is 0
		else {
		    count0++;
		}
	 
		bin = bin >> 1;
    	}
    	
    	cout << count0 << endl;
}
*/


int solution(int n){

	vector<int> v;
	int cnt = 0;

	while ( n != 0 )
	{
		cout << "n & 0x1: " << (n & 0x1) << endl;
	    if (n & 0x1) {
		cout << "Inside if : " << cnt << endl;
		v.push_back(cnt);
	
	}
	
	    n = n >> 1;
	    cout << "n : " << n << endl;
	    cnt++;
	    cout << "cnt : " << cnt << endl << endl;
	}
	
	int max = 0;
	   cout << "Printing vectors: " << endl;
	   for(auto it : v){
	   	cout << it << endl;
	   }
	for (unsigned i = 1; i < v.size(); i++)
	{
		int gap = v[i] - v[i - 1] - 1;
	    	cout << "gap : " << endl;
		if (gap > max)
		{
		    max = gap;
		    cout << "max : " << max << endl;
		}
	}
	
	return max;

}

int main(){
	
	cout << solution(9) << endl;
	return 0;
}
