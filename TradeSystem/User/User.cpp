#include "User.h"

//----------------------------------------------------------------------------------------------------
int User::s_userCounter = 0;

User::User()
:
m_isLogIn(false),
m_type(UserType::USER_DEFAULT),
m_identifier(0),
m_userName(),
m_password(),
m_balance(0)
{

}

User::User(const User& _user)
:
m_isLogIn(_user.m_isLogIn),
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

bool User::LogIn(const User& _user)
{
	*this = _user;    //it need to be tested
	m_isLogIn = true;

	return true;
}

bool User::LogOut()
{
	m_isLogIn = false;

	return true;
}

void User::PrintUserInfo()
{
	//for console
	cout << "ID:" << m_identifier;
	cout << " \tName:" << m_userName;
	cout << " \tBalance:" << m_balance;
}

void User::PrintGoodsList(vector<Goods*>& _goods)
{

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