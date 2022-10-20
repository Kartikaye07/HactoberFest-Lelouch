#include <iostream>
using namespace std;

int getSum(int *arr, int size){

    //base case
    if(size == 0){
        return 0;
    }

    int newSum =  getSum(arr + 1, size-1);
    int sum = arr[0] + newSum;
    return sum;

}

int main(){
    int arr[5] = {2,2,4,10,6};
    int size = 5;

    int ans = getSum(arr, size);
    
    cout << ans << endl;

    return 0;
}