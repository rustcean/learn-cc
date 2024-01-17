#include "grammar.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;

Grammar::Grammar(string inputString) {
    /*
    �����ַ����ָ�ķ�ʽ���ҵ�ÿһ������ʽ�Ӵ�
    �ٲ����ַ������ķ�������Ϊ���Զ�ȡʱ���԰��տո񡢻��еȵ����ָ�
    */
    //�ָ��ÿһ������ʽ�����ڿɱ�������
    vector<string> v;
    int from = 0;
    int len = 0;
    int i;
    for (i = 0; i < inputString.length(); ++i) {
        if (inputString[i] == '\n') {
            len = i - from;
            v.push_back(inputString.substr(from, len));
            from = i + 1;
        }
    }
    v.push_back(inputString.substr(from));
    //�ķ��������
    stringstream ss(v[0]);
    string s;
    ss >> s;
    //����ʼ�ķ����Ƕ��ѡ��ģ�˵����Ҫ����
    if (v[0].find('|') != string::npos) {
        v.insert(v.begin(), string(s + "'" + " -> " + s));
        s += "'";
    }
    this->start = s;

    //���ո�
    for (int i = 0; i < v.size(); i++)
    {
        string input = v[i];
        string result = "";
        for (int j = 0; j < input.length(); j++)
        {
            result += input[j];
            if ((input[j] == '-' && input[j + 1] == '>') || j == input.length() - 1 || input[j] == ' ')
                continue;
            result += ' ';
        }
        v[i] = result;
    }
    cout << "����:" << endl;
    for (auto& x : v)
        cout << x<<"1111"<< endl;


    //����ÿһ������ʽ��ɼ�ֵ��
    for (auto& x : v) {
        string key;
        vector<vector<string>> values;
        string a;
        vector<string> value;
        stringstream ss(x + " $");
        ss >> key;
        ss >> a;
        while (1) {
            ss >> a;
            if (a == "$") {
                break;
            }
            if (a == "|") {
                values.push_back(value);
                value.clear();
                continue;
            }
            int from = 0;
            int len = 0;
            int i;
            for (i = 0; i < a.length(); ++i) {
                if (a[i] == '(' || a[i] == ')') {
                    len = i - from;
                    if (len != 0) {
                        value.push_back(a.substr(from, len));
                    }
                    from = i + 1;
                    value.push_back(string(1, a[i]));
                }
            }
            if (from != i) {
                value.push_back(a.substr(from));
            }
        }
        values.push_back(value);
        this->m[key] = values;
    }

    /*����ս����*/
    for (auto it = m.begin(); it != m.end(); ++it) {
        this->ntSet.insert(it->first);
    }

    /*�������ս����follow���Ϻ�follow����*/
    this->first_follow_all();

    /*��LR(0)DFA���ж��Ƿ�ΪSLR(1)�ķ���SLR(1)���*/
    this->node_relationship();

}

string Grammar::get_start() {
    return this->start;
}

set<string> Grammar::get_ntSet() {
    return this->ntSet;
}

