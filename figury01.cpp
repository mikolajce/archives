#include <cstdlib>
#include <iostream>
using namespace std;

// Badziewiarska wersja klasy Kwadrat
class Kwadrat
{
  public:
    double bok;
    double pole()
    {
      return bok * bok;
    }
};


class KalkulatorPolFigur
{
  public:
    KalkulatorPolFigur();
    ~KalkulatorPolFigur();
    void obliczajPolaFigur();
  private:
    int pokazMenuIWczytajWyborUzytkownika();
    void obliczeniaDlaKwadratu();
    void obliczeniaDlaProstokata();
};

KalkulatorPolFigur::KalkulatorPolFigur()
{
  cout << "\nKalkulator: witaj w programie";
}

KalkulatorPolFigur::~KalkulatorPolFigur()
{
  cout << "\nNacisnij Enter by zakonczyc...";
  cin.get();
}

int KalkulatorPolFigur::pokazMenuIWczytajWyborUzytkownika()
{
  int wybor;
  cout << "\n\nWybierz figure:\n1. Kwadrat\n2. Prostokat\nInne figury\n";
  cout << "0. Koniec programu\n>> ";
  cin >> wybor;
  cin.ignore();
  return wybor;
}
// Badziewiarska wersja obliczeñ, brak kontroli na ujemne wartosci dlugosci boku
void KalkulatorPolFigur::obliczeniaDlaKwadratu()
{
  cout << "\nObliczenia dla kwadratu";
  double liczba;
  cout << "\nDlugosc boku: ";
  cin >> liczba;

  Kwadrat k;
  k.bok = liczba;
  cout << "Pole kwadratu: " << k.pole() << endl;
}

void KalkulatorPolFigur::obliczeniaDlaProstokata()
{
  cout << "\nObliczenia dla prostokata";
}


void KalkulatorPolFigur::obliczajPolaFigur()
{
  int wyborUzytkownika;
  do
  {
    wyborUzytkownika = pokazMenuIWczytajWyborUzytkownika();
    switch(wyborUzytkownika)
    {
      case 1: obliczeniaDlaKwadratu();
              break;
      case 2: obliczeniaDlaProstokata();
              break;
      // Inne figury...
    }
  }
  while(wyborUzytkownika != 0);
}

int main()
{
  int a;
void f(){
  cout << ++a;
  }

f();
f();
f();
  KalkulatorPolFigur kalkulator;
  kalkulator.obliczajPolaFigur();

  return EXIT_SUCCESS;
}

