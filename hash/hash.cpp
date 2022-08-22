#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
	unordered_map<int, int> mapp;
	mapp.insert({33, 11});
	mapp.insert({332, 121});
	mapp.insert({3, 1});
	mapp[45] = 21;
	if(mapp.find(332)==mapp.end()) cout << "ENd";
	else	cout << mapp[33];

	// for(auto i:mapp){
	// 	cout << "Key: " << i.first << "Value: " << i.second << endl;
	// }
	for(auto i = mapp.begin(); i!=mapp.end();i++){
		cout << "Key: " << i->first << "Value: " << i->second << endl;
	}
	return 0;
}