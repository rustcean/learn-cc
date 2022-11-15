#！/bin/bash

# 修改程序的权限的时候注意让usr有执行的权利就好 chmod u+x mak.sh
#列出当前目录信息

# # 输出文字
# echo "更新和清理:"
# # 更新 --将密码提前打出来可以免除界面输入
# echo 'xinxian' | sudo -S apt update #此命令不能分开
# sudo apt upgrade
# sudo apt autoclean
# sudo apt autoremove



# g++ Point.cpp Circle.cpp main.cpp -o main

# g++ *.cpp -o main

# 先删除.o文件
trash *.o
echo "当前目录信息(2秒后进行下一步):"
ls 
sleep 2
echo " "
# 编译为.o文件
echo "初步编译为 \".o\"文件"
g++ -c Point.cpp 
g++ -c Circle.cpp 
g++ -c main.cpp  

echo "当前目录信息(5秒后进行下一步):"
ls 
sleep 5
echo " "
#链接为可执行文件
echo "进行链接并结束:最后文件为 main,可执行: "
g++ Point.o Circle.o main.o -o main
ls -l main

#清除所有的.o文件
trash *.o
