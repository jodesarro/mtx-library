# Matrix Market file format library
A C++ set of functions to handle [Matrix Market file format (MTX)](https://math.nist.gov/MatrixMarket/formats.html)

## Available functions

- Get size (the number of rows and columns) of a *two-dimensional array format MTX* file
```
void mtx_getsize( std::string mtx_path, int &imax, int &jmax )
```

- Read a *two-dimensional array format MTX* file and store the values in an one-dimensional array
```
template<typename T>
void mtx_readto_array1d( std::string mtx_path, T * array1d, int imax, int jmax )

template<typename T>
void mtx_readto_complex_array1d( std::string mtx_path, std::complex<T> * array1d, int imax, int jmax )
```

- Write the values of an one-dimensional array in a *two-dimensional array format MTX* file
```
template<typename T>
void mtx_writefrom_array1d( std::string mtx_path, T * array1d, int imax, int jmax )

template<typename T>
void mtx_writefrom_complex_array1d( std::string mtx_path, std::complex<T> * array1d, int imax, int jmax )
```

## Licensing

This project is protected under <a href="https://github.com/jodesarro/mtx-library/blob/master/LICENSE">MIT License</a> and [@jodesarro]( https://github.com/jodesarro ) is the principal author.