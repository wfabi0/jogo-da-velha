#include <iostream>
#include <windows.h>
#include <vector>

#define COLUMNS 3
#define LINES 3

using namespace std;

vector<vector<char>> game(LINES, vector<char>(COLUMNS, '_')); // Definindo matriz
bool finish = false;                                          // Ninguem começa ganhando :)
bool playerFinished = false;                                  // False = Jogador 1 | True = Jogador 2 [Define quem ganhou]
bool used = false;                                            // Verificar se o espaço esta ocupado ou não

int scoreX = 0, scoreY = 0; // Salva a quantidade de vitorias dos usuários

char changeView(char character)
{
  if (character == '_')
  {
    return ' ';
  }
  else
    return character;
}

// Imprime o jogo
void print()
{
  cout << "*******Jogo da Velha*******" << endl
       << endl;
  cout << "┌───┬───┬───┐" << endl;
  for (int i = 0; i < 3; i++)
  {
    cout << "│ " << changeView(game[i][0]) << " │ " << changeView(game[i][1]) << " │ " << changeView(game[i][2]) << " │" << endl;
    if (i != 2)
    {
      cout << "├───┼───┼───┤" << endl;
    }
  }
  cout << "└───┴───┴───┘" << endl;
  cout << endl
       << "***************************" << endl;
  cout << "        Score-Board        " << endl;
  cout << "> Jogador 1 (X): " << scoreX << " vitórias" << endl;
  cout << "> Jogador 2 (O): " << scoreY << " vitórias" << endl;
  cout << endl
       << "***************************" << endl;
}

// Verificar se é o jogador 1 ou jogador 2
string playerStatus(bool player)
{
  if (!player)
  {
    return "Jogador 1";
  }
  else
  {
    return "Jogador 2";
  }
}

// Transformar jogador 1/2 em caracteres
char playerCharacter(bool player)
{
  if (!player)
  {
    return 'X';
  }
  else
  {
    return 'O';
  }
}

// Converter caracteres em número
int convertCharToInt(char character)
{
  // cout << endl  << endl << endl << "TESTE: " << character << endl << endl << endl;
  if (character == 'X')
  {
    return 1;
  }
  else if (character == '_')
  {
    return 0;
  }
  else
  {
    return (-1);
  }
}

// Verificar a posição
bool checkPosition(int x, int y)
{
  return (game[x][y] != '_');
}

// Coloca o caractere na matriz
void executePosition(int position, bool player)
{
  switch (position)
  {
  case 1:
  {
    if (checkPosition(0, 0))
    {
      used = true;
      break;
    }
    game[0][0] = playerCharacter(player);
    break;
  }
  case 2:
  {
    if (checkPosition(0, 1))
    {
      used = true;
      break;
    }
    game[0][1] = playerCharacter(player);
    break;
  }
  case 3:
  {
    if (checkPosition(0, 2))
    {
      used = true;
      break;
    }
    game[0][2] = playerCharacter(player);
    break;
  }
  case 4:
  {
    if (checkPosition(1, 0))
    {
      used = true;
      break;
    }
    game[1][0] = playerCharacter(player);
    break;
  }
  case 5:
  {
    if (checkPosition(1, 1))
    {
      used = true;
      break;
    }
    game[1][1] = playerCharacter(player);
    break;
  }
  case 6:
  {
    if (checkPosition(1, 2))
    {
      used = true;
      break;
    }
    game[1][2] = playerCharacter(player);
    break;
  }
  case 7:
  {
    if (checkPosition(2, 0))
    {
      used = true;
      break;
    }
    game[2][0] = playerCharacter(player);
    break;
  }
  case 8:
  {
    if (checkPosition(2, 1))
    {
      used = true;
      break;
    }
    game[2][1] = playerCharacter(player);
    break;
  }
  case 9:
  {
    if (checkPosition(2, 2))
    {
      used = true;
      break;
    }
    game[2][2] = playerCharacter(player);
    break;
  }
  default:
  {
    break;
  }
  }
}

// Verifica se existe algum espaço vazio
int checkContinue()
{
  for (int row = 0; row < LINES; row++)
  {
    for (int col = 0; col < COLUMNS; col++)
    {
      if (game[row][col] == '_')
        return 0;
    }
  }
  return 1;
}

