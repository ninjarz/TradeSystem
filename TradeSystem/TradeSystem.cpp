#include "TradeSystem.h"

//----------------------------------------------------------------------------------------------------
TradeSystem::TradeSystem()
:
m_userFile(USER_DATA),
m_goodsFile(GOODS_DATA),
m_users(),
m_goods()
{
	if (m_userFile.is_open())
	{
		m_userFile >> m_users;
	}
	if (m_goodsFile.is_open())
	{
		m_goodsFile >> m_goods;
	}
}

TradeSystem::~TradeSystem()
{

}

void TradeSystem::Run()
{

}

//----------------------------------------------------------------------------------------------------
template <class _Input>
_Input& operator>> (_Input& _input, UserType& _type)
{
	char type;
	_input >> type;
	switch (type)
	{
	case 'P':
		_type = UserType::USER_PURCHASER;
		break;

	case 'V':
		_type = UserType::USER_SUPERPURCHASER;
		break;

	case 'S':
		_type = UserType::USER_SELLER;
		break;

	default:
		//ERROR
		break;
	}

	return _input;
}

template <class _Input>
_Input& operator>> (_Input& _input, User*& _user)
{
	if (_user)
	{
		delete _user;
		_user = NULL;
	}

	UserType type;
	_input >> type;
	int identifier;
	_input >> identifier;
	string name;
	_input >> name;
	string password;
	_input >> password;
	float balance;
	_input >> balance;
	switch (type)
	{
	case UserType::USER_PURCHASER:
		if (_input.fail())
		{
			_input.clear(ios::failbit);
			_input.ignore(255, ' ');
			//_input.sync();
			return _input;
		}
		_user = new Purchaser(identifier, name, password, balance);
		break;

	case UserType::USER_SUPERPURCHASER:
	{
										  int level;
										  _input >> level;
										  int token;
										  _input >> token;
										  if (_input.fail())
										  {
											  _input.clear(ios::failbit);
											  _input.ignore(255, ' ');
											  //_input.sync();
											  return _input;
										  }
										  _user = new SuperPurchaser(identifier, name, password, balance, level, token);
	}
		break;

	case UserType::USER_SELLER:
		if (_input.fail())
		{
			_input.clear(ios::failbit);
			_input.ignore(255, ' ');
			//_input.sync();
			return _input;
		}
		_user = new Seller(identifier, name, password, balance);
		break;

	default:
		//ERROR
		break;
	}

	return _input;
}

template <class _Input>
_Input& operator>> (_Input& _input, vector<User*>& _users)
{
	while (_input.eof())
	{
		User *user = NULL;
		_input >> user;
		if (user)
			_users.push_back(user);
		else
			break;
	}
	_input.clear();

	return _input;
}

template <class _Output>
_Output& operator<< (_Output& _output, UserType& _type)
{
	switch (_type)
	{
	case UserType::USER_PURCHASER:
		_output << "P";
		break;

	case UserType::USER_SUPERPURCHASER:
		_output << "V";
		break;

	case UserType::USER_SELLER:
		_output << "S";
		break;

	default:
		//ERROR
		break;
	}

	return _output;
}

template <class _Output>
_Output& operator<< (_Output& _output, User*& _user)
{
	_output << _user->GetType() << " ";
	_output << _user->GetIdentifier() << " ";
	_output << _user->GetUserName() << " ";
	_output << _user->GetPassword() << " ";
	_output << _user->GetBalance() << " ";
	switch (_user->GetType())
	{
	case UserType::USER_PURCHASER:
		_output << "\n";
		break;

	case UserType::USER_SUPERPURCHASER:
		_output << ((SuperPurchaser*)_user)->GetLevel() << " ";
		_output << ((SuperPurchaser*)_user)->GetToken() << "\n";
		break;

	case UserType::USER_SELLER:
		_output << "\n";
		break;

	default:
		//ERROR
		break;
	}

	return _output;
}

template <class _Output>
_Output& operator<< (_Output& _output, vector<User*>& _users)
{
	for (User* user : _users)
	{
		_output << user;
	}

	return _output;
}

template <class _Input>
_Input& operator>> (_Input& _input, GoodsType& _type)
{
	char type;
	_input >> type;
	switch (type)
	{
	case 'F':
		_type = GoodsType::GOODS_FOOD;
		break;

	case 'E':
		_type = GoodsType::GOODS_ELECTRONICS;
		break;

	case 'S':
		_type = GoodsType::GOODS_SUPPLIES;
		break;

	default:
		//ERROR
		break;
	}

	return _input;
}

