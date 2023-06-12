#include<cmath>
#include<iostream>
using namespace std;
const double PI=3.14;
class Geometric_shape{
public:
    virtual double perimeter()=0;
    virtual double area()=0;
    virtual double volume()=0;
    virtual void Show(){};
};
class Circle:public Geometric_shape{
double radius;
public:
    Circle(){radius=0;}
    Circle(double vv){radius=vv;}
    double perimeter(){return 2.0*PI*radius;}
    double area(){return PI*radius*radius;}
    double volume(){return 0;}
    void Show(){
        cout<<"圆的半径="<<radius<<'\t';
    cout<<"圆的周长="<<perimeter()<<'\t';
    cout<<"圆的面积="<<area()<<endl;}
    };
    class  Rectangle:public Geometric_shape{
    double width,length;
    public:
        Rectangle(){width=0;length=0;}
        Rectangle(double wid,double len){
        width=wid;
        length-len;
        }
        Rectangle(Rectangle &rr){
        width=rr.width;
        length=rr.length;
        }
        double perimeter(){return 2.0*(width+length);}
        double area(){return width*length;}
        double volume(){return 0;}
        void Show(){
        cout<<"矩形的长和宽分别为："<<length<<'/t'<<width<<'\t';
        cout<<"矩形周长="<<perimeter()<<'\t';
        cout<<"矩形面积="<<area()<<endl;}
        };
        class Triangle:public Geometric_shape{
        double a,b,c;
    public:
        Triangle(){a=0;b=0;c=0;}
        Triangle(double v1,double v2,double v3){a=v1;b=v2;c=v3;}
        double perimeter(){return a+b+c;}
        double area(){
        double s=(a+b+c)/2.0;
        return sqrt(s*(s-a)*(s-b)*(s-c));}
        double volume(){return 0;}
        void Show(){
        cout<<"三角形的三条边为："<<a<<'\t'<<b<<'\t'<<c<<'\t';
        cout<<"三角形周长="<<perimeter()<<'\t';
        cout<<"三角形面积="<<area()<<endl;
        }
        };
        class Box:public Rectangle{
        double height;
    public:
        Box(){height=0;}
        Box(double wid,double len,double heg):Rectangle(wid,len){height=heg;}
        double volume(){return area()*height;}
        void Show(){
        cout<<"长方体的底面是一个矩形"<<endl;
        Rectangle::Show();
        cout<<"长方体的高："<<height<<'\t';
        cout<<"长方体体积："<<volume()<<endl;
        }
        };
        class Cylinder:public Circle{
        double height;
    public:
        Cylinder(){height=0;}
        Cylinder(double vv,double heg):Circle(vv){height=heg;}
        double volume(){return area()*height;}
        void Show(){
        cout<<"圆柱体的底面是一个圆"<<endl;
        Circle::Show();
        cout<<"圆柱体的高："<<height<<'\t';
        cout<<"圆柱体体积："<<volume()<<endl;}
        };
        class Cone:public Circle{
        double height;
    public:
        Cone(){height=0;}
        Cone(double vv,double heg):Circle(vv){height=heg;}
        double volume(){return area()*height/3;}
        void Show(){
        cout<<"圆锥体的底面是一个圆"<<endl;
        Circle::Show();
        cout<<"圆锥体的高："<<height<<'\t';
        cout<<"圆锥体体积："<<volume()<<endl;}
        };

        class Pyramid:public Triangle{
        double height;
    public:
        Pyramid(){height=0;}
        Pyramid(double v1,double v2,double v3,double heg):Triangle(v1,v2,v3){height=heg;}
        double volume(){return area()*height/3;}
        void Show(){
        cout<<"三棱锥的底面是一个三角形"<<endl;
        Triangle::Show();
        cout<<"三棱锥的高："<<height<<'\t';
        cout<<"三棱锥体积："<<volume()<<endl;}
        };

        class prism:public Triangle{
            double height;
            public:
        prism(){height=0;}
        prism(double v1,double v2,double v3,double heg):Triangle(v1,v2,v3){height=heg;}
        double volume(){return area()*height;}
        void Show(){
        cout<<"三棱柱的底面是一个三角形"<<endl;
        Triangle::Show();
        cout<<"三棱柱的高："<<height<<'\t';
        cout<<"三棱柱体积："<<volume()<<endl;}
        };

int main()
{
	Geometric_shape * gs[]={new	Circle(6),new 	Rectangle(4,8),new	Triangle(3,2,3),
     new Box(3,1,2),new	Cylinder(3,3),new Cone(5,2),new Pyramid(3,3,8,3),new prism(3,3,8,3)};
    for (int i=0;i<8;i++)
	{
		gs[i]->Show();
        cout<<endl;
	}
    for (int j=0;j<8;j++)
	{
		gs[j]->Show();
        cout<<endl;
	}
	cout<<"平面图形："<<endl;
    for (int s=0;s<3;s++)
	   {
		   cout<<"图形周长："<<gs[s]->perimeter()<<'\t';
        cout<<"图形面积："<<gs[s]->area()<<'\t';
        cout<<"图形体积："<<gs[s]->volume()<<endl;
    }
	cout<<"立体图形："<<endl;
    for (int t=3;t<8;t++)
	   {
		   cout<<"图形底周长："<<gs[t]->perimeter()<<'\t';
        cout<<"图形底面积："<<gs[t]->area()<<'\t';
        cout<<"图形体积  ："<<gs[t]->volume()<<endl;
    }
	return 0;
}
