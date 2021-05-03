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
    file.open("backup.txt",ios::app);
    back_code.open("back_code.txt", ios::app);
    j=4;
    bool test;
    cout<<"Entrez le nombre d'etudiant"<<endl;
    cin>>nbr;
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
    file.open("backup.txt",ios::in);
    while(getline(file,line))
    {
        data++;
    }
    file.close();
    file.open("backup.txt",ios::in);
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
            string k = ("backup.txt");
            system(k.c_str());//commande system utilis� pour imprimer un fichier
        }
    }
    else
    {
        cout<<"la base de donnee est vide, relancer le programme et inscrivez des etudiants d'abord"<<endl;
    }
}
void data_class()
{
    string line;
    int nb_line = 0;
    char print;
    ifstream file;
    int i = 0;
    file.open("backup.txt",ios::in);
    while(getline(file,line))//determinon la quantite de ligne qu'il y a dans le fichier
    {
        nb_line++;
    }
    file.close();
    if(nb_line>0)
    {
        file.open("backup.txt",ios::in);
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

                }else if(choix1==3){
                    while(temp=="y"){
                    cout<<"||1... Saisir les informations sur un etudiants             ||"<<endl;
                    cout<<"||2... Affichage des informations du fichier                ||"<<endl;
                    cout<<"||3... Afficher les informations par ordre alphabetiques    ||"<<endl;
                    cin>>choix2;
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
                    }
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
         return 0;
    }

