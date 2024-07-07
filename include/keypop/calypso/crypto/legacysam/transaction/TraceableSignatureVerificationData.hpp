/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <memory>

#include "keypop/calypso/crypto/legacysam/spi/LegacySamRevocationServiceSpi.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/SamTraceabilityMode.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/SignatureVerificationData.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

using keypop::calypso::crypto::legacysam::spi::LegacySamRevocationServiceSpi;

/**
 * Contains the input/output data of the {@link
 * FreeTransactionManager#prepareVerifySignature(SignatureVerificationData)} method for traceable
 * signature verification using the "PSO Verify Signature" command.
 *
 * <p>An instance of this interface can be obtained via the method {@link
 * org.eclipse.keypop.calypso.crypto.legacysam.LegacySamApiFactory#createTraceableSignatureVerificationData()}.
 *
 * @since 0.1.0
 */
class TraceableSignatureVerificationData
: public SignatureVerificationData<TraceableSignatureVerificationData> {
public:
    /**
     * Indicates that the signature has been computed in "SAM traceability" mode and therefore
     * whether the revocation status of the signing SAM should be checked or not.
     *
     * <p>By default, the signature is not supposed to have been computed in "SAM traceability"
     * mode.
     *
     * @param offset The offset in bits of the SAM traceability data.
     * @param samTraceabilityMode The SAM traceability mode which have been used.
     * @param samRevocationService If it is provided, then the revocation status of the SAM that
     *        signed the data will be checked by the SAM revocation service.
     * @return The current instance.
     * @see TraceableSignatureComputationData#withSamTraceabilityMode(int, SamTraceabilityMode)
     * @throw IllegalArgumentException If the provided samTraceabilityMode is null.
     * @since 0.1.0
     */
    virtual TraceableSignatureVerificationData& withSamTraceabilityMode(
        const int offset,
        const SamTraceabilityMode samTraceabilityMode,
        const std::shared_ptr<LegacySamRevocationServiceSpi> samRevocationService)
        = 0;

    /**
     * Indicates that the signature has been computed in non "Busy" mode.
     *
     * <p>By default, the signature is supposed to have been computed in "Busy" mode.
     *
     * <p>The signature may have been generated with "Busy mode" enabled. In this mode, after a "PSO
     * Verify Signature" failing because of an incorrect signature, during a few seconds the SAM
     * rejects any "PSO Verify Signature" commands with "Busy" mode by responding with the "busy"
     * status word.
     *
     * <p>When a "PSO Verify Signature" fails with the busy status, the terminal should repeat the
     * command until the SAM is not busy anymore.
     *
     * <p>The busy mode duration is typically of a few seconds, and it is never of greater than ten
     * seconds.
     *
     * <p>Note that after a reset of the SAM, "PSO Verify Signature" commands being in "Busy" mode
     * fail with the busy status until the end of the busy mode duration.
     *
     * @return The current instance.
     * @see TraceableSignatureComputationData#withoutBusyMode()
     * @since 0.1.0
     */
    virtual TraceableSignatureVerificationData& withoutBusyMode() = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
