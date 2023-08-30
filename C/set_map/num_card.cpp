#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;
// N개의 카드를 가지고 있고, M개의 카드 중에 가지고 있는지 여부 확인.

bool binarySearch(const vector<int>& cards, int tgt){
    int left = 0;
    int right = cards.size() - 1;

    while(left <= right){
        int mid = left + (right-left) / 2;
        if (cards[mid] == tgt){
            return true;
        }
        else if (cards[mid] < tgt){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}

int main(){
    int N, M;
    cin >> N;
    vector<int> cards(N);

    for (int i = 0; i < N; i++){
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    cin >> M;

    for (int i=0; i<M; i++){
        int num;
        cin >> num;

        if (binarySearch(cards, num)){
            cout<< "1 ";
        }
        else {
            cout << "0 ";
        }
    }
}


/* With unordered set
int main(){
    int N, M;
    cin >> N;
    unordered_set<int> cards;

    for (int i=0; i<N; i++){
        int card;
        cin >> card;
        cards.insert(card);
    }

    cin >> M;   // 검사할 개수 
    for(int i=0; i<M; i++){
        int num;
        cin >> num;

        if(cards.find(num) != cards.end()){
            cout << "1 ";
        }
        else{
            cout << "0 ";
        }
    }
    return 0;
}
*/
