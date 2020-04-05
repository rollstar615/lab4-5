//
//  filme.cpp
//  laborator
//
//  Created by Rolland Koszta on 05/04/2020.
//  Copyright © 2020 Rolland Koszta. All rights reserved.
//

#include <stdio.h>
#include "filme.h"
#include <string>
#include <string.h>
#include <cstring>
using namespace std;

Film::Film()
{
    this->titlu = NULL;
    this->gen = NULL;
    this->date;
}

Film::Film(char* newTitlu, Date& newDate, char* newGen)
{
    this->titlu = new char[strlen(newTitlu) + 1];
    strncpy(this->titlu, newTitlu, strlen(newTitlu) + 1);
    this->date = newDate;
    this->gen = new char[strlen(newGen) + 1];
    strncpy(this->gen, newGen, strlen(newGen) + 1);
}

Film::Film(Film& f)
{
    *this = f;
}

Film::~Film()
{
    if (this->titlu)
    {
        delete[] this->titlu;
        this->titlu = NULL;
    }
    if (this->gen)
    {
        delete[] this->gen;
        this->gen = NULL;
    }
}

char* Film::getTitlu()
{
    return this->titlu;
}

Date& Film::getDate()
{
    return this->date;
}

char* Film::getGen()
{
    return this->gen;
}

void Film::setTitlu(char* newTitlu)
{
    if (this->titlu != NULL)
        delete[] this->titlu;
    this->titlu = new char[strlen(newTitlu) + 1];
    strncpy(this->titlu, newTitlu, strlen(newTitlu) + 1);
}

void Film::setDate(Date& newDate)
{
    this->date = newDate;
}

void Film::setGen(char* newGen)
{
    if (this->gen)
        delete[] this->gen;
    this->gen = new char[strlen(newGen) + 1];
    strncpy(this->gen, newGen,strlen(newGen) + 1);
}

Film& Film::operator=(Film& f)
{
    this->setTitlu(f.titlu);
    this->setGen(f.gen);
    this->setDate(f.date);
    return *this;
}

bool Film::operator==(Film& f)
{
    return (strcmp(this->titlu, f.titlu) == 0 && strcmp(this->gen, f.gen) == 0 && this->date == f.date);
}

bool Film::operator!=(Film& f)
{
    return !this->operator==(f);
}

ostream& operator<<(ostream& os, Film& f)
{
    os << "Film " << f.titlu << endl
        << "//" << "Data in care a aparut " << f.date << endl
        << "///" << "Genul:         " << f.gen << endl;
    return os;
}
