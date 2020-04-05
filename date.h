//
//  date.h
//  laborator
//
//  Created by Rolland Koszta on 05/04/2020.
//  Copyright © 2020 Rolland Koszta. All rights reserved.
//

#ifndef date_h
#define date_h


#endif /* date_h */
#pragma once
#include <iostream>

using namespace std;

struct Date
{
    int zi;
    int luna;
    int an;
    Date()
    {
        this->zi = 0;
        this->luna = 0;
        this->an = 0;
    }
    Date(int newZi, int newLuna, int newAn)
    {
        this->zi = newZi;
        this->luna = newLuna;
        this->an = newAn;
    }
    Date(Date& date)
    {
        *this = date;
    }
    ~Date()
    {
        this->zi = 0;
        this->luna = 0;
        this->an = 0;
    }
    bool operator<(Date& date)
    {
        return (365 * this->an + 31 * this->luna + this->zi < 365 * date.an + 31 * date.luna + date.zi);
    }
    bool operator>=(Date& date)
    {
        return !this->operator<(date);
    }
    bool operator>(Date& date)
    {
        return (365 * this->an + 30 * this->luna + this->zi > 365 * date.an + 30 * date.luna + date.zi);
    }
    bool operator<=(Date& d)
    {
        return !this->operator>(d);
    }
    bool operator==(Date& date)
    {
        return (this->operator<=(date) && this->operator>=(date));
    }
    Date& operator=(Date& date)
    {
        this->zi = date.zi;
        this->luna = date.luna;
        this->an = date.an;
        return *this;
    }
    friend ostream& operator<<(ostream& os, Date& date)
    {
        os << date.zi << ' / ' << date.luna << ' / ' << date.an;
        return os;
    }
};
