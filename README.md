# Matrix Market file format library
A C++ library to handle [Matrix Market file format (MTX)](https://math.nist.gov/MatrixMarket/formats.html)

## Available functions

- Get dimensions (the number of rows and columns) of a *two-dimensional array format MTX*
```
void mtx_get_dimensions( string mtx_path, int &mtx_rows, int &mtx_columns )
```

- Read a *two-dimensional array format MTX* and store the values in an array
```
template<typename T>
void mtx_read_to_array( string mtx_path, T * mtx_array )
```

- Write the values of an array in a *two-dimensional array format MTX* file
```
template<typename T>
void mtx_write_from_array( string mtx_path, string mtx_comments, int mtx_rows, int mtx_columns, T * mtx_array )
```
