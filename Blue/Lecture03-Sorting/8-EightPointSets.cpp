#include <bits/stdc++.h>
using namespace std;

struct EightPointSets
{
    int x, y;
};

bool option(const EightPointSets& A, const EightPointSets& B)
{
    if (A.x <= B.x )
    {
        return true;
    }
    return false;
}

bool optionY(const EightPointSets& A, const EightPointSets& B)
{
    if (A.x == B.x && A.y < B.y)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<EightPointSets> arr(8);

    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr.begin(), arr.end(), option);
    sort(arr.begin(), arr.begin()+3, optionY);
    sort(arr.begin()+3, arr.begin()+5, optionY);
    sort(arr.begin()+5, arr.begin()+8, optionY);

    bool result = false; // false = ugly, true = respectable

    if ((arr[0].x == arr[1].x) && (arr[1].x == arr[2].x) && (arr[0].y < arr[1].y) && (arr[1].y<arr[2].y))
    {
        if ((arr[5].x == arr[6].x) && (arr[6].x == arr[7].x) && (arr[5].y < arr[6].y) && (arr[6].y<arr[7].y))
        {
            if (arr[3].x == arr[4].x)
            {
                if (arr[2].x < arr[3].x && arr[4].x < arr[5].x)
                {
                    if (arr[3].y==arr[0].y && arr[4].y == arr[7].y)
                    {
                        result = true;
                    }
                }
            }
        }
    }


    (result == true) ? (cout << "respectable") : (cout << "ugly");

    return 0;
}