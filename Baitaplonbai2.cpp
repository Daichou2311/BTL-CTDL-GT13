#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* taoNode(char x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void chenCuoi(Node*& head, char x) {
    Node* p = taoNode(x);
    if (head == NULL) head = p;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
}

void xoaDanhSach(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void nhapChuoi(Node*& head) {
    xoaDanhSach(head);
    string s;
    cout << "Nhap chuoi: ";
    cin.ignore();
    getline(cin, s);
    for (char c : s) chenCuoi(head, c);
}

void inChuoi(Node* head) {
    if (!head) {
        cout << "Chuoi rong!\n";
        return;
    }
    cout << "Chuoi hien tai: ";
    while (head) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

void chenTaiViTri(Node*& head, char x, int pos) {
    Node* p = taoNode(x);
    if (pos == 0) {
        p->next = head;
        head = p;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Vi tri khong hop le!\n";
        delete p;
        return;
    }
    p->next = temp->next;
    temp->next = p;
}

void xoaTaiViTri(Node*& head, int pos) {
    if (!head) {
        cout << "Danh sach rong!\n";
        return;
    }
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp; i++)
        temp = temp->next;
    if (!temp || !temp->next) {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void daoChuoi(Node*& head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    Node* head = NULL;
    int chon;

    do {
        cout << "\n==== XU LY XAU KY TU ====\n";
        cout << "1. Nhap chuoi\n";
        cout << "2. Chen ky tu tai vi tri\n";
        cout << "3. Xoa ky tu tai vi tri\n";
        cout << "4. Dao chuoi\n";
        cout << "5. In chuoi hien tai\n";
        cout << "6. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        switch (chon) {
        case 1:
            nhapChuoi(head);
            break;
        case 2: {
            char x; int pos;
            cout << "Nhap ky tu can chen: ";
            cin >> x;
            cout << "Nhap vi tri chen (bat dau tu 0): ";
            cin >> pos;
            chenTaiViTri(head, x, pos);
            break;
        }
        case 3: {
            int pos;
            cout << "Nhap vi tri xoa (bat dau tu 0): ";
            cin >> pos;
            xoaTaiViTri(head, pos);
            break;
        }
        case 4:
            daoChuoi(head);
            cout << "Da dao chuoi thanh cong!\n";
            break;
        case 5:
            inChuoi(head);
            break;
        case 6:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 6);

    xoaDanhSach(head);
    return 0;
}

