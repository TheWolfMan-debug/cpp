#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;


//类模板
template<class NameType, class AgeType,class HeightType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name: " << this->mName << " age: " << this->mAge << endl;
    }
public:
    NameType mName;
    AgeType mAge;
};

void test01()
{
    // 指定NameType 为string类型，AgeType 为 int类型
    Person<string, double, int>P1("孙悟空", 18);
    P1.showPerson();
}

int main()
{

    test01();

    system("pause");

    return 0;
}





//#include <iostream>
//#include <iomanip>//不要忘记包含此头文件
//using namespace std;
//int main()
//{
//  int a;
//  cout<<"input a:";
//  cin>>a;
//  cout<<"dec:"<<dec<<a<<endl;  //以十进制形式输出整数
//  cout<<"hex:"<<hex<<a<<endl;  //以十六进制形式输出整数a
//  cout<<"oct:"<<setbase(8)<<a<<endl;  //以八进制形式输出整数a
//  char *pt="China";  //pt指向字符串"China"
//  cout<<setw(10)<<pt<<endl;  //指定域宽为,输出字符串
//  cout<<setfill('*')<<setw(10)<<pt<<endl;  //指定域宽,输出字符串,空白处以'*'填充
//  double pi=22.0/7.0;  //计算pi值
//  //按指数形式输出,8位小数
//  cout<<setiosflags(ios::scientific)<<setprecision(8);
//  cout<<"pi="<<pi<<endl;  //输出pi值
//  cout<<"pi="<<setprecision(4)<<pi<<endl;  //改为位小数
//  cout<<"pi="<<setiosflags(ios::fixed)<<pi<<endl;  //改为小数形式输出
//  return 0;
//}










//#include<iostream>
//using namespace std;
//
//#include <string>
//
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	string m_Name;
//	int m_Age;
//};
//
////普通函数模板
//template<class T>
//bool myCompare(T& a, T& b)
//{
//    cout << "内置的数据类型比较" << endl;
//	if (a == b)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//
////具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
////具体化优先于常规模板
//template<>
//bool myCompare(Person &p1, Person &p2)
//{
//    cout << "自定义的数据类型比较" << endl;
//	if ( p1.m_Name  == p2.m_Name && p1.m_Age == p2.m_Age)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	//内置数据类型可以直接使用通用的函数模板
//	bool ret = myCompare(a, b);
//	if (ret)
//	{
//		cout << "a == b " << endl;
//	}
//	else
//	{
//		cout << "a != b " << endl;
//	}
//}
//
//void test02()
//{
//	Person p1("Tom", 10);
//	Person p2("Tom", 10);
//	//自定义数据类型，不会调用普通的函数模板
//	//可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
//	bool ret = myCompare(p1, p2);
//	if (ret)
//	{
//		cout << "p1 == p2 " << endl;
//	}
//	else
//	{
//		cout << "p1 != p2 " << endl;
//	}
//}
//
//int main() {
//
//	test01();
//
//	test02();
//
//	system("pause");
//
//	return 0;
//}



////普通函数与函数模板调用规则
//void myPrint(int a, int b)
//{
//	cout << "调用的普通函数" << endl;
//}
//
//template<typename T>
//void myPrint(T a, T b)
//{
//	cout << "调用的模板" << endl;
//}
//
//template<typename T>
//void myPrint(T a, T b, T c)
//{
//	cout << "调用重载的模板" << endl;
//}
//
//void test01()
//{
//	//1、如果函数模板和普通函数都可以实现，优先调用普通函数
//	// 注意 如果告诉编译器  普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
//	int a = 10;
//	int b = 20;
//	myPrint(a, b); //调用普通函数
//
//	//2、可以通过空模板参数列表来强制调用函数模板
//	myPrint<>(a, b); //调用函数模板
//
//	//3、函数模板也可以发生重载
//	int c = 30;
//	myPrint(a, b, c); //调用重载的函数模板
//
//	//4、 如果函数模板可以产生更好的匹配,优先调用函数模板
//	char c1 = 'a';
//	char c2 = 'b';
//	myPrint(c1, c2); //调用函数模板
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}



