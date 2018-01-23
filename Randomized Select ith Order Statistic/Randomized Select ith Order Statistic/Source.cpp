#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//prototypes
vector<int> Populate(vector<int> &v);
void Print(vector<int> v);
int randomizedSelect(vector<int> &v, int p, int r, int k);
int Partition(vector<int> &v, int p, int r);
void Quicksort(vector<int> &v, int p, int r);
int randomPartition(vector<int> v, int p, int r);

void main() {
	vector<int> arr(10);
	Populate(arr);
	Print(arr);

	int randomSelect = randomizedSelect(arr, 0, arr.size() - 1, 3);
	Quicksort(arr, 0, arr.size() - 1);
	Print(arr);

	cout << "The third smallest element in the array is " << randomSelect << endl;
}

//function to populate array randomly and alternate between positive and negative
vector<int> Populate(vector<int> &v) {
	srand(clock());
	for (int i = 0; i < v.size(); i++) {
		//generate a 0 or 1
		//this value will determine if we generate a negative or positive number
		int negORpos = rand() % 2;
		//generate a negative number for 0
		if (negORpos == 0)
			v[i] = -rand() % 100;
		//generate a positive number for 1
		else
			v[i] = rand() % 100;
	}
	//return the now populated vector
	return v;
}

void Print(vector<int> v) {
	//output each element
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";	//add a space for formatting
	}
	//add an extra line for formatting
	cout << endl;
}

//this function will recursively sort the array
void Quicksort(vector<int> &v, int p, int r) {
	//r must be greater than p to avoid index intersection
	if (p < r) {
		int q = Partition(v, p, r);	//partition the subarray
		Quicksort(v, p, q - 1);	//quick sort the first subarray
		Quicksort(v, q + 1, r);	//quick sort the second subarray
	}
}

int randomizedSelect(vector<int> &v, int p, int r, int k) {
	//if the beginning and end are the same, there is only one element
	if (p == r)
		return v[p];
	//if the ith element we are searching for is 
	if (k == 0)
		return NULL;
	//as long as the beginning is actually before the end, check the next side
	if (p < r) {
		int q = Partition(v, p, r);  //partition the subarray
		int i = q - p + 1; //if the partition we are looking at is in the second half, we have to account for that
		if (i == k) //if the calculated location of the ith element is k, the ith element passed to the function, return that place
			return v[q];
		else if (k < i) //else if k < i we need to look on the left side
			return randomizedSelect(v, p, q - 1, k);
		else //else look on the right side
			return randomizedSelect(v, q + 1, r, k - i);
	}
}

//this function will rearrange the subarray in place
//all elements less than the pivot go to the left,
//all that are greater than the pivot go to the right
int Partition(vector<int> &v, int left, int right) {
	//set the pivot
	int pivot = v[right];

	//set the index for left 
	int i = left - 1;

	//set the index for right and begin the loop
	for (int j = left; j < right; j++) {
		if (v[j] <= pivot) {
			//if the value is less than the pivot value, swap it with v[j]
			i++;
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}
	//increase i
	i++;
	//and swap v[i] with v[right] (it puts it back in the correct place)
	int temp = v[i];
	v[i] = v[right];
	v[right] = temp;

	return i;
}