/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <cstdint>
#include <vector>

#include "keypop/calypso/card/transaction/spi/CardTransactionCryptoExtension.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

using keypop::calypso::card::transaction::spi::CardTransactionCryptoExtension;

/**
 * Extends the {@link CardTransactionCryptoExtension} interface of the "Keypop Calypso Card API" to
 * enrich the card transaction command set with specific crypto commands such as for example
 * computation and signature verification operations.
 *
 * <p>An instance of this interface can be obtained via the methods
 * keypop::calypso::card::transaction::SecureRegularModeTransactionManager
 *     ::getCryptoExtension(Class)
 * or
 * keypop::calypso::card::transaction::SecureExtendedModeTransactionManager
 *     ::getCryptoExtension(Class).
 *
 * @since 0.3.0
 */
class CardTransactionLegacySamExtension : public CardTransactionCryptoExtension {
public:
    /**
     * Schedules the execution of a "Data Cipher" or "PSO Compute Signature" command.
     *
     * <p>Once the command is processed, the result will be available in the provided input/output
     * BasicSignatureComputationData or TraceableSignatureComputationData objects.
     *
     * <p>The signature may be used for many purposes, for example:
     *
     * <ul>
     *   <li>To add a signature to data recorded in a contactless card or ticket.<br>
     *       <u>Remark</u>: to speed up processing, it is recommended to use a constant signing key
     *       (which is not diversified before ciphering). Instead, the serial number of the card or
     *       ticket should be inserted at the beginning of the data to sign.
     *   <li>To sign some data reported from a terminal to a central system.<br>
     *       <u>Remark</u>: in this case, the terminal SAM contains a signing work key diversified
     *       with its own serial number, guarantying that the data has indeed been signed by this
     *       SAM. The central system SAM uses the master signing key, diversified before signing
     *       with the diversifier set previously by "Select Diversifier" command.
     * </ul>
     *
     * @param data The input/output data containing the parameters of the command.
     * @return The current instance.
     * @throw IllegalArgumentException If the input data is inconsistent.
     * @see SignatureComputationData
     * @see BasicSignatureComputationData
     * @see TraceableSignatureComputationData
     * @since 0.3.0
     */
    virtual CardTransactionLegacySamExtension& prepareComputeSignature(SignatureComputationData<?> data) = 0;

    /**
     * Schedules the execution of a "Data Cipher" or "PSO Verify Signature" command.
     *
     * <p>Once the command is processed, the result will be available in the provided input/output
     * {@link BasicSignatureVerificationData} or {@link TraceableSignatureVerificationData} objects.
     *
     * @param data The input/output data containing the parameters of the command.
     * @return The current instance.
     * @throw IllegalArgumentException If the input data is inconsistent.
     * @throw SamRevokedException If the signature has been computed in "SAM traceability" mode and
     *        the SAM revocation status check has been requested and the SAM is revoked (for
     *        traceable signature only).
     * @see SignatureVerificationData
     * @see BasicSignatureVerificationData
     * @see TraceableSignatureVerificationData
     * @since 0.3.0
     */
    virtual CardTransactionLegacySamExtension& prepareVerifySignature(SignatureVerificationData<?> data) = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
