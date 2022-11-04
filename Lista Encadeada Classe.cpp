#include <iostream>
#include <string>
#include <new>
#include <cstdlib>

struct Dados
{
	std::string Nome;
	int Telefone;
	struct Dados *proximo;	
};

class Agenda
{		
	public:
				
		int Quantidade_Agenda(Dados *Ponteiro)
		{
			Dados *p = Ponteiro;
			
			int count = 0;
			
			while (p != NULL)
			{
				if (p->Nome != "")
				{
					count += 1;
				}
				p = p->proximo;			
			}
			
			return count;			
		}
		
		void Mostrar_Agenda(Dados *Ponteiro)
		{
			Dados *p = Ponteiro;
			
			while(p != NULL)
			{
				std::cout << "\nNome da pessoa:" << p->Nome <<
			    "\n" << "Telefone da pessoa:" << p->Telefone << "\n\n";
			    
			    p = p->proximo;
			}
			
		}
		
		void Adicionar_Agenda(Dados *&Ponteiro, std::string Nome, int Telefone)
		{
			Dados *novoUser = new Dados;
			
			novoUser->Nome = Nome;
			novoUser->Telefone = Telefone;
			
			if (Ponteiro->Nome == "")
			{
				novoUser->proximo = NULL;	
			}else{
				novoUser->proximo = Ponteiro;
			}
			
			Ponteiro = novoUser;
		}
		
		void Remover_Agenda(Dados *&Ponteiro, int TAM, std::string *Nome, int *Telefone)
		{
			if (TAM == 0)
			{
				std::cout << "Agenda atualmente esta vazia!\n\n";
			}
			else
			{
				for (;;)
				{
				int POS;
				system("cls");
				std::cout << "Digite a posicao a apagar da agenda:";
				std::cin >> POS;
				if (POS > TAM || POS <= 0)
				{
					std::cout << "\nPosicao invalida, tente novamente!\n";
					system("pause");
				}
				else{
					
					int contador;
					
					Dados *p = Ponteiro;
					
					while (contador <= POS)
					{
						if (contador == POS - 1)
						{
							*Telefone = p->Telefone;
							*Nome = p->Nome;
							
							Dados *aux = new Dados;
							
							p->proximo = aux->proximo;
							
							free(aux);
							
						}
						
						p = p->proximo;
						
						contador += 1;
					}

						free(p);
					}
				}
			}
		}
		
};

int main()
{
	int i;
	
	
	Agenda acessar;
	
	Dados *ponteiro = new Dados;
	
	ponteiro->Nome= "";
	ponteiro->Telefone = 0;
	
	
		
	int Telefone;
	std::string Nome;
	
	
	
	for (;;)
	{
		system("cls");
		std::cout << "Quantidade de contatos na agenda atualmente:"<< acessar.Quantidade_Agenda(ponteiro);
		std::cout << "\n\n01 - Cadastrar nova pessoa e numero\n";
		std::cout << "02 - Editar  pessoa e/ou numero\n";
		std::cout << "03 - Remover cadastro de pessoa\n";
		std::cout << "04 - Consultar contato da pessoa\n";
		std::cout << "05 - Mostrar a agenda com pessoas\n";
		std::cout << "06 - Sair do programa\n\n";
		
		std::cout << "Escolha uma opcao mostrada:";
		
		std::cin >> i;
		
		switch(i){
			
			case 1:
				
				system("cls");
				std::cout << "Digite seu nome:";
				std::cin >> Nome;
				std::cout << "\nDigite seu telefone:";
				std::cin >> Telefone;
				acessar.Adicionar_Agenda(ponteiro, Nome, Telefone);
				break;
				
			case 2:
				break;
				
			case 3:
				
				int POS;
				system("cls");
				acessar.Remover_Agenda(ponteiro, acessar.Quantidade_Agenda(ponteiro), &Nome, &Telefone);
				system("PAUSE");
				break;
			case 4:
				break;
			case 5:
				acessar.Mostrar_Agenda(ponteiro);
				system("PAUSE");
				break;
			case 6:	
				system("cls");
				std::cout << "Saindo do programa!";
				exit(1);		
		}
	}
	return 0;
}
