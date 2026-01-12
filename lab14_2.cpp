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

void inputMatrix(double matrix[][N]){
	string input;
	for(int i = 0; i < N; i++){
		cout << "Row " << i+1 << ": ";
		getline(cin,input);
		int col = 0;
		string num = "";
		for(int j = 0; j < (int)input.size(); j++){
			if(input[j] == ' '){
				if(num != ""){
					matrix[i][col] = stod(num);
					col++;
					num = "";
				}
			}
			else{
				num += input[j];
			}
		}
		if(num != ""){
            matrix[i][col] = stod(num);
        }
	}
}

void findLocalMax(const double input[][N], bool output[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			output[i][j] = false;
		}
	}
	for(int i = 1; i < N; i++){
		for(int j = 1; j < N; j++){
			if(input[i][j] > input[i-1][j] && input[i][j] > input[i+1][j] && input[i][j] > input[i][j-1] && input[i][j] > input[i][j+1]){
				output[i][j] = true;
			}
			else{
				output[i][j] = false;
			}
		}
	}
}

void showMatrix(const bool x[][N]){

}