// Função teste (Utilizada para desenvolvimento)
void teste()
{
  for (int row = 0; row < LINES; row++)
  {
    for (int col = 0; col < COLUMNS; col++)
    {
      cout << endl
           << endl
           << endl
           << endl
           << "\"" << game[row][col] << "\"" << endl
           << endl;
    }
  }
}

// Verifica se possui algum ganhador
bool checkWin()
{
  int row, col, sum;

  // teste();

  // Verificando linhas
  for (row = 0; row < LINES; row++)
  {
    sum = 0;
    for (col = 0; col < COLUMNS; col++)
    {
      sum += convertCharToInt(game[row][col]);
    }
    if (sum == 3)
    {
      playerFinished = false;
      return finish = true;
    }
    if (sum == -3)
    {
      playerFinished = true;
      return finish = true;
    }
  }

  // Verificando colunas
  for (col = 0; col < COLUMNS; col++)
  {
    sum = 0;
    for (row = 0; row < LINES; row++)
    {
      sum += convertCharToInt(game[row][col]);
    }
    // cout << col << " " << sum << endl;
    if (sum == 3)
    {
      playerFinished = false;
      return finish = true;
    }
    if (sum == -3)
    {
      playerFinished = true;
      return finish = true;
    }
  }

  // Verificando diagonais
  sum = (convertCharToInt(game[0][0]) + convertCharToInt(game[1][1]) + convertCharToInt(game[2][2]));
  if (sum == 3)
  {
    playerFinished = false;
    return finish = true;
  }
  if (sum == -3)
  {
    playerFinished = true;
    return finish = true;
  }

  sum = (convertCharToInt(game[0][2]) + convertCharToInt(game[1][1]) + convertCharToInt(game[2][0]));
  if (sum == 3)
  {
    playerFinished = false;
    return finish = true;
  }
  if (sum == -3)
  {
    playerFinished = true;
    return finish = true;
  }

  return false;
}

// Inicia o jogo
void init()
{

  // Reiniciando variáveis de apoio
  finish = false;
  playerFinished = false;
  used = false;

  // Definindo tudo como vazio
  for (int row = 0; row < LINES; row++)
  {
    for (int col = 0; col < COLUMNS; col++)
    {
      game[row][col] = '_';
    }
  }
}

// Reinicia o jogo
void resetGame()
{
  system("cls");
  cout << "*******Jogo da Velha*******" << endl
       << endl;
  cout << "[!] > Deseja reiniciar o jogo da velha?" << endl;
  cout << "1. Reiniciar" << endl;
  cout << "0. Fechar" << endl;
  cout << endl
       << "***************************" << endl
       << endl;

  int ask;
  cout << "> Insira sua resposta: ";
  cin >> ask;

  if (ask == 1)
  {
    init();
  }
  else
  {
    system("cls");
    cout << endl
         << "[!] > Você finalizou o jogo da velha!" << endl;
    cout << "> Pontuação Final:" << endl;
    cout << "Jogador 1: " << scoreX << " vitórias" << endl;
    cout << "Jogador 2: " << scoreY << " vitórias" << endl
         << endl;
    exit(3);
  }
}

void startGame(bool player)
{
  do
  {

    if (checkContinue() == 1)
    {
      system("cls");
      print();
      cout << endl
           << "[!] > Empate!" << endl
           << endl;
      resetGame();
      return startGame(false);
    }

    int position;
    system("cls");
    print();
    cout << "> Agora é a vez do " << playerStatus(player) << "." << endl
         << endl;
    cout << "Insira sua posição (1 a 9): ";
    cin >> position;
    if (finish)
      break;
    if (position < 1 || position > 9)
    {
      cout << endl
           << "[!] > Posição inválida." << endl;
    }
    else
    {
      executePosition(position, player);
      if (used)
      {
        cout << endl
             << "[!] > Posição (" << position << ") em uso." << endl;
        used = false;
      }
      else
      {
        checkWin();
        if (finish)
        {
          break;
        }
        player = !player;
      }
    }
    cout << endl
         << endl;
    system("pause");
  } while (finish == false);

  if (finish)
  {
    system("cls");
    print();
    cout << "[!] > O " << playerStatus(playerFinished) << " venceu!!!" << endl
         << endl;
    if (!playerFinished)
    {
      scoreX++;
    }
    else
      scoreY++;
    system("pause");

    resetGame();
    startGame(false);
  }
}

int main()
{

  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  // Iniciando jogo como jogador 1
  init();
  startGame(false);

  cout << endl
       << endl;
  return 0;
}