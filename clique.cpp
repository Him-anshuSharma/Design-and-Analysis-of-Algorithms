#include <iostream>
using namespace std;

int main()
{
    int n;
    bool isCl = true;
    cin >> n;
    int graph[n][n], candidate[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> candidate[i];
    }
    for(int i=0;i<n&&isCl;i++){
        for(int j=i+1;j<n&&isCl;j++){
            if(candidate[i] && candidate[j] && !graph[i][j]){
                isCl = false;
            }
        }
    }
    if(isCl){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}
