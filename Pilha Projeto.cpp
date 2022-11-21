#include <iostream>
#include <cstdlib>
#include <new>

class functions{
	public:
		
		int *alocar_malloc(int tam)
		{
			int *vetor;
			return vetor = (int*)malloc(tam * sizeof(int));
		}
		
		int *alocar_calloc(int tam)
		{
			int *vetor;
			return vetor = (int*)calloc(tam, sizeof(int));
		}
		
		int *alocar_new(int tam)
		{
			int *vetor;
			return vetor = new int(tam);
		}
		
		void popular(int *vetor, int tam)
		{
			for(int i = 0; i < tam; ++i)
			{
				vetor[i] = 0;
			}
		}
		
		void push(int *vetor, int *topo, int tamanho)
		{
			if (*topo == tamanho -1)
			{
				std::cout << "Pilha cheia!\n\n";
				return;
			}
			int num;
			std::cout << "Digite o numero para adicionar:";
			std::cin >> num;
			*topo += 1;
			vetor[*topo] = num;
			std::cout << "Valor adicionado!\n\n";
			return;
		}
		
		void pop(int *vetor , int *topo)
		{
			if (*topo < 0)
			{
				std::cout << "Pilha vazia!\n\n";
				return;	
			}
			
			vetor[*topo] = 0;
			*topo -= 1;
			
			std::cout << "Valor removido!\n\n";		
			return;
		}	
		
		void mostrar(int *vetor, int tam)
		{
			for (int i = 0 ; i < tam; ++i)
			{
				std::cout << vetor[i] << " "; 
			}
			
			std::cout << "\n\nValores da pilha\n\n";
		}
		
		void quantidade(int *topo)
		{
			std::cout << "Existem atualmente:" << *topo + 1 << " Valores na pilha.\n\n";
			
		}
		
		int verficar_tamanho(int tamanho)
		{
			if (tamanho <= 0)
			{
				return 1;
			}else{
				return 0;
			}
		}
};

