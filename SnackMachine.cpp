#include <string>
#include <vector>
#include <locale>
#include <iostream>
#include <fstream>
#include <algorithm>

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
    int who;
    snack item;
    cout << "Кто вы?" << endl << "1.Покупатель" << endl << "2.Админушка" << endl;
    cin >> who;
    system("cls");
    if (who == 1) {
        cout << "Вставте купюру:" << endl;
        cin >> budget;
        system("cls");
        while(true) {
            cout << "Что вы желаете?" << endl;
            cout << "Напитки" << endl << "Еда" << endl;
            if (cin >> filePath != "Напитки" && filePath != "Еда") {
                cout << filePath << " нет в списке. Попробуйте еще раз." << endl;
            } else break;
        }
        want = "/home/kirill/CLionProjects/SnackMachine/" + filePath + ".txt";
        fin.open(want);
        while (!fin.eof()) {
            fin >> item.id >> item.product >> item.price;
            a.push_back(item);
            k++;
        }
        fin.close();
        while (true) {
            for (int i = 0; i < a.size(); i++) {
                cout << a[i].id << " " << a[i].product << " " << a[i].price << endl;
            }
            cout << "Ваш бюджет:" << budget << endl;
            cin >> what;
            if (what > a.size()+1) {
                cout << "Неверный id" << endl;
                continue;
            }
            if (what == 0) {
                system("cls");
                cout << "Ваша сдача: " << budget << endl << "Список покупок:" << endl;
                for (int i = 0; i < v.size(); i++) {
                    cout << i + 1 << ")" << v[i].product << " " << v[i].price << endl;
                }
                cin.get();
                return 0;
            } else {
                for (int i = 0; i < k; i++) {
                    if (a[i].id == what) {
                        if (budget - a[i].price < 0) {
                            system("cls");
                            cout << "Не достаточно средств!" << endl;
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
    if (who == 2)
    {
        fin.open("/home/kirill/password.txt");
        string password, tryAdmin;
        fin >> password;
        for (int i = 3;i >= -1;i--)
        {
            if (i == -1)
            {
                cout << "Неверный пароль."<< endl;
                cout << "Лимит ввода пароля превышен - самоуничтожение программы." << endl;
                cin.get();
                return 0;
            }
            cout << "Введите пароль : " << endl;
            cin >> tryAdmin;
            if(tryAdmin == password) break;
            else if(i > 0)
            {
                cout << "Неверный пароль. У вас отсалось " << i << " Попыток" << endl;
            }

        }
        fin.close();
        while(true) {
            cout << "Что вы желаете?" << endl;
            cout << "Напитки" << endl << "Еда" << endl;
            if (cin >> filePath != "Напитки" && filePath != "Еда") {
                cout << filePath << " нет в списке. Попробуйте еще раз." << endl;
            } else break;
        }
        want = "/home/kirill/CLionProjects/SnackMachine/" + filePath + ".txt";
        fin.open(want);
        while (!fin.eof()) {
            fin >> item.id >> item.product >> item.price;
            a.push_back(item);
            k++;
        }
        fout.open(filePath);
        while (true) {
            system("cls");
            for (int i = 0; i < a.size(); i++) {
                cout << a[i].id << " " << a[i].product << " " << a[i].price << endl;
            }
            cout << "Введите id продукта, который хотите изменить, или 0 для завершения изменеия прайс-листа:" << endl;
            cin >> l;
            if (l == 0) {
                for (int i = 0; i < a.size(); i++) {
                    if(i < a.size() - 1)
                        fout << a[i].id << " " << a[i].product << " " << a[i].price << " " << endl;
                    else
                        fout << a[i].id << " " << a[i].product << " " << a[i].price;
                }
                return 0;
            }
            for (int i = 0; i < a.size(); i++) {
                if (a[i].id == l) {
                    cout << "Введите назание продукта: " << endl;
                    cin >> a[i].product;
                    cout << "Введите цену продукта: " << endl;
                    cin >> a[i].price;
                }
            }
        }
    }
    return 0;
}
