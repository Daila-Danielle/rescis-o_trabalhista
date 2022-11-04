/* compilar nesse site https://www.onlinegdb.com/ */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct 
{
	int dia;
	int mes;
	int ano;
} Data;

int bissexto (int ano);
unsigned long dist_dias (Data inicio, Data fim);

 /* guarda o numero de dias em cada mes para anos normais e bissextos */
int dias_mes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(void) 
{
    
Data dia1, dia2;
float salariobruto,total,fer,feriasvenc,decimovenc,saldo_fgts,saldodesalario,fgts,feriasproporcional,decimoproporcional,totalaviso;
char nome[10];
int a,m,d,escolha,ferias,decimoterceiro,aviso,diade_aviso,opcao_fgts,fg,escolhatot;
float renda,calculo_INSS,totalinss,tot_inss;
float mfgts=0.4;
float p1=0.075;
float p2=0.09;
float p3=0.12;
float p4=0.14;
float fgt=0.08;

    volt_inicio:
    printf("\n\t---PROGRAMA DE CALCULO DE RECISAO TRABALHISTA---\n\n\n");
    
    data:
	printf("INFORME OS DADOS ABAIXO\n\nDATA DE CONTRATACAO (nesse formato -> dia/mes/ano):\t");
	scanf("%d/%d/%d", &dia1.dia, &dia1.mes, &dia1.ano);
	
	printf("\nDATA DA DEMISSAO (nesse formato -> dia/mes/ano):\t");
	scanf("%d/%d/%d", &dia2.dia, &dia2.mes, &dia2.ano);
	
	system ("clear");
	
	if(dia2.ano<dia1.ano)
    {
        printf("\n<<<<<A DATA DE DEMISSAO DEVE SER MAIOR QUE A DATA DE ADMISSAO>>>>\n");
        goto data;
    }
    
   /* if((dia2.mes<dia1.mes)&&(dia1.ano==dia2.ano))
    {
        printf("\n<<<<<A DATA DE DEMISSAO DEVE SER MAIOR QUE A DATA DE ADMISSAO>>>>\n");
        goto data;
    }*/
	
    salario:	
	printf("\nSALARIO BRUTO:\t");
    scanf("%f",&salariobruto);
    
    system ("clear");
    
    if(salariobruto<=0)
    {
        printf("\n<<<<<DIGITE UM VALOR VALIDO>>>>\n");
        goto salario;
    }

renda=salariobruto;

    if ( renda <= 1212.50)
{
    calculo_INSS = renda * p1;
}
   
if ( renda >= 1212.01 && renda <= 2427.35)
{
    calculo_INSS = renda * p2;
}
if( renda >= 2427.36 && renda <= 3641.03)
{
    calculo_INSS = renda * p3;
}
if( renda >= 3641.04)
{
    calculo_INSS = renda * p4;
}
    
    printf("\nFERIAS VENCIDAS?\n\n1. SIM\n2. NAO\n\n(digite o numero):\t");
    scanf("%i",&ferias);
    
    system ("clear");
    
    printf("\ntem 13° vencido?\n1. SIM\n2. NAO\n\n(digite o numero):\t");
    scanf("%i",&decimoterceiro);
    
    system ("clear");
    
    printf("\nMOTIVO DA DEMISSAO?\n\n1. SEM JUSTA CAUSA\n2. COM JUSTA CAUSA\n3. PEDIDO DE DEMISSAO\n4. DEMISSAO POR ACORDO\n5. FIM DE CONTRADO NO PRAZO DETERMINADO\n\n(digite o numero):\t");
    scanf("%i",&escolha);
    
    system ("clear");
    
        a=dist_dias (dia1, dia2)/365; 
        m=(dist_dias (dia1, dia2) % 365)/ 30;
        d=(dist_dias (dia1, dia2) % 365)% 30;
        
        tot_inss=(calculo_INSS/30)*d;
    
    switch(escolha)
    {
        case 1:
        opcao_aviso:
        printf("\nTIPO DE AVISO:\n\n1. INDENIZADO PELO EMPREGADOR(empresa)\n2. TRABALHADO\n3. NAO CUMPRIDO\n\n(digite o numero):\t");
        scanf("%i",&aviso);
        system ("clear");
        
	    printf("\nDESEJA CALCULAR JUNTO COM FGTS?\n\n1. SIM\n2. NAO\n\n(digite o numero):\t");
        scanf("%i",&opcao_fgts);
        system ("clear");

        saldodesalario=(salariobruto/30) * d - tot_inss;
        fer=(salariobruto/12);
        feriasproporcional=(fer/3)+(fer*m);
        
        decimoproporcional= (salariobruto/12)*m- calculo_INSS;
        
        switch(aviso)
        {
            case 1:
            
                if(a>=1&&a<=20)
                {
                    diade_aviso=(a*3) + 30;
                }
                if(a==0)
                {
                     diade_aviso=0;
                }
                if(a>=21)
                {
                     diade_aviso=90;
                }
             totalinss=(calculo_INSS/30)*diade_aviso;   
             totalaviso=(salariobruto/30)*diade_aviso-totalinss;
             
            break;
            
            case 2:
            
                if(a>=1&&a<=20)
                {
                    diade_aviso=(a*3) + 30;
                }
                if(a==0)
                {
                     diade_aviso=0;
                }
                if(a>=21)
                {
                     diade_aviso=90;
                }
                
             totalinss=(calculo_INSS/30)*diade_aviso;   
             totalaviso=(salariobruto/30)*diade_aviso-totalinss;
             
            break;
            
            case 3:
                
                diade_aviso=0;
                totalaviso=(salariobruto/30)*diade_aviso;
             
            break;
            
            default:
            
            printf("\n\t<<<<DIGITE UMA OPCAO VALIDA>>>>\n");
            goto opcao_aviso;
            
        }
        
         if(opcao_fgts==1)
        {
            fg=(a*12);
            fgts=(salariobruto*fgt)*(m+fg);
            saldo_fgts=fgts+(fgts*mfgts);
        }
        if(opcao_fgts==2)
        {
          
            saldo_fgts=0;
        }
       
        if(ferias==1)
        {
            feriasvenc=salariobruto+(salariobruto/3);
        }
        else{
            feriasvenc=0;
        }
        
        if(decimoterceiro==1)
        {
            decimovenc=salariobruto - calculo_INSS;
        }
        else{
            decimovenc=0;
        }
        
        total=saldodesalario+feriasproporcional+feriasvenc+decimovenc+decimoproporcional+totalaviso+saldo_fgts;
        inicio_fim:
        printf("\n\nESCOLHA:\n\n1. VIZUALIZAR TOTAL A RECEBER\n2. VISUALIZAR DETALHADO\n3. VOLTAR AO INICIO\n4. SAIR\n\n(digite o numero):\t");
        scanf("%i",&escolhatot);
        system ("clear");
        
        switch(escolhatot)
        {
            case 1:
            
            printf("\nVALOR TOTAL A RECEBER:\t%.2f",total);
            goto inicio_fim;
            
            break;
            
            case 2:
            
            printf("\nVALOR TOTAL A RECEBER:\t%.2f",total);
            printf("\n\nsaldo de salario:\t%.2f",saldodesalario);
            printf("\nferias proporcional:\t%.2f",feriasproporcional);
            printf("\ndecimo terceiro proporcional:\t%.2f",decimoproporcional);
            printf("\nferias vencidas:\t%.2f",feriasvenc);
            printf("\ndecimo terceiro vencido:\t%.2f",decimovenc);
            printf("\nfgts:\t%.2f",saldo_fgts);
            printf("\ndias de aviso:\t%i",diade_aviso);
            printf("\nvalor do aviso:\t%.2f",totalaviso);
            printf("\n\n<<VOCE TRABALHOU %i ANO(S), %i MESES E %i DIAS>>",a,m,d);
            goto inicio_fim;
            
            break;
            
            case 3:
            
            goto volt_inicio;
            
            break;
            
            case 4:
            
            break;
            
            default:
            
            printf("\n<<<DIGITE UM NUMERO VALIDO>>>\n");
            goto inicio_fim;
        }
        
        break;
        
    case 2:
    
        saldodesalario=(salariobruto/30) * d - tot_inss;
        
        if(ferias==1)
        {
            feriasvenc=salariobruto+(salariobruto/3);
        }
        else{
            feriasvenc=0;
        }
        
        if(decimoterceiro==1)
        {
            decimovenc=salariobruto - calculo_INSS;
        }
        else{
            
            decimovenc=0;
        }
        
        total=saldodesalario+feriasvenc+decimovenc;
        
        inicio_fima:
        printf("\n\nESCOLHA:\n\n1. VIZUALIZAR TOTAL A RECEBER\n2. VISUALIZAR DETALHADO\n3. VOLTAR AO INICIO\n4. SAIR\n\n(digite o numero):\t");
        scanf("%i",&escolhatot);
        system ("clear");
        
        switch(escolhatot)
        {
            case 1:
            
            printf("\nVALOR TOTAL A RECEBER:\t%.2f",total);
            goto inicio_fima;
            
            break;
            
            case 2:
            
            printf("\nVALOR TOTAL A RECEBER:\t%.2f",total);
            printf("\n\nsaldo de salario:\t%.2f",saldodesalario);
            printf("\nferias vencidas:\t%.2f",feriasvenc);
            printf("\ndecimo terceiro vencido:\t%2.f",decimovenc);
            printf("\n\n<<VOCE TRABALHOU %i ANO(S), %i MES E %i DIA(S)>>",a,m,d);
            goto inicio_fima;
            
            break;
            
            case 3:
            
            goto volt_inicio;
            
            break;
            
            case 4:
            
            break;
            
            default:
            
            printf("\n<<<DIGITE UM NUMERO VALIDO>>>\n");
            goto inicio_fima;
        }
        
        break;
        
    case 3:
        
        opcao_aviso3:
        printf("\nTIPO DE AVISO:\n\n1. INDENIZADO PELO EMPREGADOR(empresa)\n2. TRABALHADO\n3. NAO CUMPRIDO\n\n(digite o numero):\t");
        scanf("%i",&aviso);
        system ("clear");
	    
        saldodesalario=(salariobruto/30) * d - tot_inss;
        fer=(salariobruto/12);
        feriasproporcional=(fer/3)+(fer*m);
        
        decimoproporcional= (salariobruto/12)*m- calculo_INSS;
        
        switch(aviso)
        {
            case 1:
            
                if(a>=1&&a<=20)
                {
                    diade_aviso=(a*3) + 30;
                }
                if(a==0)
                {
                     diade_aviso=0;
                }
                if(a>=21)
                {
                     diade_aviso=90;
                }
             totalinss=(calculo_INSS/30)*diade_aviso;   
             totalaviso=(salariobruto/30)*diade_aviso-totalinss;
             
            break;
            
            case 2:
            
                if(a>=1&&a<=20)
                {
                    diade_aviso=(a*3) + 30;
                }
                if(a==0)
                {
                     diade_aviso=0;
                }
                if(a>=21)
                {
                     diade_aviso=90;
                }
                
             totalinss=(calculo_INSS/30)*diade_aviso;   
             totalaviso=(salariobruto/30)*diade_aviso-totalinss;
             
            break;
            
            case 3:
                
                diade_aviso=0;
                totalaviso=(salariobruto/30)*diade_aviso;
             
            
            break;
            
            default:
            
            printf("\n\t<<<<DIGITE UMA OPCAO VALIDA>>>>\n");
            goto opcao_aviso3;
            
        }
        
          if(opcao_fgts==1)
        {
            fg=(a*12);
            fgts=(salariobruto*fgt)*(m+fg);
            saldo_fgts=fgts+(fgts*mfgts);
        }
        if(opcao_fgts==2)
        {
          
            saldo_fgts=0;
        }
        
        if(ferias==1)
        {
            feriasvenc=salariobruto+(salariobruto/3);
        }
        else{
            feriasvenc=0;
        }
        
        if(decimoterceiro==1)
        {
            decimovenc=salariobruto - calculo_INSS;
        }
        else{
            decimovenc=0;
        }
        
        total=saldodesalario+feriasproporcional+feriasvenc+decimovenc+decimoproporcional+totalaviso+saldo_fgts;
        inicio_fimb:
        printf("\n\nESCOLHA:\n\n1. VIZUALIZAR TOTAL A RECEBER\n2. VISUALIZAR DETALHADO\n3. VOLTAR AO INICIO\n4. SAIR\n\n(digite o numero):\t");
        scanf("%i",&escolhatot);
        system ("clear");
        
        switch(escolhatot)
        {
            case 1:
            
            printf("\nVALOR TOTAL A RECEBER:\t%.2f",total);
            goto inicio_fimb;
            
            break;
            
            case 2:
            
            printf("\nVALOR TOTAL A RECEBER:\t%.2f",total);
            printf("\n\nsaldo de salario:\t%.2f",saldodesalario);
            printf("\nferias proporcional:\t%.2f",feriasproporcional);
            printf("\ndecimo terceiro proporcional:\t%.2f",decimoproporcional);
            printf("\nferias vencidas:\t%.2f",feriasvenc);
            printf("\ndecimo terceiro vencido:\t%.2f",decimovenc);
            printf("\nfgts:\t%.2f",saldo_fgts);
            printf("\ndias de aviso:\t%i",diade_aviso);
            printf("\nvalor do aviso:\t%.2f",totalaviso);
            printf("\n\n<<VOCE TRABALHOU %i ANO(S), %i MES E %i DIA(S)>>",a,m,d);
            goto inicio_fimb;
            
            break;
            
            case 3:
            
            goto volt_inicio;
            
            break;
            
            case 4:
            
            break;
            
            default:
            
            printf("\n<<<DIGITE UM NUMERO VALIDO>>>\n");
            goto inicio_fimb;
        }
        
        break;
        
    case 4:
    
        opcao_aviso4:
        printf("\nTIPO DE AVISO:\n\n1. INDENIZADO PELO EMPREGADOR(empresa)\n2. TRABALHADO\n3. NAO CUMPRIDO\n\n(digite o numero):\t");
        scanf("%i",&aviso);
        system ("clear");
        
	    printf("\nDESEJA CALCULAR JUNTO COM FGTS?\n\n1. SIM\n2. NAO\n\n(digite o numero):\t");
        scanf("%i",&opcao_fgts);
        system ("clear");

        saldodesalario=(salariobruto/30) * d - tot_inss;
        fer=(salariobruto/12);
        feriasproporcional=(fer/3)+(fer*m);
        
        decimoproporcional= (salariobruto/12)*m - calculo_INSS;
        
        switch(aviso)
        {
            case 1:
            
                if(a>=1&&a<=20)
                {
                    diade_aviso=(a*3) + 30;
                }
                if(a==0)
                {
                     diade_aviso=0;
                }
                if(a>=21)
                {
                     diade_aviso=90;
                }
             totalinss=(calculo_INSS/30)*diade_aviso;   
             totalaviso=(salariobruto/30)*diade_aviso-totalinss;
             
            break;
            
            case 2:
            
                if(a>=1&&a<=20)
                {
                    diade_aviso=(a*3) + 30;
                }
                if(a==0)
                {
                     diade_aviso=0;
                }
                if(a>=21)
                {
                     diade_aviso=90;
                }
             totalinss=(calculo_INSS/30)*diade_aviso;   
             totalaviso=(salariobruto/30)*diade_aviso-totalinss;
             
            break;
            
            case 3:
                
                diade_aviso=0;
                totalaviso=(salariobruto/30)*diade_aviso;
            
            break;
            
            default:
            
            printf("\n\t<<<<DIGITE UMA OPCAO VALIDA>>>>\n");
            goto opcao_aviso4;
            
        }
        
        if(opcao_fgts==1)
        {
            fg=(a*12);
            fgts=(salariobruto*fgt)*(m+fg);
            saldo_fgts=(fgts+(fgts*mfgts)/2);
        }
        if(opcao_fgts==2)
        {
          
            saldo_fgts=0;
        }
        
        if(ferias==1)
        {
            feriasvenc=salariobruto+(salariobruto/3);
        }
        else
        {
            feriasvenc=0;
        }
        
        if(decimoterceiro==1)
        {
            decimovenc=salariobruto - calculo_INSS;
        }
        else
        {
            decimovenc=0;
        }
        
        total=saldodesalario+feriasproporcional+feriasvenc+decimovenc+decimoproporcional+totalaviso+saldo_fgts;
        inicio_fimc:
        printf("\n\nESCOLHA:\n\n1. VIZUALIZAR TOTAL A RECEBER\n2. VISUALIZAR DETALHADO\n3. VOLTAR AO INICIO\n4. SAIR\n\n(digite o numero):\t");
        scanf("%i",&escolhatot);
        system ("clear");
        
        switch(escolhatot)
        {
            case 1:
            
            printf("\nVALOR TOTAL A RECEBER:\t%.2f",total);
            goto inicio_fimc;
            
            break;
            
            case 2:
            
            printf("\nVALOR TOTAL A RECEBER:\t%.2f",total);
            printf("\n\nsaldo de salario:\t%.2f",saldodesalario);
            printf("\nferias proporcional:\t%.2f",feriasproporcional);
            printf("\ndecimo terceiro proporcional:\t%.2f",decimoproporcional);
            printf("\nferias vencidas:\t%.2f",feriasvenc);
            printf("\ndecimo terceiro vencido:\t%.2f",decimovenc);
            printf("\nfgts:\t%.2f",saldo_fgts);
            printf("\ndias de aviso:\t%i",diade_aviso);
            printf("\nvalor do aviso:\t%.2f",totalaviso);
            printf("\n\n<<VOCE TRABALHOU %i ANO(S), %i MES E %i DIA(S)>>",a,m,d);
            
            break;
            
            case 3:
            
            goto volt_inicio;
            
            break;
            
            case 4:
            
            break;
            
            default:
            
            printf("\n<<<DIGITE UM NUMERO VALIDO>>>\n");
            goto inicio_fimc;
        }

        break;
        
    case 5:
        
	    printf("\nDESEJA CALCULAR JUNTO COM FGTS?\n\n1. SIM\n2. NAO\n\n(digite o numero):\t");
        scanf("%i",&opcao_fgts);
        system ("clear");

        saldodesalario=(salariobruto/30) * d - tot_inss;
        fer=(salariobruto/12);
        feriasproporcional=(fer/3)+(fer*m);
        
        decimoproporcional= (salariobruto/12)*m- calculo_INSS;
    
         if(opcao_fgts==1)
        {
            fg=(a*12);
            fgts=(salariobruto*fgt)*(m+fg);
            saldo_fgts=fgts;
        }
        if(opcao_fgts==2)
        {
          
            saldo_fgts=0;
        }
       
        if(ferias==1)
        {
            feriasvenc=salariobruto+(salariobruto/3);
        }
        else{
            feriasvenc=0;
        }
        
        if(decimoterceiro==1)
        {
            decimovenc=salariobruto - calculo_INSS;
        }
        else{
            decimovenc=0;
        }
        
        total=saldodesalario+feriasproporcional+feriasvenc+decimovenc+decimoproporcional+saldo_fgts;
        inicio_fimd:
        printf("\n\nESCOLHA:\n\n1. VIZUALIZAR TOTAL A RECEBER\n2. VISUALIZAR DETALHADO\n3. VOLTAR AO INICIO\n4. SAIR\n\n(digite o numero):\t");
        scanf("%i",&escolhatot);
        system ("clear");
        
        switch(escolhatot)
        {
            case 1:
            
            printf("\nVALOR TOTAL A RECEBER:\t%.2f",total);
            goto inicio_fimd;
            
            break;
            
            case 2:
            
            printf("\nVALOR TOTAL A RECEBER:\t%.2f",total);
            printf("\n\nsaldo de salario:\t%.2f",saldodesalario);
            printf("\nferias proporcional:\t%.2f",feriasproporcional);
            printf("\ndecimo terceiro proporcional:\t%.2f",decimoproporcional);
            printf("\nferias vencidas:\t%.2f",feriasvenc);
            printf("\ndecimo terceiro vencido:\t%.2f",decimovenc);
            printf("\nfgts:\t%.2f",saldo_fgts);
            printf("\n\n<<VOCE TRABALHOU %i ANO(S), %i MES E %i DIA(S)>>",a,m,d);
            goto inicio_fimd;
            
            break;
            
            case 3:
            
            goto volt_inicio;
            
            break;
            
            case 4:
            
            break;
            
            default:
            
            printf("\n<<<DIGITE UM NUMERO VALIDO>>>\n");
            goto inicio_fimd;
        }
        
        break;

    }//fechamento do switch(escolha).

	return 0;
}//fechamento int main.

//Retorna 1 caso 'ano' seja bissexto, 0 caso contrário
int bissexto (int ano) {
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}
//Retorna a distancia entre inicio e fim em dias.
//Assume que inicio nao vem depois de fim.
unsigned long dist_dias (Data inicio, Data fim) {
	unsigned long idias, fdias;	// guarda qtos dias tem da data 
					// ate o comeco do ano.
	unsigned long def_anos=0;	//guarda diferenca entre anos das 
					//datas inicio e fim medida em dias.
	register int i;
	int dbissexto;

	idias = inicio.dia;
	dbissexto = bissexto (inicio.ano);
	for (i = inicio.mes - 1; i > 0; --i)
		idias += dias_mes[dbissexto][i];

	fdias = fim.dia;
	dbissexto = bissexto (fim.ano);
	for (i = fim.mes - 1; i > 0; --i)
		fdias += dias_mes[dbissexto][i];

	while (inicio.ano < fim.ano)
		def_anos += 365 + bissexto(inicio.ano++);

	return def_anos - idias + fdias;
}
