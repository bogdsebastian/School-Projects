#include "Offer.h"



void Offer::setDestination(std::string newDest) {
	destination = newDest;
}
void Offer::setName(std::string newName) {
	nameOffer = newName;
}
void Offer::setType(std::string newType){
	type = newType;
}
void Offer::setPrice(int newPrice) {
	price = newPrice;
}
bool Offer::operator==(const Offer& off) const {
	return (this->destination == off.destination && this->nameOffer == off.nameOffer && this->price == off.price && this->type==off.type);
}
std::string Offer::toStringOffer() const{
	std::string stringOffer = "Offer's name : ";
	stringOffer.append(nameOffer);
	stringOffer.append("\nDestination : ");
	stringOffer.append(destination);
	stringOffer.append("\nType : ");
	stringOffer.append(type);
	stringOffer.append("\nPrice : ");
	stringOffer.append(std::to_string(price));
	stringOffer.append("\n");
	return stringOffer;
}