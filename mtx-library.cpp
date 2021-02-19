#include <fstream>
#include <string>
#include <complex>

using namespace std;

void mtx_get_dimensions( string mtx_path, int &mtx_rows, int &mtx_columns )
{
    fstream mtx_file( mtx_path );
    mtx_file >> mtx_rows >> mtx_columns;
    while ( !mtx_file.good() )
    {
        mtx_file.clear();
        mtx_file.ignore(INT_MAX, '\n');
        mtx_file >> mtx_rows >> mtx_columns;
    }
    mtx_file.close();
}

template<typename T>
void mtx_read_to_array( string mtx_path, T * mtx_array )
{
    int mtx_rows, mtx_columns;
    fstream mtx_file( mtx_path );

    mtx_file >> mtx_rows >> mtx_columns;
    while ( !mtx_file.good() )
    {
        mtx_file.clear();
        mtx_file.ignore(INT_MAX, '\n');
        mtx_file >> mtx_rows >> mtx_columns;
    }

    int mtx_dimension = mtx_rows * mtx_columns;
    
    for ( int i=0; i<mtx_dimension; i++ )
    {
        mtx_file >> mtx_array[i];
    }

    mtx_file.close();
}

template<typename T>
void mtx_write_from_array( string mtx_path, string mtx_comment, int mtx_rows, int mtx_columns, T * mtx_array )
{    
    fstream mtx_file;
    mtx_file.open( mtx_path, fstream::out );

    mtx_file << "%%MatrixMarket matrix array real general" << endl;
    mtx_file << "%" << mtx_comment << endl;
    mtx_file << mtx_rows << " " << mtx_columns << endl;
    
    int mtx_dimension = mtx_rows * mtx_columns;

    for ( int i=0; i<mtx_dimension; i++ )
    {
        mtx_file << setprecision(16) << scientific << "   " << mtx_array[i] << endl;
    }

    mtx_file.close();
}

template<typename complex<T>>
void mtx_write_from_complex_array( string mtx_path, string mtx_comment, int mtx_rows, int mtx_columns, complex<T> * mtx_array )
{    
    fstream mtx_file;
    mtx_file.open( mtx_path, fstream::out );

    mtx_file << "%%MatrixMarket matrix array complex general" << endl;
    mtx_file << "%" << mtx_comment << endl;
    mtx_file << mtx_rows << " " << mtx_columns << endl;
    
    int mtx_dimension = mtx_rows * mtx_columns;

    for ( int i=0; i<mtx_dimension; i++ )
    {
        mtx_file << setprecision(16) << scientific << "   " << mtx_array[i] << endl;
    }

    mtx_file.close();
}
