#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;

int main() {
    // //ARRAY
    // int arr[3] = {1, 2, 3};
    // array<int, 6> a = {2, 5, 6, 7, 8, 0};
    // int size = a.size();
    // cout << "Size of STL array is : " << size << endl;
    // for(int i = 0; i<size; i++) {
    //     cout << a[i] << " ";
    // } cout << endl;
    // cout << "Element at index 2 : " << a.at(2) << endl;
    // cout << "First element : " << a.front() << endl;
    // cout << "Last index : " << a.back() << endl;
    // cout << "Array is empty or not : " << a.empty << endl;//0-> false, 1-> tuue
    //VECTOR
    // vector<int> v;
    // //Initialising vector with size and element
    // vector<int> b(5, 1);//5=Size, 1=element
    // vector<int> last(b);
    // cout << "Printing Last vector : ";
    // for(int i:last) {
    //     cout << i << " ";
    // } cout << endl;
    // cout << "Size -> " << v.size();
    // v.push_back(1);
    // cout << "Size -> " << v.size(); 
    // v.push_back(2);
    // cout << "Size -> " << v.size(); 
    // v.push_back(3);
    // v.push_back(9);
    // cout << "Size -> " << v.size() << endl; //Size give only actual element present in vector
    // cout << "Capacity -> " << v.capacity() << endl; //Note capacity double if extra element adds
    // // cout << "Checking 2-> " << binary_search(v.begin(), v.end(), 2) << endl;
    // // cout << "lower bound (Iterator of 2) -> " << lower_bound(v.begin(), v.end(), 2)-v.begin() << endl;
    // // cout << "Upper bound (Iterator of 2) -> " << upper_bound(v.begin(), v.end(), 2)-v.begin() << endl;
    // cout << "Front -> " << v.front() << endl; 
    // cout << "Back -> " << v.back() << endl; 
    // v.pop_back();
    // cout << "Before clear " << endl;
    // sort(v.begin(), v.end());//algo
    // for(int i:v) {
    //     cout << i << " ";
    // } cout << endl;
    // rotate(v.begin(), v.begin() + 1, v.end());//algo
    // cout << "After rotate " << endl;
    // for(int i:v) {
    //     cout << i << " ";
    // } cout << endl;
    // v.clear();
    // cout << "After clear" << endl;
    // cout << "Size-> " << v.size() << endl;
    // int a = 3;
    // int c = 6;
    // cout << "Max : " << max(a, c) << endl;//algo
    // swap(a, c);//algo
    // string abcd = "abcd";
    // reverse(abcd.begin(), abcd.end());//algo
    // cout << "String-> " << abcd << endl;
    // //Deque
    // deque<int> c;
    // c.push_back(1);
    // c.push_front(2);
    // c.push_back(3);
    // c.pop_back();
    // for(int i:c) {
    //     cout << i << " ";
    // } cout << endl;
    // cout << "Empty or not ->" << c.empty() << endl;
    // c.erase(c.begin(), c.begin()+1);
    // cout << c.size() << endl;
    //list
    // list<int> l;
    // list<int> n(5, 100)
    // l.push_back(2);
    // l.push_front(1);
    // cout << "Before erase" << endl;
    // for(int i:l) {
    //     cout << i << " " ;
    // } cout << endl;
    // l.erase(l.begin());
    // cout << "After erase" << endl;
    // for(int i:l) {
    //     cout << i << " " ;
    // } 
    //Stack
    // stack<string> s;
    // s.push("Rajnikant");
    // s.push("S/O Chandra kishor sharma");
    // s.push("Preparing for FANG");
    // cout << "Top element : " << s.top();
    // s.pop();
    // cout << "Top element : " << s.top();
    // int empty = s.empty();
    // cout << empty << endl;
    //Queue
    // queue<string> q;
    // q.push("Rajnikant");
    // q.push("Kumar");
    // q.push("Sharma");
    // cout << "Top element : " << q.front() << endl;
    // q.pop();
    // cout << "Top element : " << q.front() << endl;
    //Priority Queue
    // //Max heap
    // priority_queue<int> maxi;
    // //Min heap
    // priority_queue<int, vector <int> , greater<int>> min;
    // maxi.push(1);
    // maxi.push(7);
    // maxi.push(6);
    // maxi.push(3);
    // int n = maxi.size();//Because size changes after every pop
    // for(int i = 0; i<n; i++) {
    //     cout << maxi.top() << " ";
    //     maxi.pop();
    // } 
    // cout << endl;
    // min.push(1);
    // min.push(7);
    // min.push(6);
    // min.push(3);
    // int o = min.size();//Because size changes after every pop
    // for(int i = 0; i<o; i++) {
    //     cout << min.top() << " ";
    //     min.pop();
    // }
    //Set
    // set<int> t;
    // t.insert(1);
    // t.insert(9);
    // t.insert(7);
    // t.insert(2);
    // t.insert(2);
    // t.insert(7);
    // for(auto i : t) {
    //     cout << i  << " ";
    // } cout << endl;
    // set<int> :: iterator it = t.begin();
    // it++;
    // t.erase(it);
    // for(auto i : t) {
    //     cout << i  << " ";
    // } cout << endl;
    // cout << "2-> is present : " << t.count(7) << endl;
    // set<int> :: iterator itr = t.find(7);
    // for(auto it = itr; it !=t.end(); it++) {
    //     cout << *it  << " ";
    // } cout << endl;
    map <int, string> m;
    m[1] = "Rajnikant";
    m[9] = "Kumar";
    m[13] = "Sharma";
    m.insert({5, "bheem"});
    cout << "Befor erase";
    for(auto i:m) {
        cout << i.first << i.second << endl;
    }
    cout << "After erase" ;
    m.erase(9);
    for(auto i:m) {
        cout << i.first << " -> " << i.second << endl;
    }
    cout << "13-> is present or not : " << m.count(13) << endl;
    auto it = m.find(3);
    for(auto i=it; i!=m.end(); i++) {
        cout << (*i).first << endl;
    }
}