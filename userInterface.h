//
//  userInterface.h
//  laborator
//
//  Created by Rolland Koszta on 05/04/2020.
//  Copyright © 2020 Rolland Koszta. All rights reserved.
//

#ifndef userInterface_h
#define userInterface_h


#endif /* userInterface_h */
#pragma once
#include "service.h"

class UserInterface
{
private:
    Service service;
public:
    UserInterface();
    void addFilm();
    void delFilm();
    void modFilm();
    void print();
    void oneGen();
    void delInainteData();
    int find_film_ui(Service& serv, Film);
    void undo();
    void no_command();
    char meniu();
    int functie();
};