string Grammar::show() {
    /*
    �����ַ�������Ŀ���ǿ������������ļ����ķ�����չʾ��������ַ����У�ͨ��str()��������תΪ�ַ�����ʽoutputStr��
    ������������ն������ֱ����cout << outputStr ���ɡ�
    �����������QT�Ĵ������������outputStr���ɡ�
    */
    stringstream ss;
    //���������ս����first���Ϻ�follow����
    ss << "���з��ս��first����Ϊ:\n";
    for (auto& nt : this->ntSet) {
        ss << nt << ": ";
        for (auto& x : this->get_first(nt)) {
            ss << x << " ";
        }
        ss << "\n";
    }
    ss << "follow����Ϊ:\n";
    for (auto& nt : this->ntSet) {
        ss << nt << ": ";
        for (auto& x : this->get_follow(nt)) {
            ss << x << " ";
        }
        ss << "\n";
    }
    ss << "\nDFAͼΪ��\n";
    //���DFAͼ
    ss << "DFA����źͶ�Ӧ����Ŀ��Ϊ��\n";
    for (int i = 0; i < this->DFA_nodes.size(); ++i) {
        ss << "���" << i << ":\n";
        for (auto& p : this->DFA_nodes[i]) {
            ss << p.key << " -> ";
            for (int j = 0; j < this->m[p.key][p.value_num].size(); ++j) {
                if (j == p.index) {
                    ss << ".";
                }
                ss << this->m[p.key][p.value_num][j] << " ";
            }
            if (p.index == this->m[p.key][p.value_num].size()) {
                ss << ".";
            }
            ss << '\n';
        }
    }
    ss << "DFA���֮��������Ϊ(������Ԫ��ķ�ʽ):\n";
    for (auto& x : this->forwards) {
        int from = x.first;
        for (auto& y : x.second) {
            string t = y.first;
            int to = y.second;
            ss << "(" << from << ", " << t << ", " << to << ")  ";
        }
        ss << '\n';
    }
    //����Ƿ�ΪSLR(1)�ķ����粻�������ԭ��
    if (this->isSLR1) {
        ss << "\n���ķ�ΪSLR(1)�ķ�\n";
    }
    else {
        ss << "\n���ķ�����SLR(1)�ķ�\n";
        ss << "��ԭ��Ϊ:\n";
        ss << this->reason;
    }
    //���SLR(1)������
    ss << "SLR(1)������Ϊ\n";
    set<string> sSet;
    for (auto& x : this->forwards) {
        for (auto& y : x.second) {
            sSet.insert(y.first);
        }
    }
    for (auto& x : this->backs) {
        for (auto& y : x.second) {
            sSet.insert(y.first);
        }
    }
    ss.setf(ios::left);
    ss << setw(3) << " ";
    for (auto& s : sSet) {
        ss << setw(20) << s;
    }
    ss << '\n';
    for (int i = 0; i < this->DFA_nodes.size(); ++i) {
        ss << setw(3) << i;
        for (auto& s : sSet) {
            if (this->forwards[i].find(s) != this->forwards[i].end()) { //�����ƽ���
                if (this->ntSet.find(s) != this->ntSet.end()) {
                    ss << setw(20) << this->forwards[i][s];
                }
                else {
                    ss << setw(20) << "s" + to_string(this->forwards[i][s]);
                }
            }
            else if (this->backs[i].find(s) != this->backs[i].end()) { //���޹�Լ��
                Project& p = this->DFA_nodes[i][this->backs[i][s]];
                if (p.key == this->start) {
                    ss << setw(20) << "����";
                }
                else {
                    string a = "r(";
                    a += p.key;
                    a += " -> ";
                    vector<string>& value = this->m[p.key][p.value_num];
                    for (auto& b : value) {
                        a += b;
                        a += " ";
                    }
                    a[a.length() - 1] = ')';
                    ss << setw(20) << a;
                }
            }
            else {
                ss << setw(20) << " ";
            }
        }
        ss << '\n';
    }
    return ss.str();
}

string Grammar::parse(string sentence) {
    //�������ջs �� �������q
    vector<string> s;
    vector<string> q;
    //��ʼ���û��������
    stringstream ss(sentence + " $");
    string a;
    while (true) {
        ss >> a;
        if (a == "$")
            break;
        //����a�е�'(' ')'
        int from = 0;
        int len = 0;
        int i;
        for (i = 0; i < a.length(); ++i) {
            if (a[i] == '(' || a[i] == ')') {
                len = i - from;
                if (len > 0) {
                    q.push_back(a.substr(from, len));
                }
                q.push_back(string(1, a[i]));
                from = i + 1;
            }
        }
        if (from != i) {
            q.push_back(a.substr(from));
        }
    }
    q.push_back("$");
    //��ʼ������ջ
    s.push_back(to_string(0));
    s.push_back("$");
    //��������
    ss.clear();
    ss.setf(ios::left);
    ss << setw(10) << "step" << setw(30) << "parse stack" <<
        setw(30) << "input queue" << setw(30) << "action" << '\n';
    for (int i = 0; ; ++i) {
        //�������
        ss << setw(10) << i;
        //�������ջ
        a = "";
        for (int j = s.size() - 1; j >= 0; --j) {
            a += s[j];
            a += " ";
        }
        ss << setw(30) << a;
        //����������
        a = "";
        for (auto& x : q) {
            a += x;
            a += " ";
        }
        ss << setw(30) << a;
        //״̬ת��
        int f = stoi(s.front());
        string ts = q.front();
        int t;
        if (this->forwards[f].find(ts) != this->forwards[f].end()) {
            q.erase(q.begin());
            t = this->forwards[f][ts];
            s.insert(s.begin(), ts);
            s.insert(s.begin(), to_string(t));
            ss << setw(30) << "�ƽ�" + to_string(t) << '\n';
        }
        else if (this->backs[f].find(ts) != this->backs[f].end()) {
            t = this->backs[f][ts];
            Project& p = this->DFA_nodes[f][t];
            string& key = p.key;
            if (this->start == key) {
                ss << setw(30) << "����";
                ss << '\n';
                break;
            }
            vector<string> value = this->m[key][p.value_num];
            if (value[0] != "��") {
                for (int i = 0; i < value.size() * 2; ++i) {
                    s.erase(s.begin());
                }
            }

            f = stoi(s.front());
            t = this->forwards[f][key];
            s.insert(s.begin(), key);
            s.insert(s.begin(), to_string(t));
            a = "";
            a += "��";
            a += key;
            a += " -> ";
            for (auto& x : value) {
                a += x;
                a += " ";
            }
            a += "��Լ";
            ss << setw(30) << a;
            ss << '\n';
        }
        else {
            ss << setw(30) << "����";
            break;
        }
    }
    return ss.str();
}

