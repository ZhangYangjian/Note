#include <iostream>
#include <string>
//#include <functional>
#include <algorithm>
//#include <vector>
#include "Widget.h"
#include "temp.h"

using namespace std;

//int main() {
//	
//	//// Item 3: use const whenever possible
//	//const volatile int a = 5;
//	//const volatile int* const cp = &a;
//	//int**  pp;
//	//pp = (int**)&cp;
//	//**pp = 7;
//	//const volatile  int *ap;
//	//ap = &a;
// //	cout << "ap: " << *ap <<" a:"<<a<< endl;  // 假若没有volatile, a 的值依旧会是5。因为一般经过优化后寄存器只读入a的值一次，
//	//																					// 所以通过指针修改 a 所在内存，也没有改变后面的输出。
//	//																					// volatile 会使没会用到a时寄存器都会重新在内存读入a的值。
//
//
//	// Item 05: Kown what functions C++ silently writes and calls
//		//	class nameObj {
//				// 自动生成的四个函数:
//				// default constructor
//				// copy constructor
//				// destructor 
//				// copy assignment operator.
//	//		};
//
//	// Item 06: Explicitly disallow the use of compiler-generated function you do not want.
//		//class HomeForSale {
//		//private:
//		//	HomeForSale(const HomeForSale&);
//		//	HomeForSale& operator=(const HomeForSale&);
//		//	};
//
//	// Item 07: Declare destructors virtual in polymorphic base classes
//
//
//	// Item 10: Have assignment oprators return a reference to *this.
//
//	// Item 11: Handle assignment to self in operator=
//
//	// Item 12: Copy all parts of an object
//
//	//Resource Management
//	//Item 13: Use objects to manage resources.
//
//	// Item 14: Think carefully about copying behavior in resource-managing classes.
//	
//	// Item 15: Provide access to raw resources in resources-managing classes.
//
//	// Item 16: Use the same form in corresponding uses of new and delete
//		// new <---> delete
//		// new[] <---> delete[]
//
//	// Item 17: Store newed objects in smart pointers in standalong statements
//		// proccessWidget(std::shared_ptr<Widget>(new Widget),priority())
//		// 可以确定的是  new Widget 一定先于shared_ptr构造函数执行，但priority()的顺序不确定
//		// 假若顺序为： new Widget、priority()、shared_ptr构造函数，在priority() 调用期间发生异常，
//		// 就会造成Widget的指针不能赋给shared_ptr而内存泄漏。
//	
//	// Designs and Declarations
//	// Item 18: Make interfaces easy to use correctly and hard to use incorrectly
//		// 首先必须考虑客户可能做出什么样的错误。
//
//	// Item 19: Treat class design as type design.
//
//	// Item 20: Prefer pass-by-reference-to-const to pass-by-value
//		//WindowWithScorll ws;
//		//display(ws);
//
//	// Item 21: Don't try to return a reference when you must return an object.
//
//	// Item 22: Declare data members private.
//
//	// Item 23: Prefer non-member non-friend functions to member functions
//
//	// Item 24: Declare nonn-member functions when type conversions should apply to all parameters
//	
//	// Item 25: Consider support for a non-throwing swap.
//		// C++ template function 只能全特化，不可以偏特化
//		// 偏特化一个function template时，一般的做法是简单地为它添加一个重载模板
//		// 使用者可以全特化std内的template，但是不可以添加新的template
//
//	// Implementations
//	// Item 26: Postone variable definitions as long as possible.
//
//	// Item 27: Minimize casting
//	
//	// Item 28: Avoid returning "handles" to object internals.
//
//	// Item 29: Strive for exception-safe code
//		/* 基本承诺：异常抛出，程序内的任何事物仍然保持在有效状态下。
//					 没有任何对象伙数据结构会因此而败坏，所有对象都处于一种内部前后一致的状态
//					 （所有的class约束条件都继续获得满足）。
//
//		 * 强烈保证：如果异常抛出，程序状态不改变。
//					 如果函数成功，就是完全成功，如果函数失败，程序就会恢复到“函数调用之前”的状态。
//					 状态只有两种可能：达到函数成功执行后的状态，或回到函数被调用前的状态。
//
//		 * 不抛掷（nothrow）保证：承诺不抛出异常，因为总能够完成他们原先承诺的功能。
//					 作用于内置类型身上的所有操作都提供nothrow保证。
//		*/
//
//	// Item 30: Understand the ins and outs of inlining.
//		//本体 inline 函数被取地址，编译器通常必须为此函数生成一个outlined函数。
//	
//	// Item 31: Minimize compilation dependencies between files.
//		
//	// Inheritance and Object-Oriented Design
//	// Item 32: Make sure public inheritance models "is-a"
//
//	// Item 33: Avoid hiding inherited names
//
//	// Item 34: Differentiate between inheritance of interface and inheritance of implementation
//			// pure virtual 函数只具体指定接口继承及缺省实现继承。
//			// impure virtual 函数具体指定接口继承几缺省实现继承。
//			// non-virtual 函数具体指定接口继承以及强制性实现继承。
//
//	// Item 35: Consider alternatives to virtual functions.
//			// Non-Virtual Interface 手法实现 Template Method 模式
//			// Function Pointers 实现 Strategy 模式
//
//	// Item 36: Nerver redefine an inherited non-virtual function.
//
//
//	// Item 37: Nerver redefine a function's inherited default parameter value.
//		//（继承带有一个参数值的virtual函数）
//		// 理由：virtual 函数是动态绑定（dynamically bound），而缺省参数值是静态绑定（statically bound）
//		// 对象的所谓dynamic type：“目前所指对象的类型”；可以表现出一个对象将会有什么行为。
//
//	// Item 38: Model "has-a" or "is-implemented-in-terms-of" through composition.
//		
//	// Item 39: Use private inheritance judiciously 
//		// "is-implemented-in-terms-of"
//
//	// Item 40: Use multiple inheritance judiciously
//
//	//Templates and Generic Programming
//	// Item 41: Understand implicit interfaces and compile-time polymorphism
//
//	// Item 42: Understand the two meanings of typename.
//		// 在 template 中 class 和 typename(暗示并非一定是个 class 类型)等价.
//		// typename 标识嵌套从属类型名称；但不得在base class lists 或 member initialization list 内作为base class 修饰符.
//	
//	// Item 43: Know how to access names in templatized base classes.
//		
//	// Item 44: Factor parameter-independent code out of templates.
//
//	// Item 45: Use member function template to accept "all compatible types".
//
//	// Item 46: Define non-member functions inside templates when type conversions are desired.
//	
//	// Item 47: Use traits classes for information about types.
//
//	// Item 48: Be aware of template metaprogramming
//
//
//
//
//
//
//	//cout << sizeof(Empty) <<" a:"<<Empty::a<< endl;
//
//	// Customizing new and delete
//	// Item 49: Understand the behavior of the new-handler.
//
//
//	//Miscellany
//	// Item 53: Pay attention to compiler warnings.
//
//	// Item 54: Familiarize yourself with the standard library,including TR1.
//	//using namespace::std::tr1;
//
//	// Item 55: Familiarize yourself with Boost.
//
//		int a;
//		int b;
//		cout << &a << endl;
//		cout << &b << endl;
//
//	system("pause");
//	return 0;
//}


