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
void mtx_readto_array1d( std::string mtx_path, T * array1d, int imax, int jmax )
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
        mtx_file >> array1d[i];
    }

    mtx_file.close();
}

template<typename T>
void mtx_readto_complexarray1d( std::string mtx_path, std::complex<T> * array1d, int imax, int jmax )
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
        array1d[i] = std::complex<T> (realpart, imagpart);
    }

    mtx_file.close();
}

template<typename T>
void mtx_writefrom_array1d( std::string mtx_path, T * array1d, int imax, int jmax )
{    
    std::fstream mtx_file;
    mtx_file.open( mtx_path, std::fstream::out );

    mtx_file << "%%MatrixMarket matrix array real general\n%\n";
    mtx_file << imax << " " << jmax << std::endl;
    
    int DIM = imax * jmax;

    for ( int i=0; i<DIM; i++ )
    {
        mtx_file << "   " << array1d[i] << std::endl;
    }

    mtx_file.close();
}

template<typename T>
void mtx_writefrom_complexarray1d( std::string mtx_path, std::complex<T> * array1d, int imax, int jmax )
{    
    std::fstream mtx_file;
    mtx_file.open( mtx_path, std::fstream::out );

    mtx_file << "%%MatrixMarket matrix array std::complex general\n%\n";
    mtx_file << imax << " " << jmax << std::endl;
    
    int DIM = imax * jmax;

    for ( int i=0; i<DIM; i++ )
    {
        mtx_file << "   " << real(array1d[i]) << "   " << imag(array1d[i]) << std::endl;
    }

    mtx_file.close();
}