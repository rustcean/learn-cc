#include <iostream>
using namespace std;
struct anttarctica_years_end
{
    int year;
};
int main()
{
    anttarctica_years_end s01,s02,s03;
    s01.year=1998;
    anttarctica_years_end *pa=&s02;
    pa->year=1999;
    anttarctica_years_end trio[3];
    trio[0].year=2003;
    std::cout<<trio->year<<std::endl;
    const anttarctica_years_end *arp[3]={&s01,&s02,&s03};//指针数组
    std::cout<<arp[1]->year<<std::endl;
    const anttarctica_years_end **ppa=arp;//指针的指针
    auto ppb=arp;//定义过后可以用系统自动定义
    // or const anttarctica_years_end **ppb=arp;
    std::cout<<(*ppa)->year<<std::endl;
    std::cout<<(*(ppb+1))->year<<std::endl;
    return 0;
}