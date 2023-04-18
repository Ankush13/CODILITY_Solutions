/*

A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7
Write a function:

int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].

*/


#include<iostream>
#include<vector>
#include<climits>
using namespace std;


//my solution : is not working 
int solution(vector<int> &A){

	int choose = 0; 
	int add = 0;
	int n = A.size();
	vector<int> diff(A.size());
	for(int i = 0; i < n; i++){
	
		while(i >= 0){
		 	choose += A[i--];
		}
		for(int j = i + 1; j < n; j++){
			add += A[j];
			cout << "Add : " << add << endl;
		}
		int put = add - choose;
		cout << "Put : " << put << endl;
		diff.push_back( put );
	}
	
	for(auto it : diff){
		cout << it << " ";
	}
	
	int mini = INT_MAX;
	for(int i = 0; i < diff.size(); i++){
		//mini = min(mini, arr[i]);
		if(mini > diff[i]){
			mini = diff[i];
			cout << "Mini : " << mini << endl;
		}
	}
	
	cout << "Minimum is : " << mini << endl;
	return mini;
}


int solution2(vector<int> &a) {
    int left = a[0], right = 0;//taking initial values. first element in left 
    int min = INT_MAX; // taking min var
    for (unsigned i = 1; i < a.size(); i++) { // sum of the rest of the elements and then storing it in right var(from index 1 to end)
        right += a[i];
    }
    for (unsigned i = 1; i < a.size(); i++) {//this is important: here we are first calculating the difference and then with that diff updating the min value
        int val = abs(left - right);
        if (val < min) {
            min = val;
        }
        
        //this is the most important part : we are updating the left value by adding the next index element and for right we are substracting from total sum amount with next index element. Hence this way we are going forward.
        left += a[i];
        right -= a[i];
    }
    return min; // at last returning the minimum value after all the iterations are completed.
}

int main(){

	vector<int> v = {3,1,2,4,3};
	//cout << "Solution : " << solution(v) << endl;
	cout << "Solution : " << solution2(v) << endl;
	return 0;
}
