#include "grammar.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    std::ostringstream oss;
    std::string line;
    cout << "请输入要分析的文法(注意要以'@'为结束符号)" << endl;
    while (std::getline(std::cin, line)) {
        // 检查是否包含结束符'@'
        if (line.find('@') != std::string::npos) {
            // 如果包含结束符，截取字符串并追加到oss中
            oss << line.substr(0, line.find('@'));
            break;
        }
        else {
            // 否则，追加整行到oss中
            oss << line << '\n';
        }
    }
    //获取
    std::string inputString = oss.str();
    //把长度太短的当成不存在文法
    if (inputString.length()<3)
    {
        cout << "文法不成立或无文法" << endl;
        return -1;
    }

    Grammar g(inputString);
    cout << g.show();

    system("pause");
}