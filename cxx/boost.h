#ifndef _ME_BOOST_H
#define _ME_BOOST_H

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

ME_NAMESPACE_BEGIN

typedef ::boost::archive::binary_oarchive binary_oarchive;
typedef ::boost::archive::binary_iarchive binary_iarchive;

ME_NAMESPACE_END

#endif

