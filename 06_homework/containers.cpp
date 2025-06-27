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
    std::cout << example[2] << std::endl;

    
    std::cout << "Проверка односвязного списка" << std::endl;
    ForwardList<int>* forwardList = new ForwardList<int>;
    for (int i = 0; i < 10; ++i) {
        forwardList->push_back(i);
    }
    forwardList->print();
    std::cout << forwardList->size() << std::endl;
    forwardList->erase(2);
        //тут так, потому что у меня удаление одного элемента, поэтому 5 и 7 превращаются в 4 и 5 после удалений
    forwardList->erase(3);
    forwardList->erase(4);
    forwardList->print();
    forwardList->insert(0, 10);
    forwardList->print();
    forwardList->insert(4, 20);
    forwardList->print();
    forwardList->push_back(30);
    forwardList->print();
    std::cout << (*forwardList)[2] << std::endl;


    std::cout << "Проверка двусвязного списка" << std::endl;
    LinkedList<int>* linkedList = new LinkedList<int>;
    for (int i = 0; i < 10; ++i) {
        linkedList->push_back(i);
    }
    linkedList->print();
    std::cout << linkedList->size() << std::endl;
    linkedList->erase(2);
        //тут так, потому что у меня удаление одного элемента, поэтому 5 и 7 превращаются в 4 и 5 после удалений
    linkedList->erase(3);
    linkedList->erase(4);
    linkedList->print();
    linkedList->insert(0, 10);
    linkedList->print();
    linkedList->insert(4, 20);
    linkedList->print();
    linkedList->push_back(30);
    linkedList->print();
    std::cout << (*linkedList)[2] << std::endl;
    return 0;
}