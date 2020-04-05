//
//  service.cpp
//  laborator
//
//  Created by Rolland Koszta on 05/04/2020.
//  Copyright © 2020 Rolland Koszta. All rights reserved.
//

#include <stdio.h>
#include "service.h"


Service::Service()
{
    this->noUndo = 1;
    this->steps[0] = this->repo;
}

Film* Service::getAll()
{
    return this->repo.getAll();
}

int Service::getNo()
{
    return this->repo.getNo();
}

void Service::addFilm(char* titlu, Date& date, char* gen)
{
    Film f(titlu, date, gen);
    this->repo.add(f);
    this->steps[this->noUndo++] = this->repo;
}

void Service::delFilm(char* titlu)
{
    if (this->repo.find_by_titlu(titlu) != -1)
    {
        Film f = this->repo.getAll()[this->repo.find_by_titlu(titlu)];
        this->repo.del(f);
        this->steps[this->noUndo++] = this->repo;
    }
}

void Service::modFilm(Film& f, char* titlu, Date& date, char* gen)
{
    repo.mod(f, titlu, date, gen);    
}

int Service::find_film_service(Film f)
{
    return repo.find_film_repo(f);
}
Repo Service::oneGen(char* gen)
{
    Repo sortedFilme;
    for (int i = 0; i < this->repo.getNo(); i++)
        if (strcmp(this->repo.getAll()[i].getGen(), gen) == 0)
            sortedFilme.add(this->repo.getAll()[i]);
    return sortedFilme;
}

void Service::delInainteData(Date& date)
{
    Repo newRepo;
    for (int i = 0; i < this->repo.getNo(); i++)
        if (this->repo.getAll()[i].getDate() > date)
            newRepo.add(this->repo.getAll()[i]);
    if (this->repo != newRepo)
    {
        this->repo = newRepo;
        this->steps[this->noUndo++] = this->repo;
    }
}

void Service::undo()
{
    if (this->noUndo)
    {
        this->noUndo = this->noUndo - 1;
        this->repo = this->steps[this->noUndo - 1];
    }
}
