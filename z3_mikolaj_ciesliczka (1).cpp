#include <iostream>
#include <cstdlib>
#define _USE_MATH_DEFINES   //import bibliotek zawierajacych
#include <cmath>            //stala matematyczna pi uzyta w Kolo()
using namespace std;

void czekajNaEnter( const char napis[] ){
    cout << endl << napis;
    cin.get();
}

void czekajNaEnterCzyscBufor( const char napis[] ){
    cin.ignore();
    czekajNaEnter(napis);
}

void pokazMenu(){
    cout << "\n================================\n";
    cout << "\nWybierz figure, ktorej pole\n";
    cout << "chcesz obliczyc (wpisz numer).\n";
    cout << "\n1. Kwadrat.\n2. Prostokat.\n3. Kolo.\n";
    cout << "4. Trojkat. \n5. Trapez. \n";
    cout << "6. Zakoncz program. \n\n>>";
}

double Check(double liczba){
    do{
        cout << "\n>>";
        cin >> liczba;
        if(liczba <= 0){
            czekajNaEnterCzyscBufor("Nieprawidlowa wartosc!");
        }
    }while(liczba <= 0);

    return liczba;  //funkcja zapetla sie jesli liczba jest niedodatnia
}

void Kwadrat(){
    double a;

    cout << "\n================================\n";
    cout << "\nKwadrat\n";
    cout << "\nPodaj dlugosc boku:\n";

    a = Check(a); //wczytanie do zmiennej wartosci zwroconej przez Check()

    cout << "\nPole kwadratu wynosi " << a*a << ".\n";

    czekajNaEnterCzyscBufor("Enter by kontynuowac...");
}

void Prostokat(){
    double a, b;

    cout << "\n================================\n";
    cout << "\nProstokat\n";
    cout << "\nPodaj dlugosc krotszego boku:\n";

    a = Check(a);

    cout << "\nPodaj dlugosc dluzszego boku:\n";

    b = Check(b);

    cout << "\nPole prostokata wynosi " << a*b << ".\n";

    czekajNaEnterCzyscBufor("Enter by kontynuowac...");
}

void Kolo(){
    double r;

    cout << "\n================================\n";
    cout << "\nKolo\n";
    cout << "\nPodaj dlugosc promienia:\n";

    r = Check(r);

    cout << "\nPole kola wynosi " << M_PI*r*r << ".\n";
    //zastosowanie wartosci pi z <cmath>

    czekajNaEnterCzyscBufor("Enter by kontynuowac...");
}

void Trojkat(){
    double a, h;

    cout << "\n================================\n";
    cout << "\nTrojkat\n";
    cout << "\nPodaj dlugosc podstawy:\n";

    a = Check(a);
    cout << "\nPodaj wysokosc:\n";

    h = Check(h);

    cout << "\nPole trojkata wynosi " << a*h/2 << ".\n";

    czekajNaEnterCzyscBufor( "Enter by kontynuowac..." );
}

void Trapez(){
    double a, b, h;

    cout << "\n================================\n";
    cout << "\nTrapez\n";
    cout << "\nPodaj dlugosc pierwszej podstawy:\n";

    a = Check(a);

    cout << "\nPodaj dlugosc drugiej podstawy:\n";

    b = Check(b);

    cout << "\nPodaj wysokosc:\n";

    h = Check(h);

    cout << "\nPole trapezu wynosi " << (a+b)*h/2 << ".\n";

    czekajNaEnterCzyscBufor( "Enter by kontynuowac..." );
}

void wykonanie(){

  char wybor;
  const char exit = '6';

  do{
    pokazMenu();
    cin >> wybor;
    switch(wybor){
        case '1':
            Kwadrat();
            break;
        case '2':
            Prostokat();
            break;
        case '3':
            Kolo();
            break;
        case '4':
            Trojkat();
            break;
        case '5':
            Trapez();
            break;
        case '6':
            cout << "\n================================\n";
            break;
        default:
            czekajNaEnterCzyscBufor("Nieprawidlowy wybor!");
    }
  }while(wybor != exit);
}

void zakonczenie(){
  czekajNaEnterCzyscBufor("Nacisnij Enter, aby zakonczyc program.");
}

int main(){
    cout << "================================\n";
    cout << "\nProgram kalkulacyjny obliczajacy\n";
    cout << "pola wybranych figur.\n";

    wykonanie();
    zakonczenie();

    return EXIT_SUCCESS;
}
