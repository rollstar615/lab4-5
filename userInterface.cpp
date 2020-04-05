//
//  userInterface.cpp
//  laborator
//
//  Created by Rolland Koszta on 05/04/2020.
//  Copyright © 2020 Rolland Koszta. All rights reserved.
//

#include <stdio.h>
#include "userInterface.h"


UserInterface::UserInterface() {}

void UserInterface::addFilm()
{
    char titlu[50], gen[50];
    int zi, luna, an;
    cout << "TITLU ESTE ";
    cin >> titlu;
    cout << "DATA ESTE";
    cin >> zi;
    if ((cin.get() != '/') || (zi>31)  )
    {
        cout << "gresit";
        return;
    }
    cin >> luna;
    if ((cin.get() != '/')  || (luna>12) )
    {
        cout << "gresit";
        return;
    }
    cin >> an;
    cout << "GENUL ";
    cin >> gen;
    Date date(zi, luna, an);
    this->service.addFilm(titlu, date, gen);
    cout << "reusit" << endl << endl;
}

void UserInterface::delFilm()
{
    char titlu[100];
    cout << "TITLU ";
    cin >> titlu;
    this->service.delFilm(titlu);
    cout << "deleted forever" << endl << endl;
}

void UserInterface::modFilm()
{
    int zi, luna, an;
    char titlu[100];
    char gen[100];
    cin>>zi;
    cin>>luna;
    cin>>an;
    Date date (zi, luna, an);
    cout << "FILm" << endl;
    cin >> titlu;
    cin>>gen;
    Film film(titlu, date, gen);
    int i = find_film_ui(service, film);
    if (i != -1)
    {
        service.modFilm(film, titlu, date, gen);
        cout << "Filmul a fost actualizat!" << endl;
    }
    else cout << "Filmul nu a fost gasit!" << endl;
}

int UserInterface::find_film_ui(Service& service, Film film)
{
    bool rez = service.find_film_service(film);
    if (rez) return -1;
    return 0;
}


void UserInterface::print()
{
    cout << "Filmele sunt " << endl;
    for (int i = 0; i < this->service.getNo(); i++)
    {
        cout << i + 1 << "." << this->service.getAll()[i];
    }
    cout << endl;
}

void UserInterface::oneGen()
{
    char cGen[100];
    cout << "genul ";
    cin >> cGen;
    cout << "Elementele listei: " << endl;
    for (int i = 0; i < service.oneGen(cGen).getNo(); i++)
        cout << service.oneGen(cGen).getAll()[i];
    cout << endl;
}

void UserInterface::delInainteData()
{
    int zi, luna, an;
    cout << "data ";
    cin >> zi;
    if (cin.get() != '/')
    {
        cout << "gresit";
        return;
    }
    cin >> luna;
    if (cin.get() != '/')
    {
        cout << "gresit";
        return;
    }
    cin >> an;
    Date date(zi, luna, an);
    this->service.delInainteData(date);
    cout << "deleted" << endl << endl;
}

void UserInterface::undo()
{
    this->service.undo();
    this->print();
}

void UserInterface::no_command()
{
    cout << "Comanda invalida!" << endl << endl;
}

char UserInterface::meniu()
{
    char op;
    cout << "toate filmele 1" << endl
        << "adaugare2" << endl
        << "delete3" << endl
        << "update4" << endl
        << "toate filmele5" << endl
        << "filme mai vechi de6" << endl
        << "undo7" << endl
        << " x pentru iesire." << endl
        << "alege ";
    cin >> op;
    return op;
}

int UserInterface::functie()
{
    char op;
    do
    {
        op = this->meniu();
        switch (op)
        {
        default: { this->no_command(); break; }
        case '1': { this->print(); break; }
        case '2': { this->addFilm(); break; }
        case '3': { this->delFilm(); break; }
        case '4': { this->modFilm(); break; }
        case '5': { this->oneGen(); break; }
        case '6': { this->delInainteData(); break; }
        case '7': { this->undo(); break; }
        case 'x':    return 0;
        }
    } while (op);
    return 0;
}
