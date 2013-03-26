// Copyright Steinwurf ApS 2011-2013.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#ifndef KODO_PLAIN_SYMBOL_ID_READER_HPP
#define KODO_PLAIN_SYMBOL_ID_READER_HPP

#include <cstdint>

#include "plain_symbol_id.hpp"

namespace kodo
{

    /// @brief Reads the coding coefficients from the symbol id
    ///        buffer and initializes the symbol coefficients pointer.
    ///        This implementation is the most basic one
    ///        where the symbol id simply is the coding coefficients.
    ///
    /// @ingroup symbol_id_layers
    /// @ingroup factory_layers
    template<class SuperCoder>
    class plain_symbol_id_reader_base : public SuperCoder
    {
    public:

        /// @copydoc layer::read_id(uint8_t*,uint8_t**)
        void read_id(uint8_t *symbol_id, uint8_t **symbol_coefficients)
            {
                assert(symbol_id != 0);
                assert(symbol_coefficients != 0);

                *symbol_coefficients = symbol_id;
            }

    };

    /// @copydoc plain_symbol_id_reader_base
    template<class SuperCoder>
    class plain_symbol_id_reader
        : public plain_symbol_id_reader_base<
                 plain_symbol_id<SuperCoder> >
    {};

}

#endif
