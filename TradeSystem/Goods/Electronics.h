#ifndef _ELECTRONICS_H_
#define _ELECTRONICS_H_

#include "Goods.h"

//----------------------------------------------------------------------------------------------------
class Electronics : public Goods
{
public:
	Electronics();
	Electronics(const Electronics& _electronics);
	~Electronics();

private:
	int m_expiryDate;
	int m_productionDate;
	int m_depreciateFactor;
};

#endif