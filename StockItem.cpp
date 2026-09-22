#include "StockItem.h"
#include "Date.h"
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
	try {
		unique_ptr<sql::PreparedStatement>stmtUp(
			data->prepareStatement("UPDATE Stock SET Quantite = ?,NomProduit = ?,unitPrice = ? WHERE id = ?")
		);

		stmtUp->setInt(1, newQuantity);
		stmtUp->setString(2, NomProduit);
		stmtUp->setDouble(3, newPrice);
		stmtUp->setInt(4, this->getId());
		stmtUp->executeUpdate();

	}
	catch (sql::SQLException& e) {
		cerr << "Le mise a jour est echec :" << e.what() << endl;
		cerr << "SQLState" << e.getSQLState() << endl;
		cerr << "Code Erreur" << e.getErrorCode() << endl;
	}


}

double StockItem::updateCalculeValue()const {
	return this->calculateTotalValue();
}

bool StockItem::DataStock()const {
	try {
		unique_ptr<sql::PreparedStatement>stmt(
			data->prepareStatement("INSERT INTO Stock(id,Quantite,NomProduit,unitPrice) VALUES(?,?,?,?)")
		);
		stmt->setInt(1, this->getId());
		stmt->setInt(2, this->getQuantite());
		stmt->setString(3, this->getNomProduit());
		stmt->setDouble(4, this->getunite());
		stmt->execute();
		cout << "Les donnes est Enregistre" << endl;
		return true;

	}
	catch (sql::SQLException& e) {
		cerr << "Probleme :" << e.what() << endl;
		return false;
	}
}

string StockItem::Afficher() const{
	return format("id de cette Produit est :{} |le nom de produit est :{} | la quantite de cette produit :{} | le prix de cette produit est :{} DH | La date est : {}/{}/{}" , this->id ,this->NomProduit , this->quantite , this->unitPrice,this->getDay(),this->getMonth(),this->getYear());
}

