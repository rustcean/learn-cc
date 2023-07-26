#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
enum class device_type { pc, router, sw };      // 区分设备类型（用户PC，路由器）
enum class setting_type { norm, stat, defau };  // 区分路由配置类型（普通路由、特定主机路由、默认路由）
class Device;
class PC;
class Router;
class Switch;

struct route_info
{
    long long net_num;          // 目的网络地址
    long long cover_num;        // 子网掩码
    long long next_hop;         // 下一跳地址
    int route_interface;        // 接口位置
    setting_type set_type;      // 配置类型

    route_info()                // 初始化地址为0.0.0.0/0
    {
        net_num = 0;
        cover_num = 0;
        next_hop = -1;
        route_interface = -1;
        set_type = setting_type::defau;
    }
};

long long ip_to_num(string s)   // 点分十进制字符串 -> 十进制数字
{
    long long result = 0, p = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.') { result *= 256; result += p; p = 0; }
        else { p = p * 10 + long long(s[i]) - long long('0'); }
    }
    return result * 256 + p;
}

string num_to_ip(long long n)   // 十进制数字 -> 点分十进制字符串
{
    long long l = n, ip[4];
    string result = "";

    for (int i = 3; i >= 0; i--)
    {
        ip[i] = l % 256;
        l /= 256;
    }
    for (int i = 0; i < 4; i++)
    {
        if (i != 0) { result += "."; }
        result += to_string(ip[i]);
    }
    return result;
}

int longest_match(long long a, long long b)     // 求二进制共同前缀长度
{
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        if (a % 2 == b % 2) { result++; }
        else { result = 0; }
        a /= 2; b /= 2;
    }
    return result;
}


class Device        // 设备基类
{
protected:
    string name = "";
    device_type type;
    long long ip_address = 0;           // IP地址
    long long cov_num = 0;              // 子网掩码
    long long net_address;              // 所在网络
public:
    void set_IP_Address(long long ip) { ip_address = ip; }
    void set_Covnum(long long covnum) { cov_num = covnum; }
    void set_Net_Address(long long net) { net_address = net; }
    long long get_IPadd() { return ip_address; }
    long long get_Covnum() { return cov_num; }
    long long get_Netadd() { return net_address; }
    device_type get_type() { return type; }
    string get_name() { return name; }
};

class Router :public Device             // 路由器类
{
private:
    int table_len;                      // 路由表长度
    route_info route_table[20];         // 路由表信息
    Device* GE[5];                      // 路由器接口
public:
    Router(string str)
    {
        string ip, cov, netadd;
        name = str; type = device_type::router;
        table_len = 1;
        for (int i = 0; i < 5; i++) { GE[i] = nullptr; }
        ip_address = net_address = cov_num = 0;
    }

    void Display_Route_Table()          // 显示路由表信息
    {
        cout << "路由器" << name << "的路由表信息：" << endl;
        for (int i = 0; i < table_len; i++)
        {
            cout << setfill(' ') << setw(3) << i + 1 << " ";
            cout << "目的网络：";
            cout << setfill(' ') << setw(16) << num_to_ip(route_table[i].net_num) << " ";
            cout << "子网掩码：";
            cout << setfill(' ') << setw(16) << num_to_ip(route_table[i].cover_num) << " ";

            cout << "下一跳：";
            if (route_table[i].next_hop == -1) 
            { 
                if (route_table[i].route_interface == -1) { cout << setw(17) << setfill(' ') << "(默认) "; }
                else { cout << setw(17) << setfill(' ') << "无 "; }
            }
            else { cout << setw(16) << setfill(' ') << num_to_ip(route_table[i].next_hop) << " "; }

            cout << setw(8) << setfill(' ') << "接口：";
            if (route_table[i].route_interface == -1) { cout << setw(6) << setfill(' ') << "(默认)"; }
            else { cout << setfill(' ') << setw(6) << route_table[i].route_interface; }

            cout << setw(12) << setfill(' ') << "配置类型：";
            if (route_table[i].set_type == setting_type::norm) { cout << setw(13) << setfill(' ') << "普通路由 "; }
            else if (route_table[i].set_type == setting_type::stat) { cout << setw(13) << setfill(' ') << "特定主机路由 "; } 
            else { cout << setw(13) << setfill(' ') << "默认路由 "; }
            cout << endl;
        }
        cout << endl;
    }

