#pragma once
#ifndef _NOTE_MORE_EFFECTIVE_CPP_H_
#define _NOTE_MORE_EFFECTIVE_CPP_H_
	
/* 基础议题
	Item M1:指针与引用的区别
		* 指针与引用都间接引用其他对象
		* 任何情况下都不能使用指向空值的引用
		* 因为不存在指向空值的引用，再函数参数传递中使用引用的代码效率比指针高
		* 指针可以被重新赋值，而引用一旦初始化就不能改变
		* 推荐使用指针：1.存在不指向任何对象的可能、2.在不同的时刻会指向不同的对象
		* 推荐使用引用：1.指向一个对象后不再改变、2.重载某个操作符时，例如[]

	Item M2: 尽量使用C++风格的类型转换		
		* C++ 类型转换操作符：static_cast,const_cast，dynamic_cast,reinterpret_cast.
		* static_cast 功能上基本与C 风格的类型转换一样强大，含义也一样。
		* const_cast 用于去掉表达式的const或volatile属性。不可用于转换const和volatile所修饰以外的变量。
		* dynamic_cast 用于安全的沿着类的继承关系向下进行类型转换。不能被用与缺乏虚函数的类型上。
		* reinterpret_cast 转换函数指针。

	Item M3：不要对数组使用多态
		* 当通过使用含有子类类型对象的基类类型数组名字（起始地址指针）去操数组的元素，由于步长不一样，会造成不确定的访问错误。

	Item M4：避免无用的缺省构造函数
		* 
*/

/* 运算符

*/


#endif // !_NOTE_MORE_EFFECTIVE_CPP_H_

