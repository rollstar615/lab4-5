//
//  filme.h
//  laborator
//
//  Created by Rolland Koszta on 05/04/2020.
//  Copyright © 2020 Rolland Koszta. All rights reserved.
//

#ifndef filme_h
#define filme_h


#endif /* filme_h */
#pragma once
#include "date.h"
#include <string.h>
#include <cstring>
#include <string>
class Film
{
private:
    char* titlu;
    Date date;
    char* gen;
public:
    Film();
    Film(char*, Date&, char*);
    Film(Film&);
    ~Film();
    char* getTitlu();
    Date& getDate();
    char* getGen();
    void setTitlu(char*);
    void setDate(Date&);
    void setGen(char*);
    Film& operator=(Film&);
    bool operator==(Film&);
    bool operator!=(Film&);
    friend ostream& operator<<(ostream&, Film&);
};
