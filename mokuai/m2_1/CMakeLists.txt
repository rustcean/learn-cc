# 版本
cmake_minimum_required(VERSION 3.0)
# 项目名称 
project(GRAP)
# 设置一一些flag--编译器优化选项分为4个级别，-O0表示没有优化，-O1为缺省值，建议使用-O2，-O3优化级别最高
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -o2 -Wall")
# 包括源文件的目录
include_directories(${CMAKE_SOURCE_DIR}/include)   # 注意是大括号
# 参与编译的文件
add_executable(my_make_exe main.cpp src/Circle.cpp src/Point.cpp)


# 可执行命令--在主目录下
# g++ main.cpp src/Circle.cpp src/Point.cpp -Iinclude -o main 


