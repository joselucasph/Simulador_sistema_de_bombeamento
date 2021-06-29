/*
aluno: José Lucas da Silva Holanda
matricula: 20189019400

PROGRAMA PARA SIMULAR O FUNCIONAMENTO DE UM SISTEMA DE BOMBEAMENTO DE ÁGUA.

volume maximo da caixa  é 10000.
volume minimo da caixa é 2000.
vazão do poço é 4000 litros por hora.
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 12   //Maximo para tensão na boia e no poço.
#define MIN 0    //Minimo para tensão na boia e no poço.

//Declaração
int nivel_do_poco = 12, boia = 0, C1 = 5, T1 = 350, C2 = 5, T2 = 350, C3 = 5, T3 = 350, i = 0,k = 0,l = 0, x = 0 , y = 0, n = 0, reservatoriocheio = -1, reservatoriovazio = 0, tempo = -2, litros = 0;
FILE *file;
char e;
char agua_do_poco [3][30] = {" ", "nivel do poco esta baixo"};
char corrente [7][30] = {" ", "corrente na fase A alta", "corrente na fase B alta", "corrente na fase C alta","corrente na fase A baixa", "corrente na fase B baixa", "corrente na fase c baixa"};
char tensao [7][30] = {" ", "tensao na fase A alta", "tensao na fase B alta", "tensao na fase C alta","tensao na fase A baixa", "tensao na fase B baixa", "tensao na fase c baixa"};
char bomba [2][15] = {"desligada", "ligada"};
char caixa [2][10] = {"vazia","cheia"};

void salvar_arquivo(){
	//FILE *file; 
	file = fopen("estatistica.txt", "w");
	//fprintf(file,"\t\tParametros iniciais\n\n");
    //fprintf(file,"fase A\t fase B\t fase C\t boia\t poco\n350 V\t 350 V\t 350 V\t 0 V\t 12 V\n5 A\t 5 A\t 5 A\n bomba desligada\ncaixa cheia\n\n");
	fprintf(file,"fase A\t fase B\t fase C\t boia\t poco\n%d V\t %d V\t %d V\t %d V\t %d V\n%d A\t %d A\t %d A\n bomba %s\t %s\t %s\n reservatorio %s \n %s \n", T1, T2, T3, boia, nivel_do_poco, C1, C2, C3, bomba[k], tensao[x], corrente[y], caixa[l], agua_do_poco[n]);
	fprintf(file,"a caixa encheu %d vezes. \nA caixa secou %d vezes\nA bomba ficou ligada %d horas\nForam consumidos %d litros de agua\n", reservatoriocheio, reservatoriovazio, tempo, litros);
	fclose(file);
}

 void entrada(){  //Essa função apenas recebe o que o usuario digita.
 	e = getch();
 		 
 }

 void processar(){ //Essa função faz todo o preossesamento conforme especificado para o programa.
   /*PARA REALIZAR ALTERAÇÕES NO PROGRAMA SEGUEM AS LETRAS REFERENTES A CADA COMANDO
               fase A         fase B          fase C         boia            poco
	Tensao:   (q-)(Q+)       (w-)(W+)        (e-)(E+)       (r-)(R+)        (p-)(P+)
	Corrente: (a-)(A+)       (s-)(S+)        (d-)(D+)
    Para encerrar o programa e gerar o arquivo de estatisticas:
    (f)
  */
 
 	if(e == 'f'){
		 salvar_arquivo();
		exit(0);
	 }
 	    if(e == 'q'){
		  T1-=25;
	 }
	 if(e == 'w'){
		 T2-=25;
	 }
        if(e == 'e'){
		  T3-=25;
	 }
	 	if(e == 'a'){
		  C1-=1;
	 }
	 	if(e == 's'){
		  C2-=1;
	 }
	 	if(e == 'd'){	
		 C3-=1;
	 }
	 	    if(e == 'Q'){
		  T1+=25;
	 }
	 if(e == 'W'){
		 T2+=25;
	 }
        if(e == 'E'){
		  T3+=25;
	 }
	 	if(e == 'A'){
		  C1+=1;
	 }
	 	if(e == 'S'){
		  C2+=1;
	 }
	 	if(e == 'D'){	
		 C3+=1;
	 }
   	    if(e == 'P'){
		 nivel_do_poco+=12;   //Os sensores digitais trabalham com niveis lógicos, que só variam entra ativado e desativado
	 }   					  //por isso quando o usuario quiser alterar a voltagem nos sensores ele tera de selecionar entre
	    if(e == 'p'){		  //ligado ou desligado(0 ou 12).
		  nivel_do_poco-=12;
	 }
	    if(e == 'R'){
           boia -=12;
     }
		if(e == 'r'){
			boia +=12;
     }
        if(T1 > 410 || T1 < 350){
		  k=0;
     }
	    if(T2 > 410 || T2 < 350){
           k=0;
     }
        if(T3 > 410 || T3 < 350){
         k=0;
     }
	    if(C1 > 7 || C1 < 5){
		   k=0;
		}
		if(C2 > 7 || C2 < 5){
		  k=0;
		}
		if(C3 > 7 || C3 < 5){
		   k=0;	
		}
		if(nivel_do_poco == 0){
		   k=0;
		   n = 1;
		}
		if(boia == 0){
           k=0;
           l=1;
            //reservatoriocheio++;
           //tempo+=2;
           
		}
		
		if( nivel_do_poco != 0){
			n = 0;
		}
		 if(T1 < 410 && T1 >= 350){
		
           if(T2 < 410 && T2 >= 350){
		
		      if(T3 < 410 && T3 >= 350){
			      x = 0;
				  y = 0;
        		 if( nivel_do_poco == 12){
        		 	if(boia == 12){ 
        		 	  	
			          k = 1;
                      l = 0;
                      
					 }
		         }
			  }
		   }
		 }
		if(boia == MAX || boia > MAX){
			 boia = 12;
		 }
		 if(boia == MIN || boia < MIN){
			 boia = 0;
		 }	 
		 if(boia == 12){
			  reservatoriovazio++;
         }
         if(boia == 0 && nivel_do_poco ==12){
			  reservatoriocheio++;
           tempo+=2;
		 }
		 if(T1 > 410){
			 x = 1;
		 }
		  if(T2 > 410){
			 x = 2;
		 }
		  if(T3 > 410){
			 x = 3;
		 }
		  if(T1 < 350){
			 x = 4;
		 }
		  if(T2 < 350){
			 x = 5;
		 }
		  if(T3 < 350){
			x = 6; 
		 }
		  if(C1 > 7){
			  y = 1;
          }
		  if(C2 > 7){
			  y = 2;
		  }
		  if(C3 > 7){
			  y = 3;
		  }
		  if(C1 < 5){
			  y = 4;
		  }
		  if(C2 < 5){
			  y = 5;
		  }
		  if(C3 < 5){
			  y = 6;
		  }
		  
		  litros = tempo * 4000;
		   salvar_arquivo();
 }
 
 void saida(){
 		system("cls");
     printf("\t    fase A\t   fase B\t   fase C\t  boia\t          poco\nTensao:   (q-)(Q+)\t (w-)(W+)\t (e-)(E+)\t(r-)(R+)\t(p-)(P+) \nCorrente: (a-)(A+)\t (s-)(S+)\t (d-)(D+)\n\n Para encerrar o programa e gerar o arquivo de estatisticas:\n  (f)\n\n\n");
	 printf("fase A\t fase B\t fase C\t boia\t poco\n%d V\t %d V\t %d V\t %d V\t %d V\n%d A\t %d A\t %d A\n bomba %s\t %s\t %s\n reservatorio %s \n %s \n", T1, T2, T3, boia, nivel_do_poco, C1, C2, C3, bomba[k], tensao[x], corrente[y], caixa[l], agua_do_poco[n]);
     printf("a caixa encheu %d vezes. \nA caixa secou %d vezes\nA bomba ficou ligada %d horas\nForam consumidos %d litro de agua\n", reservatoriocheio, reservatoriovazio, tempo, litros);
 }

 
int main(){

	while(1){
 
     processar();
     saida();
	 entrada();
	 
	}

	return 0;
}