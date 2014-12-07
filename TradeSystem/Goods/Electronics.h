#ifndef _ELECTRONICS_H_
#define _ELECTRONICS_H_

#include "Goods.h"

//----------------------------------------------------------------------------------------------------
class Electronics : public Goods
{
public:
	Electronics();
	Electronics(int _identifier, const string& _goodsName, int _amount, int _price, const string& _owner, time_t _expiryDate, time_t _productionDate, int _depreciateFactor);
	Electronics(const Electronics& _electronics);
	~Electronics();

	int CalculatePrice(int _num);


	void SetExpiryDate(time_t _expiryDate);
	void SetProductionDate(time_t _productionDate);
	void SetDepreciateFactor(int _depreciateFactor);

	time_t& GetExpiryDate();
	time_t& GetProductionDate();
	int GetDepreciateFactor();

private:
	time_t m_expiryDate;
	time_t m_productionDate;
	int m_depreciateFactor;
};

#endif