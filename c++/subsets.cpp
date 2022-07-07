#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> subset){
    for(int i=0; i < subset.size(); i++){
        cout << subset[i] << " ";
    }
    cout << endl;
}

void search(vector<int> set, vector<int> subset, int i){
    if (i == set.size() + 1){
        print(subset);
    }
    else {
        subset.push_back(i);
        search(set, subset, i+1);
        subset.pop_back();
        search(set, subset, i+1);
    }
}

void subsets(vector<int> set, int i){
    vector<int> subset;
    search(set, subset, i);
}

int main(){
    vector<int> set;
    int n = 1;
    for(int i = n; i <= 2; i++){
        set.push_back(i);
    }
    subsets(set, n);
    return 0;
}