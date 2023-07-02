/*
길이가 1인 리스트를 정렬할 수 있다.
길이가 N인 두 정렬된 리스트를 합칠 수 있다.
길이가 N인 리스트를 정렬할 수 있으면, 길이가 2N인 리스트를 정렬할 수 있다.
*/
#include <iostream>

using namespace std;

int n = 10;
int arr[10] = {-5, 10, -3, -1, 0, 2, 5, 7, 3, 4};
int tmp[10];


void merge(int st, int en){
    int mid = (st + en) / 2;
    int l_idx = st;
    int r_idx = mid;
    
    for (int i = st; i < en; i++){
        if (arr[l_idx] <= arr[r_idx]) tmp[i] = arr[l_idx++];
        else if (r_idx == en) tmp[i] = arr[l_idx++];
        else if (l_idx == mid) tmp[i] = arr[r_idx++];
        else tmp[i] = arr[r_idx++];
    }
    for (int i=st; i<en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en){
    if (en == st+1) return;     // 배열의 크기가 1인 경우!
    int mid = (st+en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    merge_sort(0, n);
    
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}
