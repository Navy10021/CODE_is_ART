#include <iostream>
#include <cmath>

bool isPrime(int number){
    if (number <= 1) return false;
    // 소수 2
    else if (number <= 3) return true;
    // 2 또는 3으로 나눠 떨어지는 경우
    else if (number % 2 ==0 || number % 3 ==0) return false;
    // 5 이상의 수 
    for (int i=5; i*i <= number; i+=6){
        if (number % i ==0 || number % (i+2) ==0){
            return false;
        }
    }
    return true;
}

int main(){
    int start, end;
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> start >> end;
    std::cout << "The prime numbers between " << start << " and " << end << "\n";
    for (int i = start; i < end; i++){
        if (isPrime(i)) std::cout << i << " ";
    }

    return 0;
}
