#include<iostream>
using namespace std;

#include<cmath>
#include "country.h"
#include "ContactDetails.h"
#include "Customer.h"
#include "area_details.h"

ContactDetails *ContactDetails::instance = 0;
Country *Country::instance = 0;
area_details *area_details::instance = 0;

int countDigit(long long n){
    return floor(log10(n)+ 1);
}

int validate(int num, int length){
    int len = countDigit(num);
    if(len>0 && len<=length){return num;}
    else {return 0;}
}


int validate(int num){
    int len = countDigit(num);
    if(len==7){return num;}
    else {return 0;}
}

int input_countrycode(string str){
    int i=0;
    do{
        cout<<str;
        cin>>i;
        i=validate(i,3);
        if(i==0){cout<<"\nError. Try Again. Enter max 3 digit number. ";}
    }while(i==0);
    return i;
}

int input_areacode(string str){
    int i=0;
    do{
        cout<<str;
        cin>>i;
        i=validate(i,4);
        if(i==0){cout<<"\nError. Try Again. Enter max 4 digit number. ";}
    }while(i==0);
    return i;
}

int input_phonenumber(string str){
    int i=0;
    do{
        cout<<str;
        cin>>i;
        i=validate(i);
        if(i==0){cout<<"\nError. Try Again. Enter 7 digit number. ";}
    }while(i==0);
    return i;
}

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
		cout << "\n\t22. Search Area in a Country";
		cout << "\n\t23. Search Number in a specific Area";
		cout << "\n\t24. Search Specific Customer Details";
		
		cout << "\n___COUNT___";
		cout << "\n\t31. Country cout";
		cout << "\n\t32. All Areas count";
		cout << "\n\t33. Area count in a Country";
		cout << "\n\t34. All PhoneNumbers count";
		cout << "\n\t35. PhoneNumbers count in a Area";
		
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
		
		cout << "\nEnter your Choice: ";
		cin >> choice;
		string res, newCountryName, CountryName, newAreaName, AreaName, CustomerName, CustomerAddress, CustomerPincode;
		int count, newCountryCode, CountryCode, newAreaCode, AreaCode, newPhoneNumber, PhoneNumber;
		
		switch (choice) {
		case 11: 
		    CountryCode = input_countrycode("Enter new Country Code : ");
		    cout<<"Enter new Country Name : ";
		    cin>>CountryName;
			res=(c->setCountry(CountryCode,CountryName))?"Successfully Added!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 12: 
		    CountryCode = input_countrycode("Enter Country Code in which you want to add new Area : ");
		    AreaCode = input_areacode("Enter new Area Code : ");
			cout<<"Enter new Area Name : ";
		    cin>>AreaName;
			res=(a->addCode(CountryCode,AreaCode,AreaName))?"Successfully Added!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 13: 
		    CountryCode = input_countrycode("Enter Country Code in which you want to add new PhoneNumber : ");
		    AreaCode = input_areacode("Enter Area Code in which you want to add new PhoneNumber : ");
			PhoneNumber = input_phonenumber("Enter new PhoneNumber : ");
			res=(cd->addPhoneNumber(CountryCode,AreaCode,PhoneNumber))?"Successfully Added!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 14: 
		    CountryCode = input_countrycode("Enter Country Code in which you want to add new Customer Details : ");
		    AreaCode = input_areacode("Enter Area Code in which you want to add new Customer Details : ");
			PhoneNumber = input_phonenumber("Enter PhoneNumber in which you want to add new Customer Details : ");
			cout<<"Enter new Customer Name : ";
		    cin>>CustomerName;
			cout<<"Enter new Customer Address : ";
		    cin>>CustomerAddress;
			cout<<"Enter new Customer Pincode : ";
		    cin>>CustomerPincode;
			res= (cd->addCustomerDetails(CountryCode,AreaCode,PhoneNumber,CustomerName,CustomerAddress,CustomerPincode))?"Successfully Added!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 21: 
			CountryCode = input_countrycode("Enter Country Code to Search : ");
		   	 res = (c->searchCountry(CountryCode))?"Exists":"Not Exists";
		   	 cout<<res<<endl;
			break;
		case 22: 
			CountryCode = input_countrycode("Enter Country Code in which you want to search Area : ");
			AreaCode = input_areacode("Enter Area Code to Search : ");
		   	 res = (c->search(CountryCode, AreaCode))?"Exists":"Not Exists";
		   	 cout<<res<<endl;
			break;
		case 23: 
		    CountryCode = input_countrycode("Enter Country Code in which you want to search PhoneNumber : ");
		    AreaCode = input_areacode("Enter Area Code in which you want to search PhoneNumber : ");
			PhoneNumber = input_phonenumber("Enter PhoneNumber to search : ");
			res = cd->searchPhoneNumber(CountryCode,AreaCode,PhoneNumber)?"Exists":"Not Exists";
			cout<<res<<endl;
			break;
		case 24: 
		    CountryCode = input_countrycode("Enter Country Code in which you want to search Customer Details : ");
		    AreaCode = input_areacode("Enter Area Code in which you want to search Customer Details : ");
			PhoneNumber = input_phonenumber("Enter PhoneNumber in which you want to search Customer Details : ");
			try{
			    cd->searchCustomerDetails(CountryCode, AreaCode, PhoneNumber)->display();
			}
			catch(exception e){
			    cout<<"Not Exists";
			}
			break;
		case 31: 
			cout<<c->getCountryCount()<<endl;
			break;
		case 32: 
		    cout<<a->Count()<<endl;
		    break;
		case 33: 
			CountryCode = input_countrycode("Enter Country Code in which you want to get count of all Areas : ");
			cout<<a->Count(CountryCode)<<endl;
			break;
		case 34: 
			cout<<cd->countTotalPhoneNumbers()<<endl;
			break;
		case 35:
		    CountryCode = input_countrycode("Enter Country Code in which you want to get count of all PhoneNumbers : ");
		    AreaCode = input_areacode("Enter Area Code in which you want to get count of all PhoneNumbers : ");
		    cout<<cd->countAllPhoneNumbers(CountryCode, AreaCode)<<endl;
		    break;
		case 41: 
		    CountryCode = input_countrycode("Enter Country Code to update : ");
		    newCountryCode = input_countrycode("Enter new Country Code : ");
		    cout<<"Enter new Country Name : ";
		    cin>>newCountryName;
		    res=(c->updateCountry(CountryCode, newCountryCode, newCountryName))?"Successfully Updated!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 42: 
			CountryCode = input_countrycode("Enter Country Code in which you want to update Area Code : ");
		    AreaCode = input_areacode("Enter Area Code to change : ");
		  //  newAreaCode = input_areacode("Enter new Area Code : ");
		  //  cout<<"Enter new Area Name : ";
		  //  cin>>newAreaName;
		    res=(a->update(CountryCode, AreaCode))?"Successfully Updated!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 43: 
			CountryCode = input_countrycode("Enter Country Code in which you want to update PhoneNumber : ");
		    AreaCode = input_areacode("Enter Area Code in which you want to update PhoneNumber : ");
		    PhoneNumber = input_phonenumber("Enter PhoneNumber to update : ");
		    newPhoneNumber = input_phonenumber("Enter new PhoneNumber : ");
		    res=(cd->updatePhoneNumber(CountryCode, AreaCode, PhoneNumber, newPhoneNumber))?"Successfully Updated!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 44: 
			CountryCode = input_countrycode("Enter Country Code in which you want to update Customer Details : ");
		    AreaCode = input_areacode("Enter Area Code in which you want to update Customer Details : ");
		    PhoneNumber = input_phonenumber("Enter PhoneNumber in which you want to update Customer Details : ");
		    cout<<"Enter new Customer Name : ";
		    cin>>CustomerName;
			cout<<"Enter new Customer Address : ";
		    cin>>CustomerAddress;
			cout<<"Enter new Customer Pincode : ";
		    cin>>CustomerPincode;
		    res=(cd->updateCustomerDetails(CountryCode, AreaCode, PhoneNumber, CustomerName, CustomerAddress, CustomerPincode))?"Successfully Updated!":"Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 51: 
			CountryCode = input_countrycode("Enter Country Code you want to delete : ");
			res = (c->deleteCountry(CountryCode))?"Successfully Deleted": "Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 52: 
			CountryCode = input_countrycode("Enter Country Code in which you want to delete Area : ");
			AreaCode = input_areacode("Enter Area Code you want to delete : ");
			res = (a->Delete(CountryCode, AreaCode))?"Successfully Deleted": "Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 53: 
			CountryCode = input_countrycode("Enter Country Code in which you want to delete PhoneNumber : ");
			AreaCode = input_areacode("Enter Area Code in which you want to delete PhoneNumber : ");
			PhoneNumber = input_phonenumber("Enter PhoneNumber you want to delete : ");
			res = (cd->deletePhoneNumber(CountryCode, AreaCode, PhoneNumber))?"Successfully Deleted": "Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		case 54: 
			CountryCode = input_countrycode("Enter Country Code in which you want to Customer Details : ");
			AreaCode = input_areacode("Enter Area Code in which you want to delete Customer Details : ");
			PhoneNumber = input_phonenumber("Enter PhoneNumber in which you want to delete Customer Details : ");
			res = (cd->deleteCustomerDetails(CountryCode, AreaCode, PhoneNumber))?"Successfully Deleted": "Something went wrong. Try again!";
			cout<<res<<endl;
			break;
		default:
			cout << "\nInvalid Choice";
		}
		a->print_all();
		cout << "\nDo you want to perfom any other operation (Y/N): ";
		cin >> ch;
	}
}
