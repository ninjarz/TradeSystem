#include "Electronics.h"

//----------------------------------------------------------------------------------------------------
Electronics::Electronics()
:
m_expiryDate(0),
m_productionDate(0),
m_depreciateFactor(0)
{
	m_type = GoodsType::GOODS_ELECTRONICS;
}

Electronics::Electronics(const string& _goodsName, int _amount, int _price, const string& _owner, time_t _expiryDate, time_t _productionDate, int _depreciateFactor)
:
Goods(_goodsName, _amount, _price, _owner),
m_expiryDate(_expiryDate),
m_productionDate(_productionDate),
m_depreciateFactor(_depreciateFactor)
{
	m_type = GoodsType::GOODS_ELECTRONICS;
}

Electronics::Electronics(int _identifier, const string& _goodsName, int _amount, int _price, const string& _owner, time_t _expiryDate, time_t _productionDate, int _depreciateFactor)
:
Goods(_identifier, _goodsName, _amount, _price, _owner),
m_expiryDate(_expiryDate),
m_productionDate(_productionDate),
m_depreciateFactor(_depreciateFactor)
{
	m_type = GoodsType::GOODS_ELECTRONICS;
}

Electronics::Electronics(const Electronics& _electronics)
:
Goods(_electronics)
{

}

Electronics::~Electronics()
{

}

int Electronics::CalculatePrice(int _num)
{
	time_t currTime = time(NULL);
	if (currTime < m_expiryDate)
		return m_price * (float)m_depreciateFactor / 100 * _num;
	else
		return -1;
}

void Electronics::SetExpiryDate(time_t _expiryDate)
{
	m_expiryDate = _expiryDate;
}

void Electronics::SetProductionDate(time_t _productionDate)
{
	m_productionDate = _productionDate;
}

void Electronics::SetDepreciateFactor(int _depreciateFactor)
{
	m_depreciateFactor = _depreciateFactor;
}

time_t& Electronics::GetExpiryDate()
{
	return m_expiryDate;
}

time_t& Electronics::GetProductionDate()
{
	return m_productionDate;
}

int Electronics::GetDepreciateFactor()
{
	return m_depreciateFactor;
}