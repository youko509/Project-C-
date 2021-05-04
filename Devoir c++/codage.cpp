#include<iostream>
#include<string>
#include<sstream>
#include <algorithm>
#include <conio.h>
#include<cstdlib>
#include<limits>
#include<math.h>
#include<cstring>
#include<vector>
#include<fstream>
using namespace std;
void vider_buffer(){
    cin.clear();
    cin.seekg(0,ios::end);
    if(!cin.fail()){
         cin.ignore(numeric_limits<streamsize>::max());
    } else{
        cin.clear();
    }


}

int EntierValid(int &number){
    string temp;
    stringstream ss,ff,tt;

	while(true){
    	getline(cin,temp);
    	if(cin.eof() || cin.bad()){
                cerr<<"erreur de saisie";
                if(cin.eof()){
                   return false;
                }
                vider_buffer();
                continue;

    	}else if(cin.fail()|| temp.find_first_not_of("0123456789")!=string::npos){
            cerr<<"ce n'est pas un nombre"<<endl;
            vider_buffer();
            continue;
        }
            ff<<temp;
            ff>>number;
            ff.clear();
           break;
        }

}

struct Etudiant{
string code;
string nom;
string prenom;
string adresse;
};
bool is_unique(string b)
{
    ifstream back_code;
    back_code.open("back_code.txt", ios::app);
    string line;
    while(getline(back_code,line))
    {
        if(line == b)
        {
            return false;
        }
        else
        {
            true;
        }
    }
}
void add_etudiant(){
    struct Etudiant e;
    int j,i,nbr;
    string t;
    ofstream file;
    ofstream back_code;//un autre flux creer pour stocker les codes etudiants dans un fichier a part
    file.open("file.txt",ios::app);
    back_code.open("back_code.txt", ios::app);
    j=4;
    bool test;
    cout<<"Entrez le nombre d'etudiant"<<endl;
    cin>>nbr;
    EntierValid(nbr);
    string tab[nbr][j];
    for( i=0;i<nbr;i++){
        cout<<"Entrer l'etudiant "<<i+1<<endl;
        for( j=0;j<4;j++){
            fflush(stdin);
            switch(j){
                case 0:
                    cout<<"Nom: "<<endl;
                    getline(cin,e.nom);
                    tab[i][j]=e.nom;
                    break;
                case 1:
                    cout<<"Prenom: "<<endl;
                    getline(cin,e.prenom);
                    tab[i][j]=e.prenom;
                    break;
                case 2:
                    test=true;
                     while(test){
                        fflush(stdin);
                        cout<<"Code: "<<endl;
                        getline(cin,e.code);
                        if (is_unique(e.code))
                        {
                            back_code<<e.code;
                            back_code<<endl;
                            test=false;
                        }else{
                            cout<<"echec  le code doit etre unique"<<endl;
                        }
                    }
                    tab[i][j]=e.code;
                    break;
                case 3:
                    cout<<"Adresse "<<endl;
                    getline(cin,e.adresse);
                    tab[i][j]=e.adresse;
                    break;
            }
        }
         if(file && back_code){
             file<<e.nom<<"\t"<<e.prenom<<"\t"<<e.code<<"\t"<<e.adresse;
             file<<endl;



    }else{
        cout<<"le fichier n'est pas creer";
    }
}
file.close();
 back_code.close();
    }
void display_etudiant()
{
    int data = 0;
    string line;
    char print;
    ifstream file;
    file.open("file.txt",ios::in);
    while(getline(file,line))
    {
        data++;
    }
    file.close();
    file.open("file.txt",ios::in);
    if(data>0)
    {
        while(getline(file,line))
        {
            cout<<line<<endl;
        }
        cout<<"taper p pour imprimer le fichier"<<endl;
        cin>>print;
        if( int (print)==112 || int(print)==80)
        {
            string f = ("notepad.exe /p backup.txt");
            system(f.c_str());//commande system utilis� pour imprimer un fichier
        }
    }
    else
    {
        cout<<"le fichier est vide, inscrivez des etudiants d'abord"<<endl;
    }
}
void data_class()
{
    string line;
    int nb_line = 0;
    char print;
    ifstream file;
    int i = 0;
    file.open("file.txt",ios::in);
    while(getline(file,line))//determinon la quantite de ligne qu'il y a dans le fichier
    {
        nb_line++;
    }
    file.close();
    if(nb_line>0)
    {
        file.open("file.txt",ios::in);
        string tab[nb_line];
        while(getline(file,line))//stockons les valeur extrait du fichier dans un tableau
        {
            tab[i] = line;
            //si la premiere caractere du nom est minuscule changer lla en majuscule
            if(int (tab[i][0]) >97 && int (tab[i][0])<122)
            {
               tab[i][0]=char (int (tab[i][0])-32);
            }
            i++;
        }
        file.close();
        //trie du tableau par ordre alphabetique
        string temp;
        for (int p = 0; p<nb_line;p++)
        {
            for(int i = 0; i<nb_line-p;i++)
            {
                if(tab[i] > tab[i+1])
                {
                    temp=tab[i];
                    tab[i]=tab[i+1];
                    tab[i+1]=temp;
                }
            }
        }


        for (int i = 0; i<nb_line; i++)//stockons les valeur extrait du fichier dans un tableau
        {
            cout<<tab[i]<<endl;
        }
    }
}
void Menu(){
    cout<<"------------------------------------------Bienvenue dans mon Programme------------------------------"<<endl;
    cout<<"Faites un choix parmi la liste ci-dessus: "<<endl;
    cout<<"1.......................  Operation de Codage/Decodage/Transcodage"<<endl;
    cout<<"2.......................  Operations mathematiques"<<endl;
    cout<<"3.......................  Gestions d'information sur un etudiant"<<endl;
    cout<<"4.......................  Ma realisation"<<endl;
    cout<<"5....................... Pour quitter le programme"<<endl;
    cout<<""<<endl;
}

