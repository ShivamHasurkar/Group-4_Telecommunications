main: main.o country.o area_details.o ContactDetails.o Customer.o
	g++ -o main main.o country.o ContactDetails.o area_details.o Customer.o
	
main.o: main.cpp
	g++ -c main.cpp

area_details.o: area_details.cpp
	g++ -c area_details.cpp

country.o: country.cpp
	g++ -c country.cpp

ContactDetails.o: ContactDetails.cpp
	g++ -c ContactDetails.cpp

Customer.o: Customer.cpp
	g++ -c Customer.cpp

clean:
	rm *.o

	

	

