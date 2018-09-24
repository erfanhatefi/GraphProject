//********************
#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
#include "Header1.h"
#include "Header.h"
using namespace std;
void daryaft(int **, int **, int);
#define inf 2000000000
// baraye chap masir bein do ras
int path[100];
int cont = 0;
// etmam tarif
void menu(string[], int **, int **, int);
int amaliat1();
//int daryaft(int **, int **, int *);
// tabe masir do ras
int masirdoras(int **, int, int, int, int);
int mainmasirdoras(int **, int);
void welcome();
// etmam tabe masir do ras
// tabe dor hamiltoni
int hamiltoni(int **, int);
void chaphamilton(int[], int);
bool checkras(int, int **, int[], int);
bool dorhamilhs(int, int **, int[], int);
bool dorhamil(int **, int);
//andazeie matris
int andaze(int **, int);
//maximum va minimum darajeie matris
int maxmindaraje(int **, int);
//kamel boodan yaa naboodane graph
int kamelboodan(int **, int);
// tabe hambandi
int hamband(int **, int, bool);
int omqaval(int **, int *, int, int);
// tabe derakht
int derakht(int **, int);
// tabe yekrikhti
int yekrikhti(int **, int);
// tabe oileri
int memoryoil[100];
int top = -1, n;
int esmerasgraph[100], masiroileri[100];
int fp = 0, shomarande;
void zakhire(int);
int hazf();
int checkyall(int, int **, int);
int oileri(int **, int);
int checkesm(int);
int rasshoru(int, int **);
int yaftdaraje(int, int **, int);
void chapmasir();
void masiroilery(int, int **, int);
// etmam oileri
// tabe ghotr graf
int ghotregraf(int **, int);
// etmam tabe ghotr
//shoroo tabe mwghdar vizhe va energy
int eigen(int **, int, bool);
int energy(int **, int);
// etmam
// shoru mosatah
int mosatah(int **, int);
//tabe delete kardan
int paakkardan(int ** , int ** ,int);
//**********************************************************************
int main()
{
	welcome();
	// ta arif va daryaf matris asli va vazn yall ha
	// matris haye pooya
	int **matris;
	int **vaznmatris;
	int tedadras;
	system("cls");
	cout << "baraye estefade az barname matris mojaverat\nva matris vazn graf ra vared konid.\n";
	cout << "baraye mesal:\n";
	int q[3][3] = { 0,1,1,1,0,1,1,1,0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "  " << q[i][j];
		}
		cout << endl << endl;
	}
	cout << "Tedade ras ha ra vared konid:" << endl;
	cin >> tedadras;
	matris = new int *[tedadras];
	for (int i = 0; i < tedadras; i++) {
		matris[i] = new int[tedadras];
	}
	vaznmatris = new int *[tedadras];
	for (int i = 0; i < tedadras; i++) {
		vaznmatris[i] = new int[tedadras];
	}
	daryaft(matris, vaznmatris, tedadras);
	// payane matris pooya


	//daryaft(matris, vaznmatris, &tedadras);
	// shoru e moteghayer haye tabe menu
	string inter[13];
	// payane moteghayer haye tabe menu
	menu(inter, matris, vaznmatris, tedadras);


}
void daryaft(int **matris, int **vaznmatris, int tedadras)
{
	bool x = true; // sharti baraye halghe
	while (x)
	{
		system("cls");
		cout << "shomare hayii ke mikhahid vared konid bayad 1 ya 0 bashad" << endl;
		cout << "matrise mojaverat:" << endl;
		for (int i = 0; i < tedadras; i++)
		{
			cout << "baraye khate:" << (i + 1) << ":" << endl;
			for (int j = 0; j < tedadras; j++)
			{
				cout << "deraye:" << "{" << (i + 1) << " , " << (j + 1) << "}" << ":\t";
				cin >> matris[i][j];
			}
			system("cls");
		}
		cout << "matris mojaverate shoma:" << endl;
		for (int i = 0; i < tedadras; i++)
		{
			for (int j = 0; j < tedadras; j++)
			{
				cout << "  " << matris[i][j] << "  ";
			}
			cout << endl << endl << endl;
		}
		cin.get();
		// vazne matrix
		cout << "vazne matris:" << endl;
		for (int i = 0; i < tedadras; i++)
		{
			cout << "baraye khate:" << (i + 1) << ":" << endl;
			for (int j = 0; j < tedadras; j++)
			{
				cout << "deraye:" << "{" << (i + 1) << " , " << (j + 1) << "}" << ":\t";
				cin >> vaznmatris[i][j];
				if ((matris[i][j] == 0) && (vaznmatris[i][j] != 0))
				{
					vaznmatris[i][j] = 0;
					cout << "khata: barname be tore khodkar vazn ra be sefr taghir daad!" << endl;
				}
			}
			cin.get();
			system("cls");
		}

		cout << endl;
		// namayesh matris

		// namayesh vazn matris
		cout << "matris vazn graf shoma : " << endl << endl;
		for (int i = 0; i < tedadras; i++)
		{
			for (int j = 0; j < tedadras; j++)
			{
				cout << "  " << vaznmatris[i][j] << "  ";
			}
			cout << endl << endl << endl;
		}
		cout << endl << endl;
		cout << "matris mojaverate shoma:" << endl;
		for (int i = 0; i < tedadras; i++)
		{
			for (int j = 0; j < tedadras; j++)
			{
				cout << "  " << matris[i][j] << "  ";
			}
			cout << endl << endl << endl;
		}
		cin.get();
		// check kardan graf budan matris
		for (int i = 0; i < tedadras; i++)
		{
			int q = 0;
			int r;
			r = i;
			for (int j = 0; j < tedadras; j++)
			{
				if (vaznmatris[i][j] != vaznmatris[j][i])
				{
					cout << "vazne mattrise shoma motagharen nist!" << endl;
					break;
				}
			}
			if ((matris[i][r] == 0) && (matris[i][q] == matris[q][i]) && ((matris[i][q] == 1) || (matris[i][q] == 0)))
			{
				q++;
				if (i == tedadras - 1) {
					x = false;
				}
				continue;
			}
			else
			{
				cout << "khata, matris shoma yek graf nist!!!!" << endl;
				cout << "matris zir yek nemunue az matris graf ast:" << endl;
				int q[3][3] = { 0,1,1,1,0,1,1,1,0 };
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						cout << "  " << q[i][j];
					}
					cout << endl << endl;

				}
				sleep(4000);
				break;
			}
		}
	}
}
//**********************************************************************
// tabe baraye menu interactive
void menu(string inter[13], int **matris, int **vaznmatris, int tedadras) {
	// moteghayere mored niaz switch case
	int choice;
	system("cls");
	//shoru e menu ha
	cout << "khosh amadid. \n amaliat mored nazar khod ra entekhab konid:\n";
	cout << " 1-dor hamiltoni  \t \t" << inter[0] << endl;
	cout << " 2-dor oileri \t \t" << inter[1] << endl;
	cout << " 3-kootah tarin masir \t \t" << inter[2] << endl;
	cout << " 4-ghotre graphr \t \t" << inter[3] << endl;
	cout << " 5-hamband boodan ya naboodan\t \t" << inter[4] << endl;
	cout << " 6-derakht boodan \t \t" << inter[5] << endl;
	cout << " 7-max va min daraje \t \t" << inter[6] << endl;
	cout << " 8-mosatah boodan \t \t" << inter[7] << endl;
	cout << " 9-kamel boodan \t \t" << inter[8] << endl;
	cout << "10-andaze graph \t \t" << inter[9] << endl;
	cout << "11-maghadire vizhe \t \t" << inter[10] << endl;
	cout << "12-energy graph \t \t" << inter[11] << endl;
	cout << "13-yekrikhtegi \t \t" << inter[12] << endl;
	cout << endl << endl;
	cout << " 0-khorooj \t \t" << endl;
	cin >> choice;
	// payane menu ha
	// estefade az switch case baraye chaap kardane reshteye anjame amaliat va farakhani tabe ha
	switch (choice) {
	case 1:
		if (hamiltoni(matris, tedadras) == 1) {
			inter[0] = "shoma dor hamiltoni graf khod ra mohasebe kardid";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 2:
		if (oileri(matris, tedadras) == 1) {
			inter[1] = "shoma dor oileri ra hesab kardid.";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 3:
		if (mainmasirdoras(vaznmatris, tedadras) == 1) {
			inter[2] = "shoma masir bein do ras graf khod ra mohasebe kardid";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 4:
		if (ghotregraf(vaznmatris, tedadras) == 1) {
			inter[3] = "shoma ghotre graph ra bedast avardid";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 5:
		if (hamband(matris, tedadras, true) == 1) {
			inter[4] = "shoma hambandi graf kod ra barresi kardid.";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 6:
		if (derakht(matris, tedadras) == 1) {
			inter[5] = "shoma derakht budan graf khod ra barresi kardid";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 7:
		if (maxmindaraje(matris, tedadras) == 1) {
			inter[6] = "shoma bishtarin va kamtarin daraje ro'us ra mohasebe kardid";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 8:
		if (mosatah(matris, tedadras) == 1) {
			inter[7] = "shoma maximum va minimum daraje ra bedast avardid";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 9:
		if (kamelboodan(matris, tedadras) == 1) {
			inter[8] = "shoma kamel budan graf khod ra barresi kardid";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 10:
		if (andaze(matris, tedadras) == 1) {
			inter[9] = "shoma andaze graf khod ra barresi kardid.";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 11:
		if (eigen(matris, tedadras, true) == 1) {
			inter[10] = "shoma meghdare vizhe ra bedast avardid";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 12:
		if (energy(matris, tedadras) == 1) {
			inter[11] = "shoma energy graph ra barresi kardid";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 13:
		if (yekrikhti(matris, tedadras) == 1) {
			inter[12] = "shoma yek rikht budan do graf ra barresi kardid.";
		}
		menu(inter, matris, vaznmatris, tedadras);
		break;
	case 0:
		if (paakkardan(matris, vaznmatris , tedadras) == 1)
		{
			exit(1);
		}
		break;
	}
}
//**********************************************************************
// tabe asli masir do ras
int mainmasirdoras(int **vaznmatris, int tedadras) {
	int start, end, check = -1;
	system("cls");
	cout << "ras shoru ra vared konid\n";
	cin >> start;
	cout << "ras payan ra vared konid\n";
	cin >> end;
	cout << "tul kutah tarin masir bein " << start << " va " << end << ": " << masirdoras(vaznmatris, tedadras, start, end, 0) << endl << endl;
	cout << "masir tey shode: " << endl << endl;
	cout << start;
	for (int i = 0; i < 100; i++) {
		if (path[i] != -1) {
			if ((path[i] != path[i + 1] && path[i] != check) && (path[i] != start && path[i] != end)) {
				cout << "  -->  " << path[i];
				check = path[i];
			}
		}
	}
	cout << "  -->" << end;
	for (int i = 0; i < 100; i++) {
		path[i] = -1;
	}
	cin.get();
	cin.get();
	return 1;
}
// tabe bazghashti mohasebe masir bein do ras graph
int masirdoras(int **vaznmatris, int tedadras, int start, int end, int z) {
	int min = inf; // kamtarin halat baraye avalin bar inf meghdar dade mishe
	int *checkmasir;
	checkmasir = new int[tedadras];
	// agar dota ras yeki bud fasele sefr
	if (start == end)
	{
		return 0;
	}
	// z baresi tedad yall haye check shode
	if (z >= tedadras - 1)
	{
		return inf;
	}
	for (int i = 0; i < tedadras; i++) {
		if (vaznmatris[i][end] != 0 && vaznmatris[i][end] != inf)
		{
			checkmasir[i] = vaznmatris[i][end] + masirdoras(vaznmatris, tedadras, start, i, z + 1);
			if (min > checkmasir[i] && checkmasir[i] > 0) {
				min = checkmasir[i];
				path[cont] = i;
				cont++;
			}
		}

	}

	return min;
}
int amaliat1() {
	return 1;
}
//**********************************************************************
int andaze(int **matris, int tedadras)
{
	system("cls");
	int s = 0;
	for (int i = 0; i < tedadras; i++)
	{
		for (int j = 0; j < tedadras; j++)
		{
			s = s + matris[i][j];
		}
	}
	cout << "andaze ie graph: " << (s / 2) << endl;
	cin.get();
	cin.get();
	return 1;
}
//**********************************************************************
int maxmindaraje(int **matris, int tedadras)
{
	system("cls");
	int temp;
	int *maxmin = new int[tedadras];
	for (int i = 0; i < tedadras; i++) {
		maxmin[i] = 0;
	}
	for (int i = 0; i < tedadras; i++) {
		for (int j = 0; j < tedadras; j++) {
			maxmin[i] = maxmin[i] + matris[i][j];
		}
	}
	for (int i = tedadras - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (maxmin[j + 1] < maxmin[j]) {
				temp = maxmin[j];
				maxmin[j] = maxmin[j + 1];
				maxmin[j + 1] = temp;
			}
		}
	}
	cout << "minimun daraje : " << maxmin[0] << endl;
	cout << "maximum daraje : " << maxmin[tedadras - 1] << endl;
	cin.get();
	cin.get();
	return 1;
}
//**********************************************************************

int kamelboodan(int **matris, int tedadras)
{
	system("cls");
	int s = 0;
	for (int i = 0; i < tedadras; i++)
	{
		for (int j = 0; j < tedadras; j++)
		{
			s = s + matris[i][j];
		}
	}
	if (s == ((tedadras)*(tedadras)-tedadras))
	{
		cout << "graphe shoma kamel ast" << endl;
	}
	else
		cout << "graphe shoma kamel nist" << endl;
	cin.get();
	cin.get();
	return 1;
}


//**********************************************************************

void welcome()
{
	string st1 = "ERFAN";
	string st2 = "WELCOME";
	for (int i = 20; i >= 0; i = i - 2) {
		for (int j = 0; j<i; j++) {
			cout << "*";
			sleep(2);
		}
		for (int h = 0; h < (20 - i) * 2; h++) {
			cout << " ";
		}
		for (int j = i; j > 0; j--) {
			cout << "*";
			sleep(2);
		}
		cout << endl;
	}
	cout << "\t        ";
	for (int i = 0; i < st2.size(); i++)
	{
		cout << st2[i];
		sleep(170);
	}

	cout << "\n          ----PROJECT GRAPH----\n";
	sleep(2000);
	cout << "          Written By:\n";
	sleep(800);
	system("color 2");
	cout << "          \t";
	for (int i = 0; i < st1.size(); i++)
	{
		cout << st1[i];
		sleep(300);
	}
	cout << "\n          AND\n";
	system("color 1");
	cout << "          \t";
	for (int i = 0; i < st1.size(); i++)
	{
		cout << st1[i];
		sleep(300);
	}
	system("color 6");
	system("color 07");
	for (int i = 0; i <= 20; i = i + 2) {
		for (int j = 0; j < i; j++) {
			cout << "*";
			sleep(2);
		}
		for (int h = 0; h < (20 - i) * 2; h++) {
			cout << " ";
		}
		for (int j = 0; j < i; j++) {
			cout << "*";
			sleep(2);
		}
		cout << endl;
	}
	cout << "\n\n";
	cout << "Loading ";
	for (int i = 0; i < 14; i++) {
		cout << "#";
		sleep(140);
	}
}
// shoru tavabe hamiltoni
int hamiltoni(int **matris, int tedadras) {
	system("cls");
	dorhamil(matris, tedadras);
	cin.get();
	cin.get();
	return 1;
}
bool checkras(int v, int **matris, int pathhamilton[], int p)
{
	if (matris[pathhamilton[p - 1]][v] == 0)
		return false;
	for (int i = 0; i < p; i++)
		if (pathhamilton[i] == v)
			return false;

	return true;
}
bool dorhamilhs(int tedadras, int **matris, int pathhamilton[], int p)
{
	if (p == tedadras)
	{
		if (matris[pathhamilton[p - 1]][pathhamilton[0]] == 1)
			return true;
		else
			return false;
	}
	for (int v = 1; v < tedadras; v++)
	{
		if (checkras(v, matris, pathhamilton, p))
		{
			pathhamilton[p] = v;
			if (dorhamilhs(tedadras, matris, pathhamilton, p + 1) == true)
				return true;
			pathhamilton[p] = -1;
		}
	}
	return false;
}
bool dorhamil(int **matris, int tedadras)
{
	int *path = new int[tedadras];
	for (int i = 0; i < tedadras; i++)
		path[i] = -1;
	path[0] = 0;
	if (dorhamilhs(tedadras ,matris, path, 1) == false)
	{
		cout << "dor hamiltoni vojud nadarad.\n";
		return false;
	}
	chaphamilton( path, tedadras);
	return true;
}
void chaphamilton(int path[], int tedadras)
{
	cout << "jabab vojud darad:\n" << " dor hamiltoni be surat zir ast:\n";
	for (int i = 0; i < tedadras; i++) {
		cout << path[i] << "\t";
	}
	cout << path[0] << endl;
}
//etmam tavabe hemiltoni
int hamband(int **matris, int tedadras, bool drakht) {
	system("cls");
	int *checkrashambandi = new int[tedadras];
	for (int i = 0; i < tedadras; i++) {
		checkrashambandi[i] = 0;
	}
	int count = 0; char moalefe;
	int s = 1;
	omqaval(matris, checkrashambandi, 1, tedadras);
	cout << "\n";
	for (int i = 1; i <= tedadras; i++)
	{
		if (checkrashambandi[i])
			count++;
	}
	if (drakht) {
		if (count == tedadras) {
			cout << "\n graf hamband ast.";
		}
		else {
			cout << "\n graf hamband nist.";
			cout << endl << "namayesh tedad moalefe na hambandi?(y/n)\n";
			cin >> moalefe;
			if (moalefe == 'y') {
				for (int i = 1; i <= tedadras; i++) {
					if (!checkrashambandi[i]) {
						omqaval(matris, checkrashambandi, i, tedadras);
						s++;
					}
				}
				cout << "tedad moalefa haye na hambandi: " << s << endl;
			}
		}
	}
	if (!drakht) {
		if (count == tedadras)
			return 2;
		else
			return 3;
	}
	cin.get();
	cin.get();
	return 1;
}
int omqaval(int **matris, int *checkrashambandi, int r, int tedadras) {
	int i;
	checkrashambandi[r] = 1;
	for (i = 1; i <= tedadras; i++)
		if (matris[r][i] && !checkrashambandi[i])
		{
			omqaval(matris, checkrashambandi, i, tedadras);
		}
	return 0;
}
int derakht(int **matris, int tedadras) {
	system("cls");
	int yal;
	int s = 0;
	for (int i = 0; i < tedadras; i++)
	{
		for (int j = 0; j < tedadras; j++)
		{
			s = s + matris[i][j];
		}
	}
	yal = s / 2;
	if ((hamband(matris, tedadras, false) == 2) && yal + 1 == tedadras) {
		cout << "graf derakht ast.\n";
	}
	else
	{
		cout << "graf derakht nist.\n";
	}
	cin.get();
	cin.get();
	return 1;
}
int yekrikhti(int **matris, int tedadras) {
	system("cls");
	int *yekr1 = new int[tedadras];
	int *yekr2 = new int[tedadras];
	cout << "matris dovom khod ra jahat moghayese vared konid.\n";
	cout << "tedad ras matris dovom ra vared konid.\n";
	int tedadras2;
	cin >> tedadras2;
	if (tedadras != tedadras2) {
		cout << "matris ha yek rikht nistand.\n";
		cin.get();
		cin.get();
		return 1;
	}
	int **matris2 = new int *[tedadras];
	for (int i = 0; i < tedadras; i++) {
		matris2[i] = new int[tedadras];
	}
	for (int i = 0; i < tedadras; i++)
	{
		cout << "baraye khate:" << (i + 1) << ":" << endl;
		for (int j = 0; j < tedadras; j++)
		{
			cout << "deraye:" << "{" << (i + 1) << " , " << (j + 1) << "}" << ":\t";
			cin >> matris2[i][j];
		}
	}
	for (int i = 0; i < tedadras; i++)
	{
		for (int j = 0; j < tedadras; j++)
		{
			cout << matris2[i][j] << "   ";
		}
		cout << endl << endl << endl;
	}
	for (int i = 0; i < tedadras; i++) {
		for (int j = 0; j < tedadras; j++) {
			yekr1[i] = yekr1[i] + matris[i][j];
			yekr2[i] = yekr2[i] + matris2[i][j];
		}
	}
	int temp;
	for (int i = tedadras - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (yekr1[j + 1] < yekr1[j]) {
				temp = yekr1[j];
				yekr1[j] = yekr1[j + 1];
				yekr1[j + 1] = temp;
			}
		}
	}
	temp = 0;
	for (int i = tedadras - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (yekr2[j + 1] < yekr2[j]) {
				temp = yekr2[j];
				yekr2[j] = yekr2[j + 1];
				yekr2[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < tedadras; i++) {
		if (yekr1[i] != yekr2[i]) {
			cout << "graf yek rikht nist.\n";
			cin.get();
			cin.get();
			return 1;
		}
	}
	cout << "graf yek rikht ast.\n";
	cin.get();
	cin.get();
	return 1;

}
// shoru tarif tavabe oileri
void zakhire(int val)
{
	top = top + 1;
	memoryoil[top] = val;
}
int hazf()
{
	return memoryoil[top--];
}
int checkyall(int i, int **matris, int tedadras)
{
	int j;
	for (j = 0; j < tedadras; j++)
	{
		if (matris[i][j] == 1)
			return 0;
	}
	return 1;
}
int checkesm(int c)
{
	int l = 0;
	while (c != esmerasgraph[l])
		l++;
	return l;

}
void chapmasir()
{
	for (int i = 0; i < fp; i++)
	{
		if (i == fp - 1) {
			cout << masiroileri[i] << "\t";
		}
		else {
			cout << masiroileri[i] << " ---> ";
		}
	}
}
void masiroilery(int rasrishe, int **copy, int tedadras) {
	
	int l, j;
	zakhire(esmerasgraph[rasrishe]);
	while (top != -1)
	{
		l = checkesm(memoryoil[top]);
		if (checkyall(l, copy, tedadras))
		{
			masiroileri[fp++] = hazf();

		}
		else
		{
			for (j = 0; j < tedadras; j++)
			{
				if (copy[l][j] == 1)
				{

					copy[l][j] = 0;
					copy[j][l] = 0;
					zakhire(esmerasgraph[j]);

					break;

				}
			}
		}
	}
}
int yaftdaraje(int i, int **matris, int tedadras)
{
	int j, deg = 0;
	for (j = 0; j < tedadras; j++)
	{
		if (matris[i][j] == 1) deg++;
	}
	return deg;
}
int rasshoru(int tedadaras, int **matris)
{

	int ras = 1;
	for (int i = 0; i < tedadaras; i++)
	{
		if (yaftdaraje(i, matris, tedadaras) % 2 != 0)
		{
			shomarande++;
			ras = i;
		}
	}
	if (shomarande != 0 && shomarande != 2)
	{
		return 0;
	}
	else return ras;
}

int oileri(int **matris, int tedadras)
{
	system("cls");
	int **copy = new int*[tedadras];
	for (int i = 0; i < tedadras; i++)
	{
		copy[i] = new int[tedadras];
	}
	for (int i = 0; i < tedadras; i++)
	{
		for (int j = 0; j < tedadras; j++)
		{
			copy[i][j] = matris[i][j];
		}
	}
	for (int i = 0; i < tedadras; i++)
	{
		esmerasgraph[i] = i;
	}
	int rasrishe;
	if (rasrishe = rasshoru(shomarande, matris))
	{
		if (shomarande) {
			cout << "masire euilere mojood:" << endl;
		}
		else {
			cout << "dore euilerie mojood:" << endl;
		}
		masiroilery(rasrishe, copy, tedadras);
		chapmasir();
	}
	else {
		cout << "dore euilleri vojood nadarad!!" << endl;
	}
	cin.get();
	cin.get();
	return 1;
}
int ghotregraf(int **vaznmatris, int tedadras) {
	system("cls");
	int *ghotr = new int[tedadras];
	int temp = ghotr[0];
	for (int i = 0; i < tedadras; i++) {
		ghotr[i] = masirdoras(vaznmatris, tedadras, 0, i, 0);
	}
	for (int i = 0; i < tedadras; i++) {
		if (ghotr[i] > temp) {
			temp = ghotr[i];
		}
	}
	cout << "ghotre graf barabar ast ba :\n" << temp;
	cin.get();
	cin.get();
	return 1;
}
int eigen(int **matris, int tedadras, bool energy)
{
	system("cls");
	double **matrisfloat = new double *[tedadras];
	for (int i = 0; i < tedadras; i++) {
		matrisfloat[i] = new double[tedadras];
	}
	for (int i = 0; i < tedadras; i++) {
		for (int j = 0; j < tedadras; j++) {
			matrisfloat[i][j] += matris[i][j];
		}
	}
	double x[100], z[100], e[100], zmax, emax;

	for (int i = 0; i < tedadras; i++) {
		for (int j = 0; j < tedadras; j++) {
			x[i] = x[i] + matrisfloat[i][j];
		}
	}
	do
	{
		for (int i = 0; i < tedadras; i++)
		{
			z[i] = 0;
			for (int j = 0; j < tedadras; j++)
			{
				z[i] = z[i] + matrisfloat[i][j] * x[j];
			}
		}
		zmax = fabs(z[0]);
		for (int i = 1; i<tedadras; i++)
		{
			if ((fabs(z[i]))>zmax)
				zmax = fabs(z[i]);
		}
		for (int i = 0; i < tedadras; i++)
		{
			z[i] = z[i] / zmax;
		}
		for (int i = 0; i < tedadras; i++)
		{
			e[i] = 0;
			e[i] = fabs((fabs(z[i])) - (fabs(x[i])));
		}
		emax = e[0];
		for (int i = 1; i < tedadras; i++)
		{
			if (e[i] > emax)
				emax = e[i];
		}
		for (int i = 0; i < tedadras; i++)
		{
			x[i] = z[i];
		}
	} while (emax > 0.00001);
	if (energy) {
		cout << "maghadir vizhe barabar'and ba:\n" << zmax << "\t";
		for (int i = 0; i < tedadras; i++)
		{
			cout << z[i] << "\t";
		}
	}
	else {
		double s = zmax;
		for (int i = 0; i < tedadras; i++) {
			s += z[i];
		}
		cout << "energy graf baraber ast ba: \n" << s;
	}
	for (int i = 0; i < tedadras; i++) {
		delete[] matrisfloat[i];
	}
	delete[] matrisfloat;
	cin.get();
	cin.get();
	return 1;
}
int energy(int **matris, int tedadras) {
	eigen(matris, tedadras, false);
	return 1;
}
int mosatah(int **matris, int tedadras) {
	system("cls");
	int s = 0, yal;
	for (int i = 0; i < tedadras; i++)
	{
		for (int j = 0; j < tedadras; j++)
		{
			s = s + matris[i][j];
		}
	}
	yal = s / 2;
	if (yal >(3 * tedadras) - 6)
	{
		cout << "graph mostah nist" << endl;
	}
	else cout << "graph mosatah ast " << endl;
	cin.get();
	cin.get();
	return 1;
}
int paakkardan(int **matris , int **vaznmatris , int tedadras)
{
	for (int i = 0; i < tedadras; i++) {
		delete[] matris[i];
	}
	delete[] matris;
	for (int i = 0; i < tedadras; i++) {
		delete[] vaznmatris[i];
		}
	delete[] vaznmatris;
	return 1;
}
