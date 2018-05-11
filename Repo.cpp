#include "Repo.h"


void Repo::add(const Offer& off){ 
	offers.push_back(off); 
}

int Repo::findOffer(const Offer& off) const{
	for (int i = 0; i < offers.size(); i++) {
		{
			if (this->offers[i].operator==(off))
				return i;
				
		}
	}
	return -1;
}
int Repo::removeOffer(const Offer& off) {
	int index = findOffer(off);
	if (index > -1)
	{
		offers.erase(offers.begin() + index);
		return 1;
	}
	return -1;
}