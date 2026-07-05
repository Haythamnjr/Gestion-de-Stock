#include "StockItem.h"
#include<iostream>
#include "Exception.h"
#include<cmath>
#include<format>
#include<cctype>
#include<algorithm>
using namespace std;

StockItem::StockItem(int Day , int Month , int Year ,int quantite,int id,string NomProduit,double unitPrice) :
	Date(Day, Month, Year), quantite(quantite) ,id(id), NomProduit(NomProduit), unitPrice(unitPrice) { }
int StockItem::getId()const {
	return this->id;
}
void StockItem::setId(int id) {
	if (id < 0) {
		throw Exception("Entrer un nombre positif!");
		return;
	}
	else if (getId() == id) {
		throw Exception("le id de produit existe deja!");
		return;
	}
	this->id = id;
}


int StockItem::getQuantite()const {
	return this->quantite;
}
void StockItem::setQuantite(int Quan) {
	if (Quan < 0) {
		throw Exception("Entrer un nombre positif!");
		return;
	 }
	this->quantite = Quan;
}
string StockItem::getNomProduit()const {
	return this->NomProduit;
}
void StockItem::setNomProduit(string Nom) {
	bool Scan = all_of(Nom.begin(), Nom.end(), [](unsigned char c) {
		return isspace(c) || iscsym(c);
		});
	if (!Scan) {
		throw Exception("Entrer le nom de produit utilise les nombres est espace est Symbole!");
		return;
	}

	this->NomProduit = Nom;
}
double StockItem::getunite() const {
	return this->unitPrice;
}

void StockItem::setunite(double unit) {
	if (unit < 0) {
		throw Exception("Entrer le prix qui Positive!");
		return;
	}
	this->unitPrice = unit;
}

double StockItem:: calculateTotalValue()const{
	return this->getQuantite() * this->getunite();

}

void StockItem::updateStock(string NomProduit,int newQuantity, double newPrice) {
	this->NomProduit = NomProduit;
	this->quantite = newQuantity;
	this->unitPrice = newPrice;


}

double StockItem::updateCalculeValue()const {
	return this->calculateTotalValue();
}
string StockItem::Afficher() const{
	return format("id de cette Produit est :{} |le nom de produit est :{} | la quantite de cette produit :{} | le prix de cette produit est :{} DH | La date est : {}/{}/{}" , this->id ,this->NomProduit , this->quantite , this->unitPrice,this->getDay(),this->getMonth(),this->getYear());
}

