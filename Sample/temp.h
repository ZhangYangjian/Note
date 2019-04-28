#pragma once

template<typename T>
class Iterator
{
public:
	Iterator& operator++() {
		m_ptr++;
		return *this;
	}

private:
	T *m_ptr;
};
 
template <typename Company>
class MsgSender {
public:
	void sendClear() {
		Company c;
		c.sendCleartext();
	}

	void sendSecret() {
		Company c;
		c.sendEncrypted();
	}
};

template <>
class MsgSender<CompanyC> {
public:
	void sendClear() {
		CompanyC c;
		c.sendCleartext();
	}
};

template<typename Company>
class LoggingMsgSender :public MsgSender<Company> {
public:
	void sendClearMsg() {
		this->sendClear();
	}
	void sendEncryptedMsg() {
		this->sendSecret();
	}
};

