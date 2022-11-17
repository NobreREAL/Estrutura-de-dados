using MySql.Data.MySqlClient;
using MySqlX.XDevAPI.CRUD;
using Org.BouncyCastle.Crypto.Digests;
using System.Drawing.Printing;
using System.Linq.Expressions;
using System.Runtime.CompilerServices;

namespace classroom
{
    class Agenda
    {
        static string Configs()
        {

            string server = "localhost";
            string database = "dbAgenda";
            string username = "root";
            string password = "";

            string connstring = "SERVER=" + server + ";" + "DATABASE=" + database + ";" + "UID=" + username + ";" + "PASSWORD=" + password + ";";


            return connstring;
        }

        static void Create(string user, string email, string numero)
        {
            MySqlConnection rar = new MySqlConnection(Configs());
            rar.Open();
            string query = "Insert into tbContato (nome, email, numero) values (@nome, @email, @numero)";
            MySqlCommand cmd = new MySqlCommand(query, rar);
            cmd.Parameters.AddWithValue("@nome", user);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@numero", numero);
            MySqlDataReader reader = cmd.ExecuteReader();
        }

        static void Read(int id)
        {
            MySqlConnection rar = new MySqlConnection(Configs());
            rar.Open();
            string query = "select * from tbContato where id = @id";
            MySqlCommand cmd = new MySqlCommand(query, rar);
            cmd.Parameters.AddWithValue("@id", id);
            MySqlDataReader reader = cmd.ExecuteReader();

            while (reader.Read())
            {
                Console.WriteLine($"Nome do contato:{reader["nome"]}");
                Console.WriteLine($"Email do contato:{reader["email"]}");
                Console.WriteLine($"Número do contato:{reader["numero"]}");
            }
        }

        static void Update(string user, string email, string numero, int id)
        {

            MySqlConnection rar = new MySqlConnection(Configs());
            rar.Open();
            string query = "Update tbContato set nome = @nome, email = @email, numero = @numero" + " where id = @id";
            MySqlCommand cmd = new MySqlCommand(query, rar);
            cmd.Parameters.AddWithValue("@nome", user);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@id", id);
            cmd.Parameters.AddWithValue("@numero", numero);
            MySqlDataReader reader = cmd.ExecuteReader();
        }

        static void Delete(int id)
        {
            MySqlConnection rar = new MySqlConnection(Configs());
            rar.Open();
            string query = "DELETE FROM tbContato WHERE id=@id";
            MySqlCommand cmd = new MySqlCommand(query, rar);
            cmd.Parameters.AddWithValue("@id", id);
            MySqlDataReader reader = cmd.ExecuteReader();
        }

        static bool verify(int id_choiced)
        {
            int id;

            MySqlConnection rar = new MySqlConnection(Configs());
            rar.Open();
            string query = "select id from tbContato";
            MySqlCommand cmd = new MySqlCommand(query, rar);
            MySqlDataReader reader = cmd.ExecuteReader();

            while (reader.Read())
            {
               id  = reader.GetInt32("id");

               if (id == id_choiced)
                {
                    return false;
                }
            }

            return true;

            
        }

