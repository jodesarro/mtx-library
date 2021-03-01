#include <fstream>
#include <string>
#include <complex>

using namespace std;

void mtx_get_dimensions( string mtx_path, int &IMAX, int &JMAX )
{
    fstream mtx_file( mtx_path );
    mtx_file >> IMAX >> JMAX;
    while ( !mtx_file.good() )
    {
        mtx_file.clear();
        mtx_file.ignore(INT_MAX, '\n');
        mtx_file >> IMAX >> JMAX;
    }
    mtx_file.close();
}

template<typename T>
void mtx_read_to_array( string mtx_path, T * mtx_array )
{
    int IMAX, JMAX;
    fstream mtx_file( mtx_path );

    mtx_file >> IMAX >> JMAX;
    while ( !mtx_file.good() )
    {
        mtx_file.clear();
        mtx_file.ignore(INT_MAX, '\n');
        mtx_file >> IMAX >> JMAX;
    }

    int DIM = IMAX * JMAX;
    
    for ( int i=0; i<DIM; i++ )
    {
        mtx_file >> setprecision(15) >> mtx_array[i];
    }

    mtx_file.close();
}

template<typename T>
void mtx_read_to_complex_array( string mtx_path, complex<T> * mtx_array )
{
    int IMAX, JMAX;
    fstream mtx_file( mtx_path );

    mtx_file >> IMAX >> JMAX;
    while ( !mtx_file.good() )
    {
        mtx_file.clear();
        mtx_file.ignore(INT_MAX, '\n');
        mtx_file >> IMAX >> JMAX;
    }

    int DIM = IMAX * JMAX;

    double realpart, imagpart;
    for ( int i=0; i<DIM; i++ )
    {
        mtx_file >> setprecision(15) >> realpart >> imagpart;
        mtx_array[i] = complex<T> (realpart, imagpart);
    }

    mtx_file.close();
}

template<typename T>
void mtx_write_from_array( string mtx_path, string mtx_comment, int IMAX, int JMAX, T * mtx_array )
{    
    fstream mtx_file;
    mtx_file.open( mtx_path, fstream::out );

    mtx_file << "%%MatrixMarket matrix array real general" << endl;
    mtx_file << "%" << mtx_comment << endl;
    mtx_file << IMAX << " " << JMAX << endl;
    
    int DIM = IMAX * JMAX;

    for ( int i=0; i<DIM; i++ )
    {
        mtx_file << setprecision(15) << scientific << "   " << mtx_array[i] << endl;
    }

    mtx_file.close();
}

template<typename T>
void mtx_write_from_complex_array( string mtx_path, string mtx_comment, int IMAX, int JMAX, complex<T> * mtx_array )
{    
    fstream mtx_file;
    mtx_file.open( mtx_path, fstream::out );

    mtx_file << "%%MatrixMarket matrix array complex general" << endl;
    mtx_file << "%" << mtx_comment << endl;
    mtx_file << IMAX << " " << JMAX << endl;
    
    int DIM = IMAX * JMAX;

    for ( int i=0; i<DIM; i++ )
    {
        mtx_file << setprecision(15) << scientific << "   " << real(mtx_array[i]) << "   " << imag(mtx_array[i]) << endl;
    }

    mtx_file.close();
}