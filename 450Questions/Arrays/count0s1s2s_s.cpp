#include <iostream>

using namespace std;

int Partition(int arr[], int size) {
    int st = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] < 0) {
            swap(arr[i], arr[st]);
            st++;
        }
    }
    return st;
}

void rearrangeArray(int arr[], int n)
{
    int st_p = Partition(arr, n);
    
    if(st_p == 0 || st_p == n)
        return;

    int st_n = 0;
    
    while(st_p < n && st_p > st_n) {
        swap(arr[st_p], arr[st_n]);
        st_p++;
        st_n += 2;
    }
}

int main()
{
    int arr[6] = {-4,-3,-1,1,2,4};
    
    rearrangeArray(arr, 6);
    
    for(int i = 0; i < 6; i++) 
        cout << arr[i] << " ";

    return 0;
}