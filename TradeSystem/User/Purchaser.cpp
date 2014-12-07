#include "Purchaser.h"

//----------------------------------------------------------------------------------------------------
Purchaser::Purchaser()
{
	m_type = UserType::USER_PURCHASER;
}

Purchaser::Purchaser(int _identifier, const string& _userName, const string& _password, float _balance)
:
User(_identifier, _userName, _password, _balance)
{
	m_type = UserType::USER_PURCHASER;
}

Purchaser::Purchaser(const Purchaser& _purchaser)
:
User(_purchaser)
{

}

Purchaser::~Purchaser()
{

}

bool Purchaser::Register(const string& _userName, const string& _password)
{
	++s_userCounter;

	m_identifier = s_userCounter;
	m_userName = _userName;
	m_password = _password;

	return true;
}

bool Purchaser::Recharge(int _value)
{
	m_balance += _value;

	return true;
}


//----------------------------------------------------------------------------------------------------
SuperPurchaser::SuperPurchaser()
:
m_level(0),
m_token(0)
{
	m_type = UserType::USER_SUPERPURCHASER;
}

SuperPurchaser::SuperPurchaser(int _identifier, const string& _userName, const string& _password, float _balance, int m_level, int m_token)
:
Purchaser(_identifier, _userName, _password, _balance),
m_level(m_level),
m_token(m_token)
{
	m_type = UserType::USER_SUPERPURCHASER;
}

SuperPurchaser::SuperPurchaser(const SuperPurchaser& _superPurchaser)
:
Purchaser(_superPurchaser),
m_level(_superPurchaser.m_level),
m_token(_superPurchaser.m_token)
{

}

SuperPurchaser::~SuperPurchaser()
{

}

bool SuperPurchaser::Register(const string& _userName, const string& _password)
{
	++s_userCounter;

	m_identifier = s_userCounter;
	m_userName = _userName;
	m_password = _password;

	return true;
}

void SuperPurchaser::PrintUserInfo()
{
	cout << "Id:" << m_identifier;
	cout << " \tName:" << m_userName;
	cout << " \tBalance:" << m_balance;
	cout << " \tVIP Level:" << m_level;
	cout << " \tToken:" << m_token << '\n';
	cout << endl;
}

bool SuperPurchaser::TokenToBalance(int _token)
{
	if (m_token >= _token)
	{
		m_token -= _token;
		m_balance += _token * EXCHANGE_RATE;
	}
	else
		return false;

	return true;
}

void SuperPurchaser::SetLevel(int _level)
{
	m_level = _level;
}

void SuperPurchaser::SetToken(int _token)
{
	m_token = _token;
}

int SuperPurchaser::GetLevel()
{
	return m_level;
}

int SuperPurchaser::GetToken()
{
	return m_token;
}