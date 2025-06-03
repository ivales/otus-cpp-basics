#include "array.h"
#include "list.h"


int main() {
    std::cout << "Проверка последовательного списка" << std::endl;
    Array<int> example{};
    for (int i = 0; i < 10; ++i) {
        example.push_back(i);
    }
    example.print();
    std::cout << example.size() << std::endl;
    example.erase(2);
        //тут так, потому что у меня удаление одного элемента, поэтому 5 и 7 превращаются в 4 и 5 после удалений
    example.erase(3); 
    example.erase(4);
    example.print();
    example.insert(0, 10);
    example.print();
    example.insert(4, 20);
    example.print();
    example.push_back(30);
    example.print();
    std::cout << "Проверка односвязного списка" << std::endl;
    List<int> list{};
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
    list.print();
    return 0;
}