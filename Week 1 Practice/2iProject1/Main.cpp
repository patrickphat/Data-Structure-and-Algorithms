#include "SinhVien.h"

void max_gpa_list(vector<SinhVien> SV);
void nhapmangsv(vector<SinhVien>&SV);
void xuatmangsv(vector<SinhVien> SV);
int svtren5(vector<SinhVien> SV);
void timtheoten(vector<SinhVien> SV);
void timtheomssv(vector<SinhVien> SV);
void xoasinhvien(vector<SinhVien>&SV);
void sortsinhvien(vector<SinhVien>&SV);
void themsinhvien(vector<SinhVien>&SV);
bool checksort(vector<SinhVien> SV); //Kiem tra sort hay chua
int main()
{
	vector<SinhVien> SV;
	cout << "==KHOI TAO SINH VIEN==" << endl;
	nhapmangsv(SV);
	int choose=1;
	cout << "Chon trong menu:\n1.In danh sach sinh vien\n2.Liet ke nhung sinh vien co diem cao nhat\n3.Cho biet so sinh vien >5\n4.Tim sinh vien theo ten\n5.Xoa sinh vien theo mssv\n6.Sap xep sinh vien tang dan dtb\n7.Chen them sinh vien\n8.Thoat chuong trinh\n";
	
	while (1)
	{
		cin >> choose;
		switch (choose)
		{
		case 1:
			xuatmangsv(SV);
			break;
		case 2:
			max_gpa_list(SV);
			break;
		case 3:
			if (svtren5(SV)) cout << "Co " << svtren5(SV) << " sinh vien co diem trung binh tren 5!" << endl;
			else cout << "Khong co sinh vien nao tren 5";
			break;
		case 4:
			timtheoten(SV);
			break;
		case 5:
			xoasinhvien(SV);
			break;
		case 6:
			sortsinhvien(SV);
			break;
		case 7:
			themsinhvien(SV);
			break;
		case 8:
			return 0;
			break;
		}
	}
	return 0;

}
void max_gpa_list(vector<SinhVien> SV)
{
	float flag = 0;
	for (int i = 0; i < SV.size(); i++)
	{
		if (SV[i].dtb > flag) flag = SV[i].dtb; //Tim diem max
	}
	cout << "Hoc sinh co diem cao nhat :";
	for (int i = 0; i < SV.size(); i++)
	{
		if (SV[i].dtb == flag) 
		{
			cout << endl; puts(SV[i].ten);
		}
	}
}
void nhapmangsv(vector<SinhVien>&SV)
{
	int n; cout << "Nhap so sinh vien: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "SINH VIEN " << i << endl;
		SinhVien temp;
		temp.nhap();
		SV.push_back(temp);
	}
}
void xuatmangsv(vector<SinhVien> SV)
{
	for (int i = 0; i < SV.size(); i++)
	{
		cout << "SINH VIEN " << i << endl;
		SV[i].xuat();
	}
}
int svtren5(vector<SinhVien> SV)
{
	int count=0;
	for (int i = 0; i < SV.size(); i++)
	{
		if (SV[i].dtb >= 5) count++;
	}
	return count;
}
void timtheoten(vector<SinhVien> SV)
{
	int check = 0;
	char Ten[30];
	cout << "Nhap ten can tim: ";
	cin.ignore(1);
	cin.getline(Ten, 30);
	for (int i = 0; i < SV.size(); i++)
	{
		if (strcmp(Ten, SV[i].ten)==0)
		{
			SV[i].xuat();
			check = 1;
			break;
		}
	}
	if (check == 0) cout << "Khong tim duoc ten ban vua nhap!" << endl;
}
void timtheomssv(vector<SinhVien> SV)
{
	int check = 0;
	char Mssv[30];
	cout << "Nhap mssv can tim: ";
	cin.ignore(1);
	cin.getline(Mssv, 30);
	cout << "KET QUA TIM KIEM :" << endl;
	for (int i = 0; i < SV.size(); i++)
	{
		if (strcmp(Mssv, SV[i].mssv) == 0)
		{
			SV[i].xuat();
			check = 1;
		}
	}
	if (check == 0) cout << "Khong tim duoc mssv ban vua nhap!" << endl;
}
void xoasinhvien(vector<SinhVien>&SV)
{
    int check = 0;
	char Mssv[30];
	cout << "Nhap mssv can xoa: ";
	cin.ignore(1);
	cin.getline(Mssv, 30);
	for (int i = 0; i < SV.size(); i++)
	{
		if (strcmp(Mssv, SV[i].mssv) == 0)
		{
			check = 1;
			SV.erase(SV.begin() + i);
		}
	}
	if (check == 0) cout << "Khong tim duoc mssv ban vua nhap!" << endl;
	else cout << "Da xoa!" << endl;
}
void sortsinhvien(vector<SinhVien>&SV)
{
	for (int i = 0; i < SV.size()-1; i++)
	{
		for (int j = i + 1; j < SV.size(); j++)
		{
			if (SV[i].dtb > SV[j].dtb) swap(SV[i], SV[j]);
		}
	}
	cout << "Da sap xep!" << endl;
}
void themsinhvien(vector<SinhVien>&SV)
{
	if (checksort(SV))
	{
		SinhVien temp;
		cout << "THEM SINH VIEN MOI:" << endl;
		temp.nhap();
		for (int i = 0; i < SV.size(); i++)
		{
			if (SV[i].dtb > temp.dtb)
			{
				SV.insert(SV.begin() + i , temp);
				break;
			}
		}
		cout << "Da them sinh vien moi!" << endl;
	}
	else cout << "Ban phai sort truoc khi them sinh vien!" << endl;
}
bool checksort(vector<SinhVien> SV)
{
	for (int i = 0; i < SV.size()-1; i++)
	{
		if (SV[i].dtb > SV[i+1].dtb) return false;
	}
	return true;
}