////利用模板提供通用的交换函数
//template<class T>
//void mySwap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//
//// 1、自动类型推导，必须推导出一致的数据类型T,才可以使用
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	char c = 'c';
//
//	mySwap(a, b); // 正确，可以推导出一致的T
//	//mySwap(a, c); // 错误，推导不出一致的T类型
//}
//
//
//// 2、模板必须要确定出T的数据类型，才可以使用
//template<class T>
//void func()
//{
//    cout << sizeof(T) << endl;
//	cout << "func 调用" << endl;
//}
//
//void test02()
//{
//	//func(); //错误，模板不能独立使用，必须确定出T的类型
//	func<long double>(); //利用显示指定类型的方式，给T一个类型，才可以使用该模板
//}
//
//int main() {
//
//	test01();
//	test02();
//
//	system("pause");
//
//	return 0;
//}


//void swapInt(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////交换浮点型函数
//void swapDouble(double& a, double& b) {
//	double temp = a;
//	a = b;
//	b = temp;
//}
//
////利用模板提供通用的交换函数
//template<typename T>
//void mySwap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//void test01()
//{
//	int a = 10;
//	int b = 20;
//
//	//swapInt(a, b);
//
//	//利用模板实现交换
//	//1、自动类型推导
////	mySwap(a, b);
//
//	//2、显示指定类型
//	mySwap<int>(a, b);
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}

//void test01()
//{
//	ifstream ifs;
//	ifs.open("test.txt", ios::in);
//
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return;
//	}
//
//	//第一种方式
//	char buf[1024] = { 0 };
//	while (ifs >> buf)
//	{
//		cout << buf << endl;
//		cout << "----------" << endl;
//	}

//第二种
//	char buf[1024] = { 0 };
//	while (ifs.getline(buf,sizeof(buf)))
//	{
//		cout << buf << endl;
//		cout << "----------" << endl;
//	}

//第三种
//	string buf;
//	while (getline(ifs, buf))
//	{
//		cout << buf << endl;
//		cout << "----------" << endl;
//	}

//	char c;
//	while ((c = ifs.get()) != EOF)
//	{
//		cout << c;
//	}
//
//	ifs.close();
//
//
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}


//void test01()
//{
//	ofstream ofs;
//	ofs.open("test.txt", ios::in);
//
//	ofs << "姓名：王红" << endl;
//	ofs << "性别：女" << endl;
//	ofs << "年龄：20" << endl;
//
//	ofs.close();
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}



