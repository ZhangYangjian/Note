#pragma once
#define Note_Thinking_in_CPP
#ifdef Note_Thinking_in_CPP


/*	第十四章 继承和组合
	* 代码重用机制

	@14.5 
		* 普通基类继承中，在派生类的定义中明确第定义操作和返回类型，这称为普通成员函数的重定义（redefining），
			而在基类的成员函数是虚函数的情况，称为重写（overriding）[不改变函数参数列表和返回类型]
		* 任何时候重新定义了基类中的一个重载函数，在派生类之中所有其他的版本则被自动地隐藏了。
		* 继承的最终目标是为了实现多态（polymorphism）。

	@14.6 非自动继承的函数
		* 构造函数、析构函数、operator= 均不可被继承
		* static 成员函数可以被继承到派生类中，但不可是虚函数；重新定义一个静态成员，所有在积累中的其他重载函数会被隐藏。

*/


#endif // Note_Thinking_in_CPP
