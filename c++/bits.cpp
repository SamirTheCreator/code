#include <iostream>
#include <cmath>

using namespace std;

long long power2(int n){
    return 2 << n - 1;
}

bool powerof2 (int n) {
    if ((n & (n-1)) == 0){
        return true;
    }
    return false;
}

int main(){
    int n = 7;
    // pow(2, 7) == power2(7)
    cout << pow(2,n);
    cout << " == ";
    cout << power2(n);
    cout << "\n";

    int x = 4254;
    for (int k = 31; k >= 0; k--){
        if (x & (1 << k)) cout << "1";
        else cout << "0";
    }

    // powerof2(int x) return true if x is the power of 2
    int num;
    cout << "\nEnter number to check if it's a power of two\n";
    cin >> num;
    if (powerof2(num)){
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}