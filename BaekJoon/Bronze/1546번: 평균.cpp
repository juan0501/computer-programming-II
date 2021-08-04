#include <iostream>
using namespace std;

int main()
{
    int numOfSubject;
    cin >> numOfSubject;

    float *arr;
    arr = (float*)malloc(sizeof(float) * numOfSubject);

    float max = -1;
    for(int i = 0; i < numOfSubject; i++)
    {   
        scanf("%f", &arr[i]);
        if(max < arr[i]) //find maximum
            max = arr[i];
    }

    float sum = 0;
    for(int i = 0; i < numOfSubject; i++)
    {
        sum += arr[i] * 100 / max;
    }

    cout << sum / float(numOfSubject) << endl;

    return 0;
}
