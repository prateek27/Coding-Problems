#include<iostream>
using namespace std;
int print_subset(int arr[], int subset[1000][100], int index, int len) {
	if (index == len) {
		subset[0][0] = -1;
		return 1;
	}
	int x = print_subset(arr, subset, index+1, len);
	for(int i = 0 ; i < x; i++) {
		int j = 0;
		for(; subset[i][j]!= -1; j++) {
				subset[x+i][j] = subset[i][j];
		}
		subset[x+i][j] = arr[index];
		subset[x+i][j+1] = -1;
	}
	return 2*x;
}
int main() {
	int arr[100], subset[1000][100];
	int n;
	cin >> n;
	for (int i = 0; i < n ; i++) {
		cin >> arr[i];
	}
	int total_subsets = print_subset(arr, subset, 0, n);
	for(int i = 0 ; i < total_subsets; i++) {
		cout << '{';
		for(int j=0; subset[i][j]!= -1; j++) {
			cout << subset[i][j] << ',';
		}
		cout << '}' << endl;
		}
		return 0;

}
