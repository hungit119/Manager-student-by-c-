#include"Funcion.h"

int main() {

   NhanVien nhanviens[100];
   int tongSoNhanVien;
   int choice;
   char filename[] = "word.txt";
   cout<<"Da doc file: "<<filename<<endl;
    tongSoNhanVien = docFile(nhanviens,filename);
    do {
        menu();
        cout << "<Lua chon cua quy khach la: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                NhapDanhSachNhanVien(nhanviens,tongSoNhanVien);
                tongSoNhanVien ++;
                system("pause");
                break;
            case 2 :
                system("cls");
                if(tongSoNhanVien > 0){
                cout<<endl;
                cout<<"\t\t\t<<<<<<<<<<<<<<<<<<<<<<DU LIEU NHAN VIEN>>>>>>>>>>>>>>>>>>>>>>"<<endl;
                //docFile(nhanviens,filename);
                XuatDanhSachNhanVien(nhanviens,tongSoNhanVien);
                }
                else{
                    cout<<"Danh sach nhan vien trong !!"<<endl;
                }
                system("pause");
                break;
            case 3:
                system("cls");
                cout<<"Ghi du lieu nhan vien vao file"<<endl;
                ghiFile(filename,nhanviens,tongSoNhanVien);
                cout<<"Da ghi du lieu thanh cong"<<endl;
                system("pause");
                break;
            case 4:
                system("cls");
                if(tongSoNhanVien > 0) {
                    int id;
                    cout << "<<Sua thong tin nhan vien>> "<<endl;
                    XuatDanhSachNhanVien(nhanviens,tongSoNhanVien);
                    cout << "<Nhap ID(vui long nhap so): "; cin >> id;
                    capNhatNV(nhanviens,id,tongSoNhanVien);
                    XuatDanhSachNhanVien(nhanviens,tongSoNhanVien);
                }else{
                    cout << "\nSanh sach nhan vien trong!";
                }
                break;
            case 5:
                system("cls");
                cout<<"<<<<<<<<<<<<<<<<<<<<<<<Thong ke>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
                thongke(nhanviens,tongSoNhanVien);
                system("pause");
                break;
            case 6:
                system("cls");
                int choicer;
                do{
                    cout<<"1<Tim kiem theo id>"<<endl;
                cout<<"2<Tim kiem theo xep loai>"<<endl;
                cout<<"<<Lua chon cua ban :"<<endl;
                cin >>choicer;
                }while( choicer < 1 or choicer > 2 );
                switch(choicer){
                    case 1:
                        system("cls");
                        if(tongSoNhanVien > 0){
                        cout<<"<Tim kiem nhan vien theo id>"<<endl;
                        int id;
                        cout<<"<Nhap id nhan vien muon tim kiem :"<<endl;
                        cin>> id;
                        timTheoID(id,tongSoNhanVien,nhanviens);
                        }else{
                            cout<<"<<<Danh sach nhan vien trong !!!"<<endl;
                        }
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        if(tongSoNhanVien > 0){
                            int lc;
                        string luaChon[] = {"Xuat sac","Can cai thien","Bi phe binh","Bi ki luat"};
                        string loai;
                        do{
                            cout<<"<Tim kiem nhan vien theo xep loai>"<<endl;
                        cout<<"<1,Tim nhan vien xuat sac>"<<endl;
                        cout<<"<2,Tim nhan vien can cai thien>"<<endl;
                        cout<<"<3,Tim nhan vien bi phe binh>"<<endl;
                        cout<<"<4,Tim nhan vien bi ki luat>"<<endl;
                        cin >> lc;
                        }while(lc<1 or lc > 4);
                        loai = luaChon[lc -1];
                        system("cls");
                        timTheoXepLoai(loai,tongSoNhanVien,nhanviens);
                        }
                        else{
                            cout<<"<<<Danh sach nhan vien trong !!! "<<endl;
                        }
                        system("pause");
                        break;
                }
                break;
            case 7:
                system("cls");
                int Ch;
                cout<<"1<Sap xep theo id>"<<endl;
                cout<<"2<Sap xep theo tong ngay cong>"<<endl;
                cout<<"<<Lua chon cua ban :"<<endl;
                cin >>Ch;
                switch(Ch){
                    case 1:
                        system("cls");
                        cout<<"<<Sap xep nhan vien theo id>>"<<endl;
                        if(tongSoNhanVien > 0){
                            SapXepID(nhanviens,tongSoNhanVien);
                            cout<<"<<<Danh sach nhan vien>>>"<<endl;
                            XuatDanhSachNhanVien(nhanviens,tongSoNhanVien);
                        }else{
                            cout<<"<<<Danh sach nhan vien trong !!!"<<endl;
                        }
                        system("pause");
                    break;
                    case 2:
                        system("cls");
                        cout<<"<<Sap xep nhan vien theo tong ngay cong>>"<<endl;
                        if(tongSoNhanVien > 0){
                            SapXepTheoNgayCong(nhanviens,tongSoNhanVien);
                            cout<<"<<<Danh sach nhan vien>>>"<<endl;
                            XuatDanhSachNhanVien(nhanviens,tongSoNhanVien);
                        }else{
                            cout<<"<<<Danh sach nhan vien trong !!!"<<endl;
                        }
                        system("pause");
                        break;
                }
                break;
        }
    } while (choice != 0);
    cout<<"<Cam on quy khach da su dung chuong trinh !!"<<endl;
    cout<<"<Da thoat"<<endl;
    return 0;
}

