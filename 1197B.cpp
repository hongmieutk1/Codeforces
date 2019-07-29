#include <iostream>
#include <vector>

using namespace std;

int findMaxIndex(vector<int> a)
{
  int maxIndex = 0;
  int max = a[0];
  for (int i = 1; i < a.size(); i++)
  {
    if (max < a[i])
    {
      max = a[i];
      maxIndex = i;
    }
  }
  return maxIndex;
}

bool checkLeftSide(int maxIndex, vector<int> a)
{
  for (int i = 0; i < maxIndex; i++)
  {
    if (a[i] > a[i + 1])
    {
      return false;
    }
  }
  return true;
}

bool checkRightSide(int maxIndex, vector<int> a)
{
  for (int i = maxIndex; i < a.size() - 1; i++)
  {
    if (a[i + 1] > a[i])
    {
      return false;
    }
  }
  return true;
}

int main()
{

  int n;
  vector<int> a;

  cin >> n;
  for (int i = 0, temp; i < n; i++)
  {
    cin >> temp;
    a.push_back(temp);
  }

  int maxIndex = findMaxIndex(a);
  bool leftSide = checkLeftSide(maxIndex, a);
  bool rightSide = checkRightSide(maxIndex, a);

  if (leftSide && rightSide)
  {
    cout << "YES";
  }
  else
  {
    cout << "NO";
  }

  return 0;
}