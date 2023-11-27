# include <iostream>
using namespace std;
int main(){
	

	//var declaration
	string fname, lname, id, i;
	char gender;
	int yob, age;
	const int MALE_INCOME_TIER_1 = 10000, MALE_INCOME_TIER_2 = 30000, MALE_INCOME_TIER_3 = 100000; //income tier for male
	const int FEMALE_INCOME_TIER_1 = 12000, FEMALE_INCOME_TIER_2 = 35000, FEMALE_INCOME_TIER_3 = 100000;//income tier for female
	const int INCOME_TIER_3 = 50000, INCOME_TIER_4 = 70000, INCOME_TIER_5 = 150000; //income tier for age < 80
	const int AGE_TIER_1 = 55, AGE_TIER_2 = 80;//age groups
	const int YEAR = 2023;
	const int MIN_YEAR = 1920;
	const double RATE = 20.0; // hourly RATE
	const int DOUBLE_TIME_START = 45;
    const double OVERTIME_RATE_FACTOR = 1.5; // time and half overtime RATE
    const double DOUBLE_TIME_RATE_FACTOR = 2.0; // double time overtime RATE
    const int FIVE = 5;
    const int NORMAL_HOURS = 40;
    const int WEEKS_IN_YEAR = 52;
    double normal_pay, overtime_pay, double_time_pay, total_pay, tax_rate, tax_amount, hours_worked, annual_salary;
    
    
    
    
    
    //code will loop as long as user enters c 
    //code will stop as user enters q
    //if the user enters something other then c the code will run once and stop
	do {
		cout<<"Welcome to Income and tax Calculator"<<endl;
		cout<<"------- -- ------ --- --- ----------\n"<<endl;
		cout<<"Enter \"C\"to continue OR \"Q\"to quit"<<endl;
        cin >> i;
		//code will exit if user enters q
		if (i == "q" || i == "Q") {
            break;
        }
       
	   
	   
	   
	    
	//requesting input
	cout<<"Please enter your First Name:"<<endl;
	cin>>fname;
	cout<<"\n";
	cout<<"Please enter your Surname:"<<endl;
	cin>>lname;
	cout<<"\n";
	cout<<"Please enter your Employee ID:"<<endl;
	cin>>id;
	cout<<"\n";
	
	
	
	// if the user enters something else, then user will be prompted again for the input
	while (true) {
       cout<<"Please enter your Gender (M => Male, F => Female):"<<endl;
        cin>>gender;
    
        if (gender == 'm' || gender =='f') {
            break;  // exit the loop
        }
        else if(gender == 'M' || gender =='F')
        	break; //exit the loop
    }

	cout<<"\n";







	//this loop will make sure user dosent enter an year over 2023 or less then 1920
	do {
	
	cout<<"Please enter your Year of Birth: "<<endl;
	cin>>yob;
	//validating input- the user must enter an int to continue
		while(cin.fail() ){
			cin.clear();
			string not_an_int;
			cin >> not_an_int;
			cout << "Please enter the correct Year of Birth: ";
			cin >> yob;
		}
			

	}while (yob < MIN_YEAR || yob > YEAR);
	cout<<"\n";
	
	
	
	
	
	cout<<"Please enter number of hours you worked in a week:"<<endl;
	cin>>hours_worked;
	//validating input- the user must enter an int to continue

	while(cin.fail()){
			cin.clear();
			string not_an_int;
			cin >> not_an_int;
			cout << "Please enter the correct number: ";
			cin >> hours_worked;
		}
	cout<<"\n"<<endl;
	
	
	
	//calculating age
	age = YEAR - yob;
	
	
	
	//calculating income
	if (hours_worked <= NORMAL_HOURS) {
        // no overtime
        normal_pay = hours_worked * RATE;
        total_pay = normal_pay;
    } 
	else if (hours_worked <= DOUBLE_TIME_START) {
        // time and half overtime for hours worked above NORMAL_HOURS but below or equal to 45
        normal_pay = NORMAL_HOURS * RATE;
        overtime_pay = (hours_worked - NORMAL_HOURS) * RATE * OVERTIME_RATE_FACTOR;
        total_pay = normal_pay + overtime_pay;
    } 
	else {
        // double time overtime for hours worked above 45
        normal_pay = NORMAL_HOURS * RATE;
        overtime_pay = FIVE * RATE * OVERTIME_RATE_FACTOR;
        double_time_pay = (hours_worked - DOUBLE_TIME_START) * RATE * DOUBLE_TIME_RATE_FACTOR;
        total_pay = normal_pay + overtime_pay + double_time_pay;
    }
		
	annual_salary = total_pay * WEEKS_IN_YEAR;	//calculating annual salary
	
	
	
	//calculating of tax rate based on age, gender and income
	//the value of tax_rate variable will be assigned here 
	if (age < AGE_TIER_1) {
        if (gender == 'M' || gender =='m') {
            if (annual_salary < MALE_INCOME_TIER_1) {
                tax_rate = 0.0;
            } 
			else if (annual_salary <= MALE_INCOME_TIER_2) {
                tax_rate = 0.1;
            } 
			else if (annual_salary <= MALE_INCOME_TIER_3) {
                tax_rate = 0.2;
            } 
			else {
                tax_rate = 0.3;
            }
        } 
		else if (gender == 'F' || gender =='f') {
            if (annual_salary < FEMALE_INCOME_TIER_1) {
                tax_rate = 0.0;
            } 
			else if (annual_salary <= FEMALE_INCOME_TIER_2) {
                tax_rate = 0.1;
            } 
			else if (annual_salary <= FEMALE_INCOME_TIER_3) {
                tax_rate = 0.2;
            } 
			else {
                tax_rate = 0.3;
            }
        }
    } 
	else if (age < AGE_TIER_2) {
        if (annual_salary < INCOME_TIER_3) {
            tax_rate = 0.0;
        } 
		else if (annual_salary <= INCOME_TIER_4) {
            tax_rate = 0.1;
        } 
		else if (annual_salary <= INCOME_TIER_5) {
            tax_rate = 0.2;
        } 
		else {
            tax_rate = 0.3;
        }
    } 
	else {
        tax_rate = 0.0; // no tax for age >= 80
    }
	//code will break out of the if statement when one of the condition is satisfied, and use the tax RATE to calculate tax amount
    tax_amount = annual_salary * tax_rate;//calculate tax


	//outputs
	cout<<"*********************************************************\n"<<endl;
	cout<<"\t Income and Tax Calculator"<<endl;
	cout<<"\t ______ ___ ___ __________\n"<<endl;
	cout<<"\t Name:           "<<fname<<" "<<lname<<endl;
	cout<<"\t Employee ID:    "<<id<<endl;
	cout<<"\t Age:            "<<age<<endl;
	cout<<"\t Gross Pay Week: $"<<total_pay<<endl;
	cout<<"\t Annual Salary:  $"<<annual_salary<<endl;
	cout<<"\t Tax Amount:     $"<<tax_amount<<endl;
	cout<<"\n";
	cout<<"*********************************************************\n"<<endl;
	
	
}	//code will loop if the user enters c
	while( i == "c" || i == "C");
	//if the user enters something other then 'c' the code will run once and then stop	
		
		
		
		system("pause");
  		return 0;

}
	
	
	
	
	
	
	
