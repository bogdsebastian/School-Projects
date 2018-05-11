#include "Service.h"


void Service::add(std::string name, std::string dest, std::string type, int price) {
	//TODO: valid(offer) -- later on
	Offer offer(name, dest, type, price);
	if(container.findOffer(offer)==-1)
		container.add(offer);
	else {
		//TODO: throw exception/message , the offer already exists
	}

}
int Service::removeOffer(std::string name, std::string dest, std::string type, int price) {
	//TODO: valid(offer) -- later on
	Offer offer(name, dest, type, price);
	return container.removeOffer(offer);
}

int Service::findOffer(std::string name, std::string dest, std::string type, int price) {
	return container.findOffer(Offer(name, dest, type, price));

}
std::vector<Offer> Service::findOffersByPrice(int price) {
	std::vector<Offer> v;
	for (int i = 0; i < container.getSize(); i++)
	{
		if (container.getElements().operator[](i).getPrice() == price)
			v.push_back(Offer(container.getElements().operator[](i)));
	}
	return v;
}
std::vector<Offer> Service::findOffersByDest(std::string nameDest) {
	std::vector<Offer> v;
	for (int i = 0; i < container.getSize(); i++)
	{
		if (container.getElements().operator[](i).getDestination() == nameDest)
			v.push_back(Offer(container.getElements().operator[](i)));
	}
	return v;
}

int Service::modifyOffer(std::string name, std::string dest, std::string type, int price, std::string newName, std::string newDest, std::string newType, int newPrice) {
	//TODO: valid(offerOld/offerNew) -- later on

	Offer offerNew(newName, newDest, newType, newPrice);
	// Modifies the old offer only if the new version of the offer is not in the container
	if (container.findOffer(offerNew) == -1) {
		Offer offerOld(name, dest, type, price);
		return container.modifyOffer(offerOld, offerNew);
	}
	return removeOffer(name, dest, type, price);
	//TODO: handle exceptions : method modifyOffer from within the repository returns -1 if the element is not there
	//		this method removes the element from the container
}
