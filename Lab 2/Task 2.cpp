#include <iostream>
using namespace std;

int main(){
	int rows1,cols1;
	cout << "Enter number of rows for matrix: " << endl;
	cin >> rows1;
	cout << "Enter number of columns for matrix: " << endl;
	cin >> cols1;
	int** matrix1 = new int*[rows1];
	int** matrix2 = new int*[rows2];
	
	for(int i=0;i<rows1;i++){
		matrix1[i] = new int[cols1];
	}
	
	for (int i=0;i<rows1;i++){
		for (int j=0;j<cols1;j++){
			cout << "Enter element for row "<< i+1 << " and columm " << j+1 << ":" << endl;
			cin >> matrix1[i][j];
		}
	}
	
	
	
	
}
