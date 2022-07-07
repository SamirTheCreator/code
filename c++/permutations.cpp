#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> subset){
    for(int i=0; i < subset.size(); i++) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

void permutations(vector<int> set, vector<int> permutation, bool chosen[]){
    if (permutation.size() == set.size()) {
        print(permutation);
    } else {
        for (int i = 0; i < set.size() + 1; i++) {
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(set[i]);
            permutations(set, permutation, chosen);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main(){
    vector<int> set, permutation;
    for(int i = 1; i <= 3; i++){
        set.push_back(i);
    }
    bool chosen[set.size()];
    for (int i=0; i < set.size(); i++){
        chosen[i] = false;
    }
    permutations(set, permutation, chosen);

    return 0;
}