////抽象CPU类
//class CPU
//{
//public:
//	//抽象的计算函数
//	virtual void calculate() = 0;
//};
//
////抽象显卡类
//class VideoCard
//{
//public:
//	//抽象的显示函数
//	virtual void display() = 0;
//};
//
////抽象内存条类
//class Memory
//{
//public:
//	//抽象的存储函数
//	virtual void storage() = 0;
//};
//
////电脑类
//class Computer
//{
//public:
//	Computer(CPU * cpu, VideoCard * vc, Memory * mem)
//	{
//		m_cpu = cpu;
//		m_vc = vc;
//		m_mem = mem;
//	}
//
//	//提供工作的函数
//	void work()
//	{
//		//让零件工作起来，调用接口
//		m_cpu->calculate();
//
//		m_vc->display();
//
//		m_mem->storage();
//	}
//
//	//提供析构函数 释放3个电脑零件
//	~Computer()
//	{
//
//		//释放CPU零件
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//			m_cpu = NULL;
//		}
//
//		//释放显卡零件
//		if (m_vc != NULL)
//		{
//			delete m_vc;
//			m_vc = NULL;
//		}
//
//		//释放内存条零件
//		if (m_mem != NULL)
//		{
//			delete m_mem;
//			m_mem = NULL;
//		}
//	}
//
//private:
//
//	CPU * m_cpu; //CPU的零件指针
//	VideoCard * m_vc; //显卡零件指针
//	Memory * m_mem; //内存条零件指针
//};
//
////具体厂商
////Intel厂商
//class IntelCPU :public CPU
//{
//public:
//	virtual void calculate()
//	{
//		cout << "Intel的CPU开始计算了！" << endl;
//	}
//};
//
//class IntelVideoCard :public VideoCard
//{
//public:
//	virtual void display()
//	{
//		cout << "Intel的显卡开始显示了！" << endl;
//	}
//};
//
//class IntelMemory :public Memory
//{
//public:
//	virtual void storage()
//	{
//		cout << "Intel的内存条开始存储了！" << endl;
//	}
//};
//
////Lenovo厂商
//class LenovoCPU :public CPU
//{
//public:
//	virtual void calculate()
//	{
//		cout << "Lenovo的CPU开始计算了！" << endl;
//	}
//};
//
//class LenovoVideoCard :public VideoCard
//{
//public:
//	virtual void display()
//	{
//		cout << "Lenovo的显卡开始显示了！" << endl;
//	}
//};
//
//class LenovoMemory :public Memory
//{
//public:
//	virtual void storage()
//	{
//		cout << "Lenovo的内存条开始存储了！" << endl;
//	}
//};
//
//
//void test01()
//{
//	//第一台电脑零件
//	CPU * intelCpu = new IntelCPU;
//	VideoCard * intelCard = new IntelVideoCard;
//	Memory * intelMem = new IntelMemory;
//
//	cout << "第一台电脑开始工作：" << endl;
//	//创建第一台电脑
//	Computer * computer1 = new Computer(intelCpu, intelCard, intelMem);
//	computer1->work();
//	delete computer1;
//
//	cout << "-----------------------" << endl;
//	cout << "第二台电脑开始工作：" << endl;
//	//第二台电脑组装
//	Computer * computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
//	computer2->work();
//	delete computer2;
//
//	cout << "-----------------------" << endl;
//	cout << "第三台电脑开始工作：" << endl;
//	//第三台电脑组装
//	Computer * computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
//	computer3->work();
//	delete computer3;
//
//}
//
//int main()
//{
//    test01();
//    return 0;
//}

//class Animal {
//public:
//
//	Animal()
//	{
//		cout << "Animal 构造函数调用！" << endl;
//	}
//	virtual void Speak() = 0;
//
//	//析构函数加上virtual关键字，变成虚析构函数
//	virtual ~Animal()
//	{
//		cout << "Animal虚析构函数调用！" << endl;
//	}
//
//
////	virtual ~Animal() = 0;
//};
//
////Animal::~Animal()
////{
////	cout << "Animal 纯虚析构函数调用！" << endl;
////}
//
////和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。
//
//class Cat : public Animal {
//public:
//	Cat(string name)
//	{
//		cout << "Cat构造函数调用！" << endl;
//		m_Name = new string(name);
//	}
//	virtual void Speak()
//	{
//		cout << *m_Name <<  "小猫在说话!" << endl;
//	}
//	~Cat()
//	{
//		cout << "Cat析构函数调用!" << endl;
//		if (this->m_Name != NULL) {
//			delete m_Name;
//			m_Name = NULL;
//		}
//	}
//
//public:
//	string *m_Name;
//};
//
//void test01()
//{
//	Animal *animal = new Cat("Tom");
//	animal->Speak();
//
//	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
//	//怎么解决？给基类增加一个虚析构函数
//	//虚析构函数就是用来解决通过父类指针释放子类对象
//	delete animal;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}


