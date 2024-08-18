#include <iostream>
#include <string>

using namespace std;

const int MAX_COMP = 100;

struct compsSpecification {
  string name;
  string processor;
  string ram;
  string vga;
  string storage;
  string psu;
  string os;
};

compsSpecification spec[MAX_COMP];
int compCount = 0;

void clearScreen();
void displayTitle();
void displayComp(compsSpecification comp[], int itemCount);
void addComp(compsSpecification comp[], int &itemCount);
void updateComp(compsSpecification comp[], int &itemCount);
void deleteComp(compsSpecification comp[], int &itemCount);

int main() {
  clearScreen();
  char mainOption;

  do {
    string tle1 = "               Comps               ";

    cout << char(201);
    for (int i = 0; i < tle1.size(); i++) {
      cout << char(205);
    }
    cout << char(187) << endl;

    cout << char(186) << tle1 << char(186) << endl;

    cout << char(200);
    for (int i = 0; i < tle1.size(); i++) {
      cout << char(205);
    }
    cout << char(188) << endl << endl;

    cout << "1 | Lihat Komputer yang tersedia" << endl;
    cout << "2 | Tambahkan Komputer baru" << endl;
    cout << "3 | Perbarui Informasi Komputer" << endl;
    cout << "4 | Hapus Informasi Komputer" << endl;
    cout << "5 | Keluar" << endl << endl;

    cout << "Pilih menu yang ingin Anda akses => ";
    cin >> mainOption;

    switch (mainOption) {
    case '1':
      displayComp(spec, compCount);
      break;
    case '2':
      addComp(spec, compCount);
      break;
    case '3':
      updateComp(spec, compCount);
      break;
    case '4':
      deleteComp(spec, compCount);
      break;
    case '5':
      clearScreen();
      cout << "Terima Kasih telah menggunakan Program yang telah kami buat."
           << endl
           << endl;
      break;
    default:
      clearScreen();
      cout << "Pilihan Anda tidak ditemukan. Pilih antara angka 1-5!" << endl
           << endl;
    }
  } while (mainOption != '5');

  system("pause");
  return 0;
}

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

bool isDigit(int index) {
  for (int i = 1; i <= index; i++) {
    if (!(i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 ||
          i == 8 || i == 9)) {
      return false;
    }
  }
  return true;
}

void displayTitle() {
  string title = "     Display Specification     ";
  // atas
  cout << char(201);
  for (int i = 0; i < title.size(); i++) {
    cout << char(205);
  }
  cout << char(187) << endl;

  // tengah
  cout << char(186) << title << char(186) << endl;

  // bawah
  cout << char(200);
  for (int i = 0; i < title.size(); i++) {
    cout << char(205);
  }
  cout << char(188) << endl << endl;
}

void addTitle() {
  string title = "           Add Computer           ";

  cout << char(201);
  for (int i = 0; i < title.size(); i++) {
    cout << char(205);
  }
  cout << char(187) << endl;

  cout << char(186) << title << char(186) << endl;

  cout << char(200);
  for (int i = 0; i < title.size(); i++) {
    cout << char(205);
  }
  cout << char(188) << endl << endl;
}

void updateTitle() {
  string title = "           Update Computer           ";

  cout << char(201);
  for (int i = 0; i < title.size(); i++) {
    cout << char(205);
  }
  cout << char(187) << endl;

  cout << char(186) << title << char(186) << endl;

  cout << char(200);
  for (int i = 0; i < title.size(); i++) {
    cout << char(205);
  }
  cout << char(188) << endl << endl;
}

void deleteTitle() {
  string title = "           Delete Computer           ";

  cout << char(201);
  for (int i = 0; i < title.size(); i++) {
    cout << char(205);
  }
  cout << char(187) << endl;

  cout << char(186) << title << char(186) << endl;

  cout << char(200);
  for (int i = 0; i < title.size(); i++) {
    cout << char(205);
  }
  cout << char(188) << endl << endl;
}

