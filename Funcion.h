#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include <math.h>
using namespace std;
#pragma once

struct NhanVien{
    int ID;
    string HoVaTen;
    string gioitinh;
    int ngaycong[20];
    float tongNgayCong = 0;
    float ngayCongTB = 0;
    string quyetDinh ;
    void toString (){
        cout << "ID= "<<ID<<";Ho ten= "<<HoVaTen<<"; Gioi tinh= "<<gioitinh<<"; Tong ngay cong= "<<tongNgayCong<<endl;
    }
};

// Nguy?n Ti?n Dung :
void Nhap( NhanVien &nguoi);
void NhapDanhSachNhanVien(NhanVien nhanViens[] , int N );
void XuatNhanVien(NhanVien&nguoi);
void XuatDanhSachNhanVien(NhanVien nhanviens[] , int N );
void SuaThongTinNhanVien(NhanVien &nguoi);
void capNhatNV(NhanVien nhanviens[], int id, int n);
void ghiFile(char filename[],NhanVien nv[],int soNhanVien);

// Mai Tùng Duong :
void timTheoID(int id, int soluongNV, NhanVien nhanViens[]);
void timTheoXepLoai(string xepLoai, int soluongNV, NhanVien nhanViens[]);
int tongNgayCong(NhanVien &nhanVien);

// Ph?m Minh Vu :
void SapXepID (NhanVien nhanViens[], int n);
void SapXepTheoNgayCong (NhanVien nhanviens[], int n);

// Chu Ð?c Hùng :
NhanVien ngayCongLonNhat (NhanVien nhanViens[], int n);
NhanVien ngayCongNhoNhat (NhanVien nhanViens[], int n);

//Tr?n Duy Hùng :
void menu();
int docFile(NhanVien nhanViens[],char filename[]);
int ngayCongTB(NhanVien &nhanVien);
string nhanXet(NhanVien &nhanVien);
void xuatSac(NhanVien nhanVien[],int n);
void canCaiThien(NhanVien nhanVien[],int n);
void biPheBinh(NhanVien nhanVien[],int n);
void kiLuat(NhanVien nhanVien[],int n);
void thongke(NhanVien nhanViens[] , int n);
void printLine(int n);
void printSe(int n);

