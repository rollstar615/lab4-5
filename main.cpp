//
//  main.cpp
//  laborator
//
//  Created by Rolland Koszta on 05/04/2020.
//  Copyright © 2020 Rolland Koszta. All rights reserved.
//

#include <iostream>

#include "tests.h"
#include "userinterface.h"
using namespace std;

int main()
{
    tests();
    UserInterface ui;
    ui.functie();
    return 0;
}
