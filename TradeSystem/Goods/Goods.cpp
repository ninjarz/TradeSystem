#include "Goods.h"

//----------------------------------------------------------------------------------------------------
int Goods::s_goodsCounter = 0;

Goods::Goods()
:
m_type(GoodsType::GOODS_DEFAULT),
m_identifier(0),
m_goodsName(),
m_amount(0),
m_price(0),
m_owner()
{

}

Goods::Goods(const string& _goodsName, int _amount, int _price, const string& _owner)
:
m_type(GoodsType::GOODS_DEFAULT),
m_identifier(++s_goodsCounter),
m_goodsName(_goodsName),
m_amount(_amount),
m_price(_price),
m_owner(_owner)
{

}

Goods::Goods(int _identifier, const string& _goodsName, int _amount, int _price, const string& _owner)
:
m_type(GoodsType::GOODS_DEFAULT),
m_identifier(_identifier),
m_goodsName(_goodsName),
m_amount(_amount),
m_price(_price),
m_owner(_owner)
{

}

Goods::Goods(const Goods& _goods)
:
m_type(_goods.m_type),
m_identifier(_goods.m_identifier),
m_goodsName(_goods.m_goodsName),
m_amount(_goods.m_amount),
m_price(_goods.m_price),
m_owner(_goods.m_owner)
{

}

Goods::~Goods()
{

}

int Goods::CalculatePrice(int _num)
{
	return m_price * _num;
}

void Goods::SetType(GoodsType _type)
{
	m_type = _type;
}

void Goods::SetIdentifier(int _identifier)
{
	m_identifier = _identifier;
}

void Goods::SetGoodsName(const string& _name)
{
	m_goodsName = _name;
}

void Goods::SetAmount(int _amount)
{
	m_amount = _amount;
}

void Goods::SetPrice(int _price)
{
	m_price = _price;
}

void Goods::SetOwner(const string& _owner)
{
	m_owner = _owner;
}

GoodsType Goods::GetType()
{
	return m_type;
}

int Goods::GetIdentifier()
{
	return m_identifier;
}

string Goods::GetGoodsName()
{
	return m_goodsName;
}

int Goods::GetAmount()
{
	return m_amount;
}

int Goods::GetPrice()
{
	return m_price;
}

string Goods::GetOwner()
{
	return m_owner;
}