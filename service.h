//
//  service.h
//  laborator
//
//  Created by Rolland Koszta on 05/04/2020.
//  Copyright © 2020 Rolland Koszta. All rights reserved.
//

#ifndef service_h
#define service_h


#endif /* service_h */
#pragma once
#include "repo.h"

class Service
{
private:
    Repo repo;
    int noUndo;
    Repo steps[100];
public:
    Service();
    Film* getAll();
    int getNo();
    void addFilm(char*, Date&, char*);
    void delFilm(char*);
    int find_film_service(Film f);
    void modFilm(Film& f, char* , Date& date, char* );
    Repo oneGen(char*);
    void delInainteData(Date&);
    void undo();
};
