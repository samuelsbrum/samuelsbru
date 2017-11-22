/*
Unilasalle (turno da noite, engenharia)
Samantha Vieira (Matrícula: 0050014668)
Samuel Brum (Matrícula: 0050015045) 
Professor: Alex Salgado
Programação 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int cont=0;
	do
	{
		srand(time(NULL)); //para realizar sorteio
	
		char palavras[][16] = { 
			"matematica", 
			"programacao", 
			"engenharia", 
			"computador", 
			"trabalho",
			"fisica"
			}; //palavras para serem sorteadas 
		
			int random = rand() % 6; // para realizar sorteio 
			int loop = 0; 
			int vida = 5;
			int correto = 0;
			int antes = 0; 
			int tam = strlen(palavras[random]); //tamanho da palavra sorteada
			int letra[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			int para = 0;
			char adivinha[16];
			char letraColocada;
			int errada; 

		
		
			/*printf("palavras: %s random: %d tam: %d\n", palavras[random], random, tam);*/
		
			while(correto < tam)
			{
				printf("\nFaca sua nova jogada. \nPalavra:");
					for(loop =0; loop < tam; loop++)
				{
					if(letra[loop] == 1)
					{
						printf("%c", palavras[random][loop]);
					}
					else
					{
						printf("-");
					
					}
	
				}
			
				printf("\n");
			
				printf("Letras corretas ate agora: %d\n ", correto);
				printf("\nEntre com uma letra: \n");
				fgets(adivinha, 16, stdin); //recebe a letra 
			
				if(strncmp(adivinha, "para", 4) == 0)
				{
					para = 1; 
					break; 
				}
				letraColocada = adivinha[0];
				printf("\nLetra adivinhada: %c\n", letraColocada);
			
				antes = correto;
			
				for(loop =0; loop < tam; loop++)
				{
					if(letra[loop] == 1)
					{
						continue;
					}

					if(letraColocada == palavras[random][loop])
					{
						letra[loop] = 1; //se a letra estiver correta, substituir o 0 no vetor letra por 1 para indicar que a letra já foi adivinhada
						correto++; 
					}
	
				}
				if (antes == correto)
				{
					vida--; //Se colocar a letra errada, diminuir a vida 
					printf("\nVoce errou!\n");
					if(vida ==0) 
					{
						printf ("_________       \n"
                    	           "|       |       \n"
								   "|      (o)      \n"
								   "|      /|\\      \n"
						       	"|       |       \n"
							   	"|      / \\      \n"
							   	"|     ______    \n"
							   	"|     |    |    \n"
									"      |    | \n");
						break;
					}
				
					if(vida==4)
					{
					printf ("       \n"
                    	           "             \n"
								   "            \n"
								   "            \n"
						       	"             \n"
							   	"      / \\      \n"
							   	"         \n");
					}
		
					if (vida==3)
					{
					printf ("       \n"
                	               "              \n"
								   "            \n"
								   "      / \\      \n"
						    	   "              \n"
								   "      / \\      \n"
							   	"         \n"
							  	 "             \n"
									"           \n");
					}
					if (vida==2)
					{
						printf ("       \n"
            	                   "              \n"
								   "            \n"
								   "      /|\\      \n"
							       "       |       \n"
									"      / \\      \n"
								   "         \n"
								   "    \n");
					}
					if (vida==1)
					{
						printf ("       \n"
                        	       "              \n"
								   "      (o)      \n"
								   "      /|\\      \n"
							       "       |       \n"
								   "      / \\      \n"
								   "         \n"
								   "     \n");
					}
				}
				else
				{
					printf("\nParabens, voce acertou!\n"); 
				}
			}
		
			if(para == 1)
			{
				printf("\nO usuario encerrou o jogo.\n"); //O usuário encerra o jogo antes da partida terminar
			}
			else if(vida == 0)
			{
				printf("\nVoce perdeu, game over! A palavra era: %s\n", palavras[random]);
				cont --; 
			}
			else
			{
				printf("\nVoce venceu, parabens!!! :D\n");
			}
	}
			
		while(cont==0);
		
		
		system("pause");
		return 0;
		
}
