#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <assert.h>
#include<fstream>
#include <Windows.h>
using namespace std;


template<typename T>
class Stack {
	T* data;
	size_t size = 0;
public:
	Stack() :data(NULL), size(NULL) {}
	void Push(const T& newdata) {
		auto newarray = new T[size + 1]{};
		for (size_t i = 0; i < size; i++)
		{
			newarray[i] = data[i];
		}
		newarray[size] = newdata;
		/*if (size != 0) {
			delete[]data;
		}*/
		data = newarray;
		newarray = nullptr;
		++size;
	}
	T Pop() {
		assert(size > 0 && "Empty Stack");
		auto newarray = new T[size - 1]{};
		for (size_t i = 0; i < size - 1; i++)
		{
			newarray[i] = data[i];
		}
		T last = data[size - 1];
		if (size != 0) {
			delete[]data;
		}
		data = newarray;
		newarray = nullptr;
		--size;
		return last;
	}


	void DeleteByIndex(int& index) {
		assert(size > 0 && "Empty Stack");

		auto newarray = new T[size - 1]{};
		for (size_t i = 0; i < index; i++)
		{
			newarray[i] = data[i];
		}
		for (size_t i = index; i < size - 1; i++)
		{
			newarray[i] = data[i + 1];
		}
		if (size != 0) {
			delete[]data;
		}
		data = newarray;
		newarray = nullptr;
		--size;

	}
	T Peek()const {
		assert(size > 0 && "Empty Stack");
		return data[size - 1];
	}
	void Clear() {
		if (this->data == NULL || this->size == NULL) {
			return;
		}
		delete[]data;
		this->data = NULL;
		this->size = NULL;
	}
	void Show() const {
		for (size_t i = 0; i < size; i++)
		{
			cout << data[i] << endl;
		}
	}
	size_t GetSize()const {
		return size;
	}
	void SetSize(const int& size) {
		this->size = size;
	}
	T& operator[](int index) {
		return data[index];
	}
	~Stack()
	{
		//delete[]data;
	}
};

class Exception {
protected:
	string text;
	string source;
	int line;
	string date;
public:
	Exception(const string& text, const string& source
		, const int& line, const string& date)
		:text(text), source(source), line(line), date(date)
	{
	}
#pragma region Setters

	void SetText(const string& text) {
		this->text = text;
	}
	void SetSource(const string& source) {
		this->source = source;
	}
	void SetLine(const int& line) {
		this->line = line;
	}
	void SetDate(const string& date) {
		this->date = date;
	}

#pragma endregion

#pragma region Getters
	string GetText()const {
		return text;
	}
	string GetSource()const {
		return source;
	}
	int GetLine()const {
		return line;
	}
	string GetDate()const {
		return date;
	}
#pragma endregion

	void PrintMessage()const {
		cout << "++++++++++ERROR INFO+++++++++" << endl;
		cout << "Error content : " << text << endl;
		cout << "Source : " << source << endl;
		cout << "Line number : " << line << endl;
		cout << "Date : " << date << endl;
	}
};

class InvalidArgumentException :public Exception {
public:
	InvalidArgumentException(const string& text, const string& source
		, const int& line, const string& date)
		:Exception(text, source, line, date)
	{
	}


};

class InvalidStringException :public Exception {
public:
	InvalidStringException(const string& text, const string& source
		, const int& line, const string& date)
		:Exception(text, source, line, date)
	{
	}


};


