#include "grammar.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    std::ostringstream oss;
    std::string line;
    cout << "������Ҫ�������ķ�(ע��Ҫ��'@'Ϊ��������)" << endl;
    while (std::getline(std::cin, line)) {
        // ����Ƿ����������'@'
        if (line.find('@') != std::string::npos) {
            // �����������������ȡ�ַ�����׷�ӵ�oss��
            oss << line.substr(0, line.find('@'));
            break;
        }
        else {
            // ����׷�����е�oss��
            oss << line << '\n';
        }
    }
    //��ȡ
    std::string inputString = oss.str();
    //�ѳ���̫�̵ĵ��ɲ������ķ�
    if (inputString.length()<3)
    {
        cout << "�ķ������������ķ�" << endl;
        return -1;
    }

    Grammar g(inputString);
    cout << g.show();

    system("pause");
}