# Biblioteca para arquivos no formato Matrix Market

<p align="right"><a href="https://github.com/jodesarro/mtx-library/blob/master/README.pt-br.md">Leia isto em português</a></p>

Um conjunto de funções em C++ para lidar com arquivos no formato [Matrix Market (MTX)](https://math.nist.gov/MatrixMarket/formats.html).

Os arquivos MTX têm uma estrutura inteligente onde é possível armazenar dados bidimensionais em apenas uma coluna.

É muito útil para importar e exportar matrizes, tabelas, conjuntos de dados numéricos e etc.

Esses arquivos geralmente são usados para importar e exportar dados em softwares como [Cell Ranger](https://support.10xgenomics.com/single-cell-gene-expression/software/pipelines/latest/what-is-cell-ranger), [Anjal](http://murasu.com/murasu-anjal/), [Wolfram Mathematica](https://reference.wolfram.com/language/ref/format/MTX.html), dentre outros.

## Funções disponíveis

- Obter o tamanho (número de linhas e colunas) de um arquivo MTX
```
void mtx_getsize( std::string mtx_path, int &imax, int &jmax )
```

- Importar um arquivo MTX e armazená-lo em um array de uma dimensão
```
template<typename T>
void mtx_import( std::string mtx_path, T * data_array, int imax, int jmax )

template<typename T>
void mtx_import( std::string mtx_path, std::complex<T> * data_array, int imax, int jmax )
```

- Exportar um array de uma dimensão para um arquivo MTX
```
template<typename T>
void mtx_export( std::string mtx_path, T * data_array, int imax, int jmax )

template<typename T>
void mtx_export( std::string mtx_path, std::complex<T> * data_array, int imax, int jmax )
```

## Licença

Este projeto está protegido sob a licença <a href="https://github.com/jodesarro/mtx-library/blob/master/LICENSE">MIT License</a> e tem [@jodesarro](https://github.com/jodesarro) como seu principal autor.