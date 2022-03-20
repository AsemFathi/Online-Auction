#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int k = 0, l = 0; // the members , the items
string username, password; // have email , have password
bool invalid = false, activebidsseller = false, activebidsbuyer = false; //check the email 
char ask;
int itemnumbers = 1, memberid = 1;
string status; // buyer or items
double buyerwantprice, sellerwantprice; // the buyer want price
struct date
{
	int day, month, year;
};

struct member {
	string  email, name, password, adress, feedbackk;
	int phone, ID;
	int point = 0;
	double bids[5] = { };
	bool selling = false, buying = false;

}members[100];

struct sell
{
	int sellerid;
	int itemnumber;
	string category;
	double price;
	date start, end;


} itemss[50];

// function declaration
void membership(); //create an account for first time

void accepted();

void login(); //login to the user's account

void items(); //Enter information of the selling items

void checkdate();//check if the date of the selling item is correct

void feedback();//give feedback to the other member 

void completebuying(); //complete the buying process

void showselected(int n); // view the details of the selling item

void select();//select the item that he want to buy

void buyer(); // buying process

int main()
{

	cout << "Do you have an account ? y/n " << endl;
	cin >> ask;
	if (ask == 'n') {
		membership();
		//memberid +=1 ;
	}
	else if (ask == 'y')
	{
		login();


	}
	else
	{
		cout << "Your choose is invalid , Please choose again " << endl;
		main();
	}

	cout << endl << "You are buyer or seller? ";
	cin >> status;
	if (status == "seller")
	{
		items();
		while (true)
		{
			cout << "Do you want to sell more items ?  y/n" << endl;
			cin >> ask;
			if (ask == 'y')
				items();
			else if (ask == 'n')
				break;
		}
	}
	else if (status == "buyer")
	{
		buyer();
	}
	cout << endl << endl;

	main();
}

void membership()
{
	cout << "Username: ";
	cin >> members[k].name;
	//cout << "ID: ";
	//cin >> members[k].ID;
	cout << "Email: ";
	cin >> members[k].email;
	cout << "Password: ";
	cin >> members[k].password;
	cout << "Phone: ";
	cin >> members[k].phone;
	cout << "Adress: ";
	cin >> members[k].adress;
	members[k].ID = memberid;
	cout << "Your ID : " << members[k].ID << endl;
	k++;
	memberid++;
}

void login() //login to email
{
	int index = 0; //to show the member points when he login 
	cout << "Username : ";
	cin >> username;
	cout << "Password : ";
	cin >> password;
	for (int i = 0; i < 100; i++) //check if the username and paswor is correct
	{
		if (members[i].name == username && members[i].password == password)
		{
			invalid = true;
			index = i;
			break;
		}
	}
	while (!invalid)
	{
		cout << "Your username or password is invalid " << endl;
		login();
	}
	cout << "Your points : " << members[index].point << endl;
	cout << "Your last progress feedback : " << members[index].feedbackk << endl;

	if (activebidsseller == true || activebidsbuyer == true);
	{
		int BuyingID = members[index].bids[2];
		if (members[index].selling == true)
		{

			cout << "Your active bids : " << endl;
			cout << "Item number : " << members[index].bids[0] << endl;
			cout << "Buyer ID : " << members[index].bids[2] << endl;
			cout << "Buyer want price : " << members[index].bids[1] << endl;
			cout << "Do You accept this bid ? y/n " << endl;
			cin >> ask;
			if (ask == 'y')
			{
				cout << "Congratulations , Your item has been sold " << endl;
				accepted();

			}
			else
			{
				cout << "Enter your Want price : ";
				cin >> sellerwantprice;
				members[BuyingID - 1].bids[0] = members[index].bids[0];
				members[BuyingID - 1].bids[3] = index, members[BuyingID - 1].bids[4] = sellerwantprice;
				activebidsbuyer = true;
				members[BuyingID - 1].buying = true;
			}
			members[index].selling = false;
			activebidsseller = false;
		}
		else if (members[index].buying == true)
		{
			cout << "Your active bids : " << endl;
			cout << "Item number : " << members[index].bids[0] << endl;
			cout << "Seller ID : " << members[index].bids[3] << endl;
			cout << "Seller want price : " << members[index].bids[4] << endl;
			cout << "Do You accept this bid ? y/n " << endl;
			cin >> ask;
			if (ask == 'y')
			{
				cout << "Congratulation , the goods will delivered to your adress through 3 days." << endl;
				accepted();
			}
			else
			{
				cout << "Enter your Want price : ";
				cin >> buyerwantprice;
				activebidsseller = true;
			}
			activebidsbuyer = false;
			members[index].buying = false;
		}
	}
}

