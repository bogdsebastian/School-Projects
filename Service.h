#pragma once
#include "Repo.h"
#include <vector>
class Service
{
public:
	// Service must not contain copy-constructor, thus we have to prevent the compiler to make it by appending =delete to the copy constructors declaration
	// In order to define a constructor for the Service class , a repository's constructor is needed 
	// since a member of this class has to be instantiated , we must use the initialization list;
	Service(Repo& cont) :container(cont) {};
	// copy constructor gets disabled
	Service(const Service&) = delete;
	void add(std::string name,std::string dest,std::string type,int price);
	int findOffer(std::string name, std::string dest, std::string type, int price);
	int removeOffer(std::string name, std::string dest, std::string type, int price);
	int modifyOffer(std::string name, std::string dest, std::string type, int price, std::string newName, std::string newDest, std::string newType, int newPrice);
	std::vector<Offer> getElemente() const{ return container.getElements(); }
	std::vector<Offer> findOffersByPrice(int price);
	std::vector<Offer> findOffersByDest(std::string nameDest);
private:
	Repo& container;
};

