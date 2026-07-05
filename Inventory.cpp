#include"Inventory.h"
#include<iostream>
#include <iomanip>
#include<fstream>
#include<format>
Inventory::Inventory(vector<unique_ptr<StockItem>>Stock) :
	Stock(move(Stock)) {
}
void Inventory::addItem(unique_ptr<StockItem>item) {
	Stock.push_back(move(item));
}
void Inventory::displayAll()const {
	for (const auto& I : Stock)
		cout << setw(30) << left << I->Afficher() << endl;
}
string Inventory::displayAllFichier()const {
	string resultat;
	for (const auto& I : Stock)
		resultat += I->Afficher();
	return resultat;
}
Concate Inventory::calculateTotalInventoryValue()const {
	double total = 0;
	for (const auto& I : Stock)
		total += I->calculateTotalValue();
	return { "le total de Stock est ",total };
}
void Inventory::UpdateStocks(int index, unique_ptr<StockItem> newItem) {
	if (index - 1 >= 0 && Stock.size() > index - 1)
		Stock[index - 1] = move(newItem);



}
Concate Inventory::UpdateCalculateInventoryValue()const {
	return this->calculateTotalInventoryValue();
}
void Inventory::FichierTXT()const {
	Concate Result = calculateTotalInventoryValue();
	ofstream text("Stock.txt", ios::app);
	if (text.is_open()) {
		text << "Touts Les Informations de Stock" << endl;
		text << "le total Stock Inventroy est :" << Result.Total << " DH " << endl;
		text << displayAllFichier();
		for (const auto& S : Stock) {
			text << "le total de stock est :" << S->calculateTotalValue() << " DH " << endl;
		}
		text.close();
		cout << "Succes!" << endl;
	}


}
void Inventory::FichierTXTUpdate()const {
	Concate Result = UpdateCalculateInventoryValue();
	ofstream text("Stock.txt", ios::out);
	if (text.is_open()) {
		text << "Touts Les Informations de Stock" << endl;
		text << "le total Stock Inventroy est :" << Result.Total << " DH " << endl;
		text << displayAllFichier();
		for (const auto& S : Stock) {
			text << "le total de stock est :" << S->calculateTotalValue() << " DH " << endl;
		}
		text.close();
		cout << "mise a jour est succes!";
	}
}


