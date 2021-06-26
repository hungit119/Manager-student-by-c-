#include"Funcion.h"

void menu(){
    cout << "\t\t\t\t\t\t=====CHUONG TRINH QUAN LI NHAN VIEN CPP NHOM 5=====" << endl;
    cout << "\t\t\t\t\t\t____________________________________________________" << endl;
    cout << "\t\t\t\t\t\t|_______________________Menu_______________________|" << endl;
    cout << "\t\t\t\t\t\t|1,<Them thong tin nhan vien vao danh sach>        |" << endl;
    cout << "\t\t\t\t\t\t|2,<Hien thi danh sach nhan vien>                  |" << endl;
    cout << "\t\t\t\t\t\t|3,<Luu nhan vien vao file                         |" << endl;
    cout << "\t\t\t\t\t\t|4,<Sua thong tin nhan vien theo Id>               |" << endl;
    cout << "\t\t\t\t\t\t|5,<Thong ke>                                      |" << endl;
    cout << "\t\t\t\t\t\t|6,<Tim kiem>                                      |" << endl;
    cout << "\t\t\t\t\t\t|7,<Sap xep>                                       |" << endl;
    cout << "\t\t\t\t\t\t|0,<Thoat>                                         |" << endl;
    return;
}
string nhanXet(NhanVien &nhanVien){
    if(nhanVien.ngayCongTB >= 30){
        nhanVien.quyetDinh = "Xuat sac";
    }
    else if(nhanVien.ngayCongTB >= 25){
        nhanVien.quyetDinh = "Can cai thien";
    }
    else if(nhanVien.ngayCongTB >= 20){
        nhanVien.quyetDinh = "Bi phe binh";
    }
    else if (nhanVien.ngayCongTB >= 10){
        nhanVien.quyetDinh = "Bi ki luat";
    }
    return nhanVien.quyetDinh;
}
void xuatSac(NhanVien nhanVien[],int n){
    for (int i = 0; i < n; i++) {
        if(nhanVien[i].quyetDinh == "Xuat sac"){
           cout<<"   "<<setw(20)<<left<<nhanVien[i].HoVaTen<<"| ngay cong TB: "<<nhanVien[i].ngayCongTB<<endl;
        }
    }
    return;
}
void canCaiThien(NhanVien nhanVien[],int n){
    for (int i = 0; i < n; i++) {
        if(nhanVien[i].quyetDinh == "Can cai thien"){
            cout<<"   "<<setw(20)<<left<<nhanVien[i].HoVaTen<<"| ngay cong TB: "<<nhanVien[i].ngayCongTB<<endl;
        }
    }
    return;
}
void biPheBinh(NhanVien nhanVien[],int n){
    for (int i = 0; i < n; i++) {
        if(nhanVien[i].quyetDinh == "Bi phe binh"){
            cout<<"   "<<setw(20)<<left<<nhanVien[i].HoVaTen<<"| ngay cong TB: "<<nhanVien[i].ngayCongTB<<endl;
        }
    }
    return;
}
void kiLuat(NhanVien nhanVien[],int n){
    for (int i = 0; i < n; i++) {
        if(nhanVien[i].quyetDinh == "Bi ki luat"){
            cout<<"   "<<setw(20)<<left<<nhanVien[i].HoVaTen<<"| ngay cong TB: "<<nhanVien[i].ngayCongTB<<endl;
        }
    }
    return;
}
int tongNgayCong(NhanVien &nhanVien){
    int tong = 0;
    for (int i = 0; i < 12; i++) {
         tong += nhanVien.ngaycong[i];
    }
    return tong;
}
int ngayCongTB(NhanVien &nhanVien){
    return tongNgayCong(nhanVien)/12;
}

void SuaThongTinNhanVien(NhanVien &nguoi){
    do {
        cout<<"<Nhap ID nhan vien thay the: ";
        cin>>nguoi.ID;
    } while (nguoi.ID < 0 or nguoi.ID >= 1000);
    cin.ignore();
    cout<<"<Nhap ho ten nhan vien thay the: ";
    getline(cin , nguoi.HoVaTen);
    cout<<"<Nhap gioi tinh nhan vien thay the (Nam hoac Nu): ";
    cin>>nguoi.gioitinh;
    for ( int i = 0 ; i < 12 ; i ++){
        cout<<"<Nhap so ngay cong thang "<<i+1<<":";
        cin>>nguoi.ngaycong[i];
        while (nguoi.ngaycong[i] < 0 or nguoi.ngaycong[i] > 31){
            cout<<"Vui long nhap du lieu hop le !!!";
            cout<<endl;
            cout<<"<Nhap so ngay cong thang "<<i+1<<":";
            cin>>nguoi.ngaycong[i];
        }
    }
    nguoi.tongNgayCong = tongNgayCong(nguoi);
    nguoi.ngayCongTB = ngayCongTB(nguoi);
    nguoi.quyetDinh = nhanXet(nguoi);
    return;
}

