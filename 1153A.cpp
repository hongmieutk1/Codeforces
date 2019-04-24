#include <iostream>
#include <vector>

using namespace std;

struct route
{
    int s;
    int d;
};

int n, t;

vector<route> routes;

int findFirstArriveTime(int t, int s, int d)
{
    if (t <= s)
        return s;
    
    int firstArrive;
    firstArrive = s + ((t-s)/d)*d;
    return (t-s)%d == 0 ? s : firstArrive + d;
}

int main()
{
    cin >> n >> t;
    for (int i = 0, temp, temp2; i < n; i++)
    {
        cin >> temp >> temp2;
        struct route routeTemp;
        routeTemp.s = temp;
        routeTemp.d = temp2;
        routes.push_back(routeTemp);
    }

    vector<int> firstArrive;
    for (int i = 0; i < n; i++)
    {
        firstArrive.push_back(findFirstArriveTime(t, routes.at(i).s, routes.at(i).d));
    }

    int min =firstArrive.at(0);
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (min > firstArrive.at(i)) {
            min = firstArrive.at(i);
            index = i;
        }
    }

    cout << index + 1;

    return 0;
}