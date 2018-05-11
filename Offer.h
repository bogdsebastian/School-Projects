#pragma once
#include <string>
#include <iostream>
class Offer
{
public:
	
	Offer() = default;

	// initialization list is optional , because it is possible to use the base constructor and then assign each member, the proper parameter 
	// this is the constructor with parameters. It allows to instantiate objects of this class using the following syntax : Offer off1(param1,param2,....,paramN);  
	Offer(std::string baseName, std::string baseDestination, std::string baseType, int basePrice) :nameOffer(baseName),destination(baseDestination),type(baseType),price(basePrice){};
	Offer(const Offer& offer) = default;
	~Offer() = default ;
	
	// member acces functions : setters and getters 
	void setPrice(int newPrice);
	void setName(std::string newName);
	void setDestination(std::string newDestination);
	void setType(std::string newType);

	int getPrice() const { return price; }
	std::string getName() const { return nameOffer; }
	std::string getDestination() const { return destination; }
	std::string getType() const { return type; }

	// equals operator , true the members of the 2 Offers are the same
	// marked both the parameter and current instance to be const since neither of them should change
	bool operator ==(const Offer& ) const;
	
	std::string toStringOffer()const;
private:
	std::string nameOffer;
	std::string destination;
	std::string type;
	int price;
};

