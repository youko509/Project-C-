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
using namespace std;


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

void  BintoDecimal(string str, int test ){
    int t,h;
    int num,number;
    int dec;
    string r, text, quo;
    stringstream ss,ff,tt;
    t=str.length();
    for(int i=0;i<t;i++){
        ff<<str[i];
        ff>>num;
        ff.clear();
        while(num!=0 && num!=1){
            cout<<"erreur entrer de nouveau le nombre"<<endl;
            cin>>str;
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
                                dec = num*pow(16,g-1);                               ;
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
         temp = "y";
            if(choix1==1){
                Choice();
                cout<<"choissisez pour continuez"<<endl;
                cin>>choix2;
                if(choix2==1){
                    while(temp=="y"){
                        ChoiceDecimal();
                        cout<<"choissisez pour continuez"<<endl;
                        cin>>choix3;
                        if(choix3==1){
                            cout<<"Entrez le nombre"<<endl;
                            cin>>number;
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
                                cin>>str;
                                BintoDecimal(str,test);
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
                                cin>>str;
                                BintoDecimal(str,test);
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
                                cin>>str;
                                BintoDecimal(str,test);;
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
                }
        }
         return 0;
    }

