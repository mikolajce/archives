#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_LEN 128

/*
Nieprzygotowane funkcje, w ktorych nie
zaimplementowano zwracania wartosci zwykle
zwracaja losowe liczby, czesto odstajace od
zamierzonych wynikow. Jest to spowodowane faktem
przydzielenia wczesniej do funkcji smieciowych
danych, ktore nie zostaly wyzerowane, a wiec
ich wartosc jest przypadkowa. Czesc
kompilatorow przyjmuje takie smieci jako
prawidlowa wartosc do zwrotu przez funkcje, a
niektore kompilatory zglaszaja bledy.
*/

int str_len(char s[]){
    int i = 0;
    for(i = 0;s[i] != '\0';){
        i++;
    }
    return i;
}

int lwr_str_cnt( char s[] ){
    int literki = 0;
    for(int i = 0;s[i] != '\0';i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            literki++;
        }
    }
    return literki;
}

int upr_str_cnt( char s[] ){
    int litery = 0;
    for(int i = 0;s[i] != '\0';i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            litery++;
        }
    }
    return litery;
}

int dgt_str_cnt( char s[] ){
    int cyfry = 0;
    for(int i = 0;s[i] != '\0';i++){
        if(s[i] >= '0' && s[i] <= '9'){
            cyfry++;
        }
    }
    return cyfry;
}

int nalpha_str_cnt( char s[] ){
    return lwr_str_cnt(s) + upr_str_cnt(s) + dgt_str_cnt(s);
}

int chr_str_cnt( char c, char s[] ){
    int jest = 0;
    for(int i = 0;s[i] != '\0';i++){
        if(s[i] == c){
            jest++;
        }
    }
    return jest;
}

int chr_str_pos( char c, char s[] ){
    int pozycja = 0;
    for(int i = 0;s[i] != '\0';i++){
        if(s[i] == c){
            return pozycja;
        }
        pozycja++;
    }
    return -1;
}

int chr_str_rpos( char c, char s[] ){
    return str_len(s) - chr_str_pos(c, s) - 1;
}

void str_rev( char s[] ){
    int i, koniec = str_len(s);
    for(i = 0,koniec--;i < koniec;i++,koniec--){
        char c = s[i];
        s[i] = s[koniec];
        s[koniec] = c;
    }
}

int main(){
  char line[ MAX_LEN ];
  char c;
  int pos;

  cout << "\n\nWpisz linie tekstu: ";
  cin.getline( line, MAX_LEN );

  cout << "\nLiczba znakow           : " << str_len( line );
  cout << "\nLiczba malych liter     : " << lwr_str_cnt( line );
  cout << "\nLiczba duzych liter     : " << upr_str_cnt( line );
  cout << "\nLiczba cyfr             : " << dgt_str_cnt( line );
  cout << "\nLiczba alfanumerycznych : " << nalpha_str_cnt( line );

  cout << "\n\nPodaj pojedynczy znak: ";
  cin.get( c );

  cout << "\nLiczba wystapien znaku  " << c << " : " << chr_str_cnt( c, line );

  if( ( pos = chr_str_pos( c, line ) ) != -1 )
    cout << "\nPierwsze wystapienie znaku " << c << " od poczatku : " << pos + 1;
  else
    cout << "\nZnak " << c << " nie zostal znaleziony";

  if( ( pos = chr_str_rpos( c, line ) ) != -1 )
    cout << "\nPierwsze wystapienie znaku " << c << " od konca : " << pos + 1;
  else
    cout << "\nZnak " << c << " nie zostal znaleziony";

  cout << "\n\nNapis oryginalny : " << line;
  str_rev( line );
  cout << "\nNapis odwrocony  : " << line;

  cin.ignore();
  cin.get();
  return EXIT_SUCCESS;
}
