#include <iostream>
#include <string>
#include <cctype>

void addPrefix(std::string *text)
{
    // 让text指针指向的内容前面加上"CPP_"
    *text = "CPP_" + *text;
}

void makeUppercase(std::string &text)
{
    // 对text逐位转为大写
    for (int i = 0; i < text.size(); i++)
        text[i] = toupper(text[i]);
}

int main()
{
    std::string str;
    std::cin >> str;
    std::cout << str << std::endl;
    addPrefix(&str); // 应传入str的地址
    std::cout << str << std::endl;
    makeUppercase(str);
    std::cout << str << std::endl;

    return 0;
}