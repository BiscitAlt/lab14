#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 

void inputMatrix(double A[][N]){
	string input;
	for(int i = 0; i < N; i++){
		cout << "Row " << i+1 << ": ";
		getline(cin,input);
		int col = 0;
		string num = "";
		for(int j = 0; j < (int)input.size(); j++){
			if(input[j] == ' '){
				if(num != ""){
					A[i][col] = stod(num);
					col++;
					num = "";
				}
			}
			else{
				num += input[j];
			}
		}
		if(num != ""){
            A[i][col] = stod(num);
        }
	}
}

void findLocalMax(const double A[][N], bool B[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(A[i][j] >= A[i-1][j] && A[i][j] >= A[i+1][j] && A[i][j] >= A[i][j-1] && A[i][j] >= A[i][j+1]){
				B[i][j] = true;
			}
			else{
				B[i][j] = false;
			}
		}
	}
	for(int i = 0; i < N; i++){
		if(i == 0 || i == N-1){
			for(int j = 0; j < N; j++){
				B[i][j] = false;
			}
			continue;
		}
		B[i][0] = false;
		B[i][N-1] = false;
	}
}

void showMatrix(const bool A[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++) cout << A[i][j] << " ";
		cout << endl;
	}
}