void capNhatNV(NhanVien nhanviens[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (nhanviens[i].ID == id) {
            found = 1;
            cout << "\n Cap nhat thong tin nhan vien co ID = " << id<<endl;
            SuaThongTinNhanVien(nhanviens[i]);
            break;
        }
    }
    if (found == 0) {
        printf("\n Nhan vien co ID = %d khong ton tai.", id);
    }
    return;
}

void Nhap( NhanVien &nguoi){
    do {
        cout<<"<Nhap ID nhan vien : ";
        cin>>nguoi.ID;
    } while (nguoi.ID < 0 or nguoi.ID >= 1000);
    cin.ignore();
    cout<<"<Nhap ho ten nhan vien : ";
    getline(cin , nguoi.HoVaTen);
    cout<<"<Nhap gioi tinh nhan vien (Nam hoac Nu) : ";
    cin>>nguoi.gioitinh;
    for ( int i = 0 ; i < 12 ; i ++){
        cout<<"<Nhap so ngay cong thang "<<i+1<<":";
        cin>>nguoi.ngaycong[i];
        while (nguoi.ngaycong[i] < 0 or nguoi.ngaycong[i] > 31){
            cout<<"Vui long nhap du lieu hop le !!!"<<endl;
            cout<<endl;
            cout<<"<Nhap so ngay cong thang "<<i+1<<":";
            cin>>nguoi.ngaycong[i];
        }
    }
    nguoi.tongNgayCong = tongNgayCong(nguoi);
    nguoi.ngayCongTB = ngayCongTB(nguoi);
    nguoi.quyetDinh = nhanXet(nguoi);
    return;
}
void NhapDanhSachNhanVien(NhanVien nhanViens[] , int n ){
        cout<<endl;
        cout<<"________________________________"<<endl;
        cout<<"<Nhap thong tin cua nhan vien thu "<<n+1<<" :\n\n";
        Nhap(nhanViens[n]);
        return;
}
void XuatNhanVien(NhanVien&nguoi){
    cout<<setw(5+3)<< left <<nguoi.ID;
    cout<<setw(25)<< left <<nguoi.HoVaTen;
    cout<<setw(11)<< left <<nguoi.gioitinh;
    for(int i = 0 ; i < 12 ; i ++)
        cout<<setw(3)<< left <<nguoi.ngaycong[i]<<" ";
    cout<<setw(8)<< right <<nguoi.tongNgayCong;
    cout<<setw(8)<< right <<nguoi.ngayCongTB;
    cout<<endl;
    return;
}
void printLine(int n){
    for(int i = 0 ; i < n ; i ++){
        cout<<"_";
    }
    cout<<endl;
    return;
}
void printSe(int n){
    for(int i = 0 ; i < n ; i ++){
        cout<<"-";
    }
    cout<<endl;
    return;
}
void XuatDanhSachNhanVien(NhanVien nhanviens[] , int N ){
    printLine(165-30-15-4-2);
    cout<<setw(10)<<left<<"ID"<<setw(25-3)<<left<<"Ho va ten"<<setw(12)<<"Gioi tinh"
    <<setw(4)<<left<<"T1"<<setw(4)<<left<<"T2"<<setw(4)<<left<<"T3"<<setw(4)<<left<<"T4"
    <<setw(4)<<left<<"T5"<<setw(4)<<left<<"T6"<<setw(4)<<left<<"T7"<<setw(4)<<left<<"T8"
    <<setw(4)<<left<<"T9"<<setw(4)<<left<<"T10"<<setw(4)<<left<<"T11"<<setw(4)<<left<<"T12"
    <<setw(10)<<right<<"TongNC"<<setw(12)<<right<<"NgayCongTB"<<endl;
    printSe(165-30-15-4-2);
    for ( int i = 0 ; i < N ; i ++){
        XuatNhanVien(nhanviens[i]);
    }
    printLine(165-30-15-4-2);
    return;
}

