//#include <iostream>
//void show() {
//	std::cout << "show" << std::endl;
//}


#include <stdio.h>


extern int a;
//static  int a=4; 

void foo() {
	//printf("%x\n", &a);
}
int main() {
	extern int a;
	printf("%x\n", &a);
	 int a = 10;
	{
		//static int a = 10;
		printf("%x\n", &a);
	}
	printf("%x\n", &a);
	foo();
	return 0;
}