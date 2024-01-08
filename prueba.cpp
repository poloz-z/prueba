//SISTEMA DE INVENTARIO HIDROCAPITAL 
//EL USO DE ESTE SISTEMA ESTA DIRIGIDO PARA EL PERSONAL
//DEL DEPARTAMENTO DE TELECOMUNICACIONES DE DICHA EMPRESA
//UNEXCA - JORGE POLO - ROBIN GIL
// 2023-2024
#include <iostream>
#include <vector>
#include <iomanip>

//COLORES
#define RESET     "\033[0m"
#define ROJO      "\033[31m"
#define VERDE     "\033[32m"
#define AMARILLO  "\033[33m"
#define AZUL      "\033[34m"
#define MAGENTA   "\033[35m"
#define CYAN      "\033[36m"

using namespace std;

struct Equipos {
  int    id;
  string tipo_objeto;
  string marca;
  int    serial;
  string fecha_ingreso;
  string fecha_egreso;
};

class Inventario {
  private:
    vector<Equipos> lista_equipos;

  public: 
    int id = 0;
    void añadir_valor(string tipo, string marca, int serial,
                      string  fecha_i,string fecha_e) {
      id = id+1;
      lista_equipos.push_back({id, tipo, marca, serial, fecha_i, fecha_e});
    }

    void informe_de_equipos() {
      for (int x=0; x<lista_equipos.size(); x++) { //(Equipos equipo: lista_equipos) {
        cout << MAGENTA << left << setw(4) << lista_equipos[x].id
             << AZUL << setw(17) << lista_equipos[x].tipo_objeto 
             << setw(10) << lista_equipos[x].marca 
             << setw(8) << lista_equipos[x].serial 
             << setw(12)<< lista_equipos[x].fecha_ingreso << VERDE 
             << setw(12) << lista_equipos[x].fecha_egreso << RESET << endl;
      }
    }

    void actualizar_valor(int id, string fecha_egreso) {
      for (int x=0; x <= lista_equipos.size(); x++) {
        if (lista_equipos[x].id == id) {
          lista_equipos[x].fecha_egreso = fecha_egreso;
          cout << AMARILLO <<  "Valor actualizado" << RESET << endl;
          break;
        } else if (x > lista_equipos.size()) {
          cout << ROJO << "Equipo no encontrado" << RESET << endl;
        }

      }
    }

    void filtrar_valor(string tipo_objeto) {
      for (int x=0; x < lista_equipos.size(); x++) {
        if (lista_equipos[x].tipo_objeto == tipo_objeto) {
          cout << MAGENTA << left << setw(4) << lista_equipos[x].id
              << AZUL << left << setw(17) << lista_equipos[x].tipo_objeto 
              << setw(10) << lista_equipos[x].marca 
              << setw(8) << lista_equipos[x].serial 
              << setw(12)<< lista_equipos[x].fecha_ingreso << VERDE 
              << setw(12) << lista_equipos[x].fecha_egreso << RESET << endl;
        } 
      }
    }

    void eliminar_valor (int serial) {
      for (auto equipos=lista_equipos.begin(); equipos!=lista_equipos.end(); equipos++) {
        if (equipos->serial == serial) {
          lista_equipos.erase(equipos);
          cout << AMARILLO << "Eliminado con exito" << RESET << endl;
          break;
        } else {
          cout << ROJO << "Equipo no encontrado!" << RESET << endl; 
        }
      }
    }
};

void menu(Inventario* inventario) {
  int serial_e, id;
  string tipo_e, marca_e, fechai_e, fechae_e, opcion;
  cout << CYAN << "Bienvenido al Sistema de Inventario de HIDROCAPITAL"<< endl
       << "Para uso exclusivo para el departamento de telecomunicaciones." 
       << RESET << endl << endl;

  do {
  cout << CYAN 
       << "1-. AÑADIR UN EQUIPO." << endl  
       << "2-. AGREGAR FECHA DE EGRESO DE UN EQUIPO." << endl
       << "3-. ELIMINAR EL REGISTRO DE UN EQUIPO." << endl
       << "4-. FILTRAR UN EQUIPO." << endl 
       << "5-. GENERAR LISTA DE EQUIPOS GENERAL." << endl
       << "6-. SALIR." << RESET << endl 
       << ": ";  
  cin >> opcion;
  switch (stoi(opcion))
  {
  case 1:
    cout << CYAN << "ESCRIBA EL TIPO DE EQUIPO: " << MAGENTA;
    cin >> tipo_e;
    cout << CYAN << "ESCRIBA LA MARCA DEL EQUIPO: " << MAGENTA;
    cin >> marca_e;
    cout << CYAN << "ESCRIBA EL SERIAL DEL EQUIPO: " << MAGENTA;
    cin >> serial_e;
    cout << CYAN << "ESCRIBA LA FECHA DE INGRESO DEL PRODUCTO: " << MAGENTA;
    cin >> fechai_e; 
    cout << RESET << endl;
    inventario->añadir_valor(tipo_e,marca_e,serial_e,fechai_e,"X");
    break;
  case 2:
    cout << CYAN << "INGRESE EL ID DEL EQUIPO: " << MAGENTA;
    cin >> id;
    cout << CYAN << "INGRESE LA FECHA DE EGRESO DEL EQUIPO: " << MAGENTA;
    cin >> fechae_e;
    inventario->actualizar_valor(id,fechae_e);
    cout << RESET << endl;
    break;
  case 3:
    cout << CYAN << "INGRESE EL SERIAL DEL EQUIPO: " << MAGENTA;
    cin >> serial_e;
    cout << RESET << endl;
    inventario->eliminar_valor(serial_e);
    break;
  case 4:
    cout << CYAN << "INGRESE EL TIPO DE EQUIPO: " << MAGENTA;
    cin >> tipo_e;
    cout << RESET << endl;
    inventario->filtrar_valor(tipo_e);
    break;
  case 5:
    cout << endl;
    inventario->informe_de_equipos();
    cout << endl;
    break;
  default:
    cout << ROJO << "OPCION NO ENCONTRADA!" << RESET << endl;
    break;
  }
  } while (stoi(opcion) != 6);
}

int main() {
  Inventario* inventario = new Inventario();
  menu(inventario);
  delete inventario;

  return 0;
}