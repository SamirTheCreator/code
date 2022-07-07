#include <iostream>
#define N 8
using namespace std;

static int count = 0;
static int board[N][N] = {};

void print(int board[N][N]){
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isSafe(int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}

void search(int y) {
    if (y == N) {
        count++;
    } else {
        for (int x = 0; x < N; x++) {
            if (isSafe(x, y)) {
                board[x][y] = 1;
                search(y+1);
                board[x][y] = 0;
            }
        }
    }
}

int main(){
    search(0);
    cout << count;
    return 0;
}