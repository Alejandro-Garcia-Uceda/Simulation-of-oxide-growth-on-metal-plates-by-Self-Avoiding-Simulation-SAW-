//TRABAJO
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h> 
using namespace std;
int dim=50;
int part=100000;
int nucleo=10;
int itmax=2000;
int main(){
ofstream fout("areaoxidada.txt");
ofstream imp("malla.txt");
ofstream datos("datos.txt");
ofstream camino("camino.txt");
srand(time(NULL));
double pot_ox[3],pm[3],porcent;//pm=probability of oxidation 
int malla[dim+1][dim+1], h[dim+1][dim+1],x[itmax],y[itmax],xn[nucleo],yn[nucleo],X,Y,nox,npasos,pdesin;
nox=0;npasos=0;pdesin=0;//nox=disintegrated particles; pdesin= number of particles disintegrated

// pot_ox=oxidation potential/ 1 is aluminum, 2 is iron, 3 is tin------------
pot_ox[0]=1.68; pot_ox[1]=0.44;pot_ox[2]=0.14;
for (int i=0;i<3;i++){pm[i]=1.0-(pot_ox[i]*(1.0/3.0));}
cameback:
cout<<"Choosing a metal for the plate: " << endl;
cout << "   0.Aluminum(Al)" << endl;
cout << "   1.Hierro (Fe)" << endl;
cout << "   2.Tin (Sn)" << endl;
int b; 
cout << "The metal of choice is: ";
cin >> b;
if((b!=0)&&(b!=1)&&(b!=2)){cout << "Re-select a metal from the list provided. " << endl; goto cameback;}


//I MAKE A MATRIX OF ZEROS
for (int i=0;i<=dim;i++){ for (int j=0;j<=dim;j++){malla[i][j]=0;h[i][j]=0;}}


///////////////////////////////////////////////
//RANDOMLY SELECT THE OXIDATION NUCLEI
for (int i=0;i<nucleo;i++){ 
do{xn[i]=rand()%(dim+1); yn[i]=rand()%(dim+1);}while (malla[xn[i]][yn[i]]==1);
malla[xn[i]][yn[i]]=1; h[xn[i]][yn[i]]=1;nox++;
for (int i=0;i<=dim;i++){ for (int j=0;j<=dim;j++){imp<<malla[j][i]<<"\t";}imp<<endl;} }
for (int i=0;i<=dim;i++){for (int j=0;j<=dim;j++){/*cout<<malla[j][i]<<" "*/;}/*cout<<endl*/;}

//////RANDOMLY LOOSE PARTICLES ON THE METAL
for (int i=0;i<part;i++){int j=0; //j=number of movements
lanzamiento:
x[j]=rand()%(dim+1); y[j]=rand()%(dim+1);

//IN CASE WE LAUNCH IT IN A RUSTY ONE
comp:
if (i==2){camino<<x[j]<<"\t"<<y[j]<<endl;}
if (j>itmax){pdesin++;}
else{
 if (malla[x[j]][y[j]]==1){h[x[j]][y[j]]++;}

 //IN CASE ONE OF THE NEIGHBORS IS RUSTY
 else if (malla[x[j]][y[j]]==0 && ((x[j]!=dim && malla[x[j]+1][y[j]]==1) || (x[j]!=0 && malla[x[j]-1][y[j]]==1) || (y[j]!=dim && malla[x[j]][y[j]+1]==1) || (y[j]!=0 && malla[x[j]][y[j]-1]==1))){
    int lot=(rand()%1001)/1000;
    if (lot<=pm[b]){malla[x[j]][y[j]]=1; h[x[j]][y[j]]=1;j=0;nox++;fout<<i<<"\t"<<nox<<"\t"<<(dim+1)*(dim+1)<<endl;
    for (int w=0;w<=dim;w++){ for (int J=0;J<=dim;J++){imp<<malla[J][w]<<"\t";}imp<<endl;} }
     else {goto paso;}}
 else {
      paso:
      int mov=rand()%4;
      if (mov==0){if (x[j]!=dim){x[j+1]=x[j]+1;y[j+1]=y[j];}
         else {goto comp;}}
      else if(mov==1){if (x[j]!=0){x[j+1]=x[j]-1;y[j+1]=y[j];}
         else {goto comp;}}  
      else if (mov==2){if (y[j]!=dim){x[j+1]=x[j];y[j+1]=y[j]+1;}
         else {goto comp;}}   
      else {if (x[j]!=0){x[j+1]=x[j];y[j+1]=y[j]-1;}
         else {goto comp;}}      
      npasos++; j++;goto comp;}}}
  
for (int i=0;i<=dim;i++){ for (int j=0;j<=dim;j++){imp<<malla[j][i]<<"\t";}imp<<endl;} 
datos<<dim+1<<"\t"<<nox<<endl;

system("pause");return 0;}
