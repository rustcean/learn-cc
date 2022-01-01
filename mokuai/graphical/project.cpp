#include <iostream>
using namespace std;
class Circle
{
	public:
		Circle(){yuanxin=0;ran=0;}
		Circle(int y,int r ):yuanxin(y),ran(r){}
		void Cgetarea();//求面积
		void Cshow();//show
		void Cset(Circle &);//修改参数
	private:
		int yuanxin;//圆心
		int ran;//半径
};
class Rectangle
{
	public:
		Rectangle(){length=0;width=0;}
		Rectangle(int l):length(l){width=0;}
		Rectangle(int l,int w):length(l),width(w){}
		void Rgetarea();
	private:
		int length;
		int width;
};
class Triangle
{
	public:
		Triangle(){a=0;b=0;c=0;
		}
		Triangle(int x,int y,int z){a=x;b=y;c=z;
		}
		
	private:
	int a;//三条边
	int b;
	int c;
};

void Circle::Cgetarea()
{
	double PI=3.14159;
	cout<<"面积为："<<	PI*ran*ran<<endl;	
}

void Circle::Cshow()
{
	double PI=3.14159;
	cout<<"圆心坐标： "<<yuanxin<<endl;
	cout<<"直径为："<<2*ran<<endl;
	cout<<"周长为: "<<PI*2*ran<<endl;
	cout<<"面积为"<<PI*ran*ran<<endl;
	
}

void Circle::Cset(Circle &a)
{
	cout<<"你要修改园的参数吗？"<<endl<<"如果是，请按1，如果不是，请按2：" ;
	int y;
	cin>>y;
	if(y==1) 
	{
		int x;
		cout<<"请输入新的圆心："; 
		cin>>x;
		a.yuanxin=x;
		cout<<"请输入新的半径：";
		cin>>x;
		a.ran=x;
		cout<<"输入完成"<<endl; 
		cout<<"新的圆心和半径是：";\
		cout<<a.yuanxin<<" "<<a.ran<<endl; 
	}
	else if(y==2){cout<<"OK 再见"<<endl;	}
	else {cout<<"出错！"<<endl;	}
}

void Rectangle::Rgetarea()
{
	cout<<"面积为："<<length*width;
}


int main()
{
    Circle c1(2,2);
    c1.Cshow();
    return 0;
}