void ghiFile(char filename[],NhanVien nv[],int soNhanVien){
    ofstream ghi;
    ghi.open(filename,ios::app);
    for (int i = soNhanVien-1; i < soNhanVien; ++i) {
        ghi << nv[i].ID << endl;
        ghi << nv[i].HoVaTen << endl;
        ghi << nv[i].gioitinh << endl;
        for (int j = 0; j < 12; j++) {
            ghi << nv[i].ngaycong[j] << endl;
        }
        ghi << nv[i].tongNgayCong<<endl;
        ghi << nv[i].ngayCongTB<<endl;
        ghi << nv[i].quyetDinh<<endl;
    }
    ghi.close();
    return;
}
int docFile(NhanVien nhanViens[], char filename[]) {
    ifstream doc;
    int i = 0;
    doc.open(filename,ios::in);
        while (!doc.eof()){
            doc >> nhanViens[i].ID;
            doc.ignore();
            getline(doc,nhanViens[i].HoVaTen);
            getline(doc,nhanViens[i].gioitinh);
            for (int j = 0; j < 12; ++j) {
                doc >> nhanViens[i].ngaycong[j];
            }
            doc >> nhanViens[i].tongNgayCong;
            doc >> nhanViens[i].ngayCongTB;
            doc.ignore();
            getline(doc,nhanViens[i].quyetDinh);
            i++;
        }
        cout<<"So luong nhan vien co san trong danh sach : "<<i-1<<endl;
        cout<<endl;
        doc.close();
    return i-1;
}
NhanVien ngayCongLonNhat (NhanVien nhanViens[], int n)
{
    NhanVien max = nhanViens[0];
    int i = 0 ;
    for (i = 0; i < n ; i++) {
        if (nhanViens[i].tongNgayCong > max.tongNgayCong ){
            max = nhanViens[i];
        }
    }
    return max;
}

NhanVien ngayCongNhoNhat (NhanVien nhanViens[], int n)
{
    NhanVien min = nhanViens[0];
    int i = 0 ;
    for (i = 0; i < n ; i++) {
        if (nhanViens[i].tongNgayCong < min.tongNgayCong ){
            min = nhanViens[i];
        }
    }
    return min;
}
void thongke(NhanVien nhanViens[] , int n){
    printLine(55);
    cout<<endl;
    cout<<"<<<Danh hieu nhan vien cham chi cua nam : ";
    cout<<ngayCongLonNhat(nhanViens,n).HoVaTen;
    cout<<endl;
    cout<<"<<<Nhan vien di lam it nhat             : ";
    cout<<ngayCongNhoNhat(nhanViens,n).HoVaTen;
    cout<<endl;
    cout<<"\n\t\t<<<Nhan xet cuoi nam>>>"<<endl;
    cout<<endl;
    cout<<"<<<Nhan vien xuat sac: "<<endl;
    xuatSac(nhanViens,n);
    cout<<endl;
    cout<<"<<<Nhan vien can cai thien: "<<endl;
    canCaiThien(nhanViens,n);
    cout<<endl;
    cout<<"<<<Nhan vien bi phe binh:"<<endl;
    biPheBinh(nhanViens,n);
    cout<<endl;
    cout<<"<<<Nhan vien bi ki luat:"<<endl;
    kiLuat(nhanViens,n);
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    return;
}
void timTheoID(int id, int soluongNV, NhanVien nhanViens[]) {
    bool r = false;
    for ( int i = 0; i < soluongNV; ++i) {
        if(nhanViens[i].ID == id){
            nhanViens[i].toString();
            r = true;
        }
    }
    if(r == false){
        cout<<"Khong ton tai nhan vien co ID"<<endl;
    }
    return;
}
void timTheoXepLoai(string xepLoai, int soluongNV, NhanVien nhanViens[]) {
    cout<<"<Nhan vien can tim :"<<endl;
    for (int i = 0; i < soluongNV; ++i) {
        if(nhanViens[i].quyetDinh == xepLoai){
            cout<<"Xep loai: "<<nhanViens[i].quyetDinh<<";";
            nhanViens[i].toString();
        }
    }
    return;
}
void SapXepID (NhanVien nhanViens[], int n) {
	NhanVien tmp;
    for(int i = 0;i < n;i++) {
        for(int j = i+1; j < n;j++) {
            if(nhanViens[i].ID > nhanViens[j].ID) {
                tmp = nhanViens[i];
                nhanViens[i] = nhanViens[j];
                nhanViens[j] = tmp;
            }
        }
    }
    return;
}
void SapXepTheoNgayCong (NhanVien nhanviens[], int n) {
	NhanVien tmp;
    for(int i = 0;i < n;i++) {
        for(int j = i+1; j < n;j++) {
            if(nhanviens[i].tongNgayCong > nhanviens[j].tongNgayCong) {
                tmp = nhanviens[i];
                nhanviens[i] = nhanviens[j];
                nhanviens[j] = tmp;
            }
        }
    }
    return;
}