//class AbstractDrinking
//{
//public:
//    //烧水
//    virtual void Boil() = 0;
//    //冲泡
//    virtual void Brew() = 0;
//    //倒入杯中
//    virtual void PourInCup() = 0;
//    //加入辅料
//    virtual void PutSomething() = 0;
//    //规定流程
//    void MakeDrink()
//    {
//        Boil();
//        Brew();
//        PourInCup();
//        PutSomething();
//    }
//};
//
////制作咖啡
//class Coffee : public AbstractDrinking
//{
//public:
//    //烧水
//    virtual void Boil()
//    {
//        cout << "煮农夫山泉!" << endl;
//    }
//    //冲泡
//    virtual void Brew()
//    {
//        cout << "冲泡咖啡!" << endl;
//    }
//    //倒入杯中
//    virtual void PourInCup()
//    {
//        cout << "将咖啡倒入杯中!" << endl;
//    }
//    //加入辅料
//    virtual void PutSomething()
//    {
//        cout << "加入牛奶!" << endl;
//    }
//};
//
////制作茶水
//class Tea : public AbstractDrinking
//{
//public:
//    //烧水
//    virtual void Boil()
//    {
//        cout << "煮自来水!" << endl;
//    }
//    //冲泡
//    virtual void Brew()
//    {
//        cout << "冲泡茶叶!" << endl;
//    }
//    //倒入杯中
//    virtual void PourInCup()
//    {
//        cout << "将茶水倒入杯中!" << endl;
//    }
//    //加入辅料
//    virtual void PutSomething()
//    {
//        cout << "加入枸杞!" << endl;
//    }
//};
//
////制作奶茶
//class Milk: public AbstractDrinking
//{
//public:
//    //烧水
//    virtual void Boil()
//    {
//        cout << "煮自来水!" << endl;
//    }
//    //冲泡
//    virtual void Brew()
//    {
//        cout << "冲泡奶粉!" << endl;
//    }
//    //倒入杯中
//    virtual void PourInCup()
//    {
//        cout << "将奶茶倒入杯中!" << endl;
//    }
//    //加入辅料
//    virtual void PutSomething()
//    {
//        cout << "加入糖!" << endl;
//    }
//};
//
////业务函数
//void DoWork(AbstractDrinking* drink)
//{
//    drink->MakeDrink();
//    delete drink;
//}
//
//void test01()
//{
//    DoWork(new Coffee);
//    cout << "--------------" << endl;
//    DoWork(new Tea);
//    cout << "--------------" << endl;
//    DoWork(new Milk);
//}
//
//
//int main()
//{
//
//    test01();
//
//    system("pause");
//
//    return 0;
//}

//class Base
//{
//public:
//	//纯虚函数
//	//类中只要有一个纯虚函数就称为抽象类
//	//抽象类无法实例化对象
//	//子类必须重写父类中的纯虚函数，否则也属于抽象类
//	virtual void func() = 0;
//};
//
//class Son :public Base
//{
//public:
//	virtual void func()
//	{
//		cout << "func调用" << endl;
//	};
//};
//
//void test01()
//{
//	Base * base = NULL;
////	base = new Base; // 错误，抽象类无法实例化对象
//	base = new Son;
//	base->func();
//	delete base;//记得销毁
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}

////多态实现
////抽象计算器类
////多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
//class AbstractCalculator
//{
//public :
//
//	virtual int getResult()
//	{
//		return 0;
//	}
//
//	int m_Num1;
//	int m_Num2;
//};
//
////加法计算器
//class AddCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//
////减法计算器
//class SubCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
////乘法计算器
//class MulCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//
//
//void test02()
//{
//	//创建加法计算器
//	AbstractCalculator *abc = new AddCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;  //用完了记得销毁
//
//	//创建减法计算器
//	abc = new SubCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//
//	//创建乘法计算器
//	abc = new MulCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//}
//
//int main() {
//
//	//test01();
//
//	test02();
//
//	system("pause");
//
//	return 0;
//}

//class Animal
//{
//public:
//	//Speak函数就是虚函数
//	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
//	virtual void speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
//
//class Dog :public Animal
//{
//public:
//
//	void speak()
//	{
//		cout << "小狗在说话" << endl;
//	}
//
//};
////我们希望传入什么对象，那么就调用什么对象的函数
////如果函数地址在编译阶段就能确定，那么静态联编
////如果函数地址在运行阶段才能确定，就是动态联编
//
//void DoSpeak(Animal & animal)
//{
//	animal.speak();
//}
////
////多态满足条件：
////1、有继承关系
////2、子类重写父类中的虚函数
////多态使用：
////父类指针或引用指向子类对象
//
//void test01()
//{
//	Cat cat;
//	DoSpeak(cat);
//
//
//	Dog dog;
//	DoSpeak(dog);
//
//
//	Animal animal;
//	DoSpeak(animal);
//}
//
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}

