#pragma once
#define Note_Thinking_in_CPP
#ifdef Note_Thinking_in_CPP

/** 
	* 卷一 
 */

/* 第三章 C++ 中的 C
	@3.4 数据类型介绍
		* 数据类型（data type）定义使用存储空间（内存）的方式。
		* 通过定义数据类型，告诉编译器怎样创建一片特定的存储空间，以及怎样操作这片存储空间。
		* 引用和指针的不同之处在于，带引用的函数调用比带指针的函数调用在语法构成上更清晰。
		* 没有void引用。

	@3.5 作用域
		* C强制在作用域的开始处就定义所有的变量，以便在编译器创建一个块时，能给所有这些变量分配空间。
		* C++ 允许在变量使用前的任意地方定义变量。
		* 全局变量是在所有函数体的外部定义的，程序的所有部分（甚至其他文件中的代码）都可以使用。
		* 如果一个文件中使用extern 关键字来声明另一个文件暗中存在的全局变量，那么这个文件可以使用这个数据。
		* static：
			** 限定作用域：局部static只能在该局部域访问，文件内函数外的static函数和变量只能在本文件内访问。
			** 变量存放伴随整个程序生命周期。
		* 连接
			** 内部连接：意味着只对正在编译的文件按船舰存储空间。每个标识符创建单独的存储空间按，由static指定。
			** 外部连接：意味着为所有被编译过的文件创建一片单独的存储空间，全局变量和函数名有外部连接。（const除外）所有函数之外的变量和函数定义默认为外部连接。
		* 其实在编译一个编译单元(.cpp)生成相应的obj文件过程中编译器会将分析这个编译单元(.cpp)，
			能提供给其他编译单元(.cpp)使用的函数，变量定义记录下来。而将自己缺少的函数，变量的定义也记录下来。
		* const :变量需要初始化。
			** C中，定义const时，编译器为它创建存储空间。不能通过变量名称需改变量值。
			** C++中：
				 *** const常量使用字面值初始化，const常量会被写进符号表，在必要的时候（例如去地址）才会分配内存空间(假若修改了内存空间，再次使用const变量名取值，依然时读取符号表的值)。
				 *** const常量使用变量初始化，和C中的const常量一样，会被分配内存空间，并且不会写道符号表中。
				 *** 被volatile修饰的const常量不会进入符号表。
				 *** const成员函数不能修改成员变量，由于const成员函数默认传递的是用const修饰的this指针。
		* volatile:修饰的变量每次访问都需要从内存中读取。
		
*/



/* 第八章 常量
																			
							C 中 -- 默认为外连接，分配内存空间，可通过地址改变值
						 |
		const ---|														
						 |											-- 编译器常量:使用字面值初始化 存储在符号表中不分配内存空间 -- 取地址操作会分配内存空间（非全局），再次使用const变量名取值，依然时读取符号表的值。
						 |	                   |
							C++	-- 默认内连接 -->|
																	 |		
																	 | 			
																	 |   ---全局变量：只读值不可改变。						                 
																	 |--|
																			|														   -- 使用变量初始化分配内存空间，可通过地址改变值。-- volatile const常量不会进入符号表
																			 ---局部变量可通过地址改变值--|
																			       												|             -- 即使在取地址后分配空间也是存储在全局变量区，不可修改其值。
																			       												 -- static --| 
																			       																	     -- 使用变量初始化分配内存空间，可通过地址改变值。
	@8.1 值替代
		* 通常C++编译器并不为const创建存储空间，把这个定义保存在它的符号表里。
		* extern 意味着使用外部连接，因此必须分配存储空间。
		* 由于编译器不能完全避免为const分配内存，所以const默认是内部连接。
		* C 中const的意思是“一个不能被改变的普通变量”，const常量总是占用存储而且他的名字是全局符。（不能看成编译期常量）
		* C++ 中 extern const int x = 1；这是定义不是声明。
		* 按位const对象中的每个字节都是固定的，所以对象的每个位映像从不改变。
		* 按逻辑const，整个对象从概念上讲是不变的，但是可以以成员为单位改变。（强制转换常量性和用mutable指定成员可改变）
																			       
*/


/* 第十章 名字控制


*/