    void Route_Aggregation()    // 路由聚合算法，聚合路由器连接的两个以太网络地址，作为路由器自身的网络地址
    {
        if (GE[0] == nullptr && GE[1] == nullptr) { return; }
        if (GE[0] != nullptr && GE[1] == nullptr) { set_Net_Address(GE[0]->get_Netadd()); }
        if (GE[0] == nullptr && GE[1] != nullptr) { set_Net_Address(GE[1]->get_Netadd()); }
        if (GE[0] != nullptr && GE[1] != nullptr)
        {
            // 求出两个子路由的IP地址共用前缀长度
            int prefix_match = longest_match(GE[0]->get_Netadd(), GE[1]->get_Netadd());
            long long covnum = 0;
            for (int i = 1; i <= 32; i++)
            {
                covnum *= 2;
                if (i <= prefix_match) { covnum++; }
            }
            set_Covnum(covnum);                                     // 应用最长前缀的相应子网掩码     
            set_Net_Address((GE[0]->get_Netadd() & covnum));        // 应用对应的网络地址
        }
        cout << "路由器" << get_name() << "进行网络聚合，聚合后的网络地址：" << num_to_ip(get_Netadd());
        cout << "，子网掩码：" << num_to_ip(get_Covnum()) << endl;
    }

    void Direct_Connect(long long net, long long cov, int interf_num, Device& d)       // 设置直连网络
    {
        int num = -1;
        bool recorded = false;
        for (int i = 0; i < table_len; i++)     // 查找该网络地址是否已记录
        {
            if (net == route_table[i].net_num && cov == route_table[i].cover_num)
            {
                num = i;
                recorded = true;
                break;
            }
        }
        if (!recorded)      // 若没有记录网络地址，则重新记录
        {
            int x = table_len - 1;
            route_table[x].net_num = net;
            route_table[x].cover_num = cov;
            route_table[x].route_interface = interf_num;
            route_table[x].set_type = setting_type::norm;
            table_len++;
            GE[interf_num] = &d;
        }
        else                // 若有记录，更新连接端口信息
        {
            route_table[num].route_interface = interf_num;
        }
    }

    void Static_Connect(string ip, int interf_num, Device& d)        // 设置特定主机路由
    {
        int i = table_len - 1;
        string cov = "255.255.255.255";             // 子网掩码：固定为 "255.255.255.255"
        route_table[i].net_num = ip_to_num(ip);
        route_table[i].cover_num = ip_to_num(cov);
        route_table[i].next_hop = d.get_IPadd();
        route_table[i].route_interface = interf_num;
        route_table[i].set_type = setting_type::stat;
        GE[interf_num] = &d;
        table_len++;
    }

    Device* Search_Route(long long des_ip)      // 根据路由表，寻找下一个地址
    {
        bool find_route = false;                        // 找到转发路由
        int best_match = 0;                             // 最长匹配字符串长度
        Device* target = nullptr;                       // 下一跳指针

        for (int i = 0; i < table_len; i++)             // 遍历路由表，确定下一跳
        {
            long long address = (des_ip & route_table[i].cover_num);
            // cout << "相与结果：" << num_to_ip(address) << endl;

            if (address == route_table[i].net_num)      // 结果与目标网络地址相同，寻找最长共同前缀的一项
            { 
                find_route = true;
                int match = longest_match(address, des_ip);         // ip数字共同前缀
                if (match > best_match)
                {
                    best_match = match;
                    if (route_table[i].route_interface != -1)       // 若前缀更长，更新下一跳
                    {
                        target = GE[route_table[i].route_interface];
                    }
                    else target = nullptr;
                }
            }
        }

        cout << get_name() << ":";
        if (target == nullptr)
        { 
            if (find_route) 
            {
                cout << "IP数据报已转发到默认IP地址" << endl;
                return nullptr;
            }
            else { cout << "数据报转发出错！" << endl; }
            exit(0);
        }
        else
        { 
            cout << "将IP数据包转发给" << target->get_name() << endl;
            return target; 
        }             
    }

    void Reset_Route_Table()        // 清除并重置路由器信息（默认路由不删除）
    {
        for (int i = table_len - 2; i >= 0; i--)
        {
            route_table[i].net_num = 0;
            route_table[i].cover_num = 0;
            route_table[i].next_hop = -1;
            route_table[i].route_interface = -1;
            table_len--;
        }
    }
};

class PC : public Device        // 用户PC类
{
private:
    Router* Ethernet;           // 路由器接口
    Switch* net;
public:
    PC(string str)
    {
        string ip, cov, netadd;
        name = str; type = device_type::sw;
        Ethernet = nullptr;
        ip_address = net_address = cov_num = 0;
    }

    void set_Switch(Switch& sw) { net = &sw; }              // 设置连接的以太网交换机

