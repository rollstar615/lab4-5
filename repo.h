//
//  repo.h
//  laborator
//
//  Created by Rolland Koszta on 05/04/2020.
//  Copyright © 2020 Rolland Koszta. All rights reserved.
//

#ifndef repo_h
#define repo_h


#endif /* repo_h */
#pragma once
#include "filme.h"

class Repo
{
private:
    Film filme[30];
    int noFilme;
public:
    Repo();
    Repo(Repo&);
    ~Repo();
    Repo& operator=(Repo&);
    bool operator==(Repo&);
    bool operator!=(Repo&);
    void add(Film&);
    void del(Film&);
    void mod(Film&, char*, Date&, char*);
    Film* getAll();
    int getNo();
    int find_film_service(Film f);
    int find_by_titlu(char*);
    int find_film_repo(Film f);
    int find(Film&);
};
