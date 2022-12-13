#pragma once
#include "Classes.h"
#include <conio.h>
void mysetcolor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

void DataWriteToFile(string filename, string text, string source, int line, string date) {
	ofstream fout(filename, ios::app);

	if (fout.is_open()) {
		fout << "Information : " << text << endl;
		fout << "Source :" << source << endl;
		fout << "Line : " << line << endl;
		fout << "Date : " << date << endl;
	}
	else {
		cout << filename << " does not exist" << endl;
	}
	fout.close();
}

string GetDataFromFile(const string& filename) {
	ifstream fin(filename, ios::in);
	string result = "";
	if (fin.is_open()) {
		//fin >> result;//only one until break point
		//getline(fin, result);// only one line

		string data = "";
		while (!fin.eof())
		{
			getline(fin, data);
			result.append(data + "\n");
		}

		fin.close();
	}
	else {
		throw string("This file : " + filename + " does not exist");
	}
	return result;
}

void ShowIntro() {
	Meals meals(" ", 1);
	MixedPizza mix("Mixed Pizza(sausage,olive,tomato)", 12.5);
	ChickenRanch chick("Chicken Ranch(chicken,tomato,bacon)", 10.8);
	Dolma dolma("Dolma(beef,rice,fresh herbs)", 15);
	meals.AddMeal(mix);
	meals.AddMeal(chick);
	meals.AddMeal(dolma);
	Specials specials;
	Specials yogurt("Yogurt", 0, 2);
	Specials salad("Mixed Salad Greens", 0, 4);
	Specials cheese("Cheese Sauce", 0, 0.7);
	Specials garlic("Garlic Sauce", 0, 0.7);
	specials.Add(yogurt);
	specials.Add(salad);
	specials.Add(cheese);
	specials.Add(garlic);
	Client client(1, "", 1);
	Table1 first(0);
	Table2 second(0);
	Table3 third(0);
	Table4 fourth(0);
	Table5 fifth(0);
	Kitchen kitchen(0, 0, 0, 0, 0, 0);
	Notifications kitchennotification(0);
	Notifications clientnotification(0);
	Stock stock("Stock");
	Ingredients ing;
	Products product1("Tomato", 100);
	Products product2("Olive", 200);
	Products product3("Flour", 500);
	Products product4("Sausage", 200);
	Products product5("Rice", 500);
	Products product6("Freshherbs", 50);
	Products product7("Oil", 600);
	Products product8("Chicken", 100);
	Products product9("Bacon", 200);
	Products product10("MildCheddar", 100);
	Products product11("Beef", 400);
	Products product12("Greens", 50);
	Products product13("Spices", 30);
	Products product14("Yogurt", 50);
	Products product15("CheeseSauce", 100);
	Products product16("GarlicSauce", 100);
	Products product17("MixedSaladGreens", 30);
	stock.AddProduct(product1);
	stock.AddProduct(product2);
	stock.AddProduct(product3);
	stock.AddProduct(product4);
	stock.AddProduct(product5);
	stock.AddProduct(product6);
	stock.AddProduct(product7);
	stock.AddProduct(product8);
	stock.AddProduct(product9);
	stock.AddProduct(product10);
	stock.AddProduct(product11);
	stock.AddProduct(product12);
	stock.AddProduct(product13);
	stock.AddProduct(product14);
	stock.AddProduct(product15);
	stock.AddProduct(product16);
	stock.AddProduct(product17);

	FileHelper::Save(stock);
	Stock obj = FileHelper::Read();





	Ingredients mix1("Tomato", 36, 2);
	Ingredients mix2("Olive", 115, 10);
	Ingredients mix3("Flour", 728, 2);
	Ingredients mix4("Sausage", 346, 5);
	Ingredients mix5("Oil", 884, 5);
	mix.AddIng(mix1);
	mix.AddIng(mix2);
	mix.AddIng(mix3);
	mix.AddIng(mix4);
	mix.AddIng(mix5);

	Ingredients chick1("Tomato", 36, 2);
	Ingredients chick2("Flour", 728, 2);
	Ingredients chick3("Chicken", 239, 0.5);
	Ingredients chick4("Bacon", 541, 0.5);
	Ingredients chick5("MildCheddar", 110, 1);
	chick.AddIng(chick1);
	chick.AddIng(chick2);
	chick.AddIng(chick3);
	chick.AddIng(chick4);
	chick.AddIng(chick5);

	Ingredients dolma1("Rice", 130, 1);
	Ingredients dolma2("Freshherbs", 30, 15);
	Ingredients dolma3("Beef", 500, 1);
	Ingredients dolma4("Greens", 46, 3);
	Ingredients dolma5("Spices", 180, 2);
	dolma.AddIng(dolma1);
	dolma.AddIng(dolma2);
	dolma.AddIng(dolma3);
	dolma.AddIng(dolma4);
	dolma.AddIng(dolma5);
	mysetcolor(11, 0);

	cout << "\t\t\t\t\t __   __                               \t\t" << endl;
	cout << "\t\t\t\t\t \\ \\ / /   _ _ __ ___  _ __ ___  _   _ \t\t" << endl;
	cout << "\t\t\t\t\t  \\ V / | | | '_ ` _ \\| '_ ` _ \\| | | |\t\t" << endl;
	cout << "\t\t\t\t\t   | || |_| | | | | | | | | | | | |_| |\t\t" << endl;
	cout << "\t\t\t\t\t   |_| \\__,_|_| |_| |_|_| |_| |_|\\__, |\t\t" << endl;
	cout << "\t\t\t\t\t                                 |___/ \t\t" << endl;


	cout << "\t\t\t\t    ____           _                              _   \t       " << endl;
	cout << "\t\t\t\t   |  _ \\ ___  ___| |_ __ _ _   _ _ __ __ _ _ __ | |_ \t       " << endl;
	cout << "\t\t\t\t   | |_) / _ \\/ __| __/ _` | | | | '__/ _` | '_ \\| __|\t       " << endl;
	cout << "\t\t\t\t   |  _ <  __/\\__ \\ || (_| | |_| | | | (_| | | | | |_ \t       " << endl;
	cout << "\t\t\t\t   |_| \\_\\___||___/\\__\\__,_|\\__,_|_|  \\__,_|_| |_|\\__|\t       " << endl;
	cout << "\t\t\t\t                                                      \t       " << endl;

	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	mysetcolor(7, 0);
	int table = 0;
	int clientnotif = 0;
	while (true)
	{
		cout << "\t\t\t\t\t\tClient ----- [1]";
		mysetcolor(6, 0);
		cout << "(" << clientnotification.GetNotification() << ")" << endl << endl;
		mysetcolor(7, 0);
		cout << "\t\t\t\t\t\tKitchen ---- [2]";
		mysetcolor(6, 0);
		cout << "(" << kitchennotification.GetNotification() << ")" << endl << endl;
		mysetcolor(7, 0);
		cout << "\t\t\t\t\t\tStock ------ [3]" << endl << endl;
		cout << "\t\t\t\t\t\tExit ------- [4]" << endl << endl << endl;
		cout << "\t\t\t\t\t\tEnter your choice : " << endl;
		int person = 0;
		cin >> person;
		if (person == 1) {
			clientnotification.SetNotification(0);
			kitchen.SetMixCount(0);
			kitchen.SetChickCount(0);
			kitchen.SetDolmaCount(0);
			kitchen.SetMixPrice(0);
			kitchen.SetChickPrice(0);
			kitchen.SetDolmaPrice(0);
			specials.SetTotalPrice(0);

			system("cls");


			int currenttable = client.GetTable();
			mysetcolor(8, 0);
			cout << "                                     ,%;," << endl;
			cout << "                                     ,%%," << endl;
			cout << "                        ______________)(______________" << endl;
			cout << "                       /             (__)             \\" << endl;
			cout << "                      /________________________________\\" << endl;
			cout << "                      [________________________________]" << endl;
			cout << "                         \\ \\  / /           \\ \\  / /" << endl;
			cout << "                          \\ \\/ /             \\ \\/ /" << endl;
			cout << "                          _\\/ /_______________\\ \\/_" << endl;
			cout << "                         [_/o/_________________\\o\\_]" << endl;
			cout << "                          / /\\ \\              / /\\ \\" << endl;
			cout << "                         /_/  \\_\\            /_/  \\_\\" << endl;
			mysetcolor(7, 0);

			cout << "Table ----- [1]";
			mysetcolor(6, 0);
			cout << "("; cout << first.GetNotif();  cout << ")" << endl;
			mysetcolor(7, 0);
			cout << "Table ----- [2]";
			mysetcolor(6, 0);
			cout << "("; cout << second.GetNotif(); cout << ")" << endl;
			mysetcolor(7, 0);
			cout << "Table ----- [3]";
			mysetcolor(6, 0);
			cout << "("; cout << third.GetNotif(); cout << ")" << endl;
			mysetcolor(7, 0);
			cout << "Table ----- [4]";
			mysetcolor(6, 0);
			cout << "("; cout << fourth.GetNotif(); cout << ")" << endl;
			mysetcolor(7, 0);
			cout << "Table ----- [5]";
			mysetcolor(6, 0);
			cout << "("; cout << fifth.GetNotif(); cout << ")" << endl;
			mysetcolor(7, 0);
			cout << "Enter your choice : " << endl;
			table = _getch();
			table -= 48;
			try
			{
				client.SetTable(table);
				DataWriteToFile("info.txt", (char)(table + 48) + string(". Table has entered to the system"), __FILE__, __LINE__, __DATE__);
			}

			catch (const Exception& ex)
			{
				ex.PrintMessage();
				DataWriteToFile("error-log.txt", ex.GetText(), ex.GetSource(), ex.GetLine(), ex.GetDate());
				return;
			}

			if (table == 1) {
				if (first.GetNotif() != 0) {
					first.Show();
					try
					{
						first.SetNotif(0);
					}
					catch (const Exception& ex)
					{
						ex.PrintMessage();
						DataWriteToFile("error-log.txt", ex.GetText(), ex.GetSource(), ex.GetLine(), ex.GetDate());
						return;
					}
					cout << "Do you want to order other thing ?\Yes ----- [1]\nNo ----- [2]" << endl;
					int again = _getch();
					again -= 48;
					if (again == 1) {
					}
					else {
						continue;
					}
				}
			}
			else if (table == 2) {
				if (second.GetNotif() != 0) {
					second.Show();
					try
					{
						second.SetNotif(0);
					}
					catch (const Exception& ex)
					{
						ex.PrintMessage();
						DataWriteToFile("error-log.txt", ex.GetText(), ex.GetSource(), ex.GetLine(), ex.GetDate());
						return;
					}

					cout << "Do you want to order other thing ?\Yes ----- [1]\nNo ----- [2]" << endl;
					int again = _getch();
					again -= 48;
					if (again == 1) {
					}
					else {
						continue;
					}
				}
			}
			else if (table == 3) {
				if (third.GetNotif() != 0) {
					third.Show();
					try
					{
						third.SetNotif(0);
					}
					catch (const Exception& ex)
					{
						ex.PrintMessage();
						DataWriteToFile("error-log.txt", ex.GetText(), ex.GetSource(), ex.GetLine(), ex.GetDate());
						return;
					}

					cout << "Do you want to order other thing ?\Yes ----- [1]\nNo ----- [2]" << endl;
					int again = _getch();
					again -= 48;
					if (again == 1) {
					}
					else {
						continue;
					}
				}
			}
			else if (table == 4) {
				if (fourth.GetNotif() != 0) {
					fourth.Show();

					try
					{
						fourth.SetNotif(0);
					}
					catch (const Exception& ex)
					{
						ex.PrintMessage();
						DataWriteToFile("error-log.txt", ex.GetText(), ex.GetSource(), ex.GetLine(), ex.GetDate());
						return;
					}
					cout << "Do you want to order other thing ?\Yes ----- [1]\nNo ----- [2]" << endl;
					int again = _getch();
					again -= 48;
					if (again == 1) {
					}
					else {
						continue;
					}
				}
			}
			else if (table == 5) {
				if (fifth.GetNotif() != 0) {
					fifth.Show();
					try
					{
						fifth.SetNotif(0);
					}
					catch (const Exception& ex)
					{
						ex.PrintMessage();
						DataWriteToFile("error-log.txt", ex.GetText(), ex.GetSource(), ex.GetLine(), ex.GetDate());
						return;
					}
					cout << "Do you want to order other thing ?\Yes ----- [1]\nNo ----- [2]" << endl;
					int again = _getch();
					again -= 48;
					if (again == 1) {
					}
					else {
						continue;
					}
				}
			}


			while (true)
			{
				cout << "Show Menu ---- [1]\nSearch ------- [2]" << endl;
				int show = _getch();
				show -= 48;
				if (show == 1) {
					system("cls");
					mysetcolor(6, 0);
					cout << " ___ ___    ___ _ __  _   _" << endl;
					cout << "| '_ ` _ \\ / _ \\ '_ \\| | | |" << endl;
					cout << "| | | | | |  __/ | | | |_| |" << endl;
					cout << "|_| |_| |_|\\___|_| |_|\\__,_|" << endl;
					mysetcolor(7, 0);
					meals.ShowAll();
				}
				else if (show == 2) {
					cout << "Enter : " << endl;
					string text = "";
					while (true)
					{
						char symbol = _getch();
						int changesymb = (int)symbol;
						if (changesymb == 27) {
							break;
						}
						char sym = (char)symbol;
						text = text + sym;
						meals.Search(text);
						cout << text << endl;

					}
					continue;
				}
				else {
					cout << "INVALID ENTRY!" << endl;
				}

				cout << "Enter your choice : " << endl;
				int meal = _getch();
				meal -= 48;
				cout << "[1] ----- Order\n[2] ----- Show" << endl;
				int choose = _getch();
				choose -= 48;
				system("cls");
				if (meal == 1 && choose == 2) {
					mix.Show();
					cout << "Back ----- [1]\nOrder ---- [2]" << endl;
					int step = _getch();
					step -= 48;
					system("cls");
					if (step == 1) {
						continue;
						system("pause");
						system("cls");
					}
					else {
						cout << "Enter count : " << endl;
						int count = 0;
						cin >> count;
						auto myarr = new Ingredients[5]{ mix1, mix2, mix3, mix4, mix5 };
						bool isokay = true;
						for (size_t i = 0; i < 5; i++)
						{
							if (obj.ShowAvailability(myarr[i])) {
								isokay = true;
							}

							else {
								isokay = false;
								break;
							}
						}
						if (isokay)
						{

							int kitchenCount = kitchen.GetMixCount();
							kitchenCount += count;
							kitchen.totalmix += count;
							kitchen.SetMixCount(kitchenCount);
							kitchen.SetMixPrice(mix.GetPrice() * count);
							double totalmixPrice = mix.GetPrice() * kitchenCount;
							for (size_t i = 0; i < 5; i++)
							{
								myarr[i].count = myarr[i].count * kitchenCount;
								obj.DecreaseProduct(myarr[i]);
							}
							client.SetName(mix.GetName());
							client.SetCount(kitchenCount);
							kitchen.AddClient(client);
							cout << "You've ordered " << count << " Mixed Pizza" << endl;
							while (true)
							{

								cout << "Cheese Sauce[$0.7] ----- [1]\nGarlic Sauce[$0.7] ----- [2]\nNothing ---------------- [3]" << endl;
								cout << "Enter your choice : " << endl;
								int add = _getch();
								add -= 48;
								if (add == 1) {
									cout << "Enter count of portion : ";
									int portion = 0;
									cin >> portion;

									cheese.SetCount(portion);
									cheese.SetPrice(0.7);
									double newprice = cheese.GetPrice() * portion;
									cheese.SetPrice(newprice);
									obj.DecreaseSpecials(cheese);
									specials.SetTotalPrice(newprice);

								}
								else if (add == 2) {
									cout << "Enter count of portion : ";
									int portion = 0;
									cin >> portion;


									garlic.SetCount(portion);
									garlic.SetPrice(0.7);
									double newprice = garlic.GetPrice() * portion;
									garlic.SetPrice(newprice);
									obj.DecreaseSpecials(garlic);
									specials.SetTotalPrice(newprice);

								}
								else if (add == 3) {
									break;
								}
								else {
									cout << "INVALID ENTRY!" << endl;
								}
							}
							cout << "Back ----- [1]\nFinish --- [2]" << endl;
							int step = _getch();
							step -= 48;
							if (step == 1) {
								continue;
							}
							else {
								kitchen.SetMixPrice(totalmixPrice + specials.GetTotalPrice());
								cout << "You have to pay " << kitchen.GetTotalPrice() << " $" << endl;
								kitchennotification.notification++;
								kitchen.AddNotification(kitchennotification);
								break;
							}
							system("pause");

						}
						else {
							auto myarr = new Ingredients[5]{ mix1, mix2, mix3, mix4, mix5 };
							for (size_t i = 0; i < 5; i++)
							{
								if (!obj.ShowAvailability(myarr[i])) {
									cout << "You should not buy this meal, because " << myarr[i].name << " is out of stock" << endl;
								}
							}
							continue;
						}

					}
				}
				else if (meal == 1 && choose == 1) {
					auto myarr = new Ingredients[5]{ mix1, mix2, mix3, mix4, mix5 };
					cout << "Enter count : " << endl;
					int count = 0;
					cin >> count;
					bool isokay = true;
					for (size_t i = 0; i < 5; i++)
					{
						if (obj.ShowAvailability(myarr[i])) {
							isokay = true;
						}

						else {
							isokay = false;
							break;
						}
					}
					if (isokay)
					{

						int kitchenCount = kitchen.GetMixCount();
						kitchenCount += count;
						kitchen.totalmix += count;
						kitchen.SetMixCount(kitchenCount);
						kitchen.SetMixPrice(mix.GetPrice() * count);
						double totalmixPrice = mix.GetPrice() * kitchenCount;
						for (size_t i = 0; i < 5; i++)
						{
							myarr[i].count = myarr[i].count * kitchenCount;
							obj.DecreaseProduct(myarr[i]);
						}
						client.SetName(mix.GetName());
						client.SetCount(kitchenCount);
						kitchen.AddClient(client);
						cout << "You've ordered " << count << " Mixed Pizza" << endl;
						while (true)
						{

							cout << "Cheese Sauce[$0.7] ----- [1]\nGarlic Sauce[$0.7] ----- [2]\nNothing ---------------- [3]" << endl;
							cout << "Enter your choice : " << endl;
							int add = _getch();
							add -= 48;
							if (add == 1) {
								cout << "Enter count of portion : ";
								int portion = 0;
								cin >> portion;


								cheese.SetCount(portion);
								cheese.SetPrice(0.7);
								double newprice = cheese.GetPrice() * portion;
								cheese.SetPrice(newprice);
								obj.DecreaseSpecials(cheese);
								specials.SetTotalPrice(newprice);

							}
							else if (add == 2) {
								cout << "Enter count of portion : ";
								int portion = 0;
								cin >> portion;

								garlic.SetCount(portion);
								garlic.SetPrice(0.7);
								double newprice = garlic.GetPrice() * portion;
								garlic.SetPrice(newprice);
								obj.DecreaseSpecials(garlic);
								specials.SetTotalPrice(newprice);

							}
							else if (add == 3) {
								break;
							}
							else {
								cout << "INVALID ENTRY!" << endl;
							}
						}
						cout << "Back ----- [1]\nFinish --- [2]" << endl;
						int step = _getch();
						step -= 48;
						if (step == 1) {
							continue;
						}
						else {
							kitchen.SetMixPrice(totalmixPrice + specials.GetTotalPrice());
							cout << "You have to pay " << kitchen.GetTotalPrice() << " $" << endl;
							kitchennotification.notification++;
							kitchen.AddNotification(kitchennotification);
							break;
						}
						system("pause");

					}
					else {
						auto myarr = new Ingredients[5]{ mix1, mix2, mix3, mix4, mix5 };
						for (size_t i = 0; i < 5; i++)
						{
							if (!obj.ShowAvailability(myarr[i])) {
								cout << "You should not buy this meal, because " << myarr[i].name << " is out of stock" << endl;
							}
						}
						continue;
					}
				}
				else if (meal == 2 && choose == 2) {
					auto myarr = new Ingredients[5]{ chick1, chick2, chick3, chick4, chick5 };
					chick.Show();
					cout << "Back ----- [1]\nOrder ---- [2]" << endl;
					int step = _getch();
					step -= 48;
					system("cls");
					if (step == 1) {
						continue;
						system("pause");
						system("cls");
					}
					else {
						cout << "Enter count : " << endl;
						int count = 0;
						cin >> count;

						bool isokay = true;
						for (size_t i = 0; i < 5; i++)
						{
							if (obj.ShowAvailability(myarr[i])) {
								isokay = true;
							}

							else {
								isokay = false;
								break;
							}
						}
						if (isokay)
						{

							int kitchenCount = kitchen.GetChickCount();
							kitchenCount += count;
							kitchen.totalchick += count;
							kitchen.SetChickCount(kitchenCount);
							kitchen.SetChickPrice(chick.GetPrice() * count);
							double totalchickPrice = chick.GetPrice() * kitchenCount;
							for (size_t i = 0; i < 5; i++)
							{
								myarr[i].SetCount(myarr[i].GetCount() * kitchenCount);
								obj.DecreaseProduct(myarr[i]);
							}
							client.SetName(chick.GetName());
							client.SetCount(kitchenCount);
							kitchen.AddClient(client);
							cout << "You've ordered " << count << " ChickenRanch Pizza" << endl;
							while (true)
							{

								cout << "Cheese Sauce[$0.7] ----- [1]\nGarlic Sauce[$0.7] ----- [2]\nNothing ---------------- [3]" << endl;
								cout << "Enter your choice : " << endl;
								int add = _getch();
								add -= 48;
								if (add == 1) {
									cout << "Enter count of portion : ";
									int portion = 0;
									cin >> portion;

									cheese.SetCount(portion);
									double newprice = cheese.GetPrice() * portion;
									cheese.SetPrice(newprice);
									obj.DecreaseSpecials(cheese);
									specials.SetTotalPrice(newprice);
								}
								else if (add == 2) {
									cout << "Enter count of portion : ";
									int portion = 0;
									cin >> portion;

									garlic.SetCount(portion);
									double newprice = garlic.GetPrice() * portion;
									garlic.SetPrice(newprice);
									obj.DecreaseSpecials(garlic);
									specials.SetTotalPrice(newprice);

								}
								else if (add == 3) {
									break;
								}
								else {
									cout << "INVALID ENTRY!" << endl;
								}
							}
							cout << "Back ----- [1]\nFinish --- [2]" << endl;
							int step = _getch();
							step -= 48;
							if (step == 1) {
								continue;
							}
							else {
								kitchen.SetChickPrice(totalchickPrice + specials.GetTotalPrice());
								cout << "You have to pay " << kitchen.GetTotalPrice() << " $" << endl;
								kitchennotification.notification++;
								kitchen.AddNotification(kitchennotification);
								break;
							}
							system("pause");

						}
						else {
							int k = 0;
							string* myarray = new string[k + 1]{};
							auto myarr = new Ingredients[5]{ chick1, chick2, chick3, chick4, chick5 };
							for (size_t i = 0; i < 5; i++)
							{
								if (!obj.ShowAvailability(myarr[i])) {
									cout << "You should not buy this meal, because " << myarr[i].name << " is out of stock" << endl;
								}
							}
							continue;
						}
					}
				}

				else if (meal == 2 && choose == 1) {
					auto myarr = new Ingredients[5]{ chick1, chick2, chick3, chick4, chick5 };
					cout << "Enter count : " << endl;
					int count = 0;
					cin >> count;
					bool isokay = true;
					for (size_t i = 0; i < 5; i++)
					{
						if (obj.ShowAvailability(myarr[i])) {
							isokay = true;
						}

						else {
							isokay = false;
							break;
						}
					}
					if (isokay)
					{

						int kitchenCount = kitchen.GetChickCount();
						kitchenCount += count;
						kitchen.totalchick += count;
						kitchen.SetChickCount(kitchenCount);
						kitchen.SetChickPrice(chick.GetPrice() * count);
						double totalchickPrice = chick.GetPrice() * kitchenCount;
						for (size_t i = 0; i < 5; i++)
						{
							myarr[i].count = myarr[i].count * kitchenCount;
							obj.DecreaseProduct(myarr[i]);
						}
						client.SetName(chick.GetName());
						client.SetCount(kitchenCount);
						kitchen.AddClient(client);
						cout << "You've ordered " << count << " ChickenRanch Pizza" << endl;
						while (true)
						{

							cout << "Cheese Sauce[$0.7] ----- [1]\nGarlic Sauce[$0.7] ----- [2]\nNothing ---------------- [3]" << endl;
							cout << "Enter your choice : " << endl;
							int add = _getch();
							add -= 48;
							if (add == 1) {
								cout << "Enter count of portion : ";
								int portion = 0;
								cin >> portion;


								cheese.SetCount(portion);
								double newprice = cheese.GetPrice() * portion;
								cheese.SetPrice(newprice);
								obj.DecreaseSpecials(cheese);
								specials.SetTotalPrice(newprice);

							}
							else if (add == 2) {
								cout << "Enter count of portion : ";
								int portion = 0;
								cin >> portion;



								garlic.SetCount(portion);
								double newprice = garlic.GetPrice() * portion;
								garlic.SetPrice(newprice);
								obj.DecreaseSpecials(garlic);
								specials.SetTotalPrice(newprice);


							}
							else if (add == 3) {
								break;
							}
							else {
								cout << "INVALID ENTRY!" << endl;
							}
						}
						cout << "Back ----- [1]\nFinish --- [2]" << endl;
						int step = _getch();
						step -= 48;
						if (step == 1) {
							continue;
						}
						else {
							kitchen.SetChickPrice(totalchickPrice + specials.GetTotalPrice());
							cout << "You have to pay " << kitchen.GetTotalPrice() << " $" << endl;
							kitchennotification.notification++;
							kitchen.AddNotification(kitchennotification);
							break;
						}
						system("pause");

					}
					else {
						auto myarr = new Ingredients[5]{ chick1, chick2, chick3, chick4, chick5 };
						for (size_t i = 0; i < 5; i++)
						{
							if (!obj.ShowAvailability(myarr[i])) {
								cout << "You should not buy this meal, because " << myarr[i].name << " is out of stock" << endl;
							}
						}
						continue;
					}
				}
				else if (meal == 3 && choose == 2) {

					dolma.Show();
					cout << "Back ----- [1]\nOrder ---- [2]" << endl;
					int step = _getch();
					step -= 48;
					system("cls");
					if (step == 1) {
						continue;
						system("pause");
						system("cls");
					}
					else {
						cout << "Enter count : " << endl;
						int count = 0;
						cin >> count;
						auto myarr = new Ingredients[5]{ dolma1, dolma2, dolma3, dolma4, dolma5 };
						bool isokay = true;
						for (size_t i = 0; i < 5; i++)
						{
							if (obj.ShowAvailability(myarr[i])) {
								isokay = true;
							}

							else {
								isokay = false;
								break;
							}
						}
						if (isokay)
						{

							int kitchenCount = kitchen.GetDolmaCount();
							kitchenCount += count;
							kitchen.totaldolma += count;
							kitchen.SetDolmaCount(kitchenCount);
							kitchen.SetDolmaPrice(dolma.GetPrice() * count);
							double totaldolmaPrice = dolma.GetPrice() * kitchenCount;
							for (size_t i = 0; i < 5; i++)
							{
								myarr[i].count = myarr[i].count * kitchenCount;
								obj.DecreaseProduct(myarr[i]);
							}
							client.SetName(dolma.GetName());
							client.SetCount(kitchenCount);
							kitchen.AddClient(client);
							cout << "You've ordered " << count << " Dolma " << endl;
							while (true)
							{

								cout << "Yogurt[$2] ----------- [1]\nSalad(Greens)[$4] ---- [2]\nNothing -------------- [3]" << endl;
								cout << "Enter your choice : " << endl;
								int add = _getch();
								add -= 48;
								if (add == 1) {
									cout << "Enter count of portion : ";
									int portion = 0;
									cin >> portion;

									yogurt.SetCount(portion);
									yogurt.SetPrice(2);
									double newprice = yogurt.GetPrice() * portion;
									yogurt.SetPrice(newprice);
									obj.DecreaseSpecials(yogurt);
									specials.SetTotalPrice(newprice);


								}
								else if (add == 2) {
									cout << "Enter count of portion : ";
									int portion = 0;
									cin >> portion;

									salad.SetCount(portion);
									salad.SetPrice(4);
									double newprice = salad.GetPrice() * portion;
									salad.SetPrice(newprice);
									obj.DecreaseSpecials(salad);
									specials.SetTotalPrice(newprice);

								}
								else if (add == 3) {
									break;
								}
								else {
									cout << "INVALID ENTRY!" << endl;
								}
							}
							cout << "Back ----- [1]\nFinish --- [2]" << endl;
							int step = _getch();
							step -= 48;
							if (step == 1) {
								continue;
							}
							else {
								kitchen.SetDolmaPrice(totaldolmaPrice + specials.GetTotalPrice());
								cout << "You have to pay " << kitchen.GetTotalPrice() << " $" << endl;
								kitchennotification.notification++;
								kitchen.AddNotification(kitchennotification);
								break;
							}
							system("pause");

						}
						else {
							auto myarr = new Ingredients[5]{ dolma1, dolma2, dolma3, dolma4, dolma5 };
							for (size_t i = 0; i < 5; i++)
							{
								if (!obj.ShowAvailability(myarr[i])) {
									cout << "You should not buy this meal, because " << myarr[i].name << " is out of stock" << endl;
								}
							}
							continue;
						}
					}


				}
				else if (meal == 3 && choose == 1) {
					cout << "Enter count : " << endl;
					int count = 0;
					cin >> count;
					auto myarr = new Ingredients[5]{ dolma1, dolma2, dolma3, dolma4, dolma5 };
					bool isokay = true;
					for (size_t i = 0; i < 5; i++)
					{
						if (obj.ShowAvailability(myarr[i])) {
							isokay = true;
						}

						else {
							isokay = false;
							break;
						}
					}
					if (isokay)
					{

						int kitchenCount = kitchen.GetDolmaCount();
						kitchenCount += count;
						kitchen.totaldolma += count;
						kitchen.SetDolmaCount(kitchenCount);
						kitchen.SetDolmaPrice(dolma.GetPrice() * count);
						double totaldolmaPrice = dolma.GetPrice() * kitchenCount;
						for (size_t i = 0; i < 5; i++)
						{
							myarr[i].count = myarr[i].count * kitchenCount;
							obj.DecreaseProduct(myarr[i]);
						}
						client.SetName(dolma.GetName());
						client.SetCount(kitchenCount);
						kitchen.AddClient(client);
						cout << "You've ordered " << count << " Dolma " << endl;
						while (true)
						{

							cout << "Yogurt[$2] ----------- [1]\nSalad(Greens)[$4] ---- [2]\nNothing -------------- [3]" << endl;
							cout << "Enter your choice : " << endl;
							int add = _getch();
							add -= 48;
							if (add == 1) {
								cout << "Enter count of portion : ";
								int portion = 0;
								cin >> portion;

								yogurt.SetCount(portion);
								yogurt.SetPrice(2);
								double newprice = yogurt.GetPrice() * portion;
								yogurt.SetPrice(newprice);
								obj.DecreaseSpecials(yogurt);
								specials.SetTotalPrice(newprice);
							}
							else if (add == 2) {
								cout << "Enter count of portion : ";
								int portion = 0;
								cin >> portion;

								salad.SetCount(portion);
								salad.SetPrice(4);
								double newprice = salad.GetPrice() * portion;
								salad.SetPrice(newprice);
								obj.DecreaseSpecials(salad);
								specials.SetTotalPrice(newprice);

							}
							else if (add == 3) {
								break;
							}
							else {
								cout << "INVALID ENTRY!" << endl;
							}

						}
						cout << "Back ----- [1]\nFinish --- [2]" << endl;
						int step = _getch();
						step -= 48;
						if (step == 1) {
							continue;
						}
						else {
							kitchen.SetDolmaPrice(totaldolmaPrice + specials.GetTotalPrice());
							cout << "You have to pay " << kitchen.GetTotalPrice() << " $" << endl;
							kitchennotification.notification++;
							kitchen.AddNotification(kitchennotification);
							break;
						}
						system("pause");

					}
					else {
						auto myarr = new Ingredients[5]{ dolma1, dolma2, dolma3, dolma4, dolma5 };
						for (size_t i = 0; i < 5; i++)
						{
							if (!obj.ShowAvailability(myarr[i])) {
								cout << "You should not buy this meal, because " << myarr[i].name << " is out of stock" << endl;
							}
						}
						continue;
					}
				}
			}
		}


		else if (person == 2) {
			cin.ignore();
			cin.clear();
			cout << "\t\t\t\t\t\tEnter Kitchen Password : " << endl;
			string password = "";
			getline(cin, password);
			if (password == "TastyPasty") {
				kitchen.Show();
				kitchennotification.SetMessage("");
				cout << endl << endl;
				cout << "Total Orders : ";
				kitchen.ShowOrders();
				kitchennotification.SetNotification(0);
				if (kitchen.GetClientsSize() != 0) {
					cout << "Accept ----- [1]\nReject ----- [2]" << endl;
					cout << "Enter your choice : " << endl;
					int choice = _getch();
					choice -= 48;
					cout << "Which order?" << endl;
					int accept = _getch();
					accept -= 48;
					clientnotification.notification++;
					int tableno = kitchen.GetTableById(accept);
					Client cl = kitchen.GetClientById(accept);
					if (choice == 1) {
						if (tableno == 1) {
							int notification = first.GetNotif();
							first.SetNotif(++notification);
							first.SetMessage(string("Your order is prepairing"));
							first.SetName(cl.GetName());
							first.SetCount(cl.GetCount());
							kitchen.DeleteClientById(accept);
						}
						else if (tableno == 2) {
							int notification = second.GetNotif();
							second.SetNotif(++notification);
							second.SetMessage(string("Your order is prepairing"));
							second.SetName(cl.GetName());
							second.SetCount(cl.GetCount());
							kitchen.DeleteClientById(accept);
						}
						else if (tableno == 3) {
							int notification = third.GetNotif();
							third.SetNotif(++notification);
							third.SetMessage(string("Your order is prepairing"));
							third.SetName(cl.GetName());
							third.SetCount(cl.GetCount());
							kitchen.DeleteClientById(accept);
						}
						else if (tableno == 4) {
							int notification = fourth.GetNotif();
							fourth.SetNotif(++notification);
							fourth.SetMessage(string("Your order is prepairing"));
							fourth.SetName(cl.GetName());
							fourth.SetCount(cl.GetCount());
							kitchen.DeleteClientById(accept);
						}
						else if (tableno == 5) {
							int notification = fifth.GetNotif();
							fifth.SetNotif(++notification);
							fifth.SetMessage(string("Your order is prepairing"));
							fifth.SetName(cl.GetName());
							fifth.SetCount(cl.GetCount());
							kitchen.DeleteClientById(accept);
						}
					}
					else if (choice == 2) {
						if (tableno == 1) {
							int notification = first.GetNotif();
							first.SetNotif(++notification);
							first.SetMessage(string("Your order is rejected"));
							first.SetName(cl.GetName());
							first.SetCount(cl.GetCount());
							kitchen.DeleteClientById(accept);
						}
						else if (tableno == 2) {
							int notification = second.GetNotif();
							second.SetNotif(++notification);
							second.SetMessage(string("Your order is rejected"));
							second.SetName(cl.GetName());
							second.SetCount(cl.GetCount());
							kitchen.DeleteClientById(accept);
						}
						else if (tableno == 3) {
							int notification = third.GetNotif();
							third.SetNotif(++notification);
							third.SetMessage(string("Your order is rejected"));
							third.SetName(cl.GetName());
							third.SetCount(cl.GetCount());
							kitchen.DeleteClientById(accept);
						}
						else if (tableno == 4) {
							int notification = fourth.GetNotif();
							fourth.SetNotif(++notification);
							fourth.SetMessage(string("Your order is rejected"));
							fourth.SetName(cl.GetName());
							fourth.SetCount(cl.GetCount());
							kitchen.DeleteClientById(accept);
						}
						else if (tableno == 5) {
							int notification = fifth.GetNotif();
							fifth.SetNotif(++notification);
							fifth.SetMessage(string("Your order is rejected"));
							fifth.SetName(cl.GetName());
							fifth.SetCount(cl.GetCount());
							kitchen.DeleteClientById(accept);
						}
					}
				}
				else {

				}
			}
			else {
				mysetcolor(4, 0);
				cout << "\t\t\t\t\t\tWrong password!" << endl;
				mysetcolor(7, 0);
			}
		}

		else if (person == 3) {
			cin.ignore();
			cin.clear();
			cout << "\t\t\t\t\t\tEnter your name : " << endl;
			string name = "";
			getline(cin, name);
			cout << "\t\t\t\t\t\tEnter password : " << endl;
			string password = "";
			getline(cin, password);
			if (name == "admin" && password == "easypeasy") {
				while (true)
				{


					cout << "Show Products ------ [1]" << endl;
					cout << "Add  Product  ------ [2] " << endl;
					cout << "Update Product ----- [3] " << endl;
					cout << "Exit --------------- [4] " << endl;
					cout << "Enter your choice : ";
					int choose = _getch();
					choose -= 48;
					system("cls");
					if (choose == 1) {
						cout << endl;
						obj.Show();
					}
					else if (choose == 2) {
						cout << endl;
						cout << "Enter name of product : ";
						string name = "";
						getline(cin, name);
						cout << "Enter count of product : ";
						int count = 0;
						cin >> count;
						Products productnew(name, count);
						stock.AddProduct(productnew);
						obj.AddProduct(productnew);
					}
					else if (choose == 3) {
						cout << endl;
						obj.Show();
						cout << "Enter product id (which you want to update)  : ";
						int id = 0;
						cin >> id;
						cout << endl;
						cout << "Name ----- [1]" << endl;
						cout << "Count ---- [2]" << endl;
						cout << "What do you want to change?";
						int change = _getch();
						change -= 48;
						if (change == 1) {
							cout << endl;
							cin.ignore();
							cin.clear();
							cout << "Enter new name : ";
							string newname = "";
							getline(cin, newname);
							obj.UpdateName(id, newname);


						}
						else if (change == 2) {
							cout << endl;
							cout << "Enter new count : ";
							int newcount = 0;
							cin >> newcount;
							stock.UpdateCount(id, newcount);
						}
						else {
							cout << "INVALID ENTRY!" << endl;
						}
					}
					else if (choose == 4) {
						cout << endl;
						break;
					}

				}
			}
			else {
				mysetcolor(4, 0);
				cout << "\t\t\t\t\t\tWrong name or password!" << endl;
			}
		}
		else if (person == 4) {
			DataWriteToFile("info.txt", (char)(table + 48) + string(". Table has closed the system"), __FILE__, __LINE__, __DATE__);
			system("cls");
			mysetcolor(14, 0);
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "                           ..|'''.|   ..|''||    ..|''||   '||''|.      '||''|.   '||' '|' '||''''|  " << endl;
			cout << "                          .|'     '  .|'    ||  .|'    ||   ||   ||      ||   ||    || |    ||  .    " << endl;
			cout << "                          ||    .... ||      || ||      ||  ||    ||     ||'''|.     ||     ||''|    " << endl;
			cout << "                          '|.    ||  '|.     || '|.     ||  ||    ||     ||    ||    ||     ||       " << endl;
			cout << "                           ''|...'|   ''|...|'   ''|...|'  .||...|'     .||...|'    .||.   .||.....| " << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			return;
		}
		else {
			mysetcolor(4, 0);
			cout << "\t\t\t\t\t\tINVALID ENTRY" << endl;
		}
	}
}
