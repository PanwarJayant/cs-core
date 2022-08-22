#include <bits/stdc++.h>
using namespace std;

//struct to be passed as third argument for min heap using
//make_heap() function
struct greaters{
bool operator()(const long& a,const long& b) const{
    return a>b;
}
};

void heapSort(){
    vector<int> pp;
    pp.push_back(5);
    pp.push_back(1);
    pp.push_back(10);
    pp.push_back(30);
    pp.push_back(20);
    // MIN HEAP 
    // make_heap(pp.begin(), pp.end(), greaters());
    // MAX HEAP
    make_heap(pp.begin(), pp.end());
    sort_heap(pp.begin(), pp.end()); // min heap sorted
    // uncomment if max heap sorted required
    reverse(pp.begin(), pp.end());

    for(int i=0; i<pp.size(); i++){
        cout << pp[i] << " ";
    }
}

void vectorHeap(){
    vector<int> pp;
    pp.push_back(5);
    pp.push_back(1);
    pp.push_back(10);
    pp.push_back(30);
    pp.push_back(20);
    // MIN HEAP 
    // make_heap(pp.begin(), pp.end(), greaters());
    // MAX HEAP
    make_heap(pp.begin(), pp.end());
    pp.push_back(23);
    push_heap(pp.begin(), pp.end());
    // Remove root of heap
    pop_heap(pp.begin(), pp.end());
    pp.pop_back();

    for(int i=0; i<pp.size(); i++){
        cout << pp[i] << " ";
    }
}

void priorityQHeap(){
    // below line for max heap
    priority_queue <int> pq;
    // for min heap see below
    // priority_queue <int, vector<int>, greater<int> > pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);
    cout << "asd " << pq.size() << endl;
    // One by one extract items from max heap
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

}

int main ()
{

    // priorityQHeap();
    cout << "\nBUFFER\n";
    // vectorHeap();
    cout << "\nBUFFER\n";
    heapSort();
    return 0;
}