#include <cstdlib>
#include <iostream>
using namespace std;
const int MAX_LEN = 128;

int str_len(char * s){
    int len = 0;
        for(;*s != '\0';s++){
            len++;
        }
    return len;
}

int lwr_str_cnt(char * s){
    int literki = 0;
    for(;*s != '\0';s++){
        if(*s >= 'a' && *s <= 'z'){
            literki++;
        }
    }
    return literki;
}

int upr_str_cnt(char * s){
    int litery = 0;
    for(;*s != '\0';s++){
        if(*s >= 'A' && *s <= 'Z'){
            litery++;
        }
    }
    return litery;
}

int dgt_str_cnt(char * s){
    int cyfry = 0;
    for(int i = 0;*s != '\0';s++){
        if(*s >= '0' && *s <= '9'){
            cyfry++;
        }
    }
    return cyfry;
}

int nalpha_str_cnt(char * s){
    return lwr_str_cnt(s) + upr_str_cnt(s) + dgt_str_cnt(s);
}

int chr_str_cnt(char c, char * s){
    int jest = 0;
    for(;*s != '\0';s++){
        if(*s == c){
            jest++;
        }
    }
    return jest;
}

char * chr_str_pos(char c, char * s){
    for(;*s != '\0';s++){
        if(*s == c){
            return s+1;
        }
    }
    return NULL;
}

char * chr_str_rpos(char c, char * s){
    char * pos = NULL;
    int len = str_len(s);
    for(;*s != '\0';s++){
        if(*s == c){
            pos = s+1;
        }
    }
    return pos;
}

char * str_rev(char * s){ //sporadyczne bledy, do poprawy
    int i,len = str_len(s),koniec = len-1;
    for(i = 0; i <=(len/2);i++, koniec--){
        char c = s[i];
        s[i] = s[koniec];
        s[koniec] = c;
    }
    return s;
}

int str_word_count(char * s){
    int slowa = 0;
        for(;*s != '\0';s++){
            if(*s != ' '){
                slowa++;
                while(*s != ' ' && *s != '\0'){
                    s++;
                }
            }
        }
    return slowa;
}

int main(){
    char line[MAX_LEN];
    char c;
    char * pos;

    cout << "\n\nWpisz linie tekstu: ";
    cin.getline(line, MAX_LEN-1);

    cout << "\nLiczba znakow         : " << str_len(line);
    cout << "\nLiczba malych liter   : " << lwr_str_cnt(line);
    cout << "\nLiczba duzych liter   : " << upr_str_cnt(line);
    cout << "\nLiczba cyfr           : " << dgt_str_cnt(line);
    cout << "\nLiczba znakw alphanum : " << nalpha_str_cnt(line);

    cout << "\n\nPodaj pojedynczy znak: ";
    cin >> c;

    cout << "\nLiczba wystapien znaku " << c << ": " << chr_str_cnt(c, line);

    if((pos = chr_str_pos(c, line)) != 0)
        cout << "\nPierwsze wystapienie znaku " << *pos << " na pozycji: " << pos - line;
    else
        cout << "\nZnak " << c << " nie zostal znaleziony";

    if((pos = chr_str_rpos(c, line)) != 0)
        cout << "\nOstatnie wystapienie znaku " << *pos  << " na pozycji: " << pos - line;
    else
        cout << "\nZnak " << c << " nie zostal znaleziony";

    cout << "\n\nNapis oryginalny : " << line;
    cout << "\nNapis odwrocony  : " << str_rev(line);
    cout << "\nLiczba slow w napisie: " << str_word_count(line);
    cin.ignore();
  cin.get();
  return EXIT_SUCCESS;
}
