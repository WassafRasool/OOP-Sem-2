#include <iostream>
using namespace std;

int main(){
	int size;
	
	cout << "Enter size of the array: ";
	cin >> size;
		
	int array[size];
	
	int* arr = new int[size];
	
	for (int i=0; i<size; i++){
		cout << "Enter element " << i+1 << ": ";
		cin >> arr[i];
	}
	
	cout << "The elements of array are: " << endl;
	for (int i=0; i<size; i++){
		cout << arr[i] << endl;
	}
	

	int sum=0;
	for (int i=0;i<size;i++){
		sum = sum + arr[i];
	}
	cout << "The sum of all numbers in the array is: "<< sum << endl;
	
	int avg = sum/size;
	cout << "The average of all numbers in the array is: " << avg <<endl;
	
	int max;
	max = arr[0];
	for (int i=0;i<size;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	cout << "The maximum value is: "<< max << endl;
	
	delete[] arr;
	return 0;

}