void ChoiceDecimal( ){
    cout<<"1.......................  Binaire"<<endl;
    cout<<"2.......................  Octal"<<endl;
    cout<<"3.......................  Hexadecimal"<<endl;
}
void ChoiceBinaire( ){
    cout<<"1.......................  Decimal"<<endl;
    cout<<"2.......................  Octal"<<endl;
    cout<<"3.......................  Hexadecimal"<<endl;
}
void ChoiceHexa( ){
    cout<<"1.......................  Octal"<<endl;
    cout<<"2.......................  Binaire"<<endl;
    cout<<"3.......................  Decimal"<<endl;
}
void Choice( ){
    cout<<"Choissisez un option de codage/decodage/transcodage :"<<endl;
    cout<<"1.......................  Decimal"<<endl;
    cout<<"2.......................  Binaire"<<endl;
    cout<<"3.......................  Hexadecimal"<<endl;
}





void DectoBin(int number ){
    int quotient;
    int res;
    string r, text;
    do{
        quotient= number/2;
        res = number%2;
        if (res==0){
             text="0";
        }else{
             text="1";
        }
        r=r+text;
        number = quotient ;

    }while(quotient>=1);
    string r_reversed(r);
    reverse( r_reversed.begin(), r_reversed.end());
    cout<<"Le binaire est : "<<r_reversed<<endl;
}
void DectoOctal(int number ){
    int quotient;
    int res;
    int i;
    bool var;
    int t[8]={0,1,2,3,4,5,6,7};
    string r, text, str, quo,num;
    stringstream ss,ff,tt;
    var=false;
    for(int i=0;i<8;i++){
        if(number == t[i]){
            cout<<"l'octal est :"<<number<<endl;
            i=9;
            var=true;

        }
        }
         if(var==false){
             do{
                quotient= number/8;
                res = number%8;
                ff<<res;
                ff>>num;
                ff.clear();
                quo=quo+num;
                number = quotient ;
                if (quotient<8){
                        tt<<quotient;
                        tt>>text;
                        tt.clear();
                        quo+=text;
                }
            }while(quotient>=8);
            string r_reversed(quo);
            reverse( r_reversed.begin(), r_reversed.end());
            cout<<"l'octal est :"<<r_reversed<<endl;
        }




}
void DectoHexa(int number ){
    int quotient;
    int res;
    int i;
    bool var;
    int t[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    string r, text, str,quo,num;
    stringstream ss,ff,tt;
    var=false;
    for(int i=0;i<16;i++){
        if(number == t[i]){
           switch(number){
                case 10:
                    str="A";
                    break;
                case 11:
                    str="B";
                    break;
                case 12:
                    str="C";
                    break;
                case 13:
                    str="D";
                    break;
                case 14:
                    str="E";
                    break;
                case 15:
                    str="F";
                    break;
                default:
                    ss<<number;
                    ss>>str;
           }
           cout<<"l'Hexa est :"<<str<<endl;
           var=true;

           break;
        }
    }
         if (var==false){
            do{

                quotient= number/16;
                res = number%16;
                 switch(res){
                case 10:
                    num="A";
                    break;
                case 11:
                    num="B";
                    break;
                case 12:
                    num="C";
                    break;
                case 13:
                    num="D";
                    break;
                case 14:
                    num="E";
                    break;
                case 15:
                    num="F";
                    break;
                default:
                    ff<<res;
                    ff>>num;
                    ff.clear();
           }
                r=r+num;
                number = quotient ;
                if (quotient<16){
                    switch(quotient){
                        case 10:
                            num="A";
                            break;
                        case 11:
                            num="B";
                            break;
                        case 12:
                            num="C";
                            break;
                        case 13:
                            num="D";
                            break;
                        case 14:
                            num="E";
                            break;
                        case 15:
                            num="F";
                            break;
                        default:
                            tt<<quotient;
                            tt>>quo;
                            tt.clear();
                    }
                    quo=num;
                    r+=quo;
                }

            }while(quotient>=16);
            string r_reversed(r);
            reverse( r_reversed.begin(), r_reversed.end());
            cout<<"l'Hexadecimal :"<<r_reversed<<endl;
        }
}

void  BintoDecimal(int number, int test ){
    int t,h;
    int num;
    int dec;
    string r, text, quo,str;
    stringstream ss,ff,tt;
    ss<<number;
    ss>>str;
    ss.clear();
    t=str.length();
    for(int i=0;i<t;i++){
        ff<<str[i];
        ff>>num;
        ff.clear();
        while(num!=0 && num!=1){
            cout<<"veuillez Entrer un nombre binaire"<<endl;
            cin>>number;
            EntierValid(number);
            ss<<number;
            ss>>str;
            ss.clear();
            t=str.length();
            for(int i=0;i<t;i++){
                ff<<str[i];
                ff>>num;
                ff.clear();
                if(num!=1 && num!=0){
                   i=t;
                }
            }
        }
    }
    number=0;
    h=t;
    for(int i=0;i<t;i++){
        ff<<str[i];
        ff>>num;
        dec = num*pow(2,h-1);
        number = number + dec;
        h =h-1;
        ff.clear();
    }
    cout<<"le decimal est : "<<number<<endl;
    if(test==1){
        DectoOctal(number);
    }
    if(test==2){
        DectoHexa(number);
    }

}
void HextoDec(string trem, int test){
    int num,number;
    int res,dec;
    int i,g,j,d,tem;
    string t[6]={"A","B","C","D","E","F"};
    string p[6]={"a","b","c","d","e","f"};
    string all_ch[22]={"A","B","C","D","E","F","a","b","c","d","e","f","0","1","2","3","4","5","6","7","8","9"};
    int h[6]={10,11,12,13,14,15};
    string s[10]={"0","1","2","3","4","5","6","7","8","9"};
    stringstream ss,ff,tt;
    d=trem.length();
    string str[d]={trem};
    number=0;
    for(int v=0;v<d;v++){
        tem=trem[v];
        str[v]=tem;
    }
    j=sizeof(str)/sizeof(str[0]);
    g=j;


        for(int i=0;i<j;i++){
            for(int e=0;e<6;e++){
                if(str[i]==t[e] || str[i]==p[e]){
                        tem=h[e];
                        dec = tem*pow(16,g-1);
                        number = number + dec;
                        g = g-1;
                        ff.clear();
                        e=6;
                    }else{
                        for(int n=0; n<10;n++){
                             if(str[i]==s[n]){
                                tt<<str[i];
                                tt>>num;
                                dec = num*pow(16,g-1);
                                number = number + dec;
                                g = g-1;
                                tt.clear();
                                n=10;
                                e=6;
                            }
                        }
                    }
                }
        }
    cout<<"le decimal est : "<<number<<endl;
    if(test==1){
        DectoOctal(number);
    }else if(test==2){
        DectoBin(number);
    }


}
int n;int p; bool again= true;bool agan= true;int press=3;int looses =0;int win=0;int level; int menu;int choix;int i;;
int devde(){


	do{	system("cls");
			cout<<"choisissez le nombre d'allumette pour commencer(au minimum neuf)\n\n";
			cin>>n;
			while(n<9 ) {
				cout<<"vous devez prendre au moins huits(8) allumette.\n";
				cin>>n;
			}

			while(n>0) {if(n==1) {
							cout<<"joueur 1 n'a qu'une seule allumette restant!.... joueur 2 a gagnee\n";
							break;
						}
						cout<<"Joueur 1:choisis le nombre d'allumetes a prendre\n";

						int y;
						cin>>y;
						while(y>3 || y<0) {
							cout<<"vous devez prendre un, deux ou trois allumettes\n";
							cin>>y;
						}
						n= n-y;
						system("cls");
						cout<<"il reste " <<n << " allumettes\n";
						if(n==0) {
							cout<<"joueur 2 a gagne\n";

							break;
						}
						if(n==1) {
							cout<<"il y a qu'une seul choix pour joueur deux(2)!...., joueur 1 a gagnee \n";

							break;
						}
						system("pause");
						cout<<"Joueur 2:choisis le nombre d'allumette a prendre\n";
						cin>>p;
						while(p>3 || p<0) {
							cout<<"vous devez prendre un, deux ou trois allumettes\n";
							cin>>p;
						}
						n=n-p;

						if(n==0) {
							cout<<"joueuer un(1) a gagner\n";
							break;
						}
						cout<<"..il reste " <<n <<" allumettes\n";
						system("pause");

					}
				do {
					cout<<"Pressez un(1) pour rejouer deux(2) pour quitter\n\n";
					cin>>press;
						if(press==2) {
							again=false;
						}

					}while(!(press==1)&& !(press==2));
			}while(again);

		cout<<"Fin de la Partie\n\n";


}
int jouer1 (){

	do{	int levelup=0;
				do {system("cls");
						cout<<"\tchoisissez le niveau de difficultee\n\n";
						cout<<"\tpressez un(1)pour facile\n\n"<<"\tpressez deux(2)pour medium\n\n"<<"\tpressez trois(3)pour difficile\n\n";
						cin>>level;

					}while(!(level==1)&& !(level==2)&&!(level==3));
					system("cls");
			cout<<"choisissez le nombre d'allumette pour commencer(au minimum neuf)\n\n";
			cin>>n;
			while(n<9 ) {
				cout<<"vous devez prendre au moins huits(8) allumette.\n";
				cin>>n;
			}

			while(n>0) {if(n==1) {looses++;
							cout<<"vous avez qu'une seul choix!.... sorry vous avez perdu\n";
							break;
						}
						cout<<"choisis le nombre d'allumetes a prendre\n";

						int y;
						cin>>y;
						while(y>3 || y<0) {
							cout<<"vous devez prendre un, deux ou trois allumettes\n";
							cin>>y;
						}
						n= n-y;
						system("cls");
						cout<<"il reste " <<n << " allumettes\n";
						if(n==0) {
							cout<<"vous avez perdu\n";
							looses++;
							break;
						}
						if(n==1) {
							cout<<"il y a qu'une seul choix!.... bravo, vous avez gagnee\n";
							win++;
							break;
						}
						if(n%4==3) {
							p=2;
							if((levelup%2==0 && level==1)||((levelup%5==0) && level==2 )  ) {
								p=3;
							}
						}else if(n%4==2) {
							p=1;
							if((levelup%2==0 && level==1)||((levelup%5==0) && level==2 )  ) {
								p=3;
							}

						}else if(n%4==0) {
							 p=3;
							 if((levelup%2==0 && level==1)||((levelup%5==0) && level==2 )  ) {
									p=2;
							}

						}else {
							p=1;
						}levelup++;
						system("pause");
						cout<<"moi j'en prends "<<p<<":)\n";
						n=n-p;

						if(n==0) {win++;
							cout<<"bravo vous avez gagnee\n";
							break;
						}
						cout<<"donc...il reste " <<n <<" allumettes\n";
						system("pause");

					}
				do {
					cout<<"Pressez un(1) pour rejouer deux(2) pour quitter\n\n";
					cin>>press;
						if(press==2) {
							again=false;
						}

					}while(!(press==1)&& !(press==2));
			}while(again);

		cout<<"Fin de la Partie\n\n";


}
int jouer(){ system("cls");
    cout<<"\n\tPresser un(1) pour jouer contre un ami\n\n\tpresser deux(2) pour jouer contre l'IA\n";
    cin>>press;
    switch(press){
        case 1:devde();break;
        case 2:jouer1();break;
        default: jouer;
    }
}
int astuce(){
    system("cls");
    cout<<"\t\t\t\tASTUCES\n\n\n1:Fais en sorte de laisse que la derniere allumettes a votre adversaire.\n\tEx: si il reste 4 allumettes, et c'est a votre tour,choisissez de prendre 3 allumettes ,ainsi votre adversaire n'aura qu'une seule option,c'est de prendre la derniere ainsi vous aurez gagne.\n\n2:Essayer de jouer le plus que possible avec le IA, il pourrais vous reveler son secret :)\n\n3:Fais attention au numero 5. \n";
    system("pause");
}
int stats(){
    do{system("cls");
    cout<<"Total win: "<<win;
		cout<<"\n\nTotal looses: "<< looses<<"\n\n\nPresser un(1)pour clear\n\n\nPresser deux(2) pour quitter\n";
		cin>>press;
    if(press==1){
        win=0;looses=0;
    }
    }while(!(press==2));
}
int regles(){
    system("cls");
    cout<<"\t\t\t\t LES JEU DES ALLUMETTES\n\n\n\tLe jeu des allumettes comprends trois regles simples\n\n1: vous disposez d'un nombre d'allumettes (Nombre que vous choisissez au prealable).\n\n2:Vous devez tirer un,deux,ou trois allumettes de la pile d'allumettes a chaque tour,puis l'IA ou votre adversaire en tire aussi un\n\n 3:La personne a tirer la ou les dernieres allumette aura perdu.\n\n\n\npresser un(1) pour voir quelque astuces\npresser deux(2)pour retourne au menu principale\n "
;cin>>press;
    switch(press){
        case 1:astuce();
        case !2:regles();
    }
}
int allumettes(){
    do{system("cls");
    cout<<"\t\t================Menu================\n\n\n\t\tPresser un(1)pour jouer\n\n\t\tPresser deux(2) pour voir les regles\n\n\t\tPresser trois(3) pour voir les statistiques\n\n";
        cin>>choix;
        switch(choix){
            case 1:jouer();break;
            case 2:regles();break;
            case 3:stats();

        }

    }while(true);
}
int multi(){
    int choix1,choix2,choix3, choixDeRetour, m_lignes,m_colonnes,m_lignes1,m_colonnes1;
        cout<<"Entrer le nombre de lignes de votre matrice1"<<endl;
        cin>>m_lignes;
        cout<<"Entrer le nombre de colonnes de votre matrice1"<<endl;
        cin>>m_colonnes;
        cout<<"Entrer le nombre de lignes de votre matrice2"<<endl;
        cin>>m_lignes1;
        cout<<"Entrer le nombre de colonnes de votre matrice2"<<endl;
        cin>>m_colonnes1;
        while(m_colonnes!=m_lignes1)
        {
        cout<<"Erreur!!Le nombre de colonnes de matrice1 doit egales au nombre de lignes de matrice2.Veuillez reesayer"<<endl;
        cout<<"Entrer le nombre de lignes de votre matrice1"<<endl;//mettre pause peut etre
        cin>>m_lignes;
        cout<<"Entrer le nombre de colonnes de votre matrice1"<<endl;
        cin>>m_colonnes;
        cout<<"Entrer le nombre de lignes de votre matrice2"<<endl;
        cin>>m_lignes1;
        cout<<"Entrer le nombre de colonnes de votre matrice2"<<endl;
        cin>>m_colonnes1;
        }
        int a[m_lignes][m_colonnes];
        int b[m_lignes1][m_colonnes1];
        int p,h;
        p=0;
        h=0;
        cout<<"Entrer les valeurs de la premiere matrice"<<endl;
        for(int k=0;k<m_lignes;k++)
        {
        for(int l=0;l<m_colonnes;l++)
        {
            cin>>a[k][l];
        }
        }
        cout<<"Entrer les valeurs de la deuxieme matrice"<<endl;
        for(int m=0;m<m_lignes1;m++)
        {
        for(int n=0;n<m_colonnes1;n++)
        {
            cin>>b[m][n];
        }
        }

        cout<<"Le resultat est: "<<endl;
        int r[m_lignes][m_colonnes1];

                for(int k=0;k<m_lignes;k++)
                {
                       for(int l=0;l<m_colonnes1;l++)
                        {
                            for(int m=0;m<m_lignes1;m++)
                            {
                                p= a[k][m]*b[m][l]+p;
                            }
                            r[k][l]=p;
                            p=0;
                        }
                }
                cout<<"le troisime matrice devient"<<endl;
               for(int k=0;k<m_lignes;k++)
                {
                       for(int l=0;l<m_colonnes1;l++)
                        {
                            cout<<r[k][l]<<"|";
                        }
                        cout<<"\n";
                }
                system("pause");
}
void remp_tab(int* p,int* tab,int l,int c)
{
    int k=0;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            p[k]=tab[k];
            k++;
        }
    }
    k=0;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<tab[k]<<"|";
            k++;
        }
        cout<<endl;
    }
    system("pause");
}
void ajout_valeur(int& val1,int& val2,int& val3,int& val4,int i,int j,int k,int L,int x,int n)
{
    if( (i==(L*2)-2 && j==n/2) || (i==(L*2)&& j!=n/2) )//cas de U
    {
        val1=k+3;
        val2=k+2;
        val3=k+1;
        val4=k;
    }
    else if(x-1!=0 && i>=(L*2)+2)//cas de X
    {
        val1=k+3;
        val2=k+1;
        val3=k+2;
        val4=k;
    }
    else//cas de L
    {
        val1=k;
        val2=k+2;
        val3=k+1;
        val4=k+3;
    }
}
void simple_square(int *p,int n)
{
    int tab[n][n],i,j,k;
    int x=((n/2)-1)/2, L=x+1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            tab[i][j]=0;
        }
    }
    i=0;
    j=n/2;
    ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,1,L,x,n);
    for(k=5;k<=n*n;k+=4)
    {
        i-=2;
        j+=2;
        if(i>=0 && j<n && tab[i][j]==0)//case ok
        {
             ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,k,L,x,n);
        }
        else if(i>=0 && j<n && tab[i][j]!=0)//case occupe
        {
            i+=4;
            j-=2;
            ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,k,L,x,n);
        }
        else if(i<0 && j<n)//debordement en haut
        {
            i=n-2;
            ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,k,L,x,n);
        }
        else if(i>=0 && j>=n)//debordement a droite
        {
            j=1;
            ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,k,L,x,n);
        }
        else
        {
            i+=4;
            j-=2;
            ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,k,L,x,n);
        }
    }
    remp_tab(p,(int*)tab,n,n);
}

