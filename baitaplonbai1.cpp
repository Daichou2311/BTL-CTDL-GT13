#include <bits/stdc++.h>
using namespace std;


class HangHoa {
private:
    string maHang, tenHang;
    double gia;
    int soLuong;

public:
    HangHoa(string ma = "", string ten = "", double g = 0, int sl = 0)
        : maHang(ma), tenHang(ten), gia(g), soLuong(sl) {}


    friend istream& operator>>(istream& in, HangHoa& h) {
        cout << "Nhap ma hang: ";
        getline(in, h.maHang);
        cout << "Nhap ten hang: ";
        getline(in, h.tenHang);
        cout << "Nhap gia: ";
        in >> h.gia;
        cout << "Nhap so luong: ";
        in >> h.soLuong;
        in.ignore();
        return in;
    }


    friend ostream& operator<<(ostream& out, const HangHoa& h) {
        out << left << setw(15) << h.maHang
            << setw(25) << h.tenHang
            << setw(15) << h.gia
            << setw(10) << h.soLuong;
        return out;
    }


    bool operator<(const HangHoa& khac) const {
        return gia < khac.gia;
    }

    double layGia() const { return gia; }
    string layMa() const { return maHang; }
};


class DanhSachHangHoa {
private:
    vector<HangHoa> danhSach;

public:
    void them(const HangHoa& h) {
        danhSach.push_back(h);
        cout << ">> Da them hang hoa thanh cong!\n";
    }

    void sua() {
        int viTri;
        cout << "Nhap vi tri hang hoa can sua (bat dau tu 0): ";
        cin >> viTri;
        cin.ignore();
        if (viTri < 0 || viTri >= danhSach.size()) {
            cout << ">> Vi tri khong hop le!\n";
            return;
        }
        cout << "Nhap thong tin moi cho hang hoa:\n";
        cin >> danhSach[viTri];
    }

    void xoa() {
        int viTri;
        cout << "Nhap vi tri hang hoa can xoa (bat dau tu 0): ";
        cin >> viTri;
        if (viTri < 0 || viTri >= danhSach.size()) {
            cout << ">> Vi tri khong hop le!\n";
            return;
        }
        danhSach.erase(danhSach.begin() + viTri);
        cout << ">> Da xoa thanh cong!\n";
    }

    void xuat() const {
        cout << left << setw(15) << "Ma hang"
             << setw(25) << "Ten hang"
             << setw(15) << "Gia"
             << setw(10) << "So luong" << endl;
        cout << string(65, '-') << endl;
        for (auto h : danhSach)
            cout << h << endl;
    }

    void sapXepTang() {
        sort(danhSach.begin(), danhSach.end());
        cout << ">> Da sap xep danh sach theo gia tang dan!\n";
    }

    void timMax() const {
        if (danhSach.empty()) {
            cout << ">> Danh sach rong!\n";
            return;
        }
        double maxGia = danhSach[0].layGia();
        for (auto& h : danhSach)
            if (h.layGia() > maxGia)
                maxGia = h.layGia();

        cout << "Hang hoa co gia cao nhat:\n";
        cout << left << setw(15) << "Ma hang"
             << setw(25) << "Ten hang"
             << setw(15) << "Gia"
             << setw(10) << "So luong" << endl;
        for (auto& h : danhSach)
            if (h.layGia() == maxGia)
                cout << h << endl;
    }

    void timMin() const {
        if (danhSach.empty()) {
            cout << ">> Danh sach rong!\n";
            return;
        }
        double minGia = danhSach[0].layGia();
        for (auto& h : danhSach)
            if (h.layGia() < minGia)
                minGia = h.layGia();

        cout << "Hang hoa co gia thap nhat:\n";
        cout << left << setw(15) << "Ma hang"
             << setw(25) << "Ten hang"
             << setw(15) << "Gia"
             << setw(10) << "So luong" << endl;
        for (auto& h : danhSach)
            if (h.layGia() == minGia)
                cout << h << endl;
    }
};


class UngDungQuanLy {
private:
    DanhSachHangHoa danhSach;

public:
    void menu() {
        int luaChon;
        do {
            system("cls");
            cout << " MENU QUAN LY HANG HOA \n";
            cout << "1. Them hang hoa\n";
            cout << "2. Sua hang hoa\n";
            cout << "3. Xoa hang hoa\n";
            cout << "4. Xuat danh sach\n";
            cout << "5. Sap xep tang dan theo gia\n";
            cout << "6. Tim hang co gia cao nhat\n";
            cout << "7. Tim hang co gia thap nhat\n";
            cout << "8. Thoat\n";
            cout << "Chon 1 so(1->8): ";
            cin >> luaChon;
            cin.ignore();

            switch (luaChon) {
                case 1: {
                    HangHoa h;
                    cin >> h;
                    danhSach.them(h);
                    break;
                }
                case 2:
                    danhSach.sua();
                    break;
                case 3:
                    danhSach.xoa();
                    break;
                case 4:
                    danhSach.xuat();
                    break;
                case 5:
                    danhSach.sapXepTang();
                    break;
                case 6:
                    danhSach.timMax();
                    break;
                case 7:
                    danhSach.timMin();
                    break;
                case 8:
                    cout << ">> Thoat chuong trinh!\n";
                    return;
                default:
                    cout << ">> Lua chon khong hop le!\n";
            }
            cout << "\n";
            system("pause");
        } while (true);
    }
};


int main() {
    UngDungQuanLy ungDung;
    ungDung.menu();
    return 0;
}