        static void Main()
        {
            int escolha;
            for (; ; )
            {
                Console.Clear();
                Console.WriteLine("Sistema de agenda, seja bem vindo:");
                Console.WriteLine("===================================");
                Console.WriteLine("1- Adicionar contato na agenda  ");
                Console.WriteLine("2- Consultar contato na agenda  ");
                Console.WriteLine("3- Atualizar contato da agenda  ");
                Console.WriteLine("4- Remover   contato da agenda  ");
                Console.WriteLine("5- Alunos envolvidos no trabalho");
                Console.WriteLine("6- Sair do programa da agenda   ");
                Console.WriteLine("===================================");

                try {
                    escolha = int.Parse(Console.ReadLine());


                    switch (escolha)
                    {
                        case 1:

                            string nome = "";
                            string email = "";
                            string numero = "";

                            for (; ; )
                            {
                                Console.Clear();
                                Console.WriteLine("Digite o nome do contato:");
                                nome = Console.ReadLine();
                                int tamanho_nome = nome.Length;


                                if (tamanho_nome > 12)
                                {
                                    Console.WriteLine("Nome só pode ter até 12 caractéres.");
                                    Console.ReadLine();
                                }
                                else
                                {
                                    break;
                                }
                            }
                            for (; ; )
                            {
                                Console.WriteLine("Digite o email do contato:");
                                email = Console.ReadLine();
                                int tamanho_email = email.Length;

                                if (tamanho_email > 50)
                                {
                                    Console.WriteLine("Email só pode ter até 50 caractéres.");
                                    Console.ReadLine();
                                }
                                else
                                {
                                    break;
                                }
                            }
                            for (; ; )
                            {
                                Console.WriteLine("Digite o número do contato:");
                                numero = Console.ReadLine();
                                int tamanho_num = numero.Length;

                                if (tamanho_num > 15)
                                {
                                    Console.WriteLine("Telefone só pode ter até 15 números.");
                                    Console.ReadLine();
                                }

                                else
                                {
                                    break;
                                }


                            }

                            Console.Clear();
                            Console.WriteLine("Contato criado com sucesso!");
                            Agenda.Create(nome, email, numero);
                            Console.ReadLine();

                            break;

                        case 2:
                            int ID = 0;
                            for (; ; )
                            {
                                Console.Clear();
                                Console.WriteLine("Digite o ID do contato");
                                ID = int.Parse(Console.ReadLine());

                                if (Agenda.verify(ID))
                                {
                                    Console.Write("Id Não existe! Digite um Id Existente!");
                                    Console.ReadLine();
                                }

                                else
                                {
                                    break;
                                }
                            }

                            Console.Clear();
                            Agenda.Read(ID);
                            Console.ReadLine();


                            break;

                        case 3:
                            ID = 0;
                            for (; ; )
                            {
                                Console.Clear();
                                Console.WriteLine("Digite o ID do contato");
                                ID = int.Parse(Console.ReadLine());

                                if (Agenda.verify(ID))
                                {
                                    Console.Write("Id Não existe! Digite um Id Existente!");
                                    Console.ReadLine();
                                }

                                else
                                {
                                    break;
                                }
                            }

                            nome = "";
                            email = "";
                            numero = "";

                            for (; ; )
                            {
                                Console.Clear();
                                Console.WriteLine("Digite o nome do contato:");
                                nome = Console.ReadLine();
                                int tamanho_nome = nome.Length;


                                if (tamanho_nome > 12)
                                {
                                    Console.WriteLine("Nome só pode ter até 12 caractéres.");
                                    Console.ReadLine();
                                }
                                else
                                {
                                    break;
                                }
                            }
                            for (; ; )
                            {
                                Console.WriteLine("Digite o email do contato:");
                                email = Console.ReadLine();
                                int tamanho_email = email.Length;

                                if (tamanho_email > 50)
                                {
                                    Console.WriteLine("Email só pode ter até 50 caractéres.");
                                    Console.ReadLine();
                                }
                                else
                                {
                                    break;
                                }
                            }
                            for (; ; )
                            {
                                Console.WriteLine("Digite o número do contato:");
                                numero = Console.ReadLine();
                                int tamanho_num = numero.Length;

                                if (tamanho_num > 15)
                                {
                                    Console.WriteLine("Telefone só pode ter até 15 números.");
                                    Console.ReadLine();
                                }

                                else
                                {
                                    break;
                                }

                            }

                            Agenda.Update(nome, email, numero, ID);
                            Console.WriteLine("Editado");
                            Console.ReadLine();

                            break;

                        case 4:
                            ID = 0;
                            for (; ; )
                            {
                                Console.Clear();
                                Console.WriteLine("Digite o ID do contato");
                                ID = int.Parse(Console.ReadLine());

                                if (Agenda.verify(ID))
                                {
                                    Console.Write("Id Não existe! Digite um Id Existente!");
                                    Console.ReadLine();
                                }

                                else
                                {
                                    break;
                                }
                            }

                            Agenda.Delete(ID);
                            Console.WriteLine("Apagado");
                            Console.ReadLine();

                            break;

                        case 5:
                            Console.Clear();
                            Console.WriteLine("Alunos envolvidos:");
                            Console.WriteLine("Jardênia Lopes");
                            Console.WriteLine("Lucas Nobre");
                            Console.ReadLine();
                            break;
                        case 6:
                            Console.Clear();
                            Console.Write("Saindo do programa!");
                            Environment.Exit(0);
                            break;

                        default:
                            Console.Clear();
                            Console.Write("Digito inválido!");
                            break;
                    }


                    }
                catch
                {
                    Console.WriteLine("Digito ínválido!");
                }



                }

            }

        }
    }

    
