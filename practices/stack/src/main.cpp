#include "Stack.h"

int main(){
    Stack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.print();
    std::cout << "Pop: " << stack.pop() << std::endl;
    stack.print();
    std::cout << "Pop: " << stack.pop() << std::endl;
    stack.print();
    std::cout << "Pop: " << stack.pop() << std::endl;
    stack.print();
    std::cout << "Pop: " << stack.pop() << std::endl;
    stack.print();
    std::cout << "Pop: " << stack.pop() << std::endl;
    stack.print();
    std::cout << "Pop: " << stack.pop() << std::endl;
    stack.print();
    return 0;
}