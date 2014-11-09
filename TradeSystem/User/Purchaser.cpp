#include "Purchaser.h"

//----------------------------------------------------------------------------------------------------
Purchaser::Purchaser()
{

}

Purchaser::Purchaser(const Purchaser& _purchaser)
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
VIP::VIP()
{

}

VIP::VIP(const VIP& _vip)
{

}

VIP::~VIP()
{

}

bool VIP::Register(const string& _userName, const string& _password)
{
	++s_userCounter;

	m_identifier = s_userCounter;
	m_userName = _userName;
	m_password = _password;

	return true;
}

void VIP::PrintUserInfo()
{
	cout << "ID:" << m_identifier;
	cout << " \tName:" << m_userName;
	cout << " \tBalance:" << m_balance;
	cout << " \tVIP Level:" << m_level;
	cout << " \tToken:" << m_token;
	cout << endl;
}

bool VIP::TokenToBalance(int _token)
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

void VIP::SetLevel(int _level)
{
	m_level = _level;
}

void VIP::SetToken(int _token)
{
	m_token = _token;
}

int VIP::GetLevel()
{
	return m_level;
}

int VIP::GetToken()
{
	return m_token;
}