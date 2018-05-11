#include "Teste.h"
#include <assert.h>
void testOffer() {
	Offer off1;
	off1.setName("berlin offer");
	off1.setDestination("berlin");
	off1.setType("tour");
	off1.setPrice(15);
	// test setters, getters and copy constructor too
	// TODO: intreaba proful sa iti explice ce se intampla aici la egal , atribuire ? sau e doar o sintaxa alternativa acestui `Offer off(off1)`
	/* -> */ Offer off = Offer(off1);
	assert(off.getDestination() == "berlin");
	assert(off.getName() == "berlin offer");
	assert(off.getType() == "tour");
	assert(off.getPrice() == 15);
	// test equals operator '=='
	assert(off == off1);
	// test constructor with parameters
	Offer offer(off1.getName(),off1.getDestination(),off1.getType(),off1.getPrice());
	assert(offer == off1);
	std::string toString;

	assert(offer.toStringOffer() == "Offer's name : berlin offer\nDestination : berlin\nType : tour\nPrice : 15\n");
}  

void testOffers() {
	// test Repo::add() , getSize() , getCapacity() and findOffer()
	Repo repository = Repo();
	Offer off1;
	off1.setDestination("berlin");
	off1.setName("berlin offer");
	off1.setType("tour");
	off1.setPrice(15);
	repository.add(off1);
	repository.add(off1);
	repository.add(off1);
	repository.add(off1);
	repository.add(off1);
	Offer off2("false","false","false",0);
	assert(repository.getSize() == 5);
	assert(repository.getCapacity() == 6);
	assert(repository.findOffer(off1) == 0);
	assert(repository.findOffer(off2) == -1);

}