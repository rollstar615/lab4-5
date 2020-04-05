//
//  repo.cpp
//  laborator
//
//  Created by Rolland Koszta on 05/04/2020.
//  Copyright © 2020 Rolland Koszta. All rights reserved.
//

#include <stdio.h>
#include "repo.h"


Repo::Repo()
{
    this->noFilme = 0;
}

Repo::Repo(Repo& repo)
{
    *this = repo;
}

Repo::~Repo()
{
    this->noFilme = 0;
}

Repo& Repo::operator=(Repo& repo)
{
    this->noFilme = repo.noFilme;
    for (int i = 0; i < this->noFilme; i++)
        this->filme[i] = repo.filme[i];
    return *this;
}

bool Repo::operator==(Repo& repo)
{
    if (this->noFilme != repo.noFilme)
        return false;
    for (int i = 0; i < this->noFilme; i++)
        if (repo.find(this->filme[i]) == -1)
            return false;
    return true;
}

bool Repo::operator!=(Repo& repo)
{
    return !this->operator==(repo);
}

void Repo::add(Film& f)
{
    this->filme[this->noFilme++] = f;
}

void Repo::del(Film& f)
{
    this->filme[this->find(f)] = this->filme[noFilme - 1];
    this->noFilme = this->noFilme - 1;
}

void Repo::mod(Film& f, char* titlu, Date& date, char* gen)
{
    
    int i = find_film_repo(f);
    if (i != -1)
    {
        filme[i].setTitlu(titlu);
        filme[i].setDate(date);
        filme[i].setGen(gen);
    }
}


int Repo::find_film_repo(Film f)
{
    for (int i = 0; i < this->noFilme; i++)
    {
        if (f == this->filme[i])
        {
            return i;
        }
    }
    return -1;
}
Film* Repo::getAll()
{
    return filme;
}

int Repo::getNo()
{
    return noFilme;
}

int Repo::find_by_titlu(char* titlu)
{
    for (int i = 0; i < noFilme; i++)
        if (strcmp(this->filme[i].getTitlu(), titlu) == 0)
            return i;
    return -1;
}

int Repo::find(Film& f)
{
    for (int i = 0; i < noFilme; i++)
        if (this->filme[i] == f)
            return i;
    return -1;
}
