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