set<string> Grammar::get_first(string key) {
    if (this->ntSet.find(key) == this->ntSet.end()) {
        return set<string>{key};
    }
    return this->m_first[key];
}

set<string> Grammar::get_follow(string key) {
    return m_follow[key];
}

set<string> Grammar::first(vector<string> value) {
    set<string> first_set;
    int k;
    for (k = 0; k < value.size(); ++k) {
        set<string> first_set_k = this->get_first(value[k]);
        for (auto& s : first_set_k) {
            first_set.insert(s);
        }
        if (first_set_k.find("��") == first_set_k.end()) {
            break;
        }
        first_set.erase("��");
    }
    if (k == value.size()) {
        first_set.insert("��");
    }
    return first_set;
}

void Grammar::first_follow_all() {
    //�����з��ս����first����
     //��ʼ��
    for (auto& nt : this->ntSet) {
        this->m_follow[nt] = set<string>();
    }
    bool isChange = true;
    while (isChange) {
        isChange = false;
        for (auto& p : this->m) {
            string key = p.first;
            vector<vector<string>> values = p.second;
            for (auto& value : values) {
                int k;
                for (k = 0; k < value.size(); ++k) {
                    auto&& first_set_k = this->get_first(value[k]);
                    for (auto& s : first_set_k) {
                        if ((s != "��") && (this->m_first[key].find(s) == this->m_first[key].end())) {
                            this->m_first[key].insert(s);
                            isChange = true;
                        }
                    }
                    if (first_set_k.find("��") == first_set_k.end()) {
                        break;
                    }
                }
                if (k == value.size() and (this->m_first[key].find("��") == this->m_first[key].end())) {
                    this->m_first[key].insert("��");
                    isChange = true;
                }
            }
        }
    }
    //�����з��ս����follow����
     //��ʼ��
    for (auto& nt : this->ntSet) {
        this->m_follow[nt] = set<string>();
    }
    this->m_follow[this->start].insert("$");
    isChange = true;
    while (isChange) {
        isChange = false;
        for (auto& p : this->m) { //����ÿһ������ʽp
            string key = p.first;
            vector<vector<string>> values = p.second;
            for (auto& value : values) {
                //����value��ÿһ�����ս��
                for (auto it = value.begin(); it != value.end(); ++it) {
                    if (this->ntSet.find(*it) != this->ntSet.end()) {
                        //�������
                        if (it + 1 == value.end()) {
                            for (auto& x : this->get_follow(key)) {
                                if (this->m_follow[*it].find(x) == this->m_follow[*it].end()) {
                                    this->m_follow[*it].insert(x);
                                    isChange = true;
                                }
                            }
                        }
                        else {
                            set<string> first_set = this->first(vector<string>(it + 1, value.end()));
                            for (auto& x : first_set) {
                                if (this->m_follow[*it].find(x) == this->m_follow[*it].end() and x != "��") {
                                    this->m_follow[*it].insert(x);
                                    isChange = true;
                                }
                            }
                            if (first_set.find("��") != first_set.end()) { //����Цŷ���
                                this->m_follow[*it].erase("��");
                                for (auto& x : this->get_follow(key)) {
                                    if (this->m_follow[*it].find(x) == this->m_follow[*it].end()) {
                                        this->m_follow[*it].insert(x);
                                        isChange = true;
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }
    }
}

void Grammar::node_relationship() {
    reason = "";
    //��ʼ��
    vector<Project> node{ Project{this->start, 0, 0, 1} };
    this->DFA_nodes.push_back(node);
    this->isSLR1 = true;
    //ѭ������ÿһ�����i
    for (int i = 0; i < this->DFA_nodes.size(); ++i) {
        this->forwards[i] = map<string, int>();
        this->backs[i] = map<string, int>();
        //��չ�ý��
        extend(i);
        //�����ý���ÿһ����Ŀ
        for (int j = 0; j < this->DFA_nodes[i].size(); ++j) {
            //�����Լ��
            Project& p = this->DFA_nodes[i][j];
            if (p.type == 2) {
                set<string> follow_set = this->get_follow(p.key);
                for (auto& s : follow_set) {
                    if (this->backs[i].find(s) != this->backs[i].end()) {
                        this->isSLR1 = false;
                        stringstream ss;
                        ss << "��" << i << "������й�Լ��Ŀ��follow�����н���\n";
                        reason += ss.str();
                    }
                    this->backs[i][s] = j;
                }
            }
            //�����ƽ���
            else {
                string t = this->m[p.key][p.value_num][p.index];
                Project newP(p.key, p.value_num, p.index + 1, 1);
                if (newP.index >= this->m[p.key][p.value_num].size()) {
                    newP.type = 2;
                }
                if (this->forwards[i].find(t) == this->forwards[i].end()) {//ת��tδ����
                    int k = 0;
                    for (k = 0; k < this->DFA_nodes.size(); ++k) {
                        vector<Project>& n = this->DFA_nodes[k];
                        if (find(n.begin(), n.end(), newP) != n.end()) {
                            break;
                        }
                    }
                    if (k < this->DFA_nodes.size()) { //��Ŀ�Ѿ�����
                        this->forwards[i][t] = k;
                    }
                    else { //��Ŀδ����
                        //�½��ڵ�
                        this->DFA_nodes.push_back(vector<Project>{newP});
                        this->forwards[i][t] = this->DFA_nodes.size() - 1;
                    }
                }
                else { //ת��t����
                    int k = this->forwards[i][t];
                    vector<Project>& n = this->DFA_nodes[k];
                    if (find(n.begin(), n.end(), newP) == n.end()) { //��Ŀ������
                        this->DFA_nodes[k].push_back(newP);
                    }
                }
            }
        }
    }
    if (this->isSLR1) {
        for (int i = 0; i < this->DFA_nodes.size(); ++i) {
            set<string> set1, set2, result;
            for (auto& x : this->forwards[i]) {
                set1.insert(x.first);
            }
            for (auto& x : this->backs[i]) {
                set2.insert(x.first);
            }
            set_intersection(begin(set1), end(set1), begin(set2), end(set2),
                inserter(result, begin(result)));
            if (result.size() != 0) {
                this->isSLR1 = false;
                stringstream ss;
                ss << "��" << i << "�������ƽ����first���Ϻ͹�Լ���follow�����н���\n";
                reason += ss.str();
            }
        }
    }
}

void Grammar::extend(int k) {
    vector<Project>& node = this->DFA_nodes[k];
    for (int i = 0; i < node.size(); ++i) {
        Project& p = node[i];
        if (p.type == 1) {
            string extend_s = this->m[p.key][p.value_num][p.index];
            if (this->ntSet.find(extend_s) != this->ntSet.end()) {
                //����չ�ķ���
                vector<vector<string>>& values = this->m[extend_s];
                //����extend_s��Ӧ��ÿһ��value
                for (int j = 0; j < values.size(); ++j) {
                    Project addP(extend_s, j, 0, 1);
                    if (values[j][0] == "��") {//extend_s -> ���������
                        addP.index = 1;
                        addP.type = 2;
                    }
                    //�ж������ظ�
                    if (find(node.begin() + i, node.end(), addP) == node.end()) {
                        node.push_back(addP);
                    }
                }
            }
        }
    }
}