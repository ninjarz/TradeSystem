#include "Supplies.h"

//----------------------------------------------------------------------------------------------------
Supplies::Supplies()
:
m_expiryDate(0)
{
	m_type = GoodsType::GOODS_SUPPLIES;
}

Supplies::Supplies(int _identifier, const string& _goodsName, int _amount, int _price, const string& _owner, time_t _expiryDate)
:
Goods(_identifier, _goodsName, _amount, _price, _owner),
m_expiryDate(_expiryDate)
{
	m_type = GoodsType::GOODS_SUPPLIES;
}

Supplies::Supplies(const Supplies& _supplies)
:
Goods(_supplies),
m_expiryDate(_supplies.m_expiryDate)
{

}

Supplies::~Supplies()
{

}

int Supplies::CalculatePrice(int _num)
{
	time_t currTime = time(NULL);
	if (currTime < m_expiryDate)
		return m_price * _num;
	else
		return -1;
}

void Supplies::SetExpiryDate(time_t _expiryDate)
{
	m_expiryDate = _expiryDate;
}

time_t& Supplies::GetExpiryDate()
{
	return m_expiryDate;
}