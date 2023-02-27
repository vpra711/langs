#include <iostream>
#include <concepts>

template <typename T>
requires std::integral<T>
T add(T a, T b)
{
    return a + b;
}

// template <std::integral T>
// T add(T a, T b)
// {
//     return a + b;
// }

//user defined concepts
// template <typename T>
// concept myconcept = std::is_integral_v<T>;

// template <typename T>
// concept divisonable = requires(T a, T b)
// {
//     a /= b;
// };

int main()
{
    auto a = add(5, 6);
    std::cout << a << std::endl;
    auto b = add(5.6, 7.6);
    std::cout << b << std::endl;
    return 0;
}