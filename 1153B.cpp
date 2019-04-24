#include <iostream>
#include <vector>

using namespace std;

int n,m,h;
vector<int> a,b;
vector< vector<int> > hij;

int getHeight(int m, int n, int h)
{
    if (h == 0)
        return 0;
    
    if (m < n)
        return m;
    else
        return n;
}

int main() {
    cin >> n >> m >> h;

    for (int i = 0, temp; i < m; i++)
        cin >> temp, a.push_back(temp);

    for (int i = 0, temp; i < n; i++)
        cin >> temp, b.push_back(temp);

    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0, temp; j < m; j++)
            cin >> temp, row.push_back(temp);
        hij.push_back(row);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << getHeight(a[j], b[i], hij[i][j]) << " ";
        cout <<"\n";
    }
    return 0;
}