//class Animal
//{
//public:
//	int m_Age;
//};
//
////继承前加virtual关键字后，变为虚继承
////此时公共的父类Animal称为虚基类
//class Sheep : virtual public Animal {};
//class Tuo   : virtual public Animal {};
//class SheepTuo : public Sheep, public Tuo {};
//
//void test01()
//{
//	SheepTuo st;
//	st.Sheep::m_Age = 100;
//	st.Tuo::m_Age = 200;
//
//	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
//	cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;
//	cout << "st.m_Age = " << st.m_Age << endl;
//}
//
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}

//class Base1
//{
//public:
//    Base1()
//    {
//        m_A = 100;
//    }
//public:
//    int m_A;
//};
//
//class Base2
//{
//public:
//    Base2()
//    {
//        m_A = 200;  //开始是m_B 不会出问题，但是改为mA就会出现不明确
//    }
//public:
//    int m_A;
//};
//
////语法：class 子类：继承方式 父类1 ，继承方式 父类2
//class Son : public Base2, public Base1
//{
//public:
//    Son()
//    {
//        m_C = 300;
//        m_D = 400;
//    }
//public:
//    int m_C;
//    int m_D;
//};
//
//
////多继承容易产生成员同名的情况
////通过使用类名作用域可以区分调用哪一个基类的成员
//void test01()
//{
//    Son s;
//    cout << "sizeof Son = " << sizeof(s) << endl;
//	cout << s.Base1::m_A << endl;
//	cout << s.Base2::m_A << endl;
//}
//
//int main()
//{
//
//    test01();
//
//    system("pause");
//
//    return 0;
//}

//class Base {
//public:
//	static void func()
//	{
//		cout << "Base - static void func()" << endl;
//	}
//	static void func(int a)
//	{
//		cout << "Base - static void func(int a)" << endl;
//	}
//
//	static int m_A;
//};
//
//int Base::m_A = 100;
//
//class Son : public Base {
//public:
//	static void func()
//	{
//		cout << "Son - static void func()" << endl;
//	}
//	static int m_A;
//};
//
//int Son::m_A = 200;
//
////同名成员属性
//void test01()
//{
//	//通过对象访问
//	cout << "通过对象访问： " << endl;
//	Son s;
//	cout << "Son  下 m_A = " << s.m_A << endl;
//	cout << "Base 下 m_A = " << s.Base::m_A << endl;
//
//	//通过类名访问
//	cout << "通过类名访问： " << endl;
//	cout << "Son  下 m_A = " << Son::m_A << endl;
//	cout << "Base 下 m_A = " << Son::Base::m_A << endl;
//}
//
////同名成员函数
//void test02()
//{
//	//通过对象访问
//	cout << "通过对象访问： " << endl;
//	Son s;
//	s.func();
//	s.Base::func();
//
//	cout << "通过类名访问： " << endl;
//	Son::func();
//	Son::Base::func();
//	//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
//	Son::Base::func(100);
//}
//int main() {
//
//	test01();
//	//test02();
//
//	system("pause");
//
//	return 0;
//}

//class Base
//{
//public:
//    Base()
//    {
//        m_A = 100;
//    }
//
//    void func()
//    {
//        cout << "Base - func()调用" << endl;
//    }
//
//    void func(int a)
//    {
//        cout << "Base - func(int a)调用" << endl;
//    }
//
//public:
//    int m_A;
//};
//
//
//class Son : public Base
//{
//public:
//    Son()
//    {
//        m_A = 200;
//    }
//
//    //当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
//    //如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
//    void func()
//    {
//        cout << "Son - func()调用" << endl;
//    }
//public:
//    int m_A;
//};
//
//void test01()
//{
//    Son s;
//
//    cout << "Son下的m_A = " << s.m_A << endl;
//    cout << "Base下的m_A = " << s.Base::m_A << endl;
//
//    s.func();
//    s.Base::func();
//    s.Base::func(10);
//
//}
//int main()
//{
//
//    test01();
//
//    system("pause");
//    return EXIT_SUCCESS;
//}

