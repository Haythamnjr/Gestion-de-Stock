#ifndef INVENTORY_H
#define INVENTORY_H
#include "StockItem.h"
#include "Date.h"
#include<iostream>
#include<memory>
#include<vector>

struct Concate {
	string Chaine;
	double Total;
};

class Inventory {
private:
	vector<unique_ptr<StockItem>>Stock;
public:
	Inventory(vector<unique_ptr<StockItem>>Stock);
	Inventory() = default;
	void addItem(unique_ptr<StockItem>item);
	void displayAll()const;
	string displayAllFichier()const;
	void FichierTXT()const;
	void FichierTXTUpdate()const;
	Concate calculateTotalInventoryValue()const;
	void UpdateStocks(int index , unique_ptr<StockItem> newItem);
	Concate UpdateCalculateInventoryValue()const;


};

#endif
