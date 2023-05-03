#include <iostream>
#include "ThuVienDoHoa.h"
using namespace std;

#define Enter 13
#define Backspace 8
#define Space 32
#define Esc 27
#define dong 5
#define cot 50
#define Up 72
#define Down 80
#define Left 75
#define Right 77
#define in 15

void thongTin(){
	cout << "Ho va ten: Le Thi Thuy Trang" << endl;
	cout << "MSSV: N19DCCN207" << endl;
	cout << "De so 8: Viet chuong trinh mo phong cac giai thuat thay the trang theo thuat toan LRU\n" << endl;
}

void Normal() {
	SetColor(15);
	SetBGColor(0);
}
void HighLight() {
	SetColor(15);
	SetBGColor(1);
}

const int gv = 3;

char menu[gv][15] = { "              ",
					  "              ",
					  "      Run     " };
					   

int MenuDong(char td[gv][15], int &n, int &t, int &vtt, int &vtk) {
	Normal();
//	system("cls");
	gotoXY(cot - 20, dong);     cout << "So trang       ->";
	gotoXY(cot - 20, dong + 1); cout << "So khung trang ->";
	int chon = 0;
	int i; //vtt = 0, vtk = 0;
	for (i = 0; i < gv; i++)
	{
		gotoXY(cot, dong + i);
		cout << td[i];
		if (n != 0 && i ==0) {
			gotoXY(cot, dong + i);
			cout << n;
		}
		if (t != 0 && i == 1) {
			gotoXY(cot, dong + i);
			cout << t;
		}
	}
	HighLight();
	gotoXY(cot, dong + chon);
	cout << td[chon];
	if (n != 0 && chon == 0) {
		gotoXY(cot, dong + chon);
		cout << n;
	}
	char kytu;
	do {
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu) {
		case Up:if (chon + 1 > 1)
		{
			Normal();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			if (n != 0 && chon == 0) {
				gotoXY(cot, dong + chon);
				cout << n;
			}
			if (t != 0 && chon == 1) {
				gotoXY(cot, dong + chon);
				cout << t;
			}
			chon--;
			HighLight();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			if (n != 0 && chon == 0) {
				gotoXY(cot, dong + chon);
				cout << n;
			}
			if (t != 0 && chon == 1) {
				gotoXY(cot, dong + chon);
				cout << t;
			}
		}
			   break;
		case Down:if (chon + 1 < gv)
		{
			Normal();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			if (n != 0 && chon == 0) {
				gotoXY(cot, dong + chon);
				cout << n;
			}
			if (t != 0 && chon == 1) {
				gotoXY(cot, dong + chon);
				cout << t;
			}
			chon++;
			HighLight();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			if (n != 0 && chon == 0) {
				gotoXY(cot, dong + chon);
				cout << n;
			}
			if (t != 0 && chon == 1) {
				gotoXY(cot, dong + chon);
				cout << t;
			}

		}
				 break;
		case 8:
			if (chon == 0 && vtt != 0) {
				gotoXY(cot + vtt, dong + chon);
				cout << "\b \b";
				n = (n - (n % 10)) % 9;
				vtt--;
				break;
			}
			if (chon == 1 && vtk != 0) {
				gotoXY(cot + vtk, dong + chon);
				cout << "\b \b";
				t = (t - (t % 10)) % 9;
				vtk--;
				break;
			}
		case 13: 
			if(chon != 0 && chon != 1){
				return chon + 1;
			}
			break;
		case 27: return chon;
		case 48:
		case 49:
		case 50:
		case 51:
		case 52:
		case 53:
		case 54:
		case 55:
		case 56:
		case 57:
			if (chon == 0) {
				gotoXY(cot + vtt, dong + chon);
				cout << kytu;
				n = n * 10 + int(kytu) - 48;
				vtt++;
				break;
			}
			if (chon == 1) {
				gotoXY(cot + vtk, dong + chon);
				cout << kytu;
				t = t * 10 + int(kytu) - 48;
				vtk++;
				break;
			}
		}  // end switch
	} while (1);
}

void khungChuoi(int n, char gtt, char gtd, char gpt, char gpd,  char gn, char gd ){
	gotoXY(31,in);
	cout << gtt;
	for(int i = 1; i < n*3 ; i++){
		if(i % 3 == 0 ){
			gotoXY(31+i,in);
			cout << char(203);
			gotoXY(31+i,in+1);
			cout << gd ;
		}
		else{
			gotoXY(31+i,in);
			cout << gn;
		}
	}
	cout << gpt;
	gotoXY(31,in+1);
	cout << gd;
	gotoXY(31+n*3,in+1);
	cout << gd;
}

void khungTrang(int n, char gtt, char gtd, char gpt, char gpd,  char gn, char gd , int t){
	for(int j = 0; j < t*2; j+=2){
		gotoXY(31,in+2+j);
		cout << char(204);
		for(int i = 1; i < n*3 ; i++){
			if(i % 3 == 0 ){
				gotoXY(31+i,in+2+j);
				cout << char(206);
				gotoXY(31+i,in+3+j);
				cout << gd ;
			}
			else{
				gotoXY(31+i,in+2+j);
				cout << gn;
			}
		}
		cout << char(185);
		gotoXY(31,in+3+j);
		cout << gd;
		gotoXY(31+n*3,in+3+j);
		cout << gd;
	}	
}