/*	第十四章 继承和组合
	* 代码重用机制

	@14.5 
		* 普通基类继承中，在派生类的定义中明确第定义操作和返回类型，这称为普通成员函数的重定义（redefining），
			而在基类的成员函数是虚函数的情况，称为重写（overriding）[不改变函数参数列表和返回类型]
		* 任何时候重新定义了基类中的一个重载函数，在派生类之中所有其他的版本则被自动地隐藏了。
		* 继承的最终目标是为了实现多态（polymorphism）。

	@14.6 非自动继承的函数
		* 构造函数、析构函数（用于函数的创建和析构）、operator= （完成类似构造函数的活动）均不可被继承
		* static 成员函数可以被继承到派生类中，但不可是虚函数；重新定义一个静态成员，所有在基类中的其他重载函数会被隐藏。

	@14.7 组合与继承的选择
		* 组合：has-a，继承:is-a

	@14.8 protected 
		* 就这个类的用户而言，它是private的，但它可被这个类的任何子类使用
		* protected 继承=“照此实现”。

	@14.9 运算符的重载与继承
	
	@14.10 多重继承
	
	@14.11 渐进式开发

	@14.12 向上类型转换
		* 将派生类的引用或指针转换为基类的引用或指针称为向上类型转换（upcasting）。
		* 在创建了自己的构造函数时，都要正确地调用基类拷贝构造函数。
		* 向上类型转换发生在函数调用或对引用和指针简单赋值期间。
		* Wind 是 Instrument 的基类：
			Wind w;
			Instrument *ip = &w;
			ip->play();
			编译器只能知道它正在对于一个Instrument指针调用play(),并调用Instrument::play()的基本版本，而不是wind::play().

	@ 小结
*/


#endif // Note_Thinking_in_CPP

/* 第十五章 多态性和虚函数
	* 面向对象三个基本特征：封装（隐藏实现细节，代码模块化）、继承（代码复用）和多态（接口与实现之间的分离，使程序具有扩展性）
	
	@15.4 虚函数
		* 派生类中virtual函数的重定义称为重写（overriding）

	@15.5 如何实现晚捆绑
		* 对每个包含虚函数的类创建一个VTABLE，VTABLE中放置特定类的虚函数的地址
		* 每个带有虚函数的类中，放置一个vpoionter(VPTR),指向这个类的VTABLE。
		* 当通过基类指针做虚函数调用时（多态调用），编译器静态地插入能取得这个VPTR并在VTABLE表中查找函数地址的代码。
		* 没有成员的类对象，被强制占用非零长度，因为每个对象必须有一个相互去别的 地址。
		* 如果在派生类中没有对在基类中声明为virtual的函数进行重新定义，编译器就使用基类的这个虚函数地址
		* 简单的继承时，对于每个对象只有一个VPTR。

	@15.7 抽象基类和纯虚函数
		* 具有纯虚函数的基类为抽象类（abstract）
		* 当继承一个抽象类时，必须实现所有纯虚函数，否则继承出阿来的类也将是一个抽象类。
		* 纯虚函数的声明意味着告诉编译器在VTABLE中为函数保留一个位置，但在这个特定位置中不放地址。
		* 只要有一个函数在类中声明为纯虚函数，则VTABLE就时不完全的。
		* 纯虚函数禁止抽象类的函数以值传递方式调用，这也是防止对象切片（object slicing）的一种方法。
		* 通过抽象类可以保证在向上类型转换期间总是使用指针或引用。
		* 纯虚函数可以定义函数体，派生类可以通过名字调用它。

	@15.8 继承和VTABLE
		* 对象切片实际上是当它拷贝到一个新的对象时，去掉原来对象的一部分，而不是像使用指针或引用那样简单地改变地址的内容。
		* 基类的纯虚函数可以防止创建基类对象，这样就可以防止对象向上类型转换，则可以防止对象切片。

	@15.9 重载和重定义
		* 重新定义一个基类中的重载函数将会隐藏所有该函数的其他基类版本。
		* 编译器不允许改变重新定义过的virtual函数的返回值。
		* 如果返回一个指向基类的指针或引用，则该函数的重定义版本将会从基类返回的内容中返回一个指向派生类的指针或引用。

	@15.10 虚函数和构造函数
		* 只要时最后调用的构造函数，那么在这个对象的生命周期内，VPTR将保持被初始化为指向这个VTABLE。
			但如果接着还有一个更晚派生的构造函数被调用，那么这个构造函数又将设置VPTR指向它的VTABLE，以此类推，直到最后的构造哈数结束。

	@15.11 析构函数和虚拟析构函数
		* 构造函数不能为虚函数，但析构函数常常必须是虚函数。
		* 必须为纯虚析构函数提供一个函数体。
		* 只有一个纯虚析构函数的基类，派生类中不进行析构函数的定义，可以通过编译；
			因为编译器会在没有显式定义析构函数的时候会自动定义析构函数。
		* 准则：任何有虚函数的类中必须定义虚析构函数。
		* 虚析构函数调用虚函数能调用的是本地版本
		* 删除一个void指针并不调用析构函数。

	@15.12 运算符重载
	
	@15.13 向下类型转换
		* dynamic_cast，安全类型向下类型转换的操作。
		* 当使用dynamic_cast时，必须对一个真正多态的层次进行操作--它含有虚函数--这个因为dynamic_cast使用了存储在VTABLE中的信息来判断实际的类型。
		* 在向下类型转换中，与dynamic_cast相比，静态的指向向下类型转换会稍快些。
		* static_cast不允许类型转换到该类层次的外面，而传统的类型转换时允许的。
	
		* 多态在C++中用虚函数实现，意味着“具有不同的形式”。

*/

/* 第十六章 模板介绍
	@16.1 容器
	
	@16.2 模板综述

	@16.3 模板语法
	.....
*/

/*
 * 卷二
 */


 