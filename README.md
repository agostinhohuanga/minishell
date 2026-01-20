# minishell

Um mini-shell simples implementado em C.

## Estrutura do Projeto

```
minishell/
├── src/          # Arquivos de código fonte (.c)
├── include/      # Arquivos de cabeçalho (.h)
├── obj/          # Arquivos objeto compilados (gerados durante a compilação)
├── bin/          # Executável final (gerado durante a compilação)
├── tests/        # Arquivos de teste
├── Makefile      # Sistema de compilação
└── README.md     # Este arquivo
```

## Compilação

Para compilar o projeto:

```bash
make
```

Para limpar os arquivos gerados:

```bash
make clean
```

## Uso

Após compilar, execute o minishell:

```bash
./bin/minishell
```

## Estrutura de Diretórios

- **src/**: Contém todos os arquivos de código fonte (.c) do projeto
- **include/**: Contém todos os arquivos de cabeçalho (.h) com declarações e protótipos
- **obj/**: Diretório para arquivos objeto (.o) gerados durante a compilação (ignorado pelo git)
- **bin/**: Diretório para o executável final (ignorado pelo git)
- **tests/**: Diretório para testes unitários e de integração