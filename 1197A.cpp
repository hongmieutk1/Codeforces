#include <iostream>
#include <vector>

using namespace std;

int findMaxIndex(vector<int> planks)
{
  int maxIndex = 0;
  int max = planks[0];
  for (int i = 1; i < planks.size(); i++)
  {
    if (max < planks[i])
    {
      max = planks[i];
      maxIndex = i;
    }
  }
  return maxIndex;
}

int detectLadder(int n, vector<int> planks)
{
  if (n < 2)
  {
    return 0;
  }

  int maxIndex1 = findMaxIndex(planks);
  planks.erase(planks.begin() + maxIndex1);
  int maxIndex2 = findMaxIndex(planks);

  if (planks[maxIndex2] <= 1)
  {
    return 0;
  }

  if (planks.size() >= planks[maxIndex2])
  {
    return planks[maxIndex2] - 1;
  }
  else
  {
    return planks.size() - 1;
  }
}

int main()
{

  int queries, n;

  cin >> queries;
  for (int i = 0; i < queries; i++)
  {
    cin >> n;
    vector<int> planks;
    for (int j = 0, temp; j < n; j++)
    {
      cin >> temp;
      planks.push_back(temp);
    }
    cout << detectLadder(n, planks) << endl;
  }

  return 0;
}