int carre(){ system("cls");
    	cout<<"\t\tLe carre magique d'odre doublement paire ou simplement\n\n\t\tCe carre est de taille k\n\n\t\tEntrer le nombre k: ";
		int r;
		cin>>r;
		while(r%2 != 0){
            cout<<"Vous devez entrer un nombre pair"<<endl;
            cin>>r;
            EntierValid(r);
		}
		int i ;
		int j ;
		int k= 1;
		int o=r;
		int p[o][o] ;
		cout<<"\n\n\t\t Votre carre est de taille "<<o<<"X"<<o<<".";
		 if (r % 2 == 0)
            {
            if (r%4 != 0)
                {
                    int k[o*o];
                    simple_square(k,r);
                }else{
                    system("pause");
                    system("cls");
                    for(i=0;i<o;i++){
                        for(j=0;j<o;j++){

                            p[i][j]= k;
                        if((((i%4==0)||((i+1)%4==0))&&((j%4==0)||((j+1)%4==0)))||((!(i%4==0)&&!((i+1)%4==0))&&(!(j%4==0)&&!((j+1)%4==0)))){

                                p[i][j]=(o*o +1)-p[i][j];
                            }

                            k++;
                            }
                        }
                        cout<<"Votre carre magique  est:\n";
                        for(i=0;i<o;i++){
                            for(j=0;j<o;j++){
                                cout<<p[i][j]<<"|";
                            }
                            cout<<"\n";
                        }system("pause");
                        while(true){
                            cout<<"\nPresser un(1) pour faire un autre  carree\nPresser deux(2) pour retourner au menu precedent\n";
                                cin>>press;
                                if(press==2 || press==1){break;}
                        };
                        if (press==1){carre();}
                            }
            }

 }