int main()
{
	
	setlocale(LC_ALL, "pt_BR.utf8");
	functions pilha;
	
	int *vetor = 0;
	
	int topo = -1;
	int tamanho = 0;
	
	int tipo_aloc_backup = 0;
	
	
	for(;;)
	{
		int tipo_aloc = 0;
		int verifica = 1;
		int escolha = 0;
		system("cls");
		std::cout << "=========================================\n";
		std::cout << "01 - Criar pilha dinamicamente\n";
		std::cout << "02 - Adicionar valor com push\n";
		std::cout << "03 - Remover valor com pop\n";
		std::cout << "04 - Mostrar quantidade tamanho da pilha\n";
		std::cout << "05 - Mostrar pilha\n";
		std::cout << "06 - Resetar pilha\n";
		std::cout << "07 - Sair do programa\n";
		
		std::cout << "=========================================\n";
		
		std::cout << "\nDigite a opcao desejada:";
		
		std::cin >> escolha;
		
		if (std::cin.fail())
		{
			system("cls");
			std::cin.clear(); 
			std::cin.ignore(512, '\n');
			std::cout << "Opcao invalida digitada, apenas numeros inteiros\n";
			std::cout << "PS: Caso numeros gigantes sejam digitados, essa tela aparecera";
			system("pause");
		}
	
		else{
		
		switch(escolha)
		{
			case 1:
				
				while(tipo_aloc < 1 || tipo_aloc > 3)
				{
				
				system("cls");
				while (verifica == 1)
				{
					system("cls");
					std::cout << "Digite o tamanho do vetor:";
					std::cin >> tamanho;
					verifica = pilha.verficar_tamanho(tamanho);
					
					if (verifica == 1)
					{
						std::cout << "Tamanho invalido! digite um tamanho valido.\n";
						system("pause");
					}
				}
				system("cls");
				std::cout << "Escolha a forma que ira ser alocado o vetor:\n";
				std::cout << "1- Usando Malloc\n";
				std::cout << "2- Usando Calloc\n";
				std::cout << "3- Usando New\n\n";
				std::cout << "Digite aqui sua escolha:";
				std::cin >> tipo_aloc;
				
				system("cls");
				
				if (tipo_aloc == 1)
				{
					vetor = pilha.alocar_malloc(tamanho);
					pilha.popular(vetor, tamanho);
					std::cout << "Pilha criada!\n\n";
					tipo_aloc_backup = tipo_aloc;
					system("PAUSE");
					break;	
				}
				
				if (tipo_aloc == 2)
				{
					vetor = pilha.alocar_calloc(tamanho);
					std::cout << "Pilha criada!\n\n";
					tipo_aloc_backup = tipo_aloc;
					system("PAUSE");
					break;	
				}
				
				if (tipo_aloc == 3)
				{
					vetor = pilha.alocar_new(tamanho);
					pilha.popular(vetor, tamanho);
					tipo_aloc_backup = tipo_aloc;
					std::cout << "Pilha criada!\n\n";
					system("PAUSE");
					break;
				}
				
				else{
					std::cout << "Digito invalido, tente novamente!\n\n";
					system("pause");
				}
				
				
			}
			
			break;


				
			case 2:
				system("cls");
				
				if (vetor == 0)
				{
					std::cout << "Vetor nao existe! crie para continuar.\n\n";
					system("PAUSE");
					break;
				}
				
				pilha.push(vetor, &topo, tamanho);
				system("PAUSE");
				break;
				
			case 3:
				system("cls");
				
				if (vetor == 0)
				{
					std::cout << "Vetor nao existe! crie para continuar.\n\n";
					system("PAUSE");
					break;
				}
				
				pilha.pop(vetor,  &topo);
				system("PAUSE");
				break;
				
			case 4:
				system("cls");
				if (vetor == 0)
				{
					std::cout << "Vetor nao existe, pilha atualmente esta vazia.\n\n";
					system("PAUSE");
					break;
				}
				
				pilha.quantidade(&topo);
				system("pause");
				break;
				
			case 5:
				
				if (vetor == 0)
				{
					std::cout << "Vetor nao existe! crie para continuar.\n\n";
					system("PAUSE");
					break;
				}
				
				system("cls");
				pilha.mostrar(vetor, tamanho);
				system("PAUSE");
				break;
				
			case 6:
				system("cls");
				if (vetor == 0)
				{
					std::cout << "Vetor nao existe! crie para continuar.\n\n";
					system("PAUSE");
					break;
				}
				
				while (verifica == 1)
				{
					system("cls");
					std::cout << "Digite o tamanho do vetor:";
					std::cin >> tamanho;
					verifica = pilha.verficar_tamanho(tamanho);
					
					if (verifica == 1)
					{
						std::cout << "Tamanho invalido! digite um tamanho valido.\n";
						system("pause");
					}
				}
				
				if (tipo_aloc_backup == 1)
				{
					vetor = pilha.alocar_malloc(tamanho);
					pilha.popular(vetor, tamanho);
					std::cout << "Pilha resetada!\n\n";
					system("PAUSE");
					break;	
				}
				
				if (tipo_aloc_backup == 2)
				{
					vetor = pilha.alocar_calloc(tamanho);
					std::cout << "Pilha resetada!\n\n";
					system("PAUSE");
					break;	
				}
				
				if (tipo_aloc_backup == 3)
				{
					vetor = pilha.alocar_new(tamanho);
					pilha.popular(vetor, tamanho);
					std::cout << "Pilha resetada!\n\n";
					system("PAUSE");
					break;
				}

			case 7:
				system("cls");
				std::cout << "Saindo do programa!";
				exit(1);
				
			default:
				system("cls");
				std::cout << "DIGITO INVALIDO!\n\n";
				system("PAUSE");
			}
		
		}
	}
}
