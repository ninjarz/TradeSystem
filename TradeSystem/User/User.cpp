#include "User.h"

//----------------------------------------------------------------------------------------------------
int User::s_userCounter = 0;

User::User()
:
m_isLogin(false),
m_type(UserType::USER_DEFAULT),
m_identifier(0),
m_userName(),
m_password(),
m_balance(0)
{

}

User::User(int _identifier, const string& _userName, const string& _password, float _balance)
:
m_isLogin(false),
m_type(UserType::USER_DEFAULT),
m_identifier(_identifier),
m_userName(_userName),
m_password(_password),
m_balance(_balance)
{

}

User::User(const User& _user)
:
m_isLogin(_user.m_isLogin),
m_type(_user.m_type),
m_identifier(_user.m_identifier),
m_userName(_user.m_userName),
m_password(_user.m_password),
m_balance(_user.m_balance)
{

}

User::~User()
{

}

bool User::Login()
{
	m_isLogin = true;

	return true;
}

void User::Logout()
{
	m_isLogin = false;
}

void User::PrintUserInfo()
{
	//for console
	cout << "ID:" << m_identifier;
	cout << " \tName:" << m_userName;
	cout << " \tBalance:" << m_balance << '\n';
}

void User::SetType(UserType _type)
{
	m_type = _type;
}

void User::SetIdentifier(int _identifier)
{
	m_identifier = _identifier;
}

void User::SetUserName(const string& _userName)
{
	m_userName = _userName;
}

void User::SetPassword(const string& _password)
{
	m_password = _password;
}

void User::SetBalance(float _balance)
{
	m_balance = _balance;
}

UserType User::GetType()
{
	return m_type;
}

int User::GetIdentifier()
{
	return m_identifier;
}

string User::GetUserName()
{
	return m_userName;
}

string User::GetPassword()
{
	return m_password;
}

float User::GetBalance()
{
	return m_balance;
}