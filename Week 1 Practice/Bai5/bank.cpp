#include "bank.h"


void bank::naptien()
{
	int n;
	cin >> n;
	tien += n;
}
bank::bank()
{
	tien = 10;
}


bank::~bank()
{
}
