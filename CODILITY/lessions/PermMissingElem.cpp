/*

An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

int solution(vector<int> &A);

that, given an array A, returns the value of the missing element.

For example, given array A such that:

  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].


*/

//integer range : -2,147,483,648 to 2,147,483,647
// long range : -2,147,483,648 to 2,147,483,647

int solution(vector<int> &A) {
    // Implement your solution here
    long n = A.size(); // as TC can exceed int range so we have taken long
    int total = (n + 1) * (n + 2) / 2;
	for(unsigned int i = 0; i < n; i++){
		total = total - A[i];
	}
	// 21 - 1 = 20, 20 - 2 = 18, 18 - 4 = 14,
	// 14 - 5 = 9, 9 - 6 = 3 
	return total;
}

