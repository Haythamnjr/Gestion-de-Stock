#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#include <iostream>
#include "Inventory.h"
#include "Date.h"
#include "Exception.h"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	Inventory Stock;
	StockItem item;
	int quantite, id, jour, mois, annes, choix;
	bool ScanNom = true, ScanPrix = true, ScanQuantite = true, ScanId = true, ScanJour = true, ScanMois = true, Scananne = true;
	string nomProduit;
	double UnitPrice;
	while (true) {
		try {
			cout << YELLOW;
			cout << "===========================================" << endl;
			cout << "||        GESTION DE STOCK           ||" << endl;
			cout << "===========================================" << endl;
			cout << '\t' << "1) Entrer les infos" << endl;
			cout << '\t' << "2) Ajouter un produit" << endl;
			cout << '\t' << "3) Ajouter dans un fichier" << endl;
			cout << '\t' << "4) Afficher tout" << endl;
			cout << '\t' << "5) Mise a jour stock" << endl;
			cout << '\t' << "6) Mise a jour fichier" << endl;
			cout << '\t' << "7) Quitter" << endl;

			cout << "===========================================" << endl;
			cout << '\t' << "Choix : ";
			if (!(cin >> choix)) {
				throw Exception("Entrer un nombre entier!");
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			if (choix < 1 || choix > 7) {
				throw Exception("Entrer une seul choix compris entre 1 et 7!");
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			if (choix == 7) {
				cout << RESET << GREEN;
				cout << "Fin";
				cout << RESET;
				break;
			}
			cout << endl;

		}catch (const Exception& e) {
			cout << RED << e.what() << RESET << YELLOW << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		switch (choix) {
		case 1:
			ScanId = true;
			while (ScanId) {
				try {
					cout << "Entrer l'ID de cette Produit :";
					if (!(cin >> id)) {
						throw Exception("Entrer un Nombre!");
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					
					}
					if (cin.peek() == '.') {
						throw Exception("Entrer un nombre entier!");
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

					}
					item.setId(id);
					ScanId = false;

				}
				catch (const Exception& e) {
					cout << RED << e.what() << RESET << YELLOW << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

				}

			}
			ScanJour = true;
			while (ScanJour) {
				try {
					cout << endl;
					cout << "Entrer le jour de cette Produit :";
					if (!(cin >> jour)) {
						throw Exception("Entrer un Nombre!");
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					if (cin.peek() == '.') {
						throw Exception("Entrer un nombre qui no caractéristique par virgule!");
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					item.setDay(jour);
					ScanJour = false;

				}
				catch (const Exception& e) {
					cout << RED << e.what() << RESET << YELLOW << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

				}
			}
			ScanMois = true;
			while (ScanMois) {
				try {
					cout << endl;
					cout << "Entrer le mois de cette Produit :";
					if (!(cin >> mois)) {
						throw Exception("Entrer un Nombre!");
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					if (cin.peek() == '.') {
						throw Exception("Entrer un nombre qui no caractéristique par virgule!");
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					item.setMonth(mois);
					ScanMois = false;

				}
				catch (const Exception& e) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << RED << e.what() << RESET << YELLOW << endl;


				}
			}
			Scananne = true;
			while (Scananne) {
				try {
					cout << endl;
					cout << "Entrer l'année de cette Produit :";
					if (!(cin >> annes)) {
						throw Exception("Entrer un Nombre!");
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					if (cin.peek() == '.') {
						throw Exception("Entrer un nombre qui no caractéristique par virgule!");
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					item.setYear(annes);
					Scananne = false;
				}
				catch (const Exception& e) {
					cout << RED << e.what() << RESET << YELLOW << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');



				}
				cout << endl;
				cin.ignore();
				cout << "Entrer le nom de Produit :";
				getline(cin, nomProduit);
				item.setNomProduit(nomProduit);
				cout << endl;
				ScanQuantite = true;
				while (ScanQuantite)
				{
					try {
						cout << "Entrer la quantite de cette Produit :";
						cin >> quantite;
						if (cin.peek() == '.') {
							throw Exception("Entrer un nombre qui no caractéristique par virgule!");
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						item.setQuantite(quantite);
						ScanQuantite = false;

					}
					catch (const Exception& e) {
						cout << RED << e.what() << RESET << YELLOW << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
				cout << endl;
				cout << "Entrer le Prix de cette Produit :";
				cin >> UnitPrice;
				item.setunite(UnitPrice);
				cout << endl;
				break;

			
				break;
		case 2:
			cout << GREEN;
			Stock.addItem(make_unique<StockItem>(jour, mois, annes, quantite, id, nomProduit, UnitPrice));
			Stock.calculateTotalInventoryValue();
			break;
		case 3:
			cout << GREEN;
			Stock.FichierTXT();
			break;
		case 4:
			cout << GREEN;
			Stock.displayAll();
			cout << "Les informations sont Ajoutées avec succès";
			cout << endl;
			break;
		case 5:
			cout << RESET << YELLOW;
			cout << "Entrer id de produit pour mise a jour :";
			cin >> id;
			cout << endl;
			cout << "Entrer le nom de produit pour mise a jour :";
			cin >> nomProduit;
			cout << endl;
			cout << "Entrer la quantite de produit pour mise a jour :";
			cin >> quantite;
			cout << endl;
			cout << "Entrer le prix de produit pour mise a jour :";
			cin >> UnitPrice;
			Stock.UpdateStocks(id, move(make_unique<StockItem>(jour, mois, annes, quantite, id, nomProduit, UnitPrice)));
			Stock.UpdateCalculateInventoryValue();
			cout << RESET << GREEN;
			cout << "misa a jour est reussir";
			break;

		}

		}

	}
}