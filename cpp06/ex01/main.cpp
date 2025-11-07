#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "Zakaria";
    data.value = 3.14;

    std::cout << "Original Data pointer: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << ptr << std::endl;

    if (ptr == &data)
        std::cout << "✅ Success: Pointers are equal" << std::endl;
    else
        std::cout << "❌ Failure: Pointers differ" << std::endl;

    std::cout << "Deserialized content: " << ptr->name << ", id=" << ptr->id << ", value=" << ptr->value << std::endl;
}
