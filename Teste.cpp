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
	// test Repo::add() , getSize() , getCapacity() , findOffer() and removeOffer()
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
	repository.add(Offer("true", "true", "true",1));
	assert(repository.removeOffer(Offer("true", "true", "true", 1))>-1);
	assert(repository.getSize() == 5);
	assert(repository.getCapacity() == 6);
	assert(repository.removeOffer(off2)==-1);
	repository.add(off2);
	assert(repository.modifyOffer(off2, Offer("czech", "Czech offer", "tour",20)) ==5 );
	assert(repository.modifyOffer(off2, Offer("czech", "Czech offer", "tour", 21)) == -1);
}

void testService() {
	Repo repository = Repo();
	Offer off1;
	off1.setDestination("berlin");
	off1.setName("berlin offer");
	off1.setType("tour");
	off1.setPrice(15);
	Repo repo2 = Repo();
	repo2.add(off1);
	// The copy contructor of the Service class is disabled ( = delete)
	// Earlier versions had Service serv = Service(repository); , which calls the copy constructor implicitly via the assign symbol
	Service serv(repository);
	serv.add("berlin", "berlin offer", "tour", 15);				

	// The container can have no duplicates, so executing add with the same parameters again , wont add that offer to the container
	serv.add("berlin", "berlin offer", "tour", 15);
	assert(serv.getElemente().size() == 1);
	serv.add("berlin", "berlin offer", "tour", 11);
	serv.add("berlin", "berlin offer1", "tour", 15);
	serv.add("berlin2", "berlin offer", "tour", 15);
	
	// the new version of this offer already exists , so it is going to be removed from the container and returns 1
	assert(serv.modifyOffer("berlin2", "berlin offer", "tour", 15, "berlin", "berlin offer", "tour", 15)==1);
	assert(serv.getElemente().size() == 3);
	
	// the offer to be replaced does not exist , nothing happens , returns -1
	assert(serv.modifyOffer("berlin2", "berlin offer", "tour", 15, "berlin", "berlin offer", "tour", 15) == -1);
	
	// change first added offer to have uppercase initials, returns the index where the old version was found , offer1 was the first element to be added so the index is 0
	assert(serv.modifyOffer("berlin", "berlin offer", "tour", 15, "Berlin", "Berlin offer", "Tour", 15)==0);
}