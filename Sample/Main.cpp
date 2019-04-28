#include <iostream>
#include <string>
//#include <functional>
#include <algorithm>
//#include <vector>
#include "Widget.h"
#include "temp.h"

using namespace std;

class Base {
public:
	Base() { log(); }
	virtual void log() { cout << "Base Log" << endl; }
	virtual ~Base(){}
};

class Driver:public Base{
public:
	void log() { cout << "Driver Log" << endl; }
};


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
// //	cout << "ap: " << *ap <<" a:"<<a<< endl;  // ����û��volatile, a ��ֵ���ɻ���5����Ϊһ�㾭���Ż���Ĵ���ֻ����a��ֵһ�Σ�
//	//																					// ����ͨ��ָ���޸� a �����ڴ棬Ҳû�иı����������
//	//																					// volatile ��ʹû���õ�aʱ�Ĵ��������������ڴ����a��ֵ��
//
//
//	// Item 05: Kown what functions C++ silently writes and calls
//		//	class nameObj {
//				// �Զ����ɵ��ĸ�����:
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
//		// ����ȷ������  new Widget һ������shared_ptr���캯��ִ�У���priority()��˳��ȷ��
//		// ����˳��Ϊ�� new Widget��priority()��shared_ptr���캯������priority() �����ڼ䷢���쳣��
//		// �ͻ����Widget��ָ�벻�ܸ���shared_ptr���ڴ�й©��
//	
//	// Designs and Declarations
//	// Item 18: Make interfaces easy to use correctly and hard to use incorrectly
//		// ���ȱ��뿼�ǿͻ���������ʲô���Ĵ���
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
//		// C++ template function ֻ��ȫ�ػ���������ƫ�ػ�
//		// ƫ�ػ�һ��function templateʱ��һ��������Ǽ򵥵�Ϊ�����һ������ģ��
//		// ʹ���߿���ȫ�ػ�std�ڵ�template�����ǲ���������µ�template
//
//	// Implementations
//	// Item 26: Postone variable definitions as long as possible.
//
//	// Item 27: Minimize casting
//	
//	// Item 28: Avoid returning "handles" to object internals.
//
//	// Item 29: Strive for exception-safe code
//		/* ������ŵ���쳣�׳��������ڵ��κ�������Ȼ��������Ч״̬�¡�
//					 û���κζ�������ݽṹ����˶��ܻ������ж��󶼴���һ���ڲ�ǰ��һ�µ�״̬
//					 �����е�classԼ������������������㣩��
//
//		 * ǿ�ұ�֤������쳣�׳�������״̬���ı䡣
//					 ��������ɹ���������ȫ�ɹ����������ʧ�ܣ�����ͻ�ָ�������������֮ǰ����״̬��
//					 ״ֻ̬�����ֿ��ܣ��ﵽ�����ɹ�ִ�к��״̬����ص�����������ǰ��״̬��
//
//		 * ��������nothrow����֤����ŵ���׳��쳣����Ϊ���ܹ��������ԭ�ȳ�ŵ�Ĺ��ܡ�
//					 �����������������ϵ����в������ṩnothrow��֤��
//		*/
//
//	// Item 30: Understand the ins and outs of inlining.
//		//���� inline ������ȡ��ַ��������ͨ������Ϊ�˺�������һ��outlined������
//	
//	// Item 31: Minimize compilation dependencies between files.
//		
//	// Inheritance and Object-Oriented Design
//	// Item 32: Make sure public inheritance models "is-a"
//
//	// Item 33: Avoid hiding inherited names
//
//	// Item 34: Differentiate between inheritance of interface and inheritance of implementation
//			// pure virtual ����ֻ����ָ���ӿڼ̳м�ȱʡʵ�ּ̳С�
//			// impure virtual ��������ָ���ӿڼ̳м�ȱʡʵ�ּ̳С�
//			// non-virtual ��������ָ���ӿڼ̳��Լ�ǿ����ʵ�ּ̳С�
//
//	// Item 35: Consider alternatives to virtual functions.
//			// Non-Virtual Interface �ַ�ʵ�� Template Method ģʽ
//			// Function Pointers ʵ�� Strategy ģʽ
//
//	// Item 36: Nerver redefine an inherited non-virtual function.
//
//
//	// Item 37: Nerver redefine a function's inherited default parameter value.
//		//���̳д���һ������ֵ��virtual������
//		// ���ɣ�virtual �����Ƕ�̬�󶨣�dynamically bound������ȱʡ����ֵ�Ǿ�̬�󶨣�statically bound��
//		// �������νdynamic type����Ŀǰ��ָ��������͡������Ա��ֳ�һ�����󽫻���ʲô��Ϊ��
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
//		// �� template �� class �� typename(��ʾ����һ���Ǹ� class ����)�ȼ�.
//		// typename ��ʶǶ�״����������ƣ���������base class lists �� member initialization list ����Ϊbase class ���η�.
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


#define Note_TCP_IP
#ifdef Note_TCP_IP

#include <WinSock2.h>
#include <vector>
#include <deque>
DWORD WINAPI Func(LPVOID lpParamter) {
	WSADATA wsaData;
	int port = 8009;
	// �����׽���
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		return 1;
	}
	// ��ʼ��IP�Ͷ˿���Ϣ
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
	// ��Ϣ
	char szMsg[1024];
	memset(szMsg, 0, sizeof(szMsg));
	// �ȴ��ͻ�������
	printf("����������ɹ�......�ȴ��ͻ���������...\n");
	while (1)
	{
		// ��������
		if (SOCKET_ERROR != recvfrom(sockClient, szMsg, 10, 0, (SOCKADDR*)&addrClnt, &nLen))
		{
			printf("���ͷ���%s\n", szMsg);
			char szSrvMsg[] = "�յ�...";
			// ��������
			sendto(sockClient, szSrvMsg, sizeof(szSrvMsg), 0, (SOCKADDR*)&addrClnt, nLen);
		}
		cout <<"Last Err:"<< WSAGetLastError() << endl;
	}
	// ����Ϊ����ѭ�������´��벻��ִ��
	// �ر��׽���
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
	WSADATA wsaData;//��ʼ��
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
