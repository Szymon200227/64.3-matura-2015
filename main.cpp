#include <iostream>
#include <fstream>
using namespace std;


const int SIZE = 200;
ifstream in("obrazek.txt");
char tab[21][21];

void wczytaj() 
{
  for (int i = 0; i < 21; i++) 
  {
    for (int j = 0; j < 21; j++) 
	{
      if (i == 20 && j == 20) return;
      in >> tab[i][j];
    }
  }
}




int poziomo() 
{
  int sum = 0, licznik = 0;
  
  for (int i = 0; i < 20; i++) 
  {
    for (int j = 0; j < 21; j++) 
	{
      if (tab[i][j] == '1' && j != 20) sum++;
      if (j == 20) 
	  {
        if (sum % 2 == 0 && tab[i][j] == '1') licznik++;
        if (sum % 2 == 1 && tab[i][j] == '0') licznik++; 
      }
    }
    sum = 0;
  }
  return licznik;
}

int pionowo() 
{
  int sum = 0, licznik = 0;
  for (int i = 0; i < 20; i++) 
  {
    for (int j = 0; j < 21; j++) 
	{
      if (tab[j][i] == '1' && j != 20) sum++;
      if (j == 20) 
	  {
        if (sum % 2 == 0 && tab[j][i] == '1') licznik++;
        if (sum % 2 == 1 && tab[j][i] == '0') licznik++; 
      }
    }
    sum = 0;
  }
  return licznik;
}

int nieParzyste() 
{
  return pionowo() + poziomo();
}

bool jest_poprawnie () 
{
  if (nieParzyste() == 0) return true;
}

bool jest_naprawialne() 
{
  if (jest_poprawnie()) return false;
  if (poziomo() < 2 && pionowo() < 2)
    return true;
}



int main() {


  int l_poprawnych = 0, l_naprawialne = 0, l_nienapr = 0, max_zla_parz = 0, zla_parz;


  
  for (int n = 0; n < SIZE; n++) 
  {
    wczytaj();

    if (jest_poprawnie()) l_poprawnych++;
    else if (jest_naprawialne()) l_naprawialne++;
    else l_nienapr++; 
	zla_parz = nieParzyste();
    if (zla_parz > max_zla_parz) max_zla_parz = zla_parz;
    
  }
  


  cout << "Zadanie 3:" << endl;
  cout << "Liczba poprawnych:" << l_poprawnych << endl;
  cout << "Liczba naprawialnych: " << l_naprawialne << endl;
  cout << "Liczba nienaprawialnych: " << l_nienapr << endl;
  cout << "Najwiecej zlej parzystosci: " << max_zla_parz << endl << endl;
  
}
