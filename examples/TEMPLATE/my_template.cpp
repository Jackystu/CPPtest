#include <iostream>

template <typename T>
void myPrint(T value)
{
    std::cout << value << std::endl;
}

template <typename T, int size>
class Array
{
private:
    T m_Array[size];

public:
    int getSize() const;
    void writeArray();
    void printArray();
};
template <>
int Array<std::string, 3>::getSize() const
{
    return 3;
}

template <>
void Array<std::string, 3>::writeArray()
{
    for (int i = 0; i < 3; i++)
    {
        std::cin >> m_Array[i];
    }
}

template <>
void Array<std::string, 3>::printArray()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << m_Array[i] << std::endl;
    }
};

int main()
{
    myPrint(5);
    myPrint<std::string>("Hello World");
    Array<std::string, 3> array;
    std::cout << array.getSize() << std::endl;
    array.writeArray();
    array.printArray();

    return 0;
}