    void Display_Info()                                     // 显示用户PC的IP信息
    {
        cout << "用户主机" << name << "的IP信息：" << endl;
        cout << "  IP地址：";
        cout << setfill(' ') << setw(16) << num_to_ip(ip_address) << endl;
        cout << "网络地址：";
        cout << setfill(' ') << setw(16) << num_to_ip(net_address) << endl;
        cout << "子网掩码：";
        cout << setfill(' ') << setw(16) << num_to_ip(cov_num) << endl;
        cout << endl << endl;
    }
    Switch* get_Switch() { return net; }                    // 查找连接到的以太网交换机
    Router* to_Ethernet() { return Ethernet; }              // 查找直接连接的路由器
};


class Switch : public Device         // 以太网交换机
{
private:
    int counter;
    PC* Ethernet[10];
    Router* GE[2];
public:
    Switch(string str)
    {
        string ip, cov, netadd;
        counter = 3; name = str; type = device_type::sw;
        for (int i = 0; i < 10; i++) { Ethernet[i] = nullptr; }
        Ethernet[0] = Ethernet[1] = nullptr;

        cout << "请输入交换机" << str << "信息：" << endl;
        cout << "网络地址："; cin >> netadd;
        cout << "子网掩码："; cin >> cov;
        cout << endl;

        net_address = ip_to_num(netadd);
        cov_num = ip_to_num(cov);
    }
    void Add_PC(PC& pc, int port_num)
    {
        Ethernet[port_num] = &pc;
        pc.set_Switch(*this);
        pc.set_IP_Address(net_address + counter);
        pc.set_Net_Address(net_address);
        pc.set_Covnum(cov_num);
        cout << "用户主机" << pc.get_name() << "与以太网交换机" << get_name() << "已建立连接" << endl;
        counter++;
    }
    void Connect_Router(Router& r, int interf_num)
    {
        GE[interf_num] = &r;
        r.set_IP_Address(net_address + 1);
    }
    Router* get_Router(int port = 0) { return GE[port]; }
    PC* IP_find_PC(long long ip)
    {
        for (int i = 0; i < 10; i++)
        {
            if (Ethernet[i] == nullptr) { continue; }
            if (Ethernet[i]->get_IPadd() == ip) { return Ethernet[i]; }
        }
        return nullptr;
    }
};

void Connect(Switch& sw, Router& r, int sw_interfnum, int r_interfnum)     // 连接交换机和路由器
{
    sw.Connect_Router(r, sw_interfnum);
    r.set_Net_Address(sw.get_Netadd());
    r.set_IP_Address(sw.get_Netadd() + sw_interfnum + 1);
    r.set_Covnum(sw.get_Covnum());
    r.Direct_Connect(sw.get_Netadd(), sw.get_Covnum(), r_interfnum, sw);

    cout << "交换机" << sw.get_name() << "与路由器" << r.get_name() << "已建立连接" << endl;
    r.Route_Aggregation(); cout << endl;
}

void Connect(Router& a, Router& b, int a_interfnum, int b_interfnum)    // 连接两个路由器
{
    a.Direct_Connect(b.get_Netadd(), b.get_Covnum(), a_interfnum, b);
    b.Direct_Connect(a.get_Netadd(), a.get_Covnum(), b_interfnum, a);
}

