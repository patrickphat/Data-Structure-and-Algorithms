#include "SinhVien.h"

SinhVien::SinhVien()
{
	char a[] = "n/a";
	strcpy_s(ten,a);
	dtb = 0;
	strcpy_s(mssv,a);
}
SinhVien::~SinhVien()
{
}
void SinhVien::nhap()
{
	cin.ignore(1);
	cout << "Ten: ";  
	cin.getline(ten, 30);
	cout << "MSSV: ";  
	cin.getline(mssv, 30);
	cout << "Diem trung binh: "; cin >> dtb;
}
void SinhVien::xuat()
{
	cout << "Ten :"; puts(ten);
	cout << "MSSV: "; puts(mssv);
	cout << "Diem trung binh: "; cout << dtb << endl;
}