int systemD(){system("cls");
    cout<<"\t\tSYSTEM D'EQUATIONS A DEUX INCONNU\n\n\n\tle systeme d'equation est de la forme suivante:\n\t\tax+by=c \n\t\t\n\t\tet\n \n\t\tmx+ny=p\n\n";
        system("pause");
        	double a;double b;double c;double ai;double bi;double ci;double x;double y;
        	cout<<"\n\nEntrer a: ";
        	cin>>a;
        	cout<<"\nEntrer b: ";
        	cin>>b;
        	cout<<"\nEntrer c: ";
        	cin>>c;
        	cout<<"\nEntrer m: ";
        	cin>>ai;
        	cout<<"\nEntrer n: ";
        	cin>>bi;
        	cout<<"\nEntrer p: ";
        	cin>>ci;
	x=(c-(b*ci/bi))/(a-(ai*b/bi));y=(c-a*x)/b;
	cout<<"La solution du systeme est le couple x,y:(";
	cout<<x<<","<<y<<").\n\n";
	 while(true){
                cout<<"\nPresser un(1) pour faire un autre  calcul\nPresser deux(2) pour retourner au menu precedent\n";
                    cin>>press;
                    if(press==2 || press==1){break;}
            };
	switch(press){
        case 1: systemD();

	}

}

