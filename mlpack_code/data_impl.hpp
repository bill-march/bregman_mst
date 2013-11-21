/**
 * @file bregman_mst/mlpack_code/data_impl.hpp
 * @author Pari Ram (p.ram@gatech.edu)
 *
 * Implementation of the functions defined in data.hpp
 */

#ifndef _data_impl_hpp
#define _data_impl_hpp

#include "data.hpp"

namespace bmst
{ 

template <typename T>
Point<T>::Point() :
  values_(std::vector<T>(0)),
  n_dims_(0) 
{}

template <typename T>
Point<T>::Point(const std::vector<T>& point) :
  values_(point),
  n_dims_(point.size()) 
{}

template<typename T>
Point<T>::Point(const Point<T>& point)
{
  *this = point;
}

template<typename T>
T& Point<T>::operator[](const size_t i)
{
  if (i >= n_dims_) 
  {
    std::cout << "[ERROR] Point index out of range" << std::endl;
    exit(1);
  }
  return values_[i];
}

template<typename T>
const T& Point<T>::operator[](const size_t i) const
{
  if (i >= n_dims_) 
  {
    std::cout << "[ERROR] Point index out of range" << std::endl;
    exit(1);
  }
  return values_[i];
}

template<typename T>
Point<T>& Point<T>::operator=(const Point<T>& point)
{
  n_dims_ = point.n_dims();
  values_.resize(n_dims_);
  for (size_t i = 0; i < n_dims_; i++) 
    values_[i] = point.values_[i];

  return *this;
}

template<typename T>
Point<T>& Point<T>::operator+=(const Point<T>& point)
{
  if (n_dims_ == point.n_dims_) 
  {
    for (size_t i = 0; i < n_dims_; i++)
      values_[i] += point.values_[i];
  }
  else
  {
    std::cout << "[ERROR] Dimensions mismatch in point addition" <<
      std::endl;
    exit(1);
  }
  return *this;
}

template<typename T>
Point<T>& Point<T>::operator-=(const Point<T>& point)
{
  if (n_dims_ == point.n_dims_) 
  {
    for (size_t i = 0; i < n_dims_; i++)
      values_[i] -= point.values_[i];
  }
  else
  {
    std::cout << "[ERROR] Dimensions mismatch in point subtraction" <<
      std::endl;
    exit(1);
  }
  return *this;
}

template<typename T>
Point<T>& Point<T>::operator*=(const double scalar)
{
  for (size_t i = 0; i < n_dims_; i++)
    values_[i] *= scalar;

  return *this;
}

template<typename T>
Point<T>& Point<T>::operator/=(const double scalar)
{
  for (size_t i = 0; i < n_dims_; i++)
    values_[i] /= scalar;

  return *this;
}

template<typename T>
void Point<T>::zeros()
{
  values_.assign(n_dims_, 0);
}

template<typename T>
void Point<T>::zeros(const size_t num_dims)
{
  values_.assign(num_dims, 0);
  n_dims_ = num_dims;
}

template<typename T>
void Point<T>::ones()
{
  values_.assign(n_dims_, 1);
}

template<typename T>
void Point<T>::ones(const size_t num_dims)
{
  values_.assign(num_dims, 1);
  n_dims_ = num_dims;
}

// Binary +
template<typename TPoint>
TPoint operator+(const TPoint& lhs, const TPoint& rhs)
{
  return TPoint(lhs) += rhs;
}

// Binary -
template<typename TPoint>
TPoint operator-(const TPoint& lhs, const TPoint& rhs)
{
  return TPoint(lhs) -= rhs;
}

// Binary *
template<typename TPoint>
TPoint operator*(const double lhs, const TPoint& rhs)
{
  return TPoint(rhs) *= lhs;
}

template<typename TPoint>
TPoint operator*(const TPoint& lhs, const double rhs)
{
  return TPoint(lhs) *= rhs;
}

// Binary /
template<typename TPoint>
TPoint operator/(const TPoint& lhs, const double rhs)
{
  return TPoint(lhs) /= rhs;
}

// Binary dot product
template<typename TPoint>
double Dot(const TPoint& a, const TPoint& b)
{
  if (a.n_dims() != b.n_dims())
  {
    // fail here
    std::cout << "[ERROR] Dimension mismatch in dot product computation" <<
      std::endl;
    exit(1);
  }
  double dot_product = 0;
  // FIXME: Improve efficiency of this loop
  for (size_t i = 0; i < a.n_dims(); i++)
    dot_product += (a[i] * b[i]);
  return dot_product;
}

template<typename T>
Table<T>::Table() :
  points_(std::vector<Point<T> >(0)),
  n_points_(0)
{}

template<typename T>
Table<T>::Table(const std::vector<std::vector<T> >& points)
{

}

template<typename T>
Table<T>::Table(const std::vector<Point<T> >& points)
{

}

template<typename T>
Table<T>::Table(const Table& table)
{

}

template<typename T>
Table<T>::Table(const std::string& file_name) 
{

}

template<typename T>
Point<T>& Table<T>::operator[](const size_t i)
{

}

template<typename T>
const Point<T>& Table<T>::operator[](const size_t i) const
{

}

template<typename T>
Table<T>& Table<T>::operator=(const Table& table) 
{

}

}; // namespace
#endif