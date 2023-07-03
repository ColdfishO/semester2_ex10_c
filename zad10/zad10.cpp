#include <iostream>
#include<locale.h>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<sstream>
using namespace std;
void autor(void) {
    cout << endl;
    for (int i = 1; i <= 120; i++) cout << "*";
    cout << "Autor programu: Simon Dudek\n\n";
    for (int i = 1; i <= 120; i++) cout << "*";
    cout << "\n\n";
}
void wyswietl(string i) {
    cout << i << endl;
}
bool namale(char znak1, char znak2)
{
    return (tolower(static_cast<unsigned char>(znak1)) < tolower(static_cast<unsigned char>(znak2)));
}
bool bezwielkosci(const string& ciag1, const string& ciag2)
{
    return lexicographical_compare(ciag1.begin(), ciag1.end(), ciag2.begin(), ciag2.end(), namale);
}
int main() {
    setlocale(LC_ALL, "");
    autor();
    ifstream odczyt;
    ofstream zapis;
    string wiersz;
    vector<string>wyrazy;
    odczyt.open("wyrazy.txt");
    if (odczyt.is_open()) {
        cout << "Plik odczytu otwarto pomyślnie\n" << endl;
        while (getline(odczyt, wiersz)) {
            istringstream slowo(wiersz);
            string bla;
            while (slowo>>bla) {
                wyrazy.push_back(bla);
            }
        }
        sort(wyrazy.begin(), wyrazy.end(), bezwielkosci);
    }
    else {
        cout << "Nie znaleziono pliku odczytu" << endl;
    }
    odczyt.close();
    zapis.open("posortowane.txt", ios_base::app);
    for (int i = 0;i < wyrazy.size();i++) {
        zapis << wyrazy[i] << " ";
    }
    zapis.close();
    system("pause");
    return 0;
}