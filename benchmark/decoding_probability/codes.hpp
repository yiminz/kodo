// Copyright Steinwurf ApS 2011-2013.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once


#include <kodo/rlnc/full_vector_codes.hpp>
#include <kodo/linear_block_decoder_delayed.hpp>
#include <kodo/sparse_uniform_generator.hpp>
#include <kodo/sparse_staircase_encoder.hpp>
#include <kodo/sparse_staircase_feedback_generator.hpp>
#include <kodo/sparse_nonzero_uniform_generator.hpp>

namespace kodo
{

    template<class Field>
    class full_delayed_rlnc_decoder
        : public // Payload API
                 payload_recoder<recoding_stack,
                 payload_decoder<
                 // Codec Header API
                 systematic_decoder<
                 symbol_id_decoder<
                 // Symbol ID API
                 plain_symbol_id_reader<
                 // Codec API
                 aligned_coefficients_decoder<
                 linear_block_decoder_delayed<
                 linear_block_decoder<
                 // Coefficient Storage API
                 coefficient_storage<
                 coefficient_info<
                 // Storage API
                 deep_symbol_storage<
                 storage_bytes_used<
                 storage_block_info<
                 // Finite Field API
                 finite_field_math<typename fifi::default_field<Field>::type,
                 finite_field_info<Field,
                 // Factory API
                 final_coder_factory_pool<
                 // Final type
                 full_delayed_rlnc_decoder<Field>
                     > > > > > > > > > > > > > > > >
    { };

    template<class Field>
    class full_rlnc_decoder_unsystematic
        : public // Payload API
            payload_recoder<recoding_stack,
            payload_decoder<
            // Codec Header API
            symbol_id_decoder<
            // Symbol ID API
            plain_symbol_id_reader<
            // Codec API
            aligned_coefficients_decoder<
            linear_block_decoder_delayed<
            linear_block_decoder<
            // Coefficient Storage API
            coefficient_storage<
            coefficient_info<
            // Storage API
            deep_symbol_storage<
            storage_bytes_used<
            storage_block_info<
            // Finite Field API
            finite_field_math<typename fifi::default_field<Field>::type,
            finite_field_info<Field,
            // Factory API
            final_coder_factory_pool<
            // Final type
            full_rlnc_decoder_unsystematic<Field>
            > > > > > > > > > > > > > > >
    { };

    template<class Field>
    class full_rlnc_encoder_unsystematic :
        public // Payload Codec API
               payload_encoder<
               // Codec Header API
               symbol_id_encoder<
               // Symbol ID API
               plain_symbol_id_writer<
               // Coefficient Generator API
               uniform_generator<
               // Codec API
               encode_symbol_tracker<
               zero_symbol_encoder<
               linear_block_encoder<
               storage_aware_encoder<
               // Coefficient Storage API
               coefficient_info<
               // Symbol Storage API
               deep_symbol_storage<
               storage_bytes_used<
               storage_block_info<
               // Finite Field API
               finite_field_math<typename fifi::default_field<Field>::type,
               finite_field_info<Field,
               // Factory API
               final_coder_factory_pool<
               // Final type
               full_rlnc_encoder_unsystematic<Field
                   > > > > > > > > > > > > > > > >
    { };

    /// RLNC encoder using a density based random generator, which can be
    /// used to control the density i.e. the number of non-zero elements in
    /// the encoding vector.
    template<class Field>
    class sparse_full_rlnc_encoder :
        public // Payload Codec API
               payload_encoder<
               // Codec Header API
               systematic_encoder<
               symbol_id_encoder<
               // Symbol ID API
               plain_symbol_id_writer<
               // Coefficient Generator API
               sparse_uniform_generator<
               // Codec API
               encode_symbol_tracker<
               zero_symbol_encoder<
               linear_block_encoder<
               storage_aware_encoder<
               // Coefficient Storage API
               coefficient_info<
               // Symbol Storage API
               deep_symbol_storage<
               storage_bytes_used<
               storage_block_info<
               // Finite Field API
               finite_field_math<typename fifi::default_field<Field>::type,
               finite_field_info<Field,
               // Factory API
               final_coder_factory_pool<
               // Final type
               sparse_full_rlnc_encoder<Field
                   > > > > > > > > > > > > > > > > >
    { };


////// SPARSE STAIRCASE

    template<class Field>
    class sparse_nonzero_staircase_full_rlnc_encoder :
        public // User API
               sparse_staircase_encoder<
               // Payload Codec API
               payload_encoder<
               // Codec Header API
               systematic_encoder<
               symbol_id_encoder<
               // Symbol ID API
               plain_symbol_id_writer<
               // Coefficient Generator API
               sparse_nonzero_uniform_generator<
               sparse_uniform_generator<
               // Codec API
               encode_symbol_tracker<
               zero_symbol_encoder<
               linear_block_encoder<
               storage_aware_encoder<
               // Coefficient Storage API
               coefficient_info<
               // Symbol Storage API
               deep_symbol_storage<
               storage_bytes_used<
               storage_block_info<
               // Finite Field API
               finite_field_math<typename fifi::default_field<Field>::type,
               finite_field_info<Field,
               // Factory API
               final_coder_factory_pool<
               // Final type
               sparse_nonzero_staircase_full_rlnc_encoder<Field
                   > > > > > > > > > > > > > > > > > > >
    { };


    template<class Field>
    class sparse_staircase_full_rlnc_encoder :
        public // User API
               sparse_staircase_encoder<
               // Payload Codec API
               payload_encoder<
               // Codec Header API
               systematic_encoder<
               symbol_id_encoder<
               // Symbol ID API
               plain_symbol_id_writer<
               // Coefficient Generator API
               sparse_uniform_generator<
               // Codec API
               encode_symbol_tracker<
               zero_symbol_encoder<
               linear_block_encoder<
               storage_aware_encoder<
               // Coefficient Storage API
               coefficient_info<
               // Symbol Storage API
               deep_symbol_storage<
               storage_bytes_used<
               storage_block_info<
               // Finite Field API
               finite_field_math<typename fifi::default_field<Field>::type,
               finite_field_info<Field,
               // Factory API
               final_coder_factory_pool<
               // Final type
               sparse_staircase_full_rlnc_encoder<Field
                   > > > > > > > > > > > > > > > > > >
    { };

    template<class Field>
    class sparse_staircase_full_rlnc_decoder
        : public // Payload API
                 sparse_staircase_feedback_generator<
                 payload_recoder<recoding_stack,
                 payload_decoder<
                 // Codec Header API
                 systematic_decoder<
                 symbol_id_decoder<
                 // Symbol ID API
                 plain_symbol_id_reader<
                 // Codec API
                 aligned_coefficients_decoder<
                 linear_block_decoder<
                 // Coefficient Storage API
                 coefficient_storage<
                 coefficient_info<
                 // Storage API
                 deep_symbol_storage<
                 storage_bytes_used<
                 storage_block_info<
                 // Finite Field API
                 finite_field_math<typename fifi::default_field<Field>::type,
                 finite_field_info<Field,
                 // Factory API
                 final_coder_factory_pool<
                 // Final type
                 sparse_staircase_full_rlnc_decoder<Field>
                     > > > > > > > > > > > > > > > >
    { };




}