void displayComp(compsSpecification comp[], int itemCount) {
  clearScreen();

  displayTitle();

  if (itemCount == 0) {
    char choice;

    cout << "Belum ada Produk yang bisa ditampilkan!" << endl << endl;
    do {
      cout << "Apakah anda ingin kembali (y/n)? ";
      cin >> choice;
      switch (choice) {
      case 'y':
      case 'Y':
        clearScreen();
        return;
        break;
      case 'n':
      case 'N':
        break;
      default:
        cout << "Pilihan Anda tidak ditemukan!" << endl << endl;
        break;
      }
    } while (choice != 'y' && choice != 'Y');
  }

  for (int i = 0; i < itemCount; i++) {
    cout << (i + 1) << ". Nama      : " << comp[i].name << endl;
    cout << "   Processor : " << comp[i].processor << endl;
    cout << "   RAM       : " << comp[i].ram << endl;
    cout << "   VGA       : " << comp[i].vga << endl;
    cout << "   Storage   : " << comp[i].storage << endl;
    cout << "   PSU       : " << comp[i].psu << endl;
    cout << "   OS        : " << comp[i].os << endl << endl;
  }

  char choice;
  do {
    cout << "Apakah anda ingin kembali (y/n)? ";
    cin >> choice;
    switch (choice) {
    case 'y':
    case 'Y':
      clearScreen();
      return;
      break;
    case 'n':
    case 'N':
      break;
    default:
      cout << "Pilihan Anda tidak ditemukan!" << endl << endl;
      break;
    }
  } while (choice != 'y' && choice != 'Y');
}

void addComp(compsSpecification comp[], int &itemCount) {
  clearScreen();
  compsSpecification newComp;

  addTitle();

  cin.ignore();
  cout << "   Nama      : ";
  getline(cin, newComp.name);
  cout << "   Processor : ";
  getline(cin, newComp.processor);
  cout << "   RAM       : ";
  getline(cin, newComp.ram);
  cout << "   VGA       : ";
  getline(cin, newComp.vga);
  cout << "   Storage   : ";
  getline(cin, newComp.storage);
  cout << "   PSU       : ";
  getline(cin, newComp.psu);
  cout << "   OS        : ";
  getline(cin, newComp.os);

  comp[itemCount++] = newComp;
  clearScreen();
  cout << "KOMPUTER BERHASIL DITAMBAHKAN!" << endl << endl;
}

void updateComp(compsSpecification comp[], int &itemCount) {
  clearScreen();
  int index;

  updateTitle();

  if (itemCount == 0) {
    char choice;
    cout << "Tidak ada data Komputer yang dapat diperbaharui!" << endl << endl;
    do {
      cout << "Apakah anda ingin kembali (y/n)? ";
      cin >> choice;
      switch (choice) {
      case 'y':
      case 'Y':
        clearScreen();
        return;
        break;
      case 'n':
      case 'N':
        break;
      default:
        cout << "Pilihan Anda tidak ditemukan!" << endl << endl;
        break;
      }
    } while (choice != 'y' && choice != 'Y');
  }

  for (int i = 0; i < itemCount; i++) {
    cout << (i + 1) << ". Nama      : " << comp[i].name << endl;
    cout << "   Processor : " << comp[i].processor << endl;
    cout << "   RAM       : " << comp[i].ram << endl;
    cout << "   VGA       : " << comp[i].vga << endl;
    cout << "   Storage   : " << comp[i].storage << endl;
    cout << "   PSU       : " << comp[i].psu << endl;
    cout << "   OS        : " << comp[i].os << endl << endl;
  }

  cout << "Pilih nomor mana yang ingin Anda perbarui." << endl << endl;

  cout << "Pilih menu yang ingin Anda akses => ";
  cin >> index;

  isDigit(index);

  if (index >= 1 && index <= itemCount) {
    char choice;
    clearScreen();
    updateTitle();
    cout << "Informasi Komputer saat ini:" << endl;
    cout << index << ". Nama      : " << comp[index - 1].name << endl;
    cout << "   Processor : " << comp[index - 1].processor << endl;
    cout << "   RAM       : " << comp[index - 1].ram << endl;
    cout << "   VGA       : " << comp[index - 1].vga << endl;
    cout << "   Storage   : " << comp[index - 1].storage << endl;
    cout << "   PSU       : " << comp[index - 1].psu << endl;
    cout << "   OS        : " << comp[index - 1].os << endl << endl;

    cout << "Data Komputer ditemukan." << endl;
    do {
      cout << "Apakah Anda yakin ingin merubah Data ini? (y/n)? ";
      cin >> choice;
      switch (choice) {
      case 'y':
      case 'Y':
        continue;
      case 'n':
      case 'N':
        clearScreen();
        return;
        break;
      default:
        cout << "Pilihan Anda tidak ditemukan!" << endl << endl;
        break;
      }
    } while (choice != 'y' && choice != 'Y');
    cout << endl;

    cout << "Masukkan Data Komputer yang baru!" << endl;

    cin.ignore();
    cout << index << ". Nama      : ";
    getline(cin, comp[index - 1].name);
    cout << "   Processor : ";
    getline(cin, comp[index - 1].processor);
    cout << "   RAM       : ";
    getline(cin, comp[index - 1].ram);
    cout << "   VGA       : ";
    getline(cin, comp[index - 1].vga);
    cout << "   Storage   : ";
    getline(cin, comp[index - 1].storage);
    cout << "   PSU       : ";
    getline(cin, comp[index - 1].psu);
    cout << "   OS        : ";
    getline(cin, comp[index - 1].os);

    clearScreen();
    cout << "DATA KOMPUTER BERHASIL DIPERBAHARUI!" << endl << endl;
  } else {
    clearScreen();
    cout << "Pilihan Anda tidak ditemukan!" << endl << endl;
  }
}

