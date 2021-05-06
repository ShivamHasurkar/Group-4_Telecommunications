#include<iostream>
using namespace std;

#include "country.h"
#include "ContactDetails.h"
#include "Customer.h"
#include "area_details.h"

ContactDetails *ContactDetails::instance = 0;
Country *Country::instance = 0;
area_details *area_details::instance = 0;

int main(){
    Country *c= c->getInstance();
    area_details *a=a->getInstance();
    ContactDetails *cd=cd->getInstance();
    

    char ch = 'y';
	int choice = 0;
	while (ch == 'y' || ch == 'Y') {
		//system("cls");
		cout << "\n\n* * * Telephone Directory Menu * * *"<<endl;
		cout << "\n___NEW___";
		cout << "\n\t11. New Country";
		cout << "\n\t12. New Area";
		cout << "\n\t13. New Number";
		cout << "\n\t14. New Customer Details";

		cout << "\n___SEARCH___";
        cout << "\n\t21. Search Country";
		cout << "\n\t22. Search Areas in a Country";
		cout << "\n\t23. Search Numbers in a specific Area";
		cout << "\n\t24. Search Specific Customer Details with PhoneNumber";

		
		cout << "\n___COUNT___";
		cout << "\n\t31. Country cout";
		cout << "\n\t32. All Areas count";
		cout << "\n\t32. Area count in a Country";
		cout << "\n\t33. All PhoneNumbers count";
		cout << "\n\t34. PhoneNumbers count in a Area";

		
		cout << "\n___UPDATE___";
		cout << "\n\t41. Update Country";
		cout << "\n\t42. Update Area in a Country";
		cout << "\n\t43. Update PhoneNumber in a specific Area";
		cout << "\n\t44. Update Customer Details with PhoneNumber";
		
		cout << "\n___DELETE___";
		cout << "\n\t51. Delete Country";
		cout << "\n\t52. Delete Area in Country";
		cout << "\n\t53. Delete PhoneNumber in Area";
		cout << "\n\t54. Delete Customer Details with PhoneNumber";
		try{
		cout << "\nEnter your Choice: ";
		cin >> choice;
		
		string res, CountryName, AreaName, CustomerName, CustomerAddress, CustomerPincode;
		int CountryCode, AreaCode, PhoneNumber;
		try{
		switch (choice) {
		case 11: 
		    cout<<"Enter new County Code : ";
		    cin>>CountryCode;
		    cout<<"Enter new Country Name : ";
		    cin>>CountryName;
			res=(c->setCountry(CountryCode,CountryName))?"Successfully Added!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 12: 
			res=(a->addCode(52,30,"KoP"))?"Successfully Added!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 13: 
			res=(cd->addPhoneNumber(52,30,10))?"Successfully Added!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 14: 
			res= (cd->addCustomerDetails(52,30,10,"Sahil","Sahil","Sahil"))?"Successfully Added!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 21: 
			
			break;
		case 22: 
			
			break;
		case 23: 
			
			break;
		case 24: 
			
			break;
		case 31: 
			
			break;
		case 32: 
			
			break;
		case 33: 
			//cout<<c->countTotalPhoneNumbers()<<endl;
			break;
		case 34: 
			
			break;
		case 41: 
			
			break;
		case 42: 
			
			break;
		case 43: 
			
			break;
		case 44: 
			
			break;
		case 51: 
			
			break;
		case 52: 
			
			break;
		case 53: 
			
			break;
		case 54: 
			
			break;
		default:
			cout << "\nInvalid Choice";
			}
		cout << "\nDo you want to perfom any other operation (Y/N): ";
		cin >> ch;
		}
		catch(exception ex){
			cout <<"Something went wrong";
		}
		
		}catch(exception ex){}
	}
}
