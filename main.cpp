#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>

std::vector<int> getSet(){
    std::ifstream file("instancja.txt");
    std::vector<int> set;
    char element[5];

    if(file.is_open()) {
        while (file >> element) {
            int i = atoi(element);
            set.push_back(i);
        }
    } else {
        std::cout<<"Nie znaleziono pliku!";
        exit(1);
    }
    std::sort(set.begin(), set.end());
    return set;
}

int checkCuts(std::vector<int> set){
    for(int c = 1; c < 20; c++) {
        int n = (c+1) * (c+2);
        if (n / 2 == set.size()) return c;
    }
    return 0;
}

bool canUse(std::vector<int> test, std::vector<int> is_used, int x){
    for (int i = 0; i < test.size(); i++){
        if(x == test[i]){
            if(is_used[i] == 0){
                return true;
            } else continue;
        }
    }
    return false;
}

void Use(std::vector<int> test, std::vector<int> *is_used, int x){
    for (int i = 0; i < test.size(); i++){
        if(x == test[i]){
            if(is_used->at(i) == 0){
                is_used->at(i) = 1;
                return;
            }
        }
    }
}

void unUse(std::vector<int> test, std::vector<int> *is_used, int x){
    for (int i = test.size()-1; i > -1 ; i--){
        if(x == test[i]){
            if(is_used->at(i) == 1){
                is_used->at(i) = 0;
                return;
            }
        }
    }
}


void szukaj(int ind, int *jest, int cuts, int length, std::vector<int> *set, std::vector<int> *is_used, std::vector<int> *map) {
    if (ind == cuts) {
        std::cout<<"Znaleziono mape:\n";
        for (int m = 0; m < map->size(); m++) {
            std::cout << map->at(m) << " ";
        }
        *jest = 1;
    } else {
        for (int i = 0; i < set->size(); i++) {
            if(canUse(*set, *is_used, set->at(i))){
                int tmp = set->at(i);
                int cant_use = 0;
                for(int m = map->size() - 1; m > -1; m--){
                    tmp += map->at(m);
                    if(canUse(*set, *is_used, tmp) == false){
                        cant_use = 1;
                        break;
                    }
                }

                if(cant_use == 1) continue;
                if(!canUse(*set, *is_used, length - tmp)) continue;
                map->push_back(set->at(i));

                tmp = 0;
                for(int m = map->size() - 1; m > -1; m--){
                    tmp += map->at(m);
                    Use(*set, is_used, tmp);
                }
                Use(*set, is_used, length - tmp);

                if(ind == cuts-1) map->push_back(length - tmp);

                szukaj(ind + 1, jest, cuts, length, set, is_used, map);
                if (*jest==1) break;

                tmp = map->back();
                unUse(*set, is_used, map->back());
                map->pop_back();
                for(int m = map->size()-1; m > -1; m--){
                    tmp += map->at(m);
                    unUse(*set, is_used, tmp);
                }
                unUse(*set, is_used, length - tmp);
            }
        }
    }
}



int main() {
    std::vector<int> set;
    std::vector<int> map;
    set = getSet();
    std::vector<int> is_used;

    for(int i = 0; i < set.size(); i++){
        is_used.push_back(0);
    }

    int length = set.back();
    int jest;
    int cuts = checkCuts(set);

    if(cuts == 0){
        std::cout<<"Multi zbior jest zbyt krotki lub zbyt dlugi - nie ma liczby ciec odpowiadajacej danej licznosci zbioru!"<<std::endl;
        exit(2);
    } else {
        map.push_back(length-set[set.size()-2]);
        if(canUse(set, is_used,  map[0]) == 0){
            std::cout<<"W podanym multizbiorze nie ma poczatkowego elementu mapy - blad danych.";
            exit(4);
        }

        Use(set, &is_used, map[0]);
        is_used[set.size()-2] = 1;
        is_used[set.size()-1] = 1;

        auto start = std::chrono::steady_clock::now();
        szukaj(1, &jest, cuts, length, &set, &is_used, &map);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> work_time = end - start;
        std::cout<<"\nCzas dzialania programu wynosi: "<<work_time.count()<<" sekund."<<std::endl;
        if (jest==0){
            std::cout<<"Mapa dla podanego multizbioru nie istnieje.";
            exit(3);
        }
    }


    return 0;
}
