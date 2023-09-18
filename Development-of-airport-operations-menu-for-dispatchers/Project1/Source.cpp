#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define MANY 512
#define golovna cout<<"|№ |Пункт призначення   |Рейс |Д.вилету|Ч.вилету|Ч.польоту|Ч.прибуття|цiна($)|наявнiсть|"<<endl<<"|..|....................|.....|........|........|.........|..........|.......|.........|"<<endl;
using namespace std;
struct dd_mm {
    int dd;
    int mm;
};
struct hh_mm {
    int hh;
    int mm;
};
struct air {
    char finish[30];
    int travel;
    struct dd_mm data;
    struct hh_mm tstart;
    struct hh_mm tfly;
    float price;
    char yes_no[2];
}*help;
void vub(air help[], int size, int sort[]){
    int i, j;
    int temp;
    for (i = 0; i < size; i++)
        sort[i] = i;
    for (i = 1; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            if (strcmp(help[sort[j]].finish, help[sort[j + 1]].finish) > 0)
            {
                temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }
}
void vubir(air help[], int size, int sort[]){
    int i, j;
    int temp;
    for (i = 0; i < size; i++)
        sort[i] = i;
    for (i = 1; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            if (help[sort[j + 1]].tstart.hh > help[sort[j]].tstart.hh && help[sort[j + 1]].tstart.mm > help[sort[j]].tstart.mm)
            {
                temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }
}
void see(air help[], int i){
    cout << "|" << setw(2) << i + 1 << "|" << setw(20) << help[i].finish << "|" << setw(5) << help[i].travel << "|" << setw(4) << help[i].data.dd << "." << help[i].data.mm <<
        " |" << setw(4) << help[i].tstart.hh << ":" << help[i].tstart.mm << " |" << setw(4) << help[i].tfly.hh << ":" << help[i].tfly.mm <<
        "  |" << setw(4) << help[i].tfly.hh + help[i].tstart.hh << ":" << help[i].tfly.mm + help[i].tstart.mm << "   |" << setw(7) << help[i].price << "|" << setw(3) << help[i].yes_no << "      |" << endl;
}
int main(){
    int i = 0, j, n{}, size = 0, kvo = 0, query;
    int* fort;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while (n != 6)
    {
        cout << "\t\t   Вас вiтає авiакомпанiя \n\n\t\t'Ryanair.ITSTEP.Lviv.Ukraine' \n\n\t\t Зробiть свiй вибiр : \n\t\t 1. Вивести розклад польотiв \n\t\t 2. Редагувати запит \n\t\t 3. пошук ";
        cout << "\n \n (Використовуйте гарячi клавiшi для вибора : '1', '2', '3')\n \n  ";
        cout << "\t\tВаш вибiр :";
        n = 0;
        cin >> n;
        switch (n){
        case 1: if (size != 0) {
            cout << "Сортування по: \n1. Часу вильоту \n2. Пункту призначення \n3. Назад \n";
            cin >> n;
            fort = new int[size];
            while (n != 3){
                switch (n){
                case 1: vubir(help, size, fort);
                    golovna
                        for (i = 0; i < size; i++){
                            see(help, fort[i]);
                        }
                    n = 3;
                    system("pause");
                    break;
                case 2: vub(help, size, fort);
                    golovna
                        for (i = 0; i < size; i++){
                            see(help, fort[i]);
                        }
                    n = 3;
                    break;
                case 3: break;
                default: cout << "Невiрний номер! " << endl; system("pause");
                }
            }
        }
              else { cout <<"\t На даний момент вильотiв з аеропорту немає!" << endl;  system("pause"); system("cls"); }
              break;
        case 2: while (n != 3){
            cout << "\t\tРедагувати запит:\n\t\t1. Ввiд даних в запит \n\t\t2. Очистити запит \n\t\t3. Назад\n";
            cout << "\t\tВаш вибiр :";
            cin >> n;
            switch (n){
            case 1: if (size == 0) help = new air[MANY];
                i = size;
                while (n != 0){
                    cout << "\t\tВведiть значення для строки " << i + 1 << endl;
                    cout << "\t\tВведiть пункт призначення : " << endl;
                    cin >> help[i].finish;
                    do {
                        cout << "\t\tВведiть номер рейса : " << endl;
                        cin >> help[i].travel;
                    } while (help[i].travel < 0);
                    do {
                        cout << "\t\tВведiть дату вильоту (дд мм)(через пробел) :" << endl;
                        cin >> help[i].data.dd >> help[i].data.mm;
                    } while (help[i].data.dd < 0 || help[i].data.dd>32 || help[i].data.mm < 0 || help[i].data.mm>13);
                    do {
                        cout << "\t\tВведiть час вильоту (чч мм)(через пробел) : " << endl;
                        cin >> help[i].tstart.hh >> help[i].tstart.mm;
                    } while (help[i].tstart.hh < 0 || help[i].tstart.hh>25 || help[i].tstart.mm < 0 || help[i].tstart.mm>61);
                    do {
                        cout << "\t\tВведiть час польоту (чч мм)(через пробел) : " << endl;
                        cin >> help[i].tfly.hh >> help[i].tfly.mm;
                    } while (help[i].tfly.hh < 0 || help[i].tfly.hh>13 || help[i].tfly.mm < 0 || help[i].tfly.mm>61);
                    do {
                        cout << "\t\t Введiть цiну за бiлет : " << endl;
                        cin >> help[i].price;
                    } while (help[i].price < 0);
                    cout << "\t\t Введiть наявнicть бiлетiв y/n : " << endl;
                    cin >> help[i].yes_no;
                    cout << "\t\t Ввести ще? 1 - так, 0 - нi " << endl;
                    cin >> n;
                    i++;
                    system("cls");
                }
                size = i;
                system("cls");
                break;
            case 2: delete[]help;
                size = 0;
                cout << "\t\t Розклад польотiв успiшно удалено!" << endl;
                system("pause");
                system("cls");
                break;
            case 3: system("cls");
                break;
            default: cout << "\t\t Невiрнuй номер! "; system("pause");
            }
        }
              break;
        case 3: if (size != 0) {
            cout << "\tПошук (введiть данi або введiть 0, якщо помилились з пунктом в меню): " << endl;
            do {
                cout << "\t\tВведiть номер рейса" << endl;
                cin >> help[size + 1].travel;
            } while (help[size + 1].travel < 0);
            do {
                cout << "\t\tВведiть дату вильоту" << endl;
                cin >> help[size + 1].data.dd >> help[size + 1].data.mm;
            } while (help[size + 1].data.dd < 0 || help[size + 1].data.dd>32 || help[size + 1].data.mm < 0 || help[size + 1].data.mm>13);
            do {
                cout << "\t\tВведiть час вильоту" << endl;
                cin >> help[size + 1].tstart.hh >> help[size + 1].tstart.mm;
            } while (help[size + 1].tstart.hh < 0 || help[size + 1].tstart.hh>25 || help[size + 1].tstart.mm < 0 || help[size + 1].tstart.mm>61);
            kvo = 0;
            for (i = 0; i < size; i++){
                j = 0;
                if (help[i].travel == help[size + 1].travel) j++;
                if (help[size + 1].data.dd == help[i].data.dd && help[size + 1].data.mm == help[i].data.mm) j++;
                if (help[size + 1].tstart.hh == help[i].tstart.hh && help[size + 1].tstart.mm == help[i].tstart.mm) j++;
                if (j > 0) { see(help, i); kvo++; }
            }
            if (kvo > 0) cout << "\t\tЗнайдено спiвпадiнь: " << kvo << endl;
            else cout << "\t\tСпiвпадiнь немає " << endl;
        }
              else cout << "\t\tБаза пуста!" << endl;
            system("pause");
            system("cls");
            break;
        case 5: break;
        default: cout << "\t\tневiрний номер! "; system("pause");
        }
    }
    return 0;
}