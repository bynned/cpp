#include <iostream>
#include <numeric>
using namespace std;

int random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first)
   {
      srand(time(NULL) );
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

int search(int varatuthuoneet[], int N, int valittuHuone)
{
    int i;
        for (i = 0; i < N; i++)
            if (varatuthuoneet[i] == valittuHuone)
        return i;
    return -1;
}

int main() {
    int randomHuoneluku;
    randomHuoneluku = random(30,70);// Generoidaan max määrä huoneita random funktiolla.
    
    int hintaYö;
    hintaYö = random(80,100);//Generoidaan random hinta yölle 80-100.
    
    //Generoidaan looppi, jossa voidaan randomisti kertoa ohjelmalle mitkä 10 huonetta ovat varattuja.
    int varatuthuoneet[9];
    for(int i = 0; i < 10; i++){
        varatuthuoneet[i] = random(1, randomHuoneluku);
    }
    int sum = 0;
    
    for(int i = 0; i < randomHuoneluku; i++) {
        int valittuHuone;
        
        cout << "\nValitse huone väliltä: 1-" << randomHuoneluku << endl;
        cout << "Hinta per yö: " << hintaYö << "€" << endl;
        cout << "Varatut huoneet: " << endl;
        //Loopataan arrayn läpi jotta käyttäjä näkee mitkä ovat varattuja.
        for(int i = 0; i < 10; i++){
            cout<<varatuthuoneet[i] << " ";
        }
        cout << "\nSyötä \"0\" kun haluat poistua ohjelmasta " << endl;
        
        //Otetaan inputtia käyttäjältä minkä huoneen haluaa valita.
        cin >> valittuHuone;
                 
        //Kun halutaan poistua ohjelmasta, annetaan takaisin summa joka on kertynyt huonevarauksista
        if(valittuHuone == 0) {
            cout << "Hinta huoneista yhteensä: " << sum << "€" << endl;
            exit(0); //Poistutaan ohjelmasta
        }
        if(valittuHuone > randomHuoneluku || valittuHuone < 1) {
            cout << "Syötä huonenumero 1-" << randomHuoneluku << " väliltä :)" << endl;
            continue;
        }
        
        int N = sizeof(varatuthuoneet) / sizeof(varatuthuoneet[0]);
        
        //Tarkistetaan ettei koiteta varata varattua huonetta.
        int result = search(varatuthuoneet, N, valittuHuone);
        if(result == -1) {
            int Montako;
            cout << "Kuinka moneksi yöksi haluaisit jäädä?" << endl;
            cin >> Montako;
            
            int oidensumma = hintaYö * Montako;
            
            sum += oidensumma;
            cout << "Huone " << valittuHuone << " on varattu sinulle " << Montako << " yöksi" << endl;
        } else {
            cout << "Huone " << valittuHuone << " on valitettavasti varattu :(" << endl;
        }
    }
    
}
