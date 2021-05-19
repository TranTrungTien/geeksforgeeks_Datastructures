#include <iostream>
#include <vector>

// optimized rotation

void optimizedRotation(std::vector<int> &arr, int n, int d)
{
    int x = d / n;
    d -= (x * n);
    if (d == 0)
        return;
    std::vector<int> tmp(n);
    for(int i = 0; i < n; ++i)
    {
        tmp[(n - d + i) % n] = arr[i];
    }
    arr = tmp;
}

//rotation one by one
void rotationOneByOne(std::vector<int> &arr, int n, int d)
{
    int x = d / n;
    d -= (x * n);
    if (d == 0)
        return;
    while (d > 0)
    {
        int tmp = arr[0];
        for (int i = 0; i < n; ++i)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = tmp;
        --d;
    }
}

//rotation using extra array

void rotationUsingExtraArr(std::vector<int> &arr, int n, int d)
{
    int x = d / n;
    d -= (x * n);
    if (d == 0)
        return;
    std::vector<int> tmp(n);
    for (int i = 0; i < n; ++i)
    {
        tmp[i] = arr[i + d];
        if ((i + d) == (n - 1))
            d = -i - 1;
    }
    arr = tmp;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    int d = 7;
    const int n = arr.size();
    //arrayRotation();
    optimizedRotation(arr, n, d);
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}