template <class _Input>
_Input& operator>> (_Input& _input, Goods*& _goods)
{
	if (_goods)
	{
		delete _goods;
		_goods = NULL;
	}

	GoodsType type;
	_input >> type;
	int identifier;
	_input >> identifier;
	string name;
	_input >> name;
	int amount;
	_input >> amount;
	int price;
	_input >> price;
	string owner;
	_input >> owner;
	switch (type)
	{
	case GoodsType::GOODS_FOOD:
	{
								  time_t expiryDate;
								  _input >> expiryDate;
								  time_t productionDate;
								  _input >> productionDate;
								  time_t depreciateDate;
								  _input >> depreciateDate;
								  int depreciateFactor;
								  _input >> depreciateFactor;
								  if (_input.fail())
								  {
									  _input.clear(ios::failbit);
									  _input.ignore(255, ' ');
									  //_input.sync();
									  return _input;
								  }
								  _goods = new Food(identifier, name, amount, price, owner, expiryDate, productionDate, depreciateDate, depreciateFactor);
	}
		break;

	case GoodsType::GOODS_ELECTRONICS:
	{
										 time_t expiryDate;
										 _input >> expiryDate;
										 time_t productionDate;
										 _input >> productionDate;
										 int depreciateFactor;
										 _input >> depreciateFactor;
										  if (_input.fail())
										  {
											  _input.clear(ios::failbit);
											  _input.ignore(255, ' ');
											  //_input.sync();
											  return _input;
										  }
										  _goods = new Electronics(identifier, name, amount, price, owner, expiryDate, productionDate, depreciateFactor);
	}
		break;

	case GoodsType::GOODS_SUPPLIES:
	{
									  time_t expiryDate;
									  _input >> expiryDate;
									  if (_input.fail())
									  {
										  _input.clear(ios::failbit);
										  _input.ignore(255, ' ');
										  //_input.sync();
										  return _input;
									  }
									  _goods = new Supplies(identifier, name, amount, price, owner, expiryDate);
	}
		break;

	default:
		//ERROR
		break;
	}

	return _input;
}

template <class _Input>
_Input& operator>> (_Input& _input, vector<Goods*>& _goods)
{
	while (_input.eof())
	{
		Goods *goods = NULL;
		_input >> goods;
		if (goods)
			_goods.push_back(goods);
		else
			break;
	}
	_input.clear();

	return _input;
}

template <class _Output>
_Output& operator<< (_Output& _output, GoodsType& _type)
{
	switch (_type)
	{
	case GoodsType::GOODS_FOOD:
		_output << "F";
		break;

	case GoodsType::GOODS_ELECTRONICS:
		_output << "E";
		break;

	case GoodsType::GOODS_SUPPLIES:
		_output << "S";
		break;

	default:
		//ERROR
		break;
	}

	return _output;
}

template <class _Output>
_Output& operator<< (_Output& _output, Goods*& _goods)
{
	_output << _goods->GetType() << " ";
	_output << _goods->GetIdentifier() << " ";
	_output << _goods->GetGoodsName() << " ";
	_output << _goods->GetAmount() << " ";
	_output << _goods->GetPrice() << " ";
	_output << _goods->GetOwner() << " ";
	switch (_user->GetType())
	{
	case GoodsType::GOODS_FOOD:
		_output << ((Food*)_goods)->GetExpiryDate() << " ";
		_output << ((Food*)_goods)->GetProductionDate()<< " ";
		_output << ((Food*)_goods)->GetDepreciateDate() << " ";
		_output << ((Food*)_goods)->GetDepreciateFactor() << "\n";
		break;

	case GoodsType::GOODS_ELECTRONICS:
		_output << ((Electronics*)_goods)->GetExpiryDate() << " ";
		_output << ((Electronics*)_goods)->GetProductionDate() << " ";
		_output << ((Electronics*)_goods)->GetDepreciateFactor() << "\n";
		break;

	case GoodsType::GOODS_SUPPLIES:
		_output << ((Supplies*)_goods)->GetExpiryDate() << "\n";
		break;

	default:
		//ERROR
		break;
	}

	return _output;
}

template <class _Output>
_Output& operator<< (_Output& _output, vector<Goods*>& _goods)
{
	for (Goods* goods : _goods)
	{
		_output << goods;
	}

	return _output;
}