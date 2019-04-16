#include <iostream>
#include <vector>

using namespace std;

int n, t;
vector<vector<int>> route;

int findFirstArriveTime(int t, int s, int d)
{
    return s * d;
}

int main()
{
    cin >> n, t;

    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp, route[i].push_back(temp), cin >> temp, route[i].push_back(temp);
    }

    vector<int> firstArrive;
    for (int i = 0; i < n; i++)
    {
        firstArrive.push_back(findFirstArriveTime(t, route[i].at(0), route[i].at(1)));
    }

    for (int i = 0; i < n; i++)
    {
        cout << firstArrive[i] << " ";
    }

    return 0;
}