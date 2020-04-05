//
//  tests.cpp
//  laborator
//
//  Created by Rolland Koszta on 05/04/2020.
//  Copyright © 2020 Rolland Koszta. All rights reserved.
//

#include <stdio.h>
#include "tests.h"


void FilmTest()
{
    Film f;
    char titlu1[20] = "roc";
    Date date1(5, 6, 2004);
    char gen1[20] = "boc";
    Film f1(titlu1, date1, gen1);
    Film f2(f1);
    f.setTitlu(titlu1);
    f.setDate(date1);
    f.setGen(gen1);
    assert(strcmp(f1.getTitlu(), f.getTitlu()) == 0);
    assert(f1.getDate() == f.getDate());
    assert(strcmp(f1.getGen(), f.getGen()) == 0);
    assert(f1 == f);
    Date date2(9, 21, 2000);
    f2.setDate(date2);
    assert(f2 != f1);
}

void RepoTest()
{
    char titlu[20] = "roc";
    Date date(5, 6, 2004);
    char gen[20] = "boc";
    Film f(titlu, date, gen);
    Film f1(f);
    Date date2(4, 9, 2010);
    Film f2(f);
    f2.setDate(date2);
    Repo repo1;
    repo1.add(f1);
    repo1.add(f1);
    Repo repo2 = repo1;
    assert(repo1 == repo2);
    repo2.del(f1);
    assert(repo1.getAll()[0] == f1);
    assert(repo2.getNo() == 1);
    assert(repo2.getAll()[0] == f1);
    assert(repo1 != repo2);
}

void ServiceTest()
{
    Service s;
    char titlu[10] = "bambam";
    Date date(10, 11, 2011);
    char gen[10] = "ba";
    char titleMod[10] = "baaa";
    s.addFilm(titlu, date, gen);
    s.addFilm(titlu, date, gen);
    assert(s.getNo() == 2);
    s.delFilm(titleMod);
    assert(s.getNo() == 2);
    Film f(titlu, date, gen);
    assert(s.getAll()[0] == f);
    char gen1[10] = "pa";
    Date date1(12, 12, 2010);
    Film f1(titlu, date1, gen1);
    Film f2(titlu, date1, gen);
    s.addFilm(titlu, date1, gen1);
    s.addFilm(titlu, date1, gen);
    Repo repo;
    repo.add(f);
    repo.add(f2);
    assert(s.oneGen(gen) != repo);
    Date del(12, 12, 2010);
    s.delInainteData(del);
    assert(s.getNo() == 2);
    s.undo();
}

void tests()
{
    FilmTest();
    RepoTest();
    ServiceTest();
}
