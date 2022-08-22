#include<iostream>
using namespace std;

int main(){
	long long num;
	cout << "Enter number whose square root is needed!" << endl;
	cin >> num;
	if(num==1){
        return 1;
    }
    if(num==0){
        return 0;
    }
    long long start=1, end=num, pos;
    while(start<=end){
        long long mid = (start + end)/2;
        //cout << "Trying this as solution: " << mid << endl;
        if(mid*mid==num){
            pos = mid;
            cout << "True pos is" << pos << endl;
            break;
        }
        else if(mid*mid>num){
            end = mid - 1;
        }
        else{//(mid*mid<num){
            start = mid + 1;
            pos = mid;
            cout << "Pos is: " << pos << endl;
        }
    } 
    cout << pos; 
}