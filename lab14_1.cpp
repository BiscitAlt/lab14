#include <iostream>
using namespace std;

template <typename T>
void insertionSort(T d[],int N){
	for(int i = 1; i < N; i++){
		cout << "Pass " << i << ":";
		T temp = d[i];
		int j = i-1;
		while(j >= 0 && d[j]<temp){
	        d[j+1] = d[j];
	        j = j-1;
		}
	    d[j+1] = temp;
	    for(int i = 0; i < N; i++) cout << d[i] << " ";
		cout << endl;
	}
}