//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base构造函数!" << endl;
//	}
//	~Base()
//	{
//		cout << "Base析构函数!" << endl;
//	}
//};
//
//class Son : public Base
//{
//public:
//	Son()
//	{
//		cout << "Son构造函数!" << endl;
//	}
//	~Son()
//	{
//		cout << "Son析构函数!" << endl;
//	}
//
//};
//
//
//void test01()
//{
//	//继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
//	Son s;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}

//class Base
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
//};
//
////公共继承
//class Son :public Base
//{
//public:
//	int m_D;
//};
//
//void test01()
//{
//	cout << "sizeof Son = " << sizeof(Son) << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}

//class MyPrint
//{
//public:
//	void operator()(string text)
//	{
//		cout << text << endl;
//	}
//
//};
//void test01()
//{
//	//重载的（）操作符 也称为仿函数
//	MyPrint myFunc;
//	myFunc("hello world");
//}
//
//
//class MyAdd
//{
//public:
//	int operator()(int v1, int v2)
//	{
//		return v1 + v2;
//	}
//};
//
//void test02()
//{
//	MyAdd add;
//	int ret = add(10, 10);
//	cout << "ret = " << ret << endl;
//
//	//匿名对象调用
//	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
//}
//
//int main() {
//
//	test01();
//	test02();
//
//	system("pause");
//
//	return 0;
//}

//class Person
//{
//public:
//
//	Person(int age)
//	{
//		//将年龄数据开辟到堆区
//		m_Age = new int(age);
//	}
//
//	//重载赋值运算符
//	Person& operator=(Person &p)
//	{
//	    cout << *this->m_Age << endl;
//	    cout << "----------------------" << endl;
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		//编译器提供的代码是浅拷贝
//		//m_Age = p.m_Age;
//
//		//提供深拷贝 解决浅拷贝的问题
//		m_Age = new int(*p.m_Age);
//
//		//返回自身
//		return *this;
//	}
//
//
//	~Person()
//	{
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}
//
//	//年龄的指针
//	int *m_Age;
//
//};
//
//
//void test01()
//{
//	Person p1(18);
//
//	Person p2(20);
//
//	Person p3(30);
//
//	p3 = p2 = p1; //赋值操作
//
//	cout << "p1的年龄为：" << *p1.m_Age << endl;
//
//	cout << "p2的年龄为：" << *p2.m_Age << endl;
//
//	cout << "p3的年龄为：" << *p3.m_Age << endl;
//}
//
//int main() {
//
//	test01();
//
//	//int a = 10;
//	//int b = 20;
//	//int c = 30;
//
//	//c = b = a;
//	//cout << "a = " << a << endl;
//	//cout << "b = " << b << endl;
//	//cout << "c = " << c << endl;
//
//	system("pause");
//
//	return 0;
//}

//class MyInteger
//{
//
//    friend ostream& operator<<(ostream& out, MyInteger myint);
//
//public:
//    MyInteger()
//    {
//        m_Num = 0;
//    }
//    ~MyInteger()
//    {
//    cout << "析构函数" << endl;
//    }
//    //前置++
//    MyInteger& operator++()
//    {
//        //先++
//        m_Num++;
//        //再返回
//        return *this;
//    }
//
//    //后置++
//    MyInteger operator++(int)
//    {
//        //先返回
//        MyInteger temp = (*this); //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
//        this->m_Num++;
//        return temp;
//    }
////    MyInteger& operator++(int)
////    {
////        //先返回
////        MyInteger *temp = new MyInteger(*this); //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
////        this->m_Num++;
////        return *temp;
////    }
//
//private:
//    int m_Num;
//};
//
//
//ostream& operator<<(ostream& out, MyInteger myint)
//{
//    out << myint.m_Num;
//    return out;
//}
//
//
////前置++ 先++ 再返回
//void test01()
//{
//    MyInteger myInt;
//    cout << ++myInt << endl;
//    cout << myInt << endl;
//}
//
////后置++ 先返回 再++
//void test02()
//{
//
//    cout << "----------------" << endl;
//    MyInteger myInt;
//    cout << myInt++ << endl;
//    cout << myInt++ << endl;
//    cout << myInt++ << endl;
//    cout << myInt++ << endl;
//    cout << myInt << endl;
//}
//
//int main()
//{
//
//    //test01();
//    test02();
//
//    system("pause");
//
//    return 0;
//}

