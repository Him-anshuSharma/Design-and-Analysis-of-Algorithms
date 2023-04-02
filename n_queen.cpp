#include<iostream>
#include<vector>
using namespace std;

int board[100][100] = {0};

bool check(int r, int c,int n){
    for(int i=c;i>=0;i--){
        if(board[r][i])
            return false;
    }
    for(int i=r,j=c;i>=0 && j>=0; i--,j--){
        if(board[i][j])
            return false;
    }
    for(int i=r,j=c;i<n && j>=0; i++,j--){
        if(board[i][j])
            return false;
    }
    return true;

}

bool solution(int c,int n){
    if(c>=n){
        return true;
    }
    for(int r=0;r<n;r++){
        if(check(r,c,n)){
            board[r][c] = 1;
            if(solution(c+1,n))
                return true;
            board[r][c]=0;
        } 
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int size;
    cin >> size;
    if(solution(0,size) == false){
        cout << "Sol does not exist";
        return 0;
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
