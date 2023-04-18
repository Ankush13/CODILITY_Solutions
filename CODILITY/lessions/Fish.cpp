#include<iostream>
#include<vector>
using namespace std;


int solution(vector<int> &A, vector<int> &B) 
{
	vector<int> ds;
	int count = 0;
	
	for(int i = 0; i < B.size(); i++)
	{	
		if(B[i] == 1)
		{
			ds.push_back(A[i]);
		}
		else
		{
			while(!ds.empty())
			{	
				if(ds.back() > A[i])
				{
					count++;
					break;
				}
				else if(ds.back() < A[i])
				{
					ds.pop_back();
					count++;
				}
			}
		}
	}
	return A.size() - count;
}

int main(){

  	vector<int> v1 = {4,3,2,1,5};
  	vector<int> v2 = {0,1,0,0,0};
  	cout << "Solution : " << solution(v1, v2) << endl;
	
	return 0;
}