//class Person
//{
//	friend ostream& operator<<(ostream& out, Person& p);
//
//public:
//
//    Person(int a, int b)
//    {
//        this->m_A = a;
//        this->m_B = b;
//    }
//
//    //成员函数 实现不了  p << cout 不是我们想要的效果
//    //void operator<<(Person& p){
//    //}
//    ostream& operator<<(ostream& out)
//    {
//        cout << "类内实现" << endl;
//        cout << "a:" << this->m_A << " b:" << this->m_B << endl;
//        return out;
//    }
//
//private:
//    int m_A;
//    int m_B;
//};
//
////全局函数实现左移重载
////ostream对象只能有一个
//ostream& operator<<(ostream& out, Person& p) {
//    cout << "类外实现" << endl;
//	out << "a:" << p.m_A << " b:" << p.m_B << endl;
//	return out;
//}
//
//void test()
//{
//
//    Person p1(10, 20);
//
//    p1.operator<<(cout);
//    operator<<(cout,p1);
////    cout << p1 << " hello world" << endl; //链式编程
//}
//
//int main()
//{
//
//    test();
//
//    system("pause");
//
//    return 0;
//}

//class Person
//{
//public:
//    Person() {};
//    Person(int a, int b)
//    {
//        this->m_A = a;
//        this->m_B = b;
//    }
//    //成员函数实现 + 号运算符重载
//    Person operator+(const Person& p)
//    {
////        this->m_A=p.m_A+this->m_A;
////        this->m_B=p.m_B+this->m_B;
//		Person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//        cout << "调用的类内函数" << endl;
//        return temp;
//    }
//
//
//public:
//    int m_A;
//    int m_B;
//};
//
////全局函数实现 + 号运算符重载
//Person operator+(const Person& p1, const Person& p2)
//{
//    Person temp(0, 0);
//    temp.m_A = p1.m_A + p2.m_A;
//    temp.m_B = p1.m_B + p2.m_B;
//    cout << "调用的全局函数：两个引用" << endl;
//    return temp;
//}
//
////运算符重载 可以发生函数重载
//Person operator+(const Person& p2, int val)
//{
//    Person temp;
//    temp.m_A = p2.m_A + val;
//    temp.m_B = p2.m_B + val;
//    cout << "调用的全局函数：一个引用，一个整形数" << endl;
//    return temp;
//}
//
//void test()
//{
//
//    Person p1(10, 10);
//    Person p2(20, 20);
//
//    //成员函数方式
//
//    Person p3 = p2 + p1 + p2;  //相当于 p2.operaor+(p1)
//    cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;
//
//
//    Person p4 = p3 + 10; //相当于 operator+(p3,10)
//    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
//
//}
//
//int main()
//{
//
//    test();
//
//    system("pause");
//
//    return 0;
//}


//class Building;
//class goodGay
//{
//public:
//
//	goodGay();
//	~goodGay();
//	void visit();
//
//private:
//	Building *building;
//};
//
//
//class Building
//{
//	//告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
//	friend class goodGay;
//
//public:
//	Building();
//	~Building();
//
//public:
//	string m_SittingRoom; //客厅
//private:
//	string m_BedRoom;//卧室
//};
//
//Building::Building()
//{
//	this->m_SittingRoom = "客厅";
//	this->m_BedRoom = "卧室";
//}
//
//Building::~Building()
//{
//    cout << "Building的析构函数" << endl;
//}
//
//goodGay::goodGay()
//{
//	building = new Building;
//}
//
//goodGay::~goodGay()
//{
//    if(building!=NULL)
//    {
//        delete building;
//        building=NULL;
//    }
//    cout << "goodGay的析构函数" << endl;
//}
//
//void goodGay::visit()
//{
//	cout << "好基友正在访问" << building->m_SittingRoom << endl;
//	cout << "好基友正在访问" << building->m_BedRoom << endl;
//}
//
//void test01()
//{
//	goodGay gg;
//	gg.visit();
//
//}
//
//int main(){
//
//	test01();
//
//	system("pause");
//	return 0;
//}
