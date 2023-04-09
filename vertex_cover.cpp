#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;

    bool graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> cover;
    bool visited[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] && !visited[i] && !visited[j]) {
                visited[i] = true;
                visited[j] = true;
                cover.push_back(i+1);
                cover.push_back(j+1);
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cover.push_back(i+1);
        }
    }


    cout << "{ ";
    for (int i = 0; i < cover.size()-1; i++) {
        cout << (char)('a'+cover[i]) << " ";
    }
    cout << "}" << endl;

    return 0;
}
