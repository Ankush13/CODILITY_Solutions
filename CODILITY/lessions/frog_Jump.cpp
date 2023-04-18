#include<iostream>
using namespace std;

//MY solution
void solution(int X, int Y, int D){

	int jump = X, count = 0;
	
	while(jump <= Y)
	{
		jump += D;
		count++;
	}
	
	
	cout << "Count is: " << count << endl;
}

int solution2(int X, int Y, int D){

	//X = 10, Y = 85, D = 30
	int v = ( Y-X ) / D; // (85 - 10) / 30 => 75 / 30 => 2.5 => 2

	//what is X+v*D >= Y (the else part)? Answer: It's an edge case where if from position X the frog makes V jumps of distance D each (so X+v*D) and still didn't reach the other side hence X+v*D < Y, so we must add one more step therefore we return v+1
	if( X + v * D < Y )
		return v+1;
	else // (X + v * D >= Y)
		return v; 
}

#include<cmath>
int solution3(int X, int Y, int D){
	
	int ans = 0;
	if(X == Y) return 0;
	
	ans = ceil( (double)(Y-X)/D );
	return ans;
}

int main(){

	int x = 10, y = 85, d = 30;
	solution(x,y,d);
	cout << "Solution2 : " << solution2(10,85,30) << endl;

	cout << "Solution3 : " << solution3(10,85,30) << endl;

	return 0;
}