void remplir_tab(int* p,int* tab,int l,int c){
    int k=0;
    for(int i=0;i<l;i++){
         for(int j=0;j<c;j++){
            p[k]=tab[k];
            k++;
         }
    }
}
void remplir_tab(float* p,float * tab,int l,int c){
    int k=0;
    for(int i=0;i<l;i++){
         for(int j=0;j<c;j++){
            p[k]=tab[k];
            k++;
         }
    }
}
void p_gauss(float *m1,int l,int c,int &permute){
    permute=1;
    int i,j, p=0,k;
    float x, maxi, m[l][c];
    remplir_tab((float*)m,m1,l,c);
    for(j=0;j<c;j++)
    {
        maxi=m[p][j];
        k=p;
        for(i=p+1;i<l;i++)
        {
            if(maxi<abs(m[i][j]))
            {
                maxi=m[i][j];
                k=i;
            }
        }
        if(maxi!=0)
        {
            if(k!=p)
            {
                permute++;
                for(i=0;i<c;i++)
                {
                    maxi=m[k][i];
                    m[k][i]=m[p][i];
                    m[p][i]=maxi;
                }
            }
            for(i=p+1;i<l;i++)
            {
                x=-m[i][j];
                for(k=j;k<c;k++)
                {
                    m[i][k]+=(x/ m[p][j]) * m[p][k] ;
                }
            }
        }
        p++;
    }
    remplir_tab(m1,(float*)m,l,c);
}
float determinant(float *m,int n){
    float m1[n][n],delta=1;
    int i,j;
    int permute;
    remplir_tab((float*)m1,m,n,n);
    p_gauss((float*)m1,n,n,permute);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                delta*=m1[i][j];
            }
        }
    }
    if(permute%2==0)
    {
        delta*=-1;
    }
    return delta;
}
int detTrans(){ system("cls");
    int L;int l;
    cout<<"Entrer la taille de la matrice\n";
    cin>>L;cin>>l;
    float y[L][l];
    for (int i=0;i<L;i++){
        for(int j=0;j<l;j++){cout<<"y["<<i<<"]["<<j<<"]: ";
                cin>>y[i][j]; }
    }
    do{ system("cls");
    cout<<"la matrice est: \n";
    for (int i=0;i<L;i++){
        for(int j=0;j<l;j++){cout<<y[i][j]<<"|"; }
        cout<<"\n";}
    do{
            cout<<"\n\nPresser un(1) pour calculer la transposee\npresser deux(2) pour Obtenir le determinant\nPresser trois(3) pour entre un autre matrice\nPresser quatres(4) pour retourner au menu precedent\n";
    cin>>press;}while(!(press==1)&&!(press==2)&&!(press==3)&&!(press==4));

    switch(press){
    case 1:cout<<"la transposee de la matrice est: \n";
                for (int i=0;i<l;i++){
                    for(int j=0;j<L;j++){cout<<y[j][i]<<"|"; }
                cout<<"\n";};break;
    case 2:if(l==L){cout<<"le determinant est: "<<determinant(*y,l)<<endl;break;}else{cout<<"la matrice doit etre carre.";break;}
    case 3: detTrans();
    case 4:agan=false;
    }
    system("pause");
    }while(agan);
}
int math(){do{system("cls");
    cout<<"\t\tMATH\n\n\n\tPresser:\n\n\t\t1: pour realiser un carre magique d'odre doublement paire\n\t\t2:pour realiser la multiplication de deux matrices\n\t\t3:pour la resolution d'un systeme d'equations a deux inconnu\n\t\t4:Pour determiner la transposer et le determinant d'une matrice.\n\t\t5:pour retourner au menu precedent.\n";
    cin>>press;
    switch(press){
        case 1:carre();break;
        case 2: multi();break;
        case 3:systemD();break;
        case 4:detTrans();break;
        }
        if(press==5){break;}
    }while(true);

}
int main(){
    int number,test;
    string tem;
    test=0;
    int choix1,choix2, choix3;
    string temp, temp2,str;
    temp="y";
    temp2 = "o";
    while(temp2=="o"){
        Menu();
        cout<<"choissisez pour continuez"<<endl;
        cin>>choix1;
        EntierValid(choix1);
        system("cls");
         temp = "y";
            if(choix1==1){
                Choice();
                cout<<"choissisez pour continuez"<<endl;
                cin>>choix2;
                EntierValid(choix2);
                if(choix2==1){
                    while(temp=="y"){
                        ChoiceDecimal();
                        cout<<"choissisez pour continuez"<<endl;
                        cin>>choix3;
                        EntierValid(choix3);
                        if(choix3==1){
                            cout<<"Entrez le nombre"<<endl;
                            cin>>number;
                            EntierValid(number);
                            DectoBin(number);
                            system("cls");
                            cout<<"Voulez-vous continuez? tapez y pour une operation de decode, etc .... ou o pour retourner au menu "<<endl;
                            cin>>temp;
                            if(temp=="y"){
                                temp = "y";
                            }else if(temp==temp2){
                               temp2 ="o";
                            }else{
                                temp2="f";
                                break;
                            }
                        }else if(choix3==2){
                            cout<<"Entrez le nombre"<<endl;
                            cin>>number;
                            EntierValid(number);
                            DectoOctal(number);
                            cout<<"Voulez-vous continuez? tapez y pour une operation de decode, etc .... ou o pour retourner au menu "<<endl;
                            cin>>temp;
                            system("cls");
                            if(temp=="y"){
                                temp = "y";
                            }else if(temp==temp2){
                               temp2 ="o";
                            }else{
                                temp2="f";
                                break;
                            }

                        }else if(choix3==3){
                            cout<<"Entrez le nombre"<<endl;
                            cin>>number;
                            EntierValid(number);
                            DectoHexa(number);
                            cout<<"Voulez-vous continuez? tapez y pour une operation de decode, etc .... ou o pour retourner au menu "<<endl;
                            cin>>temp;
                            system("cls");
                            if(temp=="y"){
                                temp = "y";
                            }else if(temp==temp2){
                               temp2 ="o";
                            }else{
                                temp2="f";
                                break;
                            }
                        }
                    }

                }else if(choix2==2){
                       while(temp=="y"){
                            ChoiceBinaire();
                            cout<<"choissisez pour continuez"<<endl;
                            cin>>choix3;
                            if(choix3==1){
                                cout<<"Entrez le Binaire"<<endl;
                                cin>>number;
                                EntierValid(number);
                                BintoDecimal(number,test);
                                cout<<"Voulez-vous continuez? tapez y pour une operation de decode, etc .... ou o pour retourner au menu "<<endl;
                                cin>>temp;
                                system("cls");
                                if(temp=="y"){
                                    temp = "y";
                                }else if(temp==temp2){
                                   temp2 ="o";
                                }else{
                                    temp2="f";
                                    break;
                                }
                            }else if(choix3==2){
                                cout<<"Entrez le nombre"<<endl;
                                test=1;
                                cin>>number;
                                EntierValid(number);
                                BintoDecimal(number,test);
                                cout<<"Voulez-vous continuez? tapez y pour une operation de decode, etc .... ou o pour retourner au menu "<<endl;
                                cin>>temp;
                                system("cls");
                                if(temp=="y"){
                                    temp = "y";
                                }else if(temp==temp2){
                                   temp2 ="o";
                                }else{
                                    temp2="f";
                                    break;
                                }

                            }else if(choix3==3){
                                cout<<"Entrez le nombre"<<endl;
                                test=2;
                                cin>>number;
                                EntierValid(number);
                                BintoDecimal(number,test);
                                cout<<"Voulez-vous continuez? tapez y pour une operation de decode, etc .... ou o pour retourner au menu "<<endl;
                                cin>>temp;
                                system("cls");
                                if(temp=="y"){
                                    temp = "y";
                                }else if(temp==temp2){
                                   temp2 ="o";
                                }else{
                                    temp2="f";
                                    break;
                                }
                            }
                        }

                }else if(choix2==3){
                      while(temp=="y"){
                        ChoiceHexa();
                        cout<<"choissisez pour continuez"<<endl;
                        cin>>choix3;
                        if(choix3==1){
                            test=1;
                            cout<<"Entrez le nombre"<<endl;
                            cin>>tem;
                            HextoDec(tem,test);
                            cout<<"Voulez-vous continuez? tapez y pour une operation de decode, etc .... ou o pour retourner au menu "<<endl;
                            cin>>temp;
                            system("cls");
                            if(temp=="y"){
                                temp = "y";
                            }else if(temp==temp2){
                               temp2 ="o";
                            }else{
                                temp2="f";
                                break;
                            }
                        }else if(choix3==2){
                            test=2;
                            cout<<"Entrez le nombre"<<endl;
                            cin>>tem;
                            HextoDec(tem,test);
                            cout<<"Voulez-vous continuez? tapez y pour une operation de decode, etc .... ou o pour retourner au menu "<<endl;
                            cin>>temp;
                            system("cls");
                            if(temp=="y"){
                                temp = "y";
                            }else if(temp==temp2){
                               temp2 ="o";
                            }else{
                                temp2="f";
                                break;
                            }

                        }else if(choix3==3){
                            cout<<"Entrez le nombre"<<endl;
                            cin>>tem;
                            HextoDec(tem,test);
                            cout<<"Voulez-vous continuez? tapez y pour une operation de decode, etc .... ou o pour retourner au menu "<<endl;
                            cin>>temp;
                            if(temp=="y"){
                                temp = "y";
                            }else if(temp==temp2){
                               temp2 ="o";
                            }else{
                                temp2="f";
                                break;
                            }
                        }
                    }

                }
                }else if (choix1==2){
                    math();
                }else if(choix1==3){
                    while(temp=="y"){
                    cout<<"||1... Saisir les informations sur un etudiants             ||"<<endl;
                    cout<<"||2... Affichage des informations du fichier                ||"<<endl;
                    cout<<"||3... Afficher les informations par ordre alphabetiques    ||"<<endl;
                    cin>>choix2;
                    EntierValid(choix2);
                    switch(choix2){
                        case 1:
                            add_etudiant();
                            break;
                        case 2:
                            display_etudiant();
                            break;
                        case 3:
                            data_class();
                            break;
                        default:
                            cout<<"choissisez parmis les options suivantes"<<endl;
                    }
                    cout<<"Voulez-vous continuez? tapez y pour retournez au menu, etc .... ou o pour retourner au menu principale et taper n'importe quelle touche pour quitter le prgramme"<<endl;
                    cin>>temp;
                    system("cls");
                    if(temp=="y"){
                        temp = "y";
                    }else if(temp==temp2){
                       temp2 ="o";
                    }else{
                        temp2="f";
                        break;
                    }

                }
                }else if(choix1==4){
                    allumettes();
                }else if (choix1==5){
                    break;
                }
        }
         return 0;
    }

