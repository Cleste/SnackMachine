#include <string>
#include <vector>
#include <locale>
#include <iostream>
#include <fstream>

using namespace std;
struct snack
{
    int id, price;
    string product;
};

int main() {
    setlocale(LC_ALL, "Russian");
    string filePath, want;
    ifstream fin;
    ofstream fout;
    vector<snack> a;
    vector<snack> v;
    int budget, k = 0, what, l;
    snack item;
    cout << "Сколько у вас лаве?" << endl;
    cin >> budget;
    if (budget > 0) {
        while (true) {
            while (true) {
                system("clear");
                a.clear();
                cout << "Что вы желаете? Введите 0 для завершения покупок." << endl;
                cout << "1.Попить" << endl << "2.Похавать" << endl;
                cin >> filePath;
                if (filePath != "1" && filePath != "2" && filePath != "0") {
                    cout << filePath << " нет в списке. Попробуйте еще раз." << endl;
                } else break;
            }
            if (filePath == "0") {
                if (v.size() > 0) {
                    system("clear");
                    cout << "Ваша сдача: " << budget << endl << "Список покупок:" << endl;
                    for (int i = 0; i < v.size(); i++) {
                        cout << i + 1 << ")" << v[i].product << " " << v[i].price << endl;
                    }
                    cin.get();
                    return 0;
                }else {
                    cout << "Вы нищеброд и ничего не приобрели." << endl;
                    cin.get();
                    return 0;
                }
            }
            if (filePath == "1")
                want = "/home/kirill/CLionProjects/SnackMachine/Напитки.txt";
            if (filePath == "2")
                want = "/home/kirill/CLionProjects/SnackMachine/Еда.txt";
            fin.open(want);
            while (!fin.eof()) {
                fin >> item.id >> item.product >> item.price;
                a.push_back(item);
                k++;
            }
            fin.close();
            while (true) {
                system("clear");
                for (int i = 0; i < a.size(); i++) {
                    cout << a[i].id << " " << a[i].product << " " << a[i].price << endl;
                }
                cout << "Количество оставшихся лаве: " << budget << endl;
                cout << "Введите номер продукта, который желаете приобрести. Введите 0, чтобы поменять меню. " << endl;
                cin >> what;
                if (what > a.size() + 1 || what < 0) {
                    cout << "Неверный id" << endl;
                    continue;
                }
                if (what == 0) {
                    break;
                } else if (what != 0) {
                    for (int i = 0; i < k; i++) {
                        if (a[i].id == what) {
                            if (budget - a[i].price < 0) {
                                system("clear");
                                cout << "Опа. Недостаочно лаве" << endl;
                                cin.get();
                            } else {
                                v.push_back(a[i]);
                                budget = budget - a[i].price;
                            }
                            break;
                        }
                    }
                }
            }
        }
    } else if (budget == -1){
        fin.open("/home/kirill/CLionProjects/SnackMachine/password.txt");
        string pass, password;
        fin >> pass;
        for (int i = 3; i >= -1; i--) {
            system("clear");
            if (i == -1) {
                cout << "Неверный пароль." << endl;
                cout << "Лимит ввода пароля превышен - самоуничтожение программы." << endl;
                cin.get();
                return 0;
            }
            cout << "Введите пароль : " << endl;
            cin >> password;
            if (password == pass) break;
            else if (i > 0) {
                cout << "Неверный пароль. У вас отсалось " << i << " Попыток" << endl;
            }

        }
        fin.close();
        string command;
        while (command != "0") {
            system("clear");
            cout << "Введите команду. Введите 0 для завершения программы." << endl;
            cin >> command;
            if (command == "menu") {
                while (true) {
                    while (true) {
                        system("clear");
                        a.clear();
                        cout << "Какое меню вы хотите поменять? Введите 0 для возврата к вводу команд." << endl;
                        cout << "1.Напитки" << endl << "2.Еда" << endl;
                        cin >> filePath;
                        if (filePath != "1" && filePath != "2" && filePath != "0") {
                            cout << filePath << " нет в списке. Попробуйте еще раз." << endl;
                        } else break;
                    }
                    if (filePath == "1")
                        want = "/home/kirill/CLionProjects/SnackMachine/Напитки.txt";
                     else if (filePath == "2")
                        want = "/home/kirill/CLionProjects/SnackMachine/Еда.txt";
                    else break;
                    fin.open(want);
                    while (!fin.eof()) {
                        fin >> item.id >> item.product >> item.price;
                        a.push_back(item);
                        k++;
                    }
                    fin.close();
                    fout.open(want);
                    while (true) {
                        system("clear");
                        for (int i = 0; i < a.size(); i++) {
                            cout << a[i].id << " " << a[i].product << " " << a[i].price << endl;
                        }
                        cout
                                << "Введите id продукта, который хотите изменить, или 0 для возврата к выбору меню"
                                << endl;
                        cin >> l;
                        if (l == 0) {
                            for (int i = 0; i < a.size(); i++) {
                                if (i < a.size() - 1)
                                    fout << a[i].id << " " << a[i].product << " " << a[i].price << " " << endl;
                                else
                                    fout << a[i].id << " " << a[i].product << " " << a[i].price;
                            }
                            break;
                        }
                        for (int i = 0; i < a.size(); i++) {
                            if (a[i].id == l) {
                                cout << "Введите назание продукта: " << endl;
                                cin >> a[i].product;
                                cout << "Введите цену продукта: " << endl;
                                cin >> a[i].price;
                            }
                        }
                        break;
                    }
                }
            } else if (command == "passC"){
                for (int i = 3; i >= -1; i--) {
                    system("clear");
                    if (i == -1) {
                        cout << "Неверный пароль." << endl;
                        cout << "Лимит ввода пароля превышен - самоуничтожение программы." << endl;
                        cin.get();
                        return 0;
                    }
                    cout << "Введите пароль : " << endl;
                    cin >> password;
                    if (password == pass) break;
                    else if (i > 0) {
                        cout << "Неверный пароль. У вас отсалось " << i << " Попыток" << endl;
                    }
                }
                cout << "Введите новый пароль :" << endl;
                cin >> password;
                fout.open("/home/kirill/CLionProjects/SnackMachine/password.txt");
                fout << password;
            }
        }
    }
    else cout << "Вы ввели отрицательное число. LOL" << endl;
    return 0;
}
