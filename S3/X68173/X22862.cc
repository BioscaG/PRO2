#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std; 

double redondear(double r) {  
    return int(10.*(r + 0.05)) / 10.0;
} 

void opcio_num1(Cjt_estudiants& c) {
    Estudiant est; 
    est.llegir(); 
    if (c.mida() == c.mida_maxima()) cout << "no se pueden añadir mas estudiantes" << endl << endl; 
    else if (c.existeix_estudiant(est.consultar_DNI())) cout << "el estudiante " << est.consultar_DNI() << " ya estaba" << endl << endl;
    else {
        c.afegir_estudiant(est); 
    }
}

void opcio_num2(Cjt_estudiants& c) {
    int dni; 
    cin >> dni; 
    if (not c.existeix_estudiant(dni)) cout << "el estudiante " << dni << " no esta" << endl << endl;
    else if (not c.consultar_estudiant(dni).te_nota()) cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
    else cout << "el estudiante " << dni << " tiene nota " << c.consultar_estudiant(dni).consultar_nota() << endl << endl; 
}

void opcio_num3(Cjt_estudiants& c) {
    Estudiant est; 
    est.llegir(); 
    if (not c.existeix_estudiant(est.consultar_DNI())) cout << "el estudiante " << est.consultar_DNI() << " no esta" << endl << endl; 
    else c.modificar_estudiant(est);  
}

void opcio_num4(Cjt_estudiants& c) {
    for (int i = 1; i <= c.mida(); ++i) {
        if (c.consultar_iessim(i).te_nota()) {
            Estudiant est = c.consultar_iessim(i);
            est.modificar_nota(redondear(est.consultar_nota())); 
            c.modificar_iessim(i, est);
        }
    }
}

int main() {
    Cjt_estudiants c; 
    c.llegir(); 
    int n; 
    cin >> n; 
    while (n != -8) {
        if (n == -1) opcio_num1(c); 
        else if (n == -2) opcio_num2(c); 
        else if (n == -3) opcio_num3(c);
        else if (n == -4) opcio_num4(c);
        else if (n == -5) {
            int dni;
            cin >> dni;
            c.esborrar_estudiant(dni); 
        }
        else if (n == -6) cout << c.estudiant_nota_max().consultar_DNI() << endl; 
        else {
            c.escriure(); 
            cout << endl; 
        }
        cin >> n;  
    }
}