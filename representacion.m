clear all 
format long
%malla=xlsread('resultados.xlsx',-1);
load malla.txt;
load datos.txt;
load camino.txt;
x=camino(:,1);
y=camino(:,2);
dim=datos(1,1);
nox=datos(1,2);
%%dim=length(malla(:,1));
for i=0:nox
   for j=1:dim
       malla1(j,:)=malla(j+i*dim,:);
   end
   figure (1)
 %%hold on
 imagesc(ones(dim)-malla1')
 colormap(gray)
 pause(0.01)
         
end