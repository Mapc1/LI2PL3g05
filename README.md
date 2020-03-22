# LI2-PL3-G5
## Jogo Rastros para projeto de LI2

Desenvolvido por:
  
- [**Marco André Pereira da Costa**](https://github.com/Mapc1) a93283
- [**Alexandre Eduardo Vieira Martins**](https://github.com/Alexmartins01) a93242
- [**Luis Manuel Peixoto Silva**](https://github.com/LuisMPSilva01) a93293

## Resumo do trabalho
Nesta segunda semana desenvolvemos vários elementos relativos ao funcionamento do jogo bem como alguns comandos.

### Interface:

Aqui implementamos a função comando que recebe um comando e nos casos de gr/ler um argumento que será o nome do ficheiro.

Foi também adicionado um prompt, e para além disso, modificado o interpretador para acomodar as funções implementadas esta semana.

### Lógica:

Neste módulo foram implementadas 2 funções relativas à verificação do fim do jogo: **jogada_impossível** e **fim_do_jogo**.

A primeira verifica se a peça **BRANCA** está presa, a segunda verifica se esta peça chegou a uma das casas **UM** ou **DOIS**, esta forma de verificação permite que se importem tabuleiros com posições diferentes para estas casas.

A função **valida_jogada** foi também melhorada para verificar se a casa jogada é adjacente à peça **BRANCA**. 

### Dados:

Aqui foram adicionadas 2 funções relativas a importação/exportação de ficheiros.

A função **escreve_ficheiro** recebe como argumentos o **ESTADO** que será gravado e uma **string** que será o nome/localização do ficheiro.

A função **ler_ficheiro** recebe também o **ESTADO** e uma **string** e importa o ficheiro, alterando o estado.
