#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    
    cout << "***************************************" << endl;

    cout << "* Bem-vindos ao jogo da adivinhacao ! *" << endl;

    cout << "***************************************" << endl;

    cout << "Escolha seu nivel de dificuldade: " << endl;

    cout << "Facil (F), Medio(M) ou Dificil (D)" << endl;

    char dificuldade;

    cin >> dificuldade; 

    int numero_de_tentativas;

    if(dificuldade == 'F')
    {
        numero_de_tentativas = 15;
    }

    else if(dificuldade == 'M')
    {
        numero_de_tentativas = 10;
    }

    else
    {
        numero_de_tentativas = 5;
    }

    //setar uma semente para o gerador de número funcionar
    srand(time(NULL));
    //Visto que não é entre 0 e 99, temos que resolver nosso código com o resto "100"
    // Utilizamos a funcao random para gerar um valor aleatorio, faz parte de uma biblioteca de funcoes padroes em C
    const int NUMERO_SECRETO = rand() % 100;    
    // lembrando que a funcao sempre possui () apos ela

    bool nao_acertou = true;

    int tentativas = 0;

    double pontos =  1000.0;

    for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++)
    {

    int chute;

    cout << "Tentativa " << tentativas << endl;

    cout << "Qual o seu chute?" << endl;

    cin >> chute;

    // Usamos ABS(absoluto) para tirar sempre o modulo da equacao, que no caso, pode retornar um valor negativo
    // Para sempre gerar um numero real, utilizamos o 2.0 para sinalizar um valor real, e nao ser uma divisao apenas com numeros inteiros
    double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;

    pontos = pontos - pontos_perdidos;

    cout << "O Valor do seu chute e :" << chute << endl;

    bool acertou = chute == NUMERO_SECRETO;

    bool maior = chute > NUMERO_SECRETO;

    if(acertou)
    {
        cout << "Parabens !! Voce acertou o numero secreto! " << endl;

        nao_acertou = false;
        // para terminar o laço de repetição apos acertar
        break;
    }
    else if(maior)
    {
        cout << "Seu chute foi maior que o numero secreto! " << endl;
    }
    else
    {
        cout << "Seu chute foi menor que o numero secreto!" << endl;
    }

    }
    
    cout << "Fim de jogo!" << endl;

    if(nao_acertou)
    {
        cout << "Voce perdeu! Seu numero secreto era " << NUMERO_SECRETO << ".Tente novamente!" << endl;
    }
    else
    {
        cout << "Voce acertou o numero secreto em: " << tentativas << " tentativas" << endl;

        // Adiciona a precisao de duas casas com a funcao precision
        cout.precision(2);
        // Vai utilizar um marcado para manter a virgular fixa em um lugar, e para garantir que o número não aparecerá em notação científica.
        cout << fixed;

        cout << "Sua pontuacao foi de " << pontos << " pontos" << endl;
    }

}
