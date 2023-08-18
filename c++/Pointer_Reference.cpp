/*
& : 변수 앞에 붙여 해당 변수의 메모리 주소에 대한 reference 생성. 해당 변수의 별칭(alias) 원래 변수와 같은 메모리 공유!
* : 변수 앞에 붙여 해당 포이터가 가르키는 메모리 주소에 저장된 값을 참조(reference)
즉, reference(&)는 이미 존재하는 변수에 별칭을 만들어주고, Pointer(*)는 변수가 메모리 주소를 가르키거나, 주소의 저장된 값을 참조할때 사용
*/
#include <iostream>
#include <string>

int main(){
    std::string text = "Hello, Lee";

    // referece example
    std::string& ref = text;    // string에 대한 referce 생성, text 변수의 메모리 공유 
    std::cout << "Reference : " << ref << "\n";
    // ref : 자체적으로 메모리와 데이터를 소유하지 않고 문자열 전달&&참조(메모리 재할당) 메모리 성능면에서 효율적
    ref = "Hello, Sion!";    
    std::cout << "Reference : " << ref << "\n";
    std::cout << "Text : " << text << "\n";

    // Pointer example
    //std::string text = "Hello, Lee"; <- 이미 변수가 생성되어 오류 발생
    
    std::string* ptr = &text;  // string에 대한 Pointer 생성. text의 메모리 주소를 가르킴.
    *ptr = "Hello, Xion";         // Pointer의 값을 변경
    std::cout << "* Pointer : " << text << "\n";
}
