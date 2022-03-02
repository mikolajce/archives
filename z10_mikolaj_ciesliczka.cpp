#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

void menu(){
    cout << "\n================================\n";
    cout << "\nWybierz figure, ktorej pole\n";
    cout << "chcesz obliczyc (wpisz numer).\n";
    cout << "\n1. Kwadrat.\n2. Prostokat.\n3. Kolo.\n";
    cout << "4. Trojkat. \n5. Trapez. \n";
    cout << "6. Zakoncz program. \n\n>>";
}

class Figury{
    public:
    double Check(double liczba){
        do{
            cout << "\n>>";
            cin >> liczba;
            if(liczba <= 0){
                cout << "\nNieprawidlowa wartosc!\n";
            }
        }while(liczba <= 0);

        return liczba;
    }

    void kwadrat(){
        double a;
        cout << "\n===========================================\n";
        cout << "\nPodaj dlugosc boku:\n";
        a = Check(a);
        cout << "\nPole kwadratu wynosi " << a * a << "\n\n";
    }

    void prostokat(){
        double a, b;
        cout << "\n===========================================\n";
        cout << "\nPodaj pierwszy bok:\n";
        a = Check(a);
        cout << "\nPodaj drugi bok:\n";
        b = Check(b);
        cout << "\nPole prostokata wynosi " << a*b << "\n\n";
    }

    void kolo(){
        double r;
        cout << "\n===========================================\n";
        cout << "\nodaj promien kola:\n";
        r = Check(r);
        cout << "\nPole Kola wynosi " << M_PI*r*r << "\n\n";
    }

    void trojkat(){
        double a, h;
        cout << "\n===========================================\n";
        cout << "\nPodaj dlugosc podstawy trojkata:\n";
        a = Check(a);
        cout << "\nPodaj dlugosc wysokosci trojkata:\n";
        h = Check(h);
        cout << "\nPole Trojkata wynosi " << a*h/2 << "\n\n";
    }

    void trapez(){
        double a, b, h;
        cout << "\n===========================================\n";
        cout << "\nPodaj dlugosc pierwszej podstawy:\n";
        a = Check(a);
        cout << "\nPodaj dlugosc drugiej trapezu:\n";
        b = Check(b);
        cout << "\nPodaj wysokosc:\n";
        h = Check(h);
        cout << "\nPole trapezu wynosi " << (a+b)*h/2 << "\n\n";
    }
};

int main(){
    Figury pole;

    cout << "================================\n";
    cout << "\nProgram kalkulacyjny obliczajacy\n";
    cout << "pola wybranych figur.\n";

    int wybor;
    do{
        menu();
        cin >> wybor;
        switch(wybor){
            case 1: pole.kwadrat();
                    break;
            case 2: pole.prostokat();
                    break;
            case 3: pole.kolo();
                    break;
            case 4: pole.trojkat();
                    break;
            case 5: pole.trapez();
                    break;
            case 6: cout << "\n================================\n";
                    break;
            default: cout << "\nNieprawidlowy wybor!" << endl;
        }
    }while(wybor != 6);

    return EXIT_SUCCESS;
}






