#include <iostream>

template <class T>
T product(T num1, T num2)
{
    return num1 * num2;
}

int main()
{
    int numb1, numb2;
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> numb1 >> numb2;
    std::cout << "numb1 * numb2 = " << product(numb1, numb2);

    float n1, n2;
    std::cout << "\nEnter two numbers: " << std::endl;
    std::cin >> n1 >> n2;
    std::cout << "numb1 * numb2 = " << product(n1, n2);


}