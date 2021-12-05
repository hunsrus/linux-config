#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string dia;

    if(argc > 1)
    {
        dia = argv[1];
    }else
    {
        cout << "Pasa el argumento alce" << endl;
        return 0;
    }

    if(dia == "lun")
    {
        cout << "16:30-18:45 | (T)ASYS" << endl;
        cout << "18:55-20:25 | (P)Medios de enlace" << endl;
        cout << "20:30-22:00 | (T)Medios de enlace";
    }else if(dia == "mar")
    {
        cout << "18:00-21:00 | TCI" << endl;
        cout << "21:05-22:35 | (P)EAPLI";
    }else if(dia == "mié")
    {
        cout << "09:00-11:15 | (P)ASYS" << endl;
        cout << "16:00-17:30 | Legislación" << endl;
        cout << "18:30-22:30 | Física Electrónica" << endl;
    }else if(dia == "jue")
    {
        cout << "18:50-20:20 | (T)TDI" << endl;
    }else if(dia == "vie")
    {
        cout << "16:00-\"18:00\" | (T)EAPLI" << endl;
        cout << "18:15-19:45 | (P)TDI";
    }else cout << "No hay horario que cumplir" << endl << "SAPEEE!!";

    return 0;
}
