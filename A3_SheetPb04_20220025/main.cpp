#include <bits\stdc++.h>
using namespace std;
#define BUFFALO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
template<typename T>
class Set{
private:
    vector<T>MySet;
public:
    void Add(T Item);
    void Pop(T Item);
    int Size();
    bool if_IN(T Item);
    T* PTR();



};
template<typename T>
void Set<T>::Add(T Item) {
    if(find(MySet.begin(), MySet.end(),Item) == MySet.end()){
        MySet.push_back(Item);
    }else{
        return;
    }
}
template<typename T>
void Set<T>::Pop(T Item){
    auto itr = find(MySet.begin(), MySet.end(),Item);
    if(itr == MySet.end()){
        return;
    }else{
        MySet.erase(itr);
    }
}
template<typename T>
int Set<T>::Size() {
    return MySet.size();
}
template<typename T>
bool Set<T>::if_IN(T Item){
    auto itr = find(MySet.begin(), MySet.end(),Item);
    if(itr == MySet.end()){
        return 0;
    }else{
        return 1;
    }
}
template<typename T>
T* Set<T>::PTR() {
    T* arr = new T[this->Size()];

    for (int i = 0; i < this->Size(); ++i) {
        arr[i] = MySet[i];
    }
    return arr;
}
int main() {
    BUFFALO
    Set<int>S1;
    S1.Add(1);
    S1.Add(2);
    S1.Add(3);
    S1.Add(1);
    S1.Add(4);
    S1.Add(3);
    cout<<S1.Size()<<" "<<S1.if_IN(3)<<endl;
    S1.Pop(3);
    cout<<S1.Size()<<" "<<S1.if_IN(3)<<endl;
    auto returnedArray = S1.PTR();
    cout<<returnedArray<<" ";
    for (int i = 0; i < S1.Size(); ++i) {
        cout <<returnedArray[i]<<" ";

    }
    cout << endl;
    delete[] returnedArray;
    Set<string>S2;
    S2.Add("Ahmed");
    S2.Add("Abdelaziz");
    S2.Add("Ahmed");
    S2.Add("Ahmed");
    S2.Add("Mohamed");
    S2.Add("FCB");
    cout<<S2.Size()<<" " <<S2.if_IN("Ahmed")<< endl;
    S2.Pop("Ahmed");
    cout<<S2.Size()<<" " <<S2.if_IN("Ahmed")<< endl;
    auto returnedArray2 = S2.PTR();
    cout<<returnedArray2<<" ";
    for (int i = 0; i < S2.Size(); ++i) {
        cout <<returnedArray2[i]<<" ";

    }
    delete[] returnedArray2;




    return 0;
}

