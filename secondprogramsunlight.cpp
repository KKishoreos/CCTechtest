#include <iostream>
using namespace std;

int numberofbuildings(int arr[], int x)
{

     int count = 1;


    int curr_max = arr[0];
    for (int i=1; i<x; i++)
    {

        if (arr[i] > curr_max)
        {
            count++;
            curr_max=arr[i];
        }
    }

    return count;
}


int main()
{
    int arr[] = {8, 3, 4, 11, 21,25};
    int x = sizeof(arr) / sizeof(arr[0]);
    cout << numberofbuildings(arr, x);
    return 0;
}