class Products {
	string name;
	double count;
public:
	Products() = default;
	Products(const string& name, const int& count)
	{
		SetName(name);
		SetCount(count);
	}
#pragma region Setters
	void SetName(const string& name) {
		if (name.empty()) {
			throw InvalidStringException("Name must not be empty",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->name = name;
		}
	}
	void SetCount(const double& count) {
		if (count < 0) {
			throw InvalidArgumentException("Count must be greater than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->count = count;
		}
	}

#pragma endregion
#pragma region Getters
	double GetCount()const {
		return count;
	}
	string GetName()const {
		return name;
	}

#pragma endregion

	void Show() {
		cout << "Product : " << GetName() << " " << GetCount() << " (count,port.,sp.)" << endl;
	}

};
class Meals {
	Stack<Meals>meals;
protected:
	string name;
	double price;
public:
	Meals() = default;
	Meals(const string& name, const double& price)
	{
		SetName(name);
		SetPrice(price);
	}

#pragma region Setters
	void SetName(const string& name) {
		if (name.empty()) {
			throw InvalidStringException("Name must not be empty",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->name = name;
		}
	}
	void SetPrice(const double& price) {
		if (price < 0) {
			throw InvalidArgumentException("Price must be greater than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->price = price;
		}
	}
	void AddMeal(Meals& meal) {
		meals.Push(meal);
	}
#pragma endregion

#pragma region Getters
	string GetName()const {
		return name;
	}
	double GetPrice()const {
		return price;
	}
#pragma endregion

	void Show() {
		cout << "Name : " << name << endl;
		cout << "Price : " << price << endl;
	}
	void ShowAll() {
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			cout << i + 1 << ") ";
			meals[i].Show();
		}
	}
	string text = "";
	//auto Search(const string& text) {
	//	int length = text.length();
	//	int index = 0;
	//	for (size_t i = 0; i < meals.GetSize(); i++)
	//	{
	//		for (size_t k = 0; k < meals[i].GetName().length(); k++)
	//		{
	//			auto some = meals[i].GetName().substr(k, length);
	//			if (meals[i].GetName().substr(k, length) == text) {
	//				return meals[i].GetName();
	//				//break;
	//			}
	//		}
	//	}
	//	return string("");
	//}

	void Search(const string& text) {
		int length = text.length();
		int index = 0;
		int counter = 0;
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			for (size_t k = 0; k < meals[i].GetName().length(); k++)
			{
				auto some = meals[i].GetName().substr(k, length);
				if (meals[i].GetName().substr(k, length) == text) {
					++counter;
					cout << ++index << " )";
					cout << meals[i].GetName() << endl;
					break;
				}
			}
		}
		if (counter == 0) {

			cout << "Meal could not found" << endl;
		}
	}



};

class Ingredients {
private:
public:
	string name;
	double calories;
	double count;
	double price;
	Ingredients() = default;
	Ingredients(const string& name, const double& calories, const double& count)
	{
		SetName(name);
		SetCalories(calories);
		SetCount(count);
	}
#pragma region Getters

	double GetCount()const {
		return count;
	}
	double GetPrice()const {
		return price;
	}
#pragma endregion

#pragma region Setters


	void SetName(const string& name) {
		if (name.empty()) {
			throw InvalidStringException("Name must not be empty",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->name = name;
		}
	}
	void SetCalories(const double& calories) {
		if (calories < 0) {
			throw InvalidArgumentException("Calory must be greater than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->calories = calories;
		}
	}
	void SetCount(const double& count) {
		if (count < 0) {
			throw InvalidArgumentException("Count must be greater than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->count = count;
		}
	}
	void SetPrice(const double& price) {
		if (price < 0) {
			throw InvalidArgumentException("Price must be greater than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {

			this->price = price;
		}
	}

#pragma endregion
	void Show() {
		cout << "Name of Ingredient: " << name << endl;
		cout << "Calories : " << calories << endl;
		cout << "Count/Portion/Spoon : " << count << endl;
	}
};
class Specials {
	Stack<Specials>specials;
	string name;
	int count;
	double price;
	double total = 0;
public:
	Specials() = default;
	Specials(const string& name, const int& count, const double& price)
	{
		SetName(name);
		SetCount(count);
		SetPrice(price);
	}
#pragma region Setters


	void SetName(const string& name) {
		if (name.empty()) {
			throw InvalidStringException("Name must not be empty",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->name = name;
		}
	}
	void SetCount(const int& count) {
		if (count < 0) {
			throw InvalidArgumentException("Count must be greater than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->count = count;
		}
	}
	void SetPrice(const double& price) {
		if (price < 0) {
			throw InvalidArgumentException("Price must be greater than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->price = price;
		}
	}


	void SetTotalPrice(const double& price) {
		if (price == 0) {
			total = 0;
		}
		else {
			total += price;
		}
		this->price = total;
	}



#pragma endregion

	double GetTotalPrice() {
		return total;
	}

#pragma region Getters


	string GetName()const {
		return name;
	}
	int GetCount()const {
		return count;
	}

	double GetPrice()const {
		return price;

	}

#pragma endregion
	double Total() {
		double total = 0;
		for (size_t i = 0; i < specials.GetSize(); i++)
		{
			total += specials[i].GetPrice();
		}
		return total;
	}

	void Clear() {
		for (size_t i = 0; i < specials.GetSize(); i++)
		{
			specials[i].SetPrice(0);
		}
	}


	void Show() {
		cout << "Name of Special: " << name << endl;
		cout << "Count : " << count << endl;
		cout << "Price : " << price << endl;
	}

	void Add(const Specials& special) {
		specials.Push(special);
		SetCount(++count);
	}
	double GetSpecialPrice() {
		double specialprice = 0;
		for (size_t i = 0; i < specials.GetSize(); i++)
		{
			specialprice += specials[i].GetPrice();
		}
		return specialprice;
	}



};
class MixedPizza :public Meals {
private:
	Stack<Ingredients>ingredients;
	Stack<Specials>specials;
public:
	MixedPizza() = default;
	MixedPizza(const string& name, const double& price)
		:Meals(name, price) {}

	void AddIng(Ingredients& ing) {
		ingredients.Push(ing);
	}
	void AddSpecials(Specials& special) {
		specials.Push(special);
	}
	void ShowName() {
		Meals::Show();
	}
	void Show() {
		int total = 0;
		Meals::Show();
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			ingredients[i].Show();
			total += ingredients[i].calories;
		}
		if (total != 0) {
			cout << "You will gain : " << total << " calories" << endl;

		}

	}
	double GetSpecialPrice() {
		double specialprice = 0;
		for (size_t i = 0; i < specials.GetSize(); i++)
		{
			specialprice += specials[i].GetPrice();
		}
		return specialprice;
	}

};
class ChickenRanch :public Meals {
private:
	Stack<Ingredients>ingredients;
	Stack<Specials>specials;
public:
	ChickenRanch() = default;
	ChickenRanch(const string& name, const double& price)
		:Meals(name, price) {}
	void AddIng(Ingredients& ing) {
		ingredients.Push(ing);
	}
	void AddSpecials(Specials& special) {
		specials.Push(special);
	}
	void ShowName() {
		Meals::Show();
	}
	void Show() {
		int total = 0;
		Meals::Show();
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			ingredients[i].Show();
			total += ingredients[i].calories;
		}
		if (total != 0) {
			cout << "You will gain : " << total << " calories" << endl;

		}

	}
	double GetSpecialPrice() {
		double specialprice = 0;
		for (size_t i = 0; i < specials.GetSize(); i++)
		{
			specialprice += specials[i].GetPrice();
		}
		return specialprice;
	}
};
class Dolma :public Meals {
private:
	Stack<Ingredients>ingredients;
	Stack<Specials>specials;
public:
	Dolma() = default;
	Dolma(const string& name, const double& price)
		:Meals(name, price) {}
	void AddIng(Ingredients& ing) {
		ingredients.Push(ing);
	}
	void AddSpecials(Specials& special) {
		specials.Push(special);
	}
	void ShowName() {
		Meals::Show();
	}

	void Show() {
		int total = 0;
		Meals::Show();
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			ingredients[i].Show();
			total += ingredients[i].calories;
		}
		if (total != 0) {
			cout << "You will gain : " << total << " calories" << endl;

		}

	}
	double GetSpecialPrice() {
		double specialprice = 0;
		for (size_t i = 0; i < specials.GetSize(); i++)
		{
			specialprice += specials[i].GetPrice();
		}
		return specialprice;
	}
};

//class Orders {
// int table1;
// int table2;
// int table3;
// int table4;
// int table5;
// Stack<Notifications>notifications;
//public:
// //Notifications notif;
//#pragma region Getters
// int GetFirst()const {
// return table1;
// }
// int GetSecond()const {
// return table2;
// }
// int GetThird()const {
// return table3;
// }
// int GetFourth()const {
// return table4;
// }
// int GetFifth()const {
// return table5;
// }
//#pragma endregion
//
//#pragma region Setters
// void SetFirst(const int& table1) {
// this->table1 = table1;
// }
// void SetSecond(const int& table2) {
// this->table2 = table2;
// }
// void SetThird(const int& table3) {
// this->table3 = table3;
// }
// void SetFourth(const int& table4) {
// this->table4 = table4;
// }
// void SetFifth(const int& table5) {
// this->table5 = table5;
// }
//#pragma endregion
//
//
// Orders() = default;
// void AddNotification(const Notifications&notification) {
// notifications.Push(notification);
// }
//
// void AddCount(const int& table) {
// }
//};
class Notifications {
public:
	string message;
	int notification;
	int GetNotification() const {
		return notification;
	}
	void SetMessage(const string& message) {
		this->message = message;


	}
	void SetNotification(const int& notification) {
		if (notification < 0) {
			throw InvalidStringException("Notification must not be less than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->notification = notification;
		}

	}
	string GetMessage() const {
		return message;
	}
	void Add() {
		++notification;
	}
	Notifications() = default;
	Notifications(const int& notification)
	{
		this->notification = notification;
	}
	Notifications(const int& notification, const string& message) {
		this->notification = notification;
		this->message = message;
	}
	void ShowNote() {
		cout << "(" << notification << ")";
	}

	friend ostream& operator<<(ostream& out, const Notifications& notifications);
	void Show() {
		cout << "Message : " << message << endl;
	}


};
class Client {
	Stack<Notifications>notifications;
	Stack<Client>clients;
	int table;
	string name;
	int count;
public:
	Notifications notification;
	Client() = default;
	Client(const int& table)
	{
		SetTable(table);
	}
	Client(const int& table, const string& name, const int& count)
	{
		SetTable(table);
		SetName(name);
		SetCount(count);
	}
#pragma region Setters

	void SetTable(const int& table) {
		if (table < 1 || table>5) {
			throw InvalidArgumentException("Table must be between 1 and 5",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->table = table;
		}

	}
	void SetName(const string& name) {
		this->name = name;


	}
	void SetCount(const int& count) {
		if (count < 0) {
			throw InvalidArgumentException("Count must be greater than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->count = count;
		}

	}
#pragma endregion

#pragma region Getters

	int GetTable() const {
		return table;
	}
	string GetName()const {
		return name;
	}
	int GetCount()const {
		return count;
	}
#pragma endregion

	void AddNotification(const Notifications& notification) {
		notifications.Push(notification);
	}
	void ShowNotification(Client& client) {
		client.notifications.Show();
	}
	void DeleteNotification(Client& client) {
		client.notifications.Clear();
	}
	void AddClient(const Client& client) {
		int size = clients.GetSize();
		if (size != 0) {
			for (size_t i = 0; i < size; i++)
			{
				if (client.GetTable() == clients[i].GetTable() && client.GetName() == clients[i].GetName()) {
					clients[i].SetCount(client.GetCount());
					break;
				}
				else {
					clients.Push(client);
					break;
				}
			}
		}
		else {
			clients.Push(client);
		}

	}

	void findtable(Client& client, const int& table) {
		if (client.GetTable() == table) {
			cout << ++client.notification.notification;
		}
		else {
			cout << 0;
		}
	}
	void Show() {
		if (table != NULL) {

			cout << "Table : " << table;
		}
		if (!name.empty()) {
			cout << " Name : " << name;
		}
		if (count != NULL) {
			cout << " Count : " << count;
		}
		else {
			cout << "" << endl;
		}
		cout << endl;
	}

	friend ostream& operator<<(ostream& out, const Client& client);

};

ostream& operator<<(ostream& out, const Client& client) {
	cout << "Table : " << client.table << endl;
	cout << " Name : " << client.name << endl;
	cout << " Count : " << client.count << endl;
	return out;
}

ostream& operator<<(ostream& out, const Notifications& notifications) {
	out << "Message : " << notifications.message << endl;
	return out;
}

class Table1 {
	Stack<Notifications>notifications;
	Stack<Specials>specials;
	int notif;
	string message;
	int count;
	string name;
public:
	int GetNotif()const {
		return notif;
	}
	int GetCount()const {
		return count;
	}
	string GetName()const {
		return name;
	}
	void SetNotif(const int& notif) {
		if (notif < 0) {
			throw InvalidStringException("Notification must not be less than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->notif = notif;
		}
	}
	void SetCount(const int& count) {
		this->count = count;
	}
	void SetName(const string& name) {
		this->name = name;
	}

	string GetMessage() const {
		return message;
	}

	void SetMessage(const string& message) {
		this->message = message;
	}
	Table1() = default;
	Table1(const int& notif) {
		SetNotif(notif);
	}

	void AddNotification(const Notifications& notification) {
		notifications.Push(notification);
	}
	void Show() {
		cout << "Notification : " << message << endl;
		cout << "Order Name : " << name << endl;
		cout << "Order Count : " << count << endl;
		for (size_t i = 0; i < specials.GetSize(); i++)
		{
			cout << "Special Name : " << specials[i].GetName() << endl;
			cout << "Special Count : " << specials[i].GetCount() << endl;
		}
	}


};
class Table2 {
	Stack<Notifications>notifications;
	int notif;
	string message;
	int count;
	string name;
public:
	int GetNotif()const {
		return notif;
	}
	void SetNotif(const int& notif) {
		if (notif < 0) {
			throw InvalidStringException("Notification must not be less than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->notif = notif;
		}
	}

	Table2() = default;
	Table2(const int& notif) {
		SetNotif(notif);
	}

	string GetMessage() const {
		return message;
	}
	int GetCount()const {
		return count;
	}
	string GetName()const {
		return name;
	}
	void SetCount(const int& count) {
		this->count = count;
	}
	void SetName(const string& name) {
		this->name = name;
	}
	void SetMessage(const string& message) {
		this->message = message;
	}

	void AddNotification(const Notifications& notification) {
		notifications.Push(notification);
	}
	void Show() {
		cout << "Notification : " << message << endl;
		cout << "Order Name : " << name << endl;
		cout << "Order Count : " << count << endl;
	}


};
class Table3 {
	Stack<Notifications>notifications;
	int notif;
	string message;
	int count;
	string name;
public:
	int GetNotif()const {
		return notif;
	}
	void SetNotif(const int& notif) {
		if (notif < 0) {
			throw InvalidStringException("Notification must not be less than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->notif = notif;
		}
	}

	Table3() = default;
	Table3(const int& notif) {
		SetNotif(notif);
	}

	void AddNotification(const Notifications& notification) {
		notifications.Push(notification);
	}

	string GetMessage() const {
		return message;
	}

	void SetMessage(const string& message) {
		this->message = message;
	}
	int GetCount()const {
		return count;
	}
	string GetName()const {
		return name;
	}
	void SetCount(const int& count) {
		this->count = count;
	}
	void SetName(const string& name) {
		this->name = name;
	}
	void Show() {
		cout << "Notification : " << message << endl;
		cout << "Order Name : " << name << endl;
		cout << "Order Count : " << count << endl;
	}
};
class Table4 {
	Stack<Notifications>notifications;
	int notif;
	string message;
	int count;
	string name;
public:
	int GetNotif()const {
		return notif;
	}
	void SetNotif(const int& notif) {
		if (notif < 0) {
			throw InvalidStringException("Notification must not be less than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->notif = notif;
		}
	}

	Table4() = default;
	Table4(const int& notif) {
		SetNotif(notif);
	}

	string GetMessage() const {
		return message;
	}
	int GetCount()const {
		return count;
	}
	string GetName()const {
		return name;
	}
	void SetCount(const int& count) {
		this->count = count;
	}
	void SetName(const string& name) {
		this->name = name;
	}
	void SetMessage(const string& message) {
		this->message = message;
	}

	void AddNotification(const Notifications& notification) {
		notifications.Push(notification);
	}
	void Show() {
		cout << "Notification : " << message << endl;
		cout << "Order Name : " << name << endl;
		cout << "Order Count : " << count << endl;
	}


};
class Table5 {
	Stack<Notifications>notifications;
	int notif;
	string message;
	int count;
	string name;
public:
	int GetNotif()const {
		return notif;
	}
	int GetCount()const {
		return count;
	}
	string GetName()const {
		return name;
	}
	void SetCount(const int& count) {
		this->count = count;
	}
	void SetName(const string& name) {
		this->name = name;
	}
	void SetNotif(const int& notif) {
		if (notif < 0) {
			throw InvalidStringException("Notification must not be less than zero",
				__FILE__, __LINE__, __DATE__);
		}
		else {
			this->notif = notif;
		}
	}

	Table5() = default;
	Table5(const int& notif) {
		SetNotif(notif);
	}

	void AddNotification(const Notifications& notification) {
		notifications.Push(notification);
	}

	void Show() {
		cout << "Notification : " << message << endl;
		cout << "Order Name : " << name << endl;
		cout << "Order Count : " << count << endl;
	}

	string GetMessage() const {
		return message;
	}

	void SetMessage(const string& message) {
		this->message = message;
	}


};

class Kitchen {
	Stack<Client>clients;
	Stack<Notifications>notifications;
	Stack<Meals>meals;
	Stack<Specials>specials;
	string name;
	int count;
	int table;
	int mixCount;
	int chickCount;
	int dolmaCount;
	double mixPrice;
	double chickPrice;
	double dolmaPrice;
public:
	int totalmix = 0;
	int totalchick = 0;
	int totaldolma = 0;

#pragma region Getters


	int GetMixCount()const {
		return mixCount;
	}
	int GetChickCount()const {
		return chickCount;
	}
	int GetDolmaCount()const {
		return dolmaCount;
	}
	int GetTable() {
		return table;
	}

	double GetMixPrice()const {
		return mixPrice;
	}
	double GetChickPrice()const {
		return chickPrice;
	}
	double GetDolmaPrice()const {
		return dolmaPrice;
	}
	double GetTotalPrice()const {
		return GetMixPrice() + GetChickPrice() + GetDolmaPrice();
	}


#pragma endregion
#pragma region Setters

	void SetTable(const int& table) {
		this->table = table;
	}
	void SetMixCount(const int& mixCount) {
		this->mixCount = mixCount;
	}
	void SetChickCount(const int& chickCount) {
		this->chickCount = chickCount;
	}
	void SetDolmaCount(const int& dolmaCount) {
		this->dolmaCount = dolmaCount;
	}

	void SetMixPrice(const double& mixPrice) {
		this->mixPrice = mixPrice;
	}
	void SetChickPrice(const double& chickPrice) {
		this->chickPrice = chickPrice;
	}
	void SetDolmaPrice(const double& dolmaPrice) {
		this->dolmaPrice = dolmaPrice;
	}
#pragma endregion
	Kitchen() = default;
	Kitchen(const int& mixCount, const int& chickCount, const int& dolmaCount, const double& mixPrice, const double& chickPrice, const double& dolmaPrice)
	{
		this->mixCount = mixCount;
		this->chickCount = chickCount;
		this->dolmaCount = dolmaCount;
		this->mixPrice = mixPrice;
		this->chickPrice = chickPrice;
		this->dolmaPrice = dolmaPrice;
	}
	void SetTotalprice(const double& mixPrice, const double& chickPrice, const double& dolmaPrice) {
		this->mixPrice = mixPrice;
		this->chickPrice = chickPrice;
		this->dolmaPrice = dolmaPrice;
	}

	void AddClient(const Client& client) {
		int size = clients.GetSize();
		if (size != 0) {
			for (size_t i = 0; i < size; i++)
			{
				if (client.GetTable() == clients[i].GetTable() && client.GetName() == clients[i].GetName()) {
					int newcount = clients[i].GetCount() + client.GetCount();
					clients[i].SetCount(newcount);
					break;
				}
				else {
					clients.Push(client);
					break;
				}
			}
		}
		else {
			clients.Push(client);
		}

	}


	void AddNotification(Notifications& notification) {
		notifications.Push(notification);
	}

	void ShowOrders() {
		int countmix = 0;
		for (size_t i = 0; i < clients.GetSize(); i++)
		{
		}
		cout << "Mixed Pizza : " << totalmix << endl;
		cout << "ChichkenRanch Pizza : " << totalchick << endl;
		cout << "Dolma : " << totaldolma << endl;
	}

	void Show() {
		for (size_t i = 0; i < clients.GetSize(); i++)
		{
			cout << "[" << i + 1 << "]";
			clients[i].Show();
		}
	}

	int GetTableById(int& id) {
		int temp = id - 1;
		for (size_t i = 0; i < clients.GetSize(); i++)
		{
			if (temp == i) {
				return clients[i].GetTable();
			}
		}
	}

	string GetNameById(int& id) {
		int temp = id - 1;
		for (size_t i = 0; i < clients.GetSize(); i++)
		{
			if (temp == i) {
				return clients[i].GetName();
			}
		}

	}

	Client GetClientById(int& id) {
		int temp = id - 1;
		for (size_t i = 0; i < clients.GetSize(); i++)
		{
			if (temp == i) {
				return clients[i];
			}
		}
	}

	void DeleteClientById(int& id) {
		int temp = id - 1;
		if (clients.GetSize() == 1) {
			for (size_t i = 0; i < clients.GetSize(); i++)
			{
				clients.Clear();
			}
		}
		else {

			clients.DeleteByIndex(temp);
		}
	}

	int GetClientsSize() {
		return clients.GetSize();
	}

	void Some() {
		int* arr = new int[100] {};
		for (size_t i = 0; i < clients.GetSize(); i++)
		{
			arr[i] = i + 1;
		}
	}


};


class Stock {
	string name;
	int count;
public:
	Stack<Products>products;
	Stock() = default;
	Stock(const string& name) {
		SetName(name);
	}
	void Show() {
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			cout << i + 1 << ") ";
			products[i].Show();
		}
	}
	void SetName(const string& name) {
		this->name = name;
	}
	string GetName()const {
		return name;
	}
	void SetCount(const int& count) {
		this->count = count;
	}
	int GetCount()const {
		return count;
	}
	void AddProduct(const Products& product) {
		products.Push(product);
		SetCount(++count);
	}
	bool ShowAvailability(Ingredients& ing) {
		int size = products.GetSize();
		for (size_t i = 0; i < size; i++)
		{
			if (products[i].GetName() == ing.name) {
				if (products[i].GetCount() >= ing.count) {

					return true;
				}
			}
		}
		return false;
	}

	auto Shortage(const Ingredients& ing) {
		int k = 0;
		string* myarray = new string[k + 1]{};
		int size = products.GetSize();
		for (size_t i = 0; i < size; i++)
		{
			if (products[i].GetName() == ing.name) {
				if (products[i].GetCount() >= ing.count) {

					myarray[k] = products[i].GetName();
					++k;
				}
			}
		}
		return myarray;
	}

	void DecreaseProduct(Ingredients& ing) {
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			if (products[i].GetName() == ing.name) {
				if (products[i].GetCount() >= ing.count) {
					double count = products[i].GetCount();
					count -= ing.count;
					products[i].SetCount(count);
				}
			}
		}

	}

	void DecreaseSpecials(Specials& special) {
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			if (products[i].GetName() == special.GetName()) {
				if (products[i].GetCount() >= special.GetCount()) {
					double count = products[i].GetCount();
					count -= special.GetCount();
					products[i].SetCount(count);
				}
			}
		}

	}
	Products* GetProductbyId(const int& id) {
		int temp = id - 1;
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			if (temp == i) {
				return &products[i];
			}
		}
		return nullptr;
	}


	void UpdateName(const int& id, const string& name) {
		auto current = GetProductbyId(id);
		if (current != nullptr) {
			current->SetName(name);
			cout << "Product Name is updated successfully!" << endl;
		}
		else {
			cout << "Invalid Product Name! " << endl;
		}
	}

	void UpdateCount(const int& id, const int& count) {
		auto current = GetProductbyId(id);
		if (current != NULL) {
			current->SetCount(count);
			cout << "Product Count is updated sucessfully!" << endl;
		}
		else {
			cout << "Invalid Product Count!" << endl;
		}
	}

};
#include <stdio.h>
class FileHelper {

public:
	static string filename;

	static void Save(Stock& stock) {
		remove("stock.txt");
		ofstream fout(filename, ios::app);
		if (fout.is_open()) {
			fout << stock.GetCount() << endl;
			for (size_t i = 0; i < stock.products.GetSize(); i++)
			{
				fout << stock.products[i].GetName() << " " << stock.products[i].GetCount() << endl;
			}
			fout.close();
		}

	}

	static Stock Read() {
		Stock stock;

		ifstream fin(filename);
		int stocksize;
		fin >> stocksize;
		if (fin.is_open()) {
			for (size_t i = 0; i < stocksize; i++)
			{
				Products p;
				string name;
				double count;

				fin >> name;
				fin >> count;

				p.SetName(name);
				p.SetCount(count);
				stock.AddProduct(p);

			}
			fin.close();

			return stock;
		}

	}

};



string FileHelper::filename = "stock.txt";




