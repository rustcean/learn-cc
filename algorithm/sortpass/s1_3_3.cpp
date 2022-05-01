//deque 是 double-ended queue 的缩写，又称双端队列容器。是序列容器
/*deque 容器以模板类 deque<T>（T 为存储元素的类型）的形式在 <deque>
 头文件中，并位于 std 命名空间中
*/
#include <iostream>
#include <deque>
#include <array>
using namespace std;
int main()
{
//创建
//1.直接创建空容器,空的 deque 容器在创建之后可以做添加或删除元素的操作
deque <int> d;

//2.创建n个元素的容器,默认每个值都是0
deque <int> arr(10);
/*指定值*/
deque <int> arr1(10,5);

//3.copy--注意:copy时,数据类型需一致
deque <int> d1(5);
deque <int> d2(d1);

//4.copy其他容器中指定区域内的元素
int a[]={1,2,3,4};
deque <int> d3(a,a+5);//两个位置
//适用于所有类型的容器
array <int,5> arr3{1,2,3,4,5};
deque <int> d4(arr3.begin()+2,arr3.end());//copy array容器中的{3,4,5}


//begin和end函数(不止两个,自己探索吧)其实是全局函数,也能用于数组
int arr2[]={1,2,3,4,5,6,7};
cout<<*begin(arr2)<<endl;;
cout<<end(arr2)<<endl;
cout<<(arr2+7)<<endl;
//小实践
d.push_back(1);
d.push_back(2);
d.push_back(3);
d.push_front(0);
printf("%ld",d.size());
for(auto i:d)
{
    printf("%d  ",i);
}
printf("\n");



}



/*参考的函数
begin() 	返回指向容器中第一个元素的迭代器。
end() 	    返回指向容器最后一个元素所在位置后一个位置的迭代器，通常和 begin() 结合使用。
rbegin() 	返回指向最后一个元素的迭代器。
rend() 	    返回指向第一个元素所在位置前一个位置的迭代器。
cbegin() 	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
cend() 	    和  end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crbegin() 	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crend() 	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
size() 	    返回实际元素个数。
max_size() 	返回容器所能容纳元素个数的最大值。这通常是一个很大的值，一般是 232-1，我们很少会用到这个函数。
resize() 	改变实际元素的个数。
empty() 	判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。
shrink _to_fit() 	将内存减少到等于当前元素实际所使用的大小。
at() 	    使用经过边界检查的索引访问元素。
front() 	返回第一个元素的引用。
back() 	    返回最后一个元素的引用。
assign() 	用新元素替换原有内容。
push_back() 	在序列的尾部添加一个元素。
push_front() 	在序列的头部添加一个元素。
pop_back() 	移除容器尾部的元素。
pop_front() 	移除容器头部的元素。
insert() 	在指定的位置插入一个或多个元素。
erase() 	移除一个元素或一段元素。
clear() 	移出所有的元素，容器大小变为 0。
swap() 	    交换两个容器的所有元素。
emplace() 	在指定的位置直接生成一个元素。
emplace_front()  在容器头部生成一个元素。和 push_front() 的区别是，该函数直接在容器头部构造元素，省去了复制移动元素的过程。
emplace_back() 	 在容器尾部生成一个元素。和 push_back() 的区别是，该函数直接在容器尾部构造元素，省去了复制移动元素的过程
*/


