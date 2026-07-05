#ifndef STOCKITEM_H
#define STOCKITEM_H
#include<iostream>
#include<string>
#include "Date.h"
using namespace std;

class StockItem:public Date {
private:
	
	int quantite = 0 , id = 0;
	string NomProduit = "";
	double unitPrice = 0;
public:
	StockItem(int Day, int Month, int Year,int quantite , int id, string NomProduit,double unitPrice);
	StockItem() = default;
	int getId()const;
	void setId(int id);
	int getQuantite() const;
	void setQuantite(int Quan);
	string getNomProduit()const;
	void setNomProduit(string Nom);
	double getunite() const;
	void setunite(double unit);
	virtual double calculateTotalValue()const;
	virtual double updateCalculeValue()const;
	virtual void updateStock(string NomProduit,int newQuantity, double newPrice);
	virtual string Afficher()const;


};

#endif // STOCKITEM_H