void Send_Message(PC& p, string des_ip)     // 用户PC发送IP数据报
{
    cout << "用户机" << p.get_name() << "发送IP数据报到" << des_ip << "：" << endl;

    // 目的地址与本网络子网掩码相与，如果等于本网络地址
    // 则在本网络内通信，不发送到路由器
    if ((ip_to_num(des_ip) & p.get_Covnum()) == p.get_Netadd())         
    {
        cout << p.get_name() << "：";
        cout << "目的地在本网络内，直接交付到" << des_ip << endl;

        Switch* sw = p.get_Switch();
        PC* des_pc = sw->IP_find_PC(ip_to_num(des_ip));
        cout << sw->get_name() << "：";
        cout << "接收到IP数据报，转发到IP地址为";
        cout << des_ip << "的用户PC机" << endl;
        if (des_pc != nullptr)
        {
            cout << des_pc->get_name() << "：IP数据报已收到,转发完成" << endl;
        }
        else
        {
            cout << sw->get_name() << "：";
            cout << "交换机无法找到IP地址为" << des_ip << "的用户PC,丢弃本数据报" << endl;
        }
    }

    // 否则，发送到其它网络，转发给路由器
    else        
    {
        Router* r = p.get_Switch()->get_Router();
        Device* next = static_cast<Device*>(r);                 // 下一个转发设备

        cout << p.get_name() << ":";
        cout << "IP数据报转发给路由器" << r->get_name() << endl;

        while (1)       // 在到达交换机或PC前，不断把IP数据包转发给下一个路由器
        {
            next = r->Search_Route(ip_to_num(des_ip));
            if (next != nullptr && next->get_type() == device_type::router)
            { 
                r = static_cast<Router*>(next); 
            }
            else { break; }
        }
        if (next != nullptr)
        {
            cout << next->get_name() << "：";
            cout << "接收到IP数据报，转发到IP地址为";
            cout << des_ip << "的用户PC机" << endl;

            if (next->get_type() == device_type::sw)
            {
                Switch* sw = static_cast<Switch*>(next);
                PC* des_pc = sw->IP_find_PC(ip_to_num(des_ip));
                if (des_pc != nullptr)
                {
                    cout << des_pc->get_name() << "：IP数据报已收到,转发完成" << endl;
                }
                else
                {
                    cout << sw->get_name() << ":";
                    cout << "交换机无法找到IP地址为" << des_ip << "的用户PC,丢弃分组" << endl;
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    PC pc1("Host-1"), pc2("Host-2"), pc3("Host-3"), pc4("Host-4"), 
        pc5("Host-5"), pc6("Host-6"), pc7("Host-7"), pc8("Host-8");
    Switch sw1("SW-1"), sw2("SW-2"), sw3("SW-3"), sw4("SW-4");
    Router r1("R-1"), r2("R-2");

    sw1.Add_PC(pc1, 0); sw1.Add_PC(pc2, 1);         // 用户主机连接到以太网交换机
    sw2.Add_PC(pc3, 0); sw2.Add_PC(pc4, 1);         // 交换机自动为用户主机分配IP地址
    sw3.Add_PC(pc5, 0); sw3.Add_PC(pc6, 1);
    sw4.Add_PC(pc7, 0); sw4.Add_PC(pc8, 1);
    cout << endl;

    pc1.Display_Info();
    pc2.Display_Info();
    pc3.Display_Info();
    pc4.Display_Info();
    pc1.Display_Info();
    pc2.Display_Info();
    pc3.Display_Info();
    pc4.Display_Info();

    Connect(sw1, r1, 0, 0);         // 路由器与交换机连接，路由器同时聚合两台交换机的路由
    Connect(sw2, r1, 0, 1);
    Connect(sw3, r2, 0, 0);
    Connect(sw4, r2, 0, 1);
    Connect(r1, r2, 2, 2);

/*
样例输入（交换机SW-1到SW-4的网络地址、子网掩码配置）：
128.30.33.0
255.255.255.128
128.30.33.128
255.255.255.128
128.30.35.0
255.255.255.128
128.30.35.128
255.255.255.128

    网络结构（R：路由器，SW：以太网交换机，Host：用户主机）：

                            R-1←———————————————————————————→R-2
                          ↗   ↖                            ↗   ↖
                        ↙       ↘                        ↙       ↘
                     SW-1         SW-2                SW-3      SW-4
                   ↗  ↖        ↗   ↖                ↗  ↖        ↗   ↖
                 ↙      ↘    ↙       ↘            ↙      ↘    ↙       ↘
             Host-1   Host-2  Host-3    Host-4    Host-5   Host-6  Host-7    Host-8
*/

    r1.Display_Route_Table();               // 显示R-1，R-2路由器的路由表
    r2.Display_Route_Table();

    Send_Message(pc1, "128.30.33.4");       // 主机Host-1 向目的地址   "128.30.33.4"（Host-2）发送信息（同一网络内转发）
    Send_Message(pc2, "128.30.33.5");       // 主机Host-2 向目的地址   "128.30.33.5"（不存在）发送信息（网络内目标地址不存在）
    Send_Message(pc1, "128.30.33.131");     // 主机Host-1 向目的地址 "128.30.33.131"（Host-3）发送信息（经过单个路由器转发）
    Send_Message(pc4, "128.30.33.4");       // 主机Host-4 向目的地址   "128.30.33.4"（Host-2）发送信息（经过单个路由器转发）
    Send_Message(pc1, "128.30.35.3");       // 主机Host-1 向目的地址   "128.30.35.3"（Host-5）发送信息（经过两个路由器转发）
    Send_Message(pc6, "128.30.33.132");     // 主机Host-4 向目的地址 "128.30.33.132"（Host-4）发送信息（经过两个路由器转发）

    r2.Reset_Route_Table();                     // 清除并重置路由表项
    Send_Message(pc1, "128.30.35.3");           // 主机Host-4 向目的地址"128.30.35.3"（Host-5）发送信息（发送到默认路由）

    r2.Static_Connect("128.30.35.3", 0, sw3);   // 在路由器R-2设定到Host-5的特定主机路由，下一跳到SW-3
    r2.Display_Route_Table();                   // 查看此时路由器R-2的路由表
    Send_Message(pc1, "128.30.35.3");           // 主机Host-4 向目的地址"128.30.35.3"（Host-5）发送信息（经SW-3到达，不经过默认路由）
}

