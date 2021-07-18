#include <fstream>
#include <string>
#include <complex>

void mtx_getsize( std::string mtx_path, int &imax, int &jmax )
{
    std::fstream mtx_file( mtx_path );
    mtx_file >> imax >> jmax;
    while ( !mtx_file.good() )
    {
        mtx_file.clear();
        mtx_file.ignore(INT_MAX, '\n');
        mtx_file >> imax >> jmax;
    }
    mtx_file.close();
}

template<typename T>
void mtx_import( std::string mtx_path, T * data_array, int imax, int jmax )
{
    std::fstream mtx_file( mtx_path );

    mtx_file >> imax >> jmax;
    while ( !mtx_file.good() )
    {
        mtx_file.clear();
        mtx_file.ignore(INT_MAX, '\n');
        mtx_file >> imax >> jmax;
    }

    int DIM = imax * jmax;
    
    for ( int i=0; i<DIM; i++ )
    {
        mtx_file >> data_array[i];
    }

    mtx_file.close();
}

template<typename T>
void mtx_import( std::string mtx_path, std::complex<T> * data_array, int imax, int jmax )
{
    std::fstream mtx_file( mtx_path );

    mtx_file >> imax >> jmax;
    while ( !mtx_file.good() )
    {
        mtx_file.clear();
        mtx_file.ignore(INT_MAX, '\n');
        mtx_file >> imax >> jmax;
    }

    int DIM = imax * jmax;

    double realpart, imagpart;
    for ( int i=0; i<DIM; i++ )
    {
        mtx_file >> realpart >> imagpart;
        data_array[i] = std::complex<T> (realpart, imagpart);
    }

    mtx_file.close();
}

template<typename T>
void mtx_export( std::string mtx_path, T * data_array, int imax, int jmax )
{    
    std::fstream mtx_file;
    mtx_file.open( mtx_path, std::fstream::out );

    mtx_file << "%%MatrixMarket matrix array real general\n%\n";
    mtx_file << imax << " " << jmax << std::endl;
    
    int DIM = imax * jmax;

    for ( int i=0; i<DIM; i++ )
    {
        mtx_file << "   " << data_array[i] << std::endl;
    }

    mtx_file.close();
}

template<typename T>
void mtx_export( std::string mtx_path, std::complex<T> * data_array, int imax, int jmax )
{    
    std::fstream mtx_file;
    mtx_file.open( mtx_path, std::fstream::out );

    mtx_file << "%%MatrixMarket matrix array complex general\n%\n";
    mtx_file << imax << " " << jmax << std::endl;
    
    int DIM = imax * jmax;

    for ( int i=0; i<DIM; i++ )
    {
        mtx_file << "   " << real(data_array[i]) << "   " << imag(data_array[i]) << std::endl;
    }

    mtx_file.close();
}