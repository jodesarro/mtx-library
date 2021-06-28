# Matrix Market file format library

<p align="right"><a href="https://github.com/jodesarro/mtx-library/blob/master/README.pt-br.md">Leia isto em português</a></p>

A set of C++ functions to handle files in the [Matrix Market (MTX)](https://math.nist.gov/MatrixMarket/formats.html) format.

MTX files have a clever structure where one can store two-dimensional data in only one column.

It is very useful for importing and exporting matrices, tables, numeric datasets and so on.

These files are generally used for importing and exporting data in software such as [Cell Ranger](https://support.10xgenomics.com/single-cell-gene-expression/software/pipelines/latest/what-is-cell-ranger), [Anjal](http://murasu.com/murasu-anjal/), [Wolfram Mathematica](https://reference.wolfram.com/language/ref/format/MTX.html), among others.

## Available functions

- Get size (the number of rows and columns) of a MTX file
```
void mtx_getsize( std::string mtx_path, int &imax, int &jmax )
```

- Import a MTX file and store the data in an one-dimensional array
```
template<typename T>
void mtx_import( std::string mtx_path, T * data_array, int imax, int jmax )

template<typename T>
void mtx_import( std::string mtx_path, std::complex<T> * data_array, int imax, int jmax )
```

- Export data of an one-dimensional array to a MTX file
```
template<typename T>
void mtx_export( std::string mtx_path, T * data_array, int imax, int jmax )

template<typename T>
void mtx_export( std::string mtx_path, std::complex<T> * data_array, int imax, int jmax )
```

## Licensing

This project is protected under <a href="https://github.com/jodesarro/mtx-library/blob/master/LICENSE">MIT License</a> and [@jodesarro]( https://github.com/jodesarro ) is the principal author.