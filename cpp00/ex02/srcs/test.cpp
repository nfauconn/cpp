#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"

int main (void)
{
	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size (sizeof(amounts) / sizeof(int));
	accounts_t				accounts (amounts, amounts + amounts_size);
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	Account::displayAccountsInfos();
	std::for_each (acc_begin, acc_end, std::mem_fun_ref (&Account::displayStatus));

	for  (acc_int_t it (acc_begin, dep_begin);
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second)) {

		(*(it.first)).makeDeposit (*(it.second));
	}
}
