#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	vector<int> arr{8, 23, 30, 42, 92, 100, 492, 600};
	sort(arr.begin(), arr.end());
	cout << "Lower Bound: " << lower_bound(arr.begin(), arr.end(), 492) - arr.begin() << endl;
	cout << "Upper Bound: " << upper_bound(arr.begin(), arr.end(), 492) - arr.begin() << endl;

	return 0;	
}