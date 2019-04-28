#pragma once
#include <string>
#include <iostream>

class Window {
	std::string name;
public:
	virtual	void display() const {
		std::cout << "Window display()" << std::endl;
	}
};

class WindowWithScorll :public Window {
public:
	void display() const {
		std::cout << "WindowWithiScorll display()" << std::endl;
	}
};

void display(const Window& w) {
	w.display();
}

inline int func(int a,int b) {
	int c = a + b;
	c += 10;
	return c;
}

class Empty {
public :
	static int a;
};

int Empty::a = 1;

class IPerson {
public:
	virtual const char* name() const;
};


class CompanyA {
public:
	void sendCleartext() { std::cout << "A sendCleartext" << std::endl; }
	void sendEncrypted() { std::cout << "A sendEncrypted" << std::endl; }
};

class CompanyB {
public:
	void sendCleartext() { std::cout << "B sendCleartext" << std::endl; }
	void sendEncrypted() { std::cout << "B sendEncrypted" << std::endl; }
};

class CompanyC {
public:
	void sendCleartext() { std::cout << "C sendCleartext" << std::endl; }
};