//#define Note_TCP_IP
#ifdef Note_TCP_IP

#include <WinSock2.h>
#include <vector>
#include <deque>

DWORD WINAPI Func(LPVOID lpParamter) {
	WSADATA wsaData;
	int port = 8009;
	// 加载套接字
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		return 1;
	}
	// 初始化IP和端口信息
	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(port);
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	// socket()
	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);
	if (SOCKET_ERROR == sockClient) {
		return 1;
	}

	// bind()
	if (bind(sockClient, (LPSOCKADDR)&addrSrv, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		return 1;
	}

	SOCKADDR_IN addrClnt;
	int nLen = sizeof(SOCKADDR);
	// 消息
	char szMsg[1024];
	memset(szMsg, 0, sizeof(szMsg));
	// 等待客户请求到来
	cout << "服务端启动成功......等待客户发送数据... " << endl;
	while (1)
	{
		// 接收数据
		if (SOCKET_ERROR != recvfrom(sockClient, szMsg, 10, 0, (SOCKADDR*)&addrClnt, &nLen))
		{
			cout << "发送方：szMsg " << endl;
			char szSrvMsg[] = "收到...";
			// 发送数据
			sendto(sockClient, szSrvMsg, sizeof(szSrvMsg), 0, (SOCKADDR*)&addrClnt, nLen);
		}
		cout << "Last Err:" << WSAGetLastError() << endl;
	}
	// 上面为无线循环，以下代码不会执行
	// 关闭套接字
	closesocket(sockClient);

	WSACleanup();
	return 0L;
}

class Client {
	SOCKET sock;
	HANDLE ptrThread;
public:
	Client(SOCKET sock);
	~Client();
	int revMsg();
	void start();

};

DWORD _stdcall Run(LPVOID lPrama) {

	Client* ptr = (Client*)lPrama;
	ptr->revMsg();
	return 0;
}
Client::Client(SOCKET sock)
{
	this->sock = sock;
}

Client::~Client()
{
	closesocket(sock);
}

int Client::revMsg() {
	char buff[1500] = { 0 };
	int flag = 0;
	while (recv(sock, buff, 1499, 0) > 0)
	{
		cout << "recv data : " << buff << endl;
	}
	return 0;
}

void Client::start() {
	ptrThread = CreateThread(NULL, NULL, Run, (LPVOID)this, 0, NULL);
}
vector<Client*> vClient;


