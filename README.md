## MENU DE MUSEU MULTIMIDIATICO

O código em C apresentado é um programa simples que simula a interação de um usuário com um sistema de museu chamado "MUSEU PIMEXPO". Abaixo está uma descrição do funcionamento e das principais características do código:

1. **Inclusão de Bibliotecas:**
   - O programa inclui diversas bibliotecas padrão em C, como `stdio.h`, `stdlib.h`, `string.h`, `locale.h`, `conio.h` e `time.h`, para manipulação de strings, entrada/saída padrão, manipulação de caracteres e funções relacionadas ao tempo, respectivamente.

2. **Definição de Constantes:**
   - São definidas duas constantes, `MAX_NAME_LENGTH` e `MAX_TEXT_LENGTH`, que representam o comprimento máximo de nomes e textos no programa.

3. **Inclusão de Cabeçalhos Personalizados:**
   - São incluídos três cabeçalhos personalizados (`"MenegerFunctions.h"`, `"UserFunctions.h"`, `"TextDisplay.h"`) que provavelmente contêm declarações de funções utilizadas no programa.

4. **Função Principal (main):**
   - A função principal (`main`) é o ponto de entrada do programa.
   - São declaradas variáveis inteiras (`MenuOpcao`, `OpcaoExposicao`, `UserOption`, `TodosUsuarios`, `i`) e uma variável de ponto flutuante (`MelhorAvaliado`).
   - É configurada a localidade para permitir a exibição correta de caracteres especiais, como acentos.

5. **Abertura de Arquivos:**
   - Dois arquivos são abertos, `"BDExposicoes.txt"` para dados de exposições e `"BDUsuario.txt"` para dados de usuários. Se ocorrer algum erro ao abrir o arquivo de usuários, o programa exibe uma mensagem de erro e encerra.

6. **Menu Principal:**
   - Um loop `while` é utilizado para exibir um menu principal ao usuário até que a opção 12 seja selecionada.
   - O menu apresenta exposições cadastradas, opções para visualizar os ingressos do usuário (`Meus ingressos`) e sair do museu.
   - O programa solicita a escolha do usuário e toma ações com base na escolha.

7. **Exibição de Exposições:**
   - As exposições cadastradas são exibidas ao usuário, mostrando seus nomes e posições.

8. **Tratamento de Opções do Usuário:**
   - O programa verifica se o usuário escolheu ver seus ingressos (`Meus ingressos`) ou sair do museu. Em caso afirmativo, ele chama funções relacionadas.

9. **Detalhes de Exposição:**
   - Se o usuário escolher uma exposição específica, são exibidos detalhes dessa exposição, incluindo nome, descrição, data e preço.
   - Calcula a porcentagem de usuários que recomendam essa exposição.

10. **Menu Adicional para Exposições:**
    - Se a exposição escolhida não for uma opção de saída, são apresentadas opções adicionais para aquela exposição, como visualizar o calendário, fazer uma reserva, fornecer feedback ou voltar ao menu inicial.

11. **Fechamento de Arquivos:**
    - Após a execução do programa, os arquivos são fechados (`fclose`).

12. **Retorno da Função Principal:**
    - A função principal retorna 0, indicando uma execução bem-sucedida.

Este programa simula uma interação básica de usuário em um ambiente de museu, permitindo a exploração de exposições, visualização de detalhes, interação com opções específicas e retorno ao menu principal.