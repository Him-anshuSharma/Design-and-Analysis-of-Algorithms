#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int matrix[100][100];
int INF = 1e4;

void floyd_warshall(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];

        }
    }
    floyd_warshall(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 1e4){
                cout << "INF";
                continue;
            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
