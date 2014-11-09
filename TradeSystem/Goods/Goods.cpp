#include "Goods.h"

//----------------------------------------------------------------------------------------------------
int Goods::m_goodsCounter = 0;

Goods::Goods()
{
}

Goods::Goods(const Goods& _goods)
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

//----------------------------------------------------------------------------------------------------
Food::Food()
{

}

Food::Food(const Food& _food)
{

}

Food::~Food()
{

}

//----------------------------------------------------------------------------------------------------
Electronics::Electronics()
{

}

Electronics::Electronics(const Electronics& _electronics)
{

}

Electronics::~Electronics()
{

}

//----------------------------------------------------------------------------------------------------
Supplies::Supplies()
{

}

Supplies::Supplies(const Supplies& _supplies)
{

}

Supplies::~Supplies()
{

}