void khungLoi(int n, char gtt, char gtd, char gpt, char gpd,  char gn, char gd, int t ){
	gotoXY(31,in+2+t*2);
	cout << char(204);
	for(int i = 1; i < n*3 ; i++){
		if(i % 3 == 0 ){
			gotoXY(31+i,in+2+t*2);
			cout << char(206);
			gotoXY(31+i,in+3+t*2);
			cout << gd ;
		}
		else{
			gotoXY(31+i,in+2+t*2);
			cout << gn;
		}
	}
	cout << char(185);
	gotoXY(31,in+3+t*2);
	cout << gd;
	gotoXY(31+n*3,in+3+t*2);
	cout << gd;
	gotoXY(31,in+4+t*2); 
	cout << char(gtd);
	for(int i = 1; i < n*3 ; i++){
		if(i % 3 == 0 ){
			gotoXY(31+i,in+4+t*2);
			cout << char(202);
		}
		else{
			gotoXY(31+i,in+4+t*2);
			cout << gn;
		}
	}
	cout << char(188);
}

void keKhung(int n, char gtt, char gtd, char gpt, char gpd,  char gn, char gd, int t ){
	khungChuoi(n,gtt,gtd,gpt,gpd,gn,gd);
	khungTrang(n,gtt, gtd, gpt, gpd, gn, gd , t);
	khungLoi(n, gtt, gtd, gpt, gpd, gn, gd, t);
}

void nhapDLVaoKhungChuoi(int n, int a[], int t){
	int j = 0;
	for(int i = 1; i < n*3; i+=3){
		gotoXY(31+i,in+1);
		cin >> a[j];
		j++;
	}
}

void duaDLVaoKhungTrang(int n, int c, int b[], int t, int k){
	for(int i = 0; i < k; i++){
		gotoXY(31+c,in+1+(i+1)*2);
		SetColor(4);
		cout << b[i];
		SetColor(15);
	}
}

//Kiem tra trang có trong luot truy cap khong hoac kiem tra trang co trong khung trang khong
int kiemTraLTC(int l[], int k, int x){
	for(int i = 0; i < k; i++){
		if(l[i] == x) return i;
	}
	return -1;
}

//Them trang vao luot cap moi nhat
void ThemLTC(int l[], int k, int x){
	if(kiemTraLTC(l,k,x) == -1){
		for(int i = k - 1; i > 0; i--){
			l[i] = l[i-1];
		}
		l[0] = x;
	}
	else{
		for(int i = kiemTraLTC(l,k,x); i > 0; i--){
			l[i] = l[i-1];
		}
		l[0] = x;
	}
}

//k :so luong trang dang co trong mang khung trang b[]
//c :buoc nhay in so trang ra man hinh
//s :toi cot thu may
//t :so khung trang
//l :kiem tra luot truy cap cac trang
void thuatToanLRU(int n, int a[], int t, int b[], int &k, int c, int s, int l[]){
	
	if(k < t+1){ //Neu so luong trang dang co trong mang khung trang b[] chua bang so luong khung trang t
		if(kiemTraLTC(b, k-1, a[s-1]) == -1){
			b[k-1] = a[s-1]; 
			ThemLTC(l, k, b[k-1]);
			duaDLVaoKhungTrang(n, c, b, t, k);
			k++;
		}
		else{
			ThemLTC(l, k-1, a[s-1]);
			duaDLVaoKhungTrang(n, c, b, t, k-1);
		}
	}
	else{
		for(int i = 0; i < t; i++){
			if(a[s-1] == b[i]) {
				ThemLTC(l,t,b[i]);
				duaDLVaoKhungTrang(n, c, b, t, k-1);
				return;
			}
		}
		for(int i = 0; i < t; i++){
			if(b[i] == l[k-2]){
				b[i] = a[s-1];
				ThemLTC(l, k-1, b[i]);
				duaDLVaoKhungTrang(n, c, b, t, k-1);
				gotoXY(31+c,in+1+(t+1)*2);
				cout<<"*";
				return;
			}
		}
	}
}

void xuLy(int n, int a[], int t){
	int c = 1, k = 1;
	int b[100], l[100];
	for(int i = 1; i <= n ; i++){
		thuatToanLRU(n, a, t, b, k, c, i, l);
		c += 3;
	}
}


int main(){
	int n = 0, t = 0, vtt = 0, vtk = 0;
	char gtt = 201, gtd = 200, gpt = 187, gpd = 188, gn = 205, gd = 186;
	int a[100];
/*	thongTin();
	input(n,a,t, gtt, gtd, gpt, gpd, gn, gd);
	xuLy(n, a, t);*/
	while(true){
		system("cls");
		thongTin();
		int chon = MenuDong(menu, n, t, vtt, vtk);
		switch (chon) {
			case 0:
				return 0;
				break;
			case 3:
				Normal();
				keKhung(n, gtt, gtd, gpt, gpd, gn, gd, t);
				nhapDLVaoKhungChuoi(n, a, t);
				xuLy(n, a, t);
				gotoXY(cot + 30, dong + 5);
				cout << "Bam mui ten len de tiep tuc";
				gotoXY(cot + 30, dong + 6);
				cout << "Hoac ESC de thoat chuong trinh";
				char k = _getch();
				if (k == 0) k = _getch();
				if (k == Up) continue;
				else if (k == 27) return 0;
				break;
		}
	}
	return 0;
}