void checkdate() // check if the date is correct
{
	if (itemss[l].end.month > 12 || itemss[l].start.month > 12 || itemss[l].end.month < 1 || itemss[l].start.month < 1)
	{
		cout << "the date is incorrect " << endl;
		items();
	}
	else if (itemss[l].end.day > 31 || itemss[l].start.day > 31 || itemss[l].end.day < 1 || itemss[l].start.day < 1)
	{
		cout << "the date is incorrect " << endl;
		items();
	}
	else if (itemss[l].end.year == itemss[l].start.year)
	{
		if (itemss[l].end.month == itemss[l].start.month)
		{
			if (itemss[l].end.day < itemss[l].start.day)
			{
				cout << "The Date is incorrect " << endl;
				items();
			}
		}
		else if (itemss[l].end.month < itemss[l].start.month)
		{
			cout << "The Date is incorrect" << endl;
			items();
		}
	}
	else if (itemss[l].end.year < itemss[l].start.year)
	{
		cout << "The Date is incorrect" << endl;
		items();
	}
}

void items() // 
{
	cout << "Complete the following data " << endl;
	//cout << "Item number : ";
	//cin >> itemss[l].itemnumber;
	cout << "Enter your ID : ";
	cin >> itemss[l].sellerid;
	cout << "Category : ";
	cin >> itemss[l].category;
	cout << "Price : ";
	cin >> itemss[l].price;
	cout << "Start date of the auction process : ";
	cin >> itemss[l].start.day >> itemss[l].start.month >> itemss[l].start.year;
	cout << "End date of the auction process : ";
	cin >> itemss[l].end.day >> itemss[l].end.month >> itemss[l].end.year;
	checkdate();
	itemss[l].itemnumber = itemnumbers;
	itemnumbers += 1;
	l++;
}

void feedback()
{
	int ID; // the other member ID 
	string fedback;
	int rate, idnum;
	if (status == "seller")
		cout << "Enter the buyer ID : ";
	else
		cout << "Enter the seller ID : ";
	cin >> ID;
	/*for (int i = 0; i < l; i++) // searh for the id to increase or decrease point
	{
		if (ID == members[i].ID)
			idnum = i;
	}*/
	cout << "Enter rate from 1 to 5 ' 1 is very bad , 5 is excellent' " << endl;
	cin >> rate;
	cin.ignore();
	cout << "Enter your feedback : ";
	getline(cin, fedback);
	if (rate >= 3)
		members[ID - 1].point += 1;
	members[ID - 1].feedbackk = fedback;
}
void accepted()
{
	cout << "To sent feedback press 'y' or 'n' to exit " << endl;
	cin >> ask;
	if (ask == 'y') //send feedback
	{
		feedback();
	}
}
void completebuying(int z)
{
	int ID, userid; // seller id

	cout << "Do you agree to the bid price? y/n " << endl;
	cin >> ask;
	if (ask == 'y')
	{
		cout << "Congratulation , the goods will delivered to your adress through 3 days." << endl;
		cout << "To sent feedback press 'y' or 'n' to exit " << endl;
		cin >> ask;
		if (ask == 'y') //send feedback
		{
			feedback();
		}
	}

	else if (ask == 'n')
	{
		cout << "Enter your ID : ";
		cin >> userid;
		cout << "Enter the seller ID : ";
		cin >> ID;
		cout << " Enter the price you want to pay and wait the items response " << endl;
		cin >> buyerwantprice;

		members[ID - 1].bids[0] = z, members[ID - 1].bids[1] = buyerwantprice, members[ID - 1].bids[2] = userid;
		members[userid - 1].bids[3] = ID, members[userid - 1].bids[4] = sellerwantprice;
		members[ID - 1].selling = true;
		activebidsseller = true;
	}
}

void showselected(int n, int z) // show the selected item 
{
	cout << itemss[n].itemnumber << ") " << "ctaegory : " << itemss[n].category << "  Price : " << itemss[n].price << endl;
	cout << "Start date of the auction process : ";
	cout << itemss[n].start.day << " / " << itemss[n].start.month << " / " << itemss[n].start.year << endl;
	cout << "End date of the auction process : ";
	cout << itemss[n].end.day << " / " << itemss[n].end.month << " / " << itemss[n].end.year << endl;
	cout << "The seller ID : " << itemss[n].sellerid;
	completebuying(z);

}

void select() //select item in market place
{
	bool choose = false;
	int selected;
	cout << "Enter your choose item number to show it's details : ";
	cin >> selected;
	int itemselect;
	for (int i = 0; i < l; i++) // check the select item and show its details
	{
		if (itemss[i].itemnumber == selected)
		{
			choose = true;
			itemselect = i;
			break;
		}

	}
	if (choose == true)
		showselected(itemselect, selected);
	else
	{
		cout << "Your select item is incorrect " << endl;
		select();

	}
}

void buyer()
{
	for (int i = 0; i < l; i++) //show the items in the market place
	{
		cout << itemss[i].itemnumber << ") " << itemss[i].category << "    " << itemss[i].price << endl;

	}
	select();
}
