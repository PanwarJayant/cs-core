#include <iostream>
#include <queue>

using namespace std;

void printq(queue<int>q){
	cout << "Q is: ";
	for(int i=0; i<q.size();i++){
		cout << q[i] << " ";
	}
	cout << endl;
}

int main(){
	queue<int> q;
	q.push(34);
	q.push(23);
	q.push(232);
	q.push(2323);
	printq(q);
	q.pop();
	q.pop();
	printq(q);
	cout << "Front: " << q.front() << endl;
	cout << "Empty: " << q.empty() << endl;
	return 0;

}