#pragma comment(lib,"ws2_32.lib")
int main()
{
	WSADATA wsaData;//初始化
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8009);

	if(bind(sock, (sockaddr*)(&addr), sizeof(SOCKADDR_IN)) == -1)
	{
		return 1;
	}

	HANDLE pc = CreateThread(NULL, 0, Func, NULL, 0, NULL);
	Sleep(10);
	if (listen(sock, 10) == SOCKET_ERROR) {
		return 1;
	}

	char buff[64] = {"hello"};
	while (true) {
		struct sockaddr_in remoteAddr;
		int len = sizeof(sockaddr_in);
		int socka = accept(sock, (sockaddr*)(&remoteAddr), &len);
		Client* ptrClient = new Client(socka);
		vClient.push_back(ptrClient);
		ptrClient->start();
	}
	WSACleanup();
	return 0;
}




#endif

//#define Note_More_Effective_CPP 
#ifdef Note_More_Effective_CPP

int main() {
	char *pc = 0;
	char& rc = *pc;
	cout << rc << endl;
	return 0;
}

#endif // !Note_More_Effective_CPP

//#define Note_Thinking_in_CPP
#ifdef Note_Thinking_in_CPP
#include<typeinfo>
class GameBoard {
public:
	GameBoard() { cout << "GameBoard()" << endl; }
	GameBoard(const GameBoard&) { cout << "GameBoard(const GameBoard&)" << endl; }
	GameBoard& operator=(const GameBoard&) {
		cout << "GameBoard::operator=()" << endl;
		return *this;
	}
	~GameBoard() { cout << "~GameBoard()" << endl; }
};

class Game {
	GameBoard gb;
public:
	Game() { cout << "Game()" << endl; }
	Game(const Game& g) :gb(g.gb) {
		cout << "Game(const Game&)" << endl;
	}
	Game(int) { cout << "Game(int)" << endl; }
	Game& operator=(const Game& g) {
		gb = g.gb;
		cout << "Game::operator=()" << endl;
		return *this;
	}
	class Other{};
	operator Other()const {
		return Other();
	}
	~Game() { cout << "~Game()" << endl; }
};

class Chess:public Game{};
void f(Game::Other){}
class Checkers :public Game {
public:
	Checkers() { cout << "Checkers()" << endl; }
	Checkers(const Checkers&c) :Game(c) {
		cout << "Checkers(const Checkers& c)" << endl;
	}
	Checkers& operator=(const Checkers& c) {
		Game::operator = (c);
		cout << "Checkers::operator=()" << endl;
		return *this;
	}
};

class Base {
public:
	virtual ~Base()  = 0;
	void f() { cout << "Base::f()" << endl; }
};

Base::~Base() { f(); cout << "Base::~Base()" << endl; }

class Driver:public Base {
public:
	~Driver() { f(); cout << "~Driver()" << endl; }
};

class Shape{
public:virtual ~Shape(){} 
	const int c = 10;
	int a, b;
	void fun(int arg) {
		a = arg;
	}
	void print(){
		cout << "Sharp::a:"<<a << endl;
	}
};
class Circle :public Shape{};
class Square:public Shape{};
class Other {};
 


Circle f() { 
	return  Circle();
}
void g1(Circle& x) { }
void g2(const Circle&){}


 const int ng = 10;


int main() {


	system("pause");
	return 0;
}

#endif // Note_Thinking_in_CPP

#define Note_Inside_The_CPP_Object_Model
#ifdef Note_Inside_The_CPP_Object_Model
#include <iomanip> 
static int foo;
extern int foo;

class Base {
public :
	virtual void func1(){}
	virtual void func2() {}
};

class Dirver :public Base {
public:
	 void func1() {}
	 void func2() {}
};

//class A {
//public :
//	A(const A&) { cout << "A::A(const A&)" << endl; }
//};
//
//class B {
//public :
//	B(const A&){}
//	A a;
//};

uint32_t Hash(const char* arKey, uint32_t keyLength) {
	unsigned int hash = 0;
	for (; keyLength > 0;keyLength -= 1) {
		hash = ((hash << 5) - hash) + *arKey++;
	}
	return hash;
}

// + - * /

int Sum(int a, int b) {
	int xor;
	int and;
	while (b) {
		xor = a ^ b;
		and = a & b;
		a = xor;
		b = and << 1;
	}
	return a;
}

int main() {
	 

	Dirver d1;
	Dirver d2;
	Dirver* pd1 = &d1;
	Dirver* pd2 = &d2;
	Base bs = d1;
	Base *pbs = &bs;
	Base *pbs2 = &d1;
	int* p1 = (int*)(pd1);
	int* p2 = (int*)pd2;

	int* p3= (int*)pbs;
	//cout << "p1: " << *p1 << endl;
	//cout << "p2: " << *p2 << endl;
	//cout << "p3: " << *p3 << endl;

	//cout << sizeof(short&) << endl;

	//B bba;
	//B bba2 = bba;




	cout << Sum(13,5) << endl;
	system("pause");
	return 0;
}
 
#endif // Note_Inside_The_CPP_Object_Model



