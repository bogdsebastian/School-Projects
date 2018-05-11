#pragma once
#include "Offer.h"
#include <vector>
class Repo
{
public:
	// constructors : without parameters; copy constr (have no ideea why , but i did it in case i will need it)
	Repo() = default;
	Repo(std::vector<Offer> offers):offers{ offers } {};
	~Repo() = default;

	// access members with :
	int getSize() { return offers.size(); }
	int getCapacity() { return offers.capacity(); }
	std::vector<Offer> getElements() { return offers; }

	// Everything related to functionality :
	void add(const Offer&);
	// returns first appearance's index in the container , -1 otherwise
	int findOffer(const Offer&) const;

private:
	std::vector<Offer> offers;
	
};