void deleteComp(compsSpecification comp[], int &itemCount) {
  clearScreen();
  int index;

  deleteTitle();

  if (itemCount == 0) {
    char choice;
    cout << "Tidak ada data Komputer yang dapat dihapus!" << endl << endl;
    do {
      cout << "Apakah anda ingin kembali (y/n)? ";
      cin >> choice;
      switch (choice) {
      case 'y':
      case 'Y':
        clearScreen();
        return;
        break;
      case 'n':
      case 'N':
        break;
      default:
        cout << "Pilihan Anda tidak ditemukan!" << endl << endl;
        break;
      }
    } while (choice != 'y' && choice != 'Y');
  }

  for (int i = 0; i < itemCount; i++) {
    cout << (i + 1) << ". Nama      : " << comp[i].name << endl;
    cout << "   Processor : " << comp[i].processor << endl;
    cout << "   RAM       : " << comp[i].ram << endl;
    cout << "   VGA       : " << comp[i].vga << endl;
    cout << "   Storage   : " << comp[i].storage << endl;
    cout << "   PSU       : " << comp[i].psu << endl;
    cout << "   OS        : " << comp[i].os << endl << endl;
  }

  cout << "Pilih nomor mana yang ingin Anda hapus." << endl << endl;

  cout << "Pilih menu yang ingin Anda akses => ";
  cin >> index;

  if (index >= 1 && index <= itemCount) {
    char choice;
    clearScreen();
    deleteTitle();
    cout << "Informasi Komputer:" << endl;
    cout << index << ". Nama      : " << comp[index - 1].name << endl;
    cout << "   Processor : " << comp[index - 1].processor << endl;
    cout << "   RAM       : " << comp[index - 1].ram << endl;
    cout << "   VGA       : " << comp[index - 1].vga << endl;
    cout << "   Storage   : " << comp[index - 1].storage << endl;
    cout << "   PSU       : " << comp[index - 1].psu << endl;
    cout << "   OS        : " << comp[index - 1].os << endl << endl;

    cout << "Data Komputer ditemukan." << endl;
    do {
      cout << "Apakah Anda yakin ingin menghapus Data ini? (y/n)? ";
      cin >> choice;
      switch (choice) {
      case 'y':
      case 'Y':
        continue;
      case 'n':
      case 'N':
        clearScreen();
        return;
        break;
      default:
        cout << "Pilihan Anda tidak ditemukan!" << endl << endl;
        break;
      }
    } while (choice != 'y' && choice != 'Y');
    cout << endl;

    for (int i = index - 1; i < itemCount; i++) {
      comp[i] = comp[i + 1];
    }
    --itemCount;
    cout << "DATA KOMPUTER BERHASIL DIHAPUS!" << endl << endl;
  } else {
    clearScreen();
    cout << "Pilihan Anda tidak ditemukan!" << endl << endl;
  }
}