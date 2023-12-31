#pragma once

#include <array>
#include <complex>
#include <vector>
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#include <functional>

// scalar types
typedef double real_t;
typedef std::complex<real_t> complex_t;
typedef std::size_t dim_t;


template<dim_t D>
using TinyMultiIndex=std::array<int, D>;    //define the Tiny Multi-Index (wrapper of the array with element type unsigned int)

template<int R, int C>
using CMatrix = Eigen::Matrix<complex_t,R,C>;

template<int R, int C>
using RMatrix = Eigen::Matrix<real_t,R,C>;

template<int R, int C>
using CArray = Eigen::Array<complex_t,R,C>;

template<int R, int C>
using RArray = Eigen::Array<real_t,R,C>;

template<int N>
using HaWpBasisVector = CArray<Eigen::Dynamic, N>;

using Coefficients = Eigen::Matrix<complex_t, Eigen::Dynamic, 1>;

// matrix types
template <class I, int R, int C>
using GMatrix = Eigen::Matrix<I, R, C>;

template <int R, int C>
using CMatrix = GMatrix<complex_t, R, C>;

template <int R, int C>
using RMatrix = GMatrix<real_t, R, C>;

// vector types
template <class I, int R>
using GVector = GMatrix<I, R, 1>;

template <int R>
using CVector = GVector<complex_t, R>;

template <int R>
using RVector = GVector<real_t, R>;

// function type
template <class P>
using function_t = std::function<P>;

template <int D>
using rD_to_r = function_t<real_t( RVector<D> )>;  // function wrapper for function with argument type RVector<D> and return type real_t 

template <int D>
using rD_to_rD = function_t<RVector<D>( RVector<D> )>; //function wrapper for function with argument type RVector<D> and return type RVector<D> 

template <int D>
using rD_to_rDxD = function_t<RMatrix<D, D>( RVector<D> )>;  // function wrapper for function with argument type RVector<D> and return type RMatrix<D, D>

template <int D>
using rD_to_c = function_t<complex_t( RVector<D> )>;   // function wrapper for function with argument type RVector<D> and return type complex_t

template <int D>
using rD_to_cD = function_t<CVector<D>( RVector<D> )>;  // function wrapper for function with argument type RVector<D> and return type CVector<D>( 

template <int D>
using rD_to_cDxD = function_t<CMatrix<D, D>( RVector<D> )>; //function wrapper for function with argument type RVector<D> and return type CMatrix<D, D> 

template <int D, int N>
using rD_to_cNxN = function_t<CMatrix<N, N>( RVector<D> )>; // function wrapper for function with argument type RVector<D> and return type CMatrix<N, N> 

template <int D>
using cD_to_r = function_t<real_t( CVector<D> )>;   // function wrapper for function with  argument type CVector<D> and return type real_t 

template <int D>
using cD_to_rD = function_t<RVector<D>( CVector<D> )>;  // function wrapper for function with argument type CVector<D> and return type RVector<D> 

template <int D>
using cD_to_rDxD = function_t<RMatrix<D, D>( CVector<D> )>; // function wrapper for function with argument type CVector<D> and return type RMatrix<D, D> 

using c_to_c = function_t<complex_t(complex_t)>;  // function wrapper for function with argument type complex_t and return type complex_t 

template <int D>
using cD_to_c = function_t<complex_t( CVector<D> )>; // function wrapper for function with argument type CVector<D> and return type complex_t 

template <int D>
using cD_to_cD = function_t<CVector<D>( CVector<D> )>;  //function wrapper for function with argument type CVector<D>  and return type CVector<D> 

template <int D>
using cD_to_cDxD = function_t<CMatrix<D, D>( CVector<D> )>;  //function wrapper for function with argument type CVector<D>  and return type CMatrix<D, D> 

template <int D, int N>
using cD_to_cNxN = function_t<CMatrix<N, N>( CVector<D> )>;  //function wrapper for function with argument type CVector<D> return type CMatrix<N, N> 

// function valued functions
template <int D, class F>
using rD_to_function = function_t<F( RVector<D> )>;   //  function wrapper for function with argument type RVector<D> and return type function F 

template <int D, int N, class F>
using rD_to_function_vector = function_t<GVector<F, N>( RVector<D> )>; //function wrapper for function with argument type RVector<D>  adn return type function vector GVector<F, N>

template <int D, int N, class F>
using rD_to_function_matrix = function_t<GMatrix<F, N, N>( RVector<D> )>; //function wrapper for function with argument type RVector<D> return type function matrix GMatrix<F, N, N>

template <int D, class F>
using cD_to_function = function_t<F( CVector<D> )>;   //function wrapper for function with argument type CVector<D> and return type function F 

template <int D, int N, class F>
using cD_to_function_vector = function_t<GVector<F, N>( CVector<D> )>; //function wrapper for function with argument type CVector<D>  and return type function vector GVector<F, N>

template <int D, int N, class F>
using cD_to_function_matrix = function_t<GMatrix<F, N, N>( CVector<D> )>; //function wrapper for function with argument type CVector<D> and return type function matrix GMatrix<F, N, N>

 // eigenvalue
template <int N>
using eigenvalues_t =
        typename Eigen::EigenSolver<RMatrix<N, N> >::EigenvalueType;  //eigenvalue type 

template <int N>
    using eigenvector_t =
        typename Eigen::EigenSolver<RMatrix<N, N> >::EigenvectorsType; //eigenveector type 

