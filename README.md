# 📄 ft_printf

> `ft_printf` é uma implementação personalizada da função padrão `printf` em C.  
> Ela reproduz as funcionalidades básicas, interpretando strings de formato e exibindo dados formatados na saída padrão.  
> Este projeto é um excelente exercício para manipulação de strings, funções variádicas e entendimento de operações de entrada e saída em baixo nível.

![Banner](https://img.shields.io/badge/Project-ft_printf-blueviolet) ![C](https://img.shields.io/badge/Language-C-red) ![License](https://img.shields.io/badge/License-MIT-green)

---

✨ **Objetivo**

Recriar do zero a função `ft_printf` com as seguintes características:

- Suporte aos especificadores: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` e `%%`.
- Impressão dos dados formatados na saída padrão.
- Retorno do número total de caracteres impressos.
- Gerenciamento manual de variáveis e formatação, sem uso da libc (exceto funções permitidas).
- Total compatibilidade com as normas da 42.

---

⚙️ **Protótipo**

```c
int ft_printf(const char *format, ...);
```
`format`: string que contém texto e especificadores de formato que indicam como os argumentos seguintes devem ser formatados.

`...`: número variável de argumentos que serão usados para substituir os especificadores na string format.

`Retorno`: o número total de caracteres impressos na saída padrão.

Essa função funciona de forma semelhante ao printf da libc, interpretando a string de formato e imprimindo os dados formatados.
O uso de argumentos variádicos permite passar quantos parâmetros forem necessários conforme os especificadores presentes.

## 🚀 Funcionalidades

- Suporte aos especificadores de conversão:
  - `%c` — imprime um caractere
  - `%s` — imprime uma string
  - `%p` — imprime o endereço de um ponteiro em hexadecimal
  - `%d` e `%i` — imprime números inteiros com sinal em decimal
  - `%u` — imprime números inteiros sem sinal em decimal
  - `%x` e `%X` — imprime números inteiros sem sinal em hexadecimal (minúsculo e maiúsculo)
  - `%%` — imprime o caractere `%` literal

- Retorna a quantidade de caracteres impressos

## 🧠 Conceitos Trabalhados

- 📚 Manipulação de strings e leitura de variáveis variádicas (`stdarg.h`)
- 🧠 Parsing e interpretação de formatos de impressão
- 🧵 Controle de fluxo e tomada de decisão com condicionais
- 🧼 Gerenciamento manual de memória (uso de `malloc` e `free`)
- 📦 Modularização do código com funções auxiliares
- 🛠️ Escrita eficiente usando a função `write`

## 💻 Exemplo de Uso

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Olá, %s!\n", "mundo");
    ft_printf("Foram impressos %d caracteres.\n", count);

    count = ft_printf("Caracteres: %c, inteiro: %d, hexadecimal: %x\n", 'A', 123, 255);
    ft_printf("Total de caracteres impressos: %d\n", count);

    return 0;
}
```

## 📂 Arquivos

| Arquivo            | Descrição                                                                 |
|--------------------|---------------------------------------------------------------------------|
| `ft_printf.c`      | Contém a lógica principal da função `ft_printf` e o parser de formatos    |
| `ft_printfutils.c` | Funções auxiliares como `ft_putnbr`, `ft_puthex`, entre outras conversões |
| `ft_printf.h`      | Header com protótipos, includes e definições necessárias                  |
| `Makefile`         | Facilita a compilação, recompilação e limpeza do projeto                  |


## 🛠 Instalação

### 🔧 Como Compilar e Usar

#### 📦 Compilação com Makefile

Para compilar o projeto, basta rodar no terminal:

```bash
make
```
Isso irá compilar todos os arquivos e gerar um executável.

♻️ Outros comandos úteis

`make re` — recompila o projeto do zero (faz fclean e depois all)

`make clean` — remove os arquivos objeto .o

`make fclean` — remove os arquivos objeto e o executável

### 💻 Como Usar

#### 📌 Passo 1: Incluir o Header
Inclua o arquivo de cabeçalho no seu código:

```c
#include "ft_printf.h"
```
#### 📌 Passo 2: Compilar
Você pode compilar seu código de duas formas:

##### ✅ Usando o Makefile
Se quiser apenas compilar a biblioteca:
```bash
make
```
Depois, compile o seu arquivo `main.c` com os objetos gerados:
```bash
gcc main.c libftprintf.a -I. -Wall -Wextra -Werror
```
##### 🔧 Compilação manual
Se preferir compilar tudo manualmente (sem Makefile):
```bash
gcc main.c ft_printf.c ft_printfutils.c -I. -Wall -Wextra -Werror -o ft_printf_test
./ft_printf_test
```

## 🧠 Dicas e Considerações

- ✅ **Retorno da função**: Sempre utilize o valor retornado por `ft_printf` para verificar quantos caracteres foram impressos. Isso é útil para testes e validação do comportamento.
- 🔍 **Teste com diferentes formatos**: Verifique se sua função lida corretamente com combinações diversas de especificadores, inclusive casos extremos como strings nulas, valores negativos, ponteiros vazios, etc.
- 🧪 **Casos de borda são importantes**:
  - `%s` com `NULL`
  - `%p` com ponteiros nulos
  - `%%` no início, meio e fim da string
  - Múltiplos especificadores misturados

- ⚠️ **Norma da 42**:
  - Nenhuma função da libc é permitida, exceto `write`, `malloc` e `free`.
  - É proibido o uso de variáveis globais.
  - Seu código deve seguir a `Norminette`.

- 💡 **Mantenha o código modular**: Quebrar seu código em funções auxiliares facilita manutenção, testes e futuras adições (como o bônus).
- 🛠 **Faça testes com `diff` ou `cmp`**: Compare a saída do `ft_printf` com o `printf` original para garantir compatibilidade.

---

## 👩‍💻 Autoria

**✨ Amy Rodrigues ✨** 

🎓 Estudante de C e desenvolvimento de baixo nível na [42 São Paulo](https://www.42sp.org.br/)

🐧 Usuária de Linux | 💻 Fã de terminal | 🎯 Apaixonada por entender como tudo funciona por trás dos bastidores

---

## 📎 Licença

Este projeto foi desenvolvido como parte do currículo educacional da 42 São Paulo.

📘 **Uso permitido**:
- Pode ser utilizado como referência para estudos e aprendizado individual
- Pode servir de inspiração para seus próprios projetos

🚫 **Proibido**:
- Submeter cópias deste projeto como se fossem de sua autoria em avaliações da 42 ou outras instituições

Seja ético e contribua para uma comunidade de desenvolvedores mais honesta e colaborativa 🤝
