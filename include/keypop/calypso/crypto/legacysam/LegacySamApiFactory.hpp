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
#include <string>

#include "keypop/calypso/card/transaction/spi/SymmetricCryptoCardTransactionManagerFactory.hpp"
#include "keypop/calypso/crypto/legacysam/sam/LegacySam.hpp"
#include "keypop/calypso/crypto/legacysam/sam/LegacySamSelectionExtension.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/AsyncTransactionCreatorManager.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/AsyncTransactionExecutorManager.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/BasicSignatureComputationData.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/BasicSignatureVerificationData.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/FreeTransactionManager.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/KeyPairContainer.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/LegacyCardCertificateComputationData.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/SecuritySetting.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/TraceableSignatureComputationData.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/TraceableSignatureVerificationData.hpp"
#include "keypop/reader/CardReader.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {

using keypop::calypso::card::transaction::spi::SymmetricCryptoCardTransactionManagerFactory;
using keypop::calypso::crypto::legacysam::sam::LegacySam;
using keypop::calypso::crypto::legacysam::sam::LegacySamSelectionExtension;
using keypop::calypso::crypto::legacysam::transaction::AsyncTransactionCreatorManager;
using keypop::calypso::crypto::legacysam::transaction::AsyncTransactionExecutorManager;
using keypop::calypso::crypto::legacysam::transaction::BasicSignatureComputationData;
using keypop::calypso::crypto::legacysam::transaction::BasicSignatureVerificationData;
using keypop::calypso::crypto::legacysam::transaction::FreeTransactionManager;
using keypop::calypso::crypto::legacysam::transaction::KeyPairContainer;
using keypop::calypso::crypto::legacysam::transaction::LegacyCardCertificateComputationData;
using keypop::calypso::crypto::legacysam::transaction::SecuritySetting;
using keypop::calypso::crypto::legacysam::transaction::TraceableSignatureComputationData;
using keypop::calypso::crypto::legacysam::transaction::TraceableSignatureVerificationData;
using keypop::reader::CardReader;

/**
 * Legacy SAM API Factory.
 *
 * @since 0.3.0
 */
class LegacySamApiFactory {
public:
    /**
     * Returns a new instance of LegacySamSelectionExtension.
     *
     * @return A new instance of LegacySamSelectionExtension.
     * @since 0.3.0
     */
    virtual std::shared_ptr<LegacySamSelectionExtension> createLegacySamSelectionExtension() = 0;

    /**
     * Returns a new instance of SymmetricCryptoCardTransactionManagerFactory to be used to
     * secure a card transaction.
     *
     * @param samReader The reader to use to communicate with the SAM.
     * @param sam The associated control SAM to be used with the card transaction.
     * @return A new instance of SymmetricCryptoCardTransactionManagerFactory to be used to
     *         secure a card transaction.
     * @throw IllegalArgumentException If an argument is null or invalid.
     * @since 0.3.0
     */
    virtual std::shared_ptr<SymmetricCryptoCardTransactionManagerFactory>
    createSymmetricCryptoCardTransactionManagerFactory(
        const std::shared_ptr<CardReader> samReader, const std::shared_ptr<LegacySam> sam)
        = 0;

    /**
     * Returns a new instance of {@link SecuritySetting}.
     *
     * @return A new instance of {@link SecuritySetting}.
     * @since 0.3.0
     */
    virtual std::shared_ptr<SecuritySetting> createSecuritySetting() = 0;

    /**
     * Returns a new instance of FreeTransactionManager.
     *
     * @param samReader The reader to use to communicate with the SAM.
     * @param sam The SAM image.
     * @return A new instance of FreeTransactionManager.
     * @throw IllegalArgumentException If an argument is null or invalid.
     * @since 0.3.0
     */
    virtual std::shared_ptr<FreeTransactionManager> createFreeTransactionManager(
        const std::shared_ptr<CardReader> samReader, const std::shared_ptr<LegacySam> sam)
        = 0;

    /**
     * Returns a new instance of AsyncTransactionCreatorManager.
     *
     * <p>The target SAM context can be retrieved with the method
     * FreeTransactionManager::exportTargetSamContextForAsyncTransaction().
     *
     * @param targetSamContext The target SAM context.
     * @param securitySetting The security settings.
     * @return A new instance of AsyncTransactionCreatorManager.
     * @throw IllegalArgumentException If an argument is null or invalid.
     * @since 0.3.0
     */
    virtual std::shared_ptr<AsyncTransactionCreatorManager> createAsyncTransactionCreatorManager(
        const std::string& targetSamContext, const std::shared_ptr<SecuritySetting> securitySetting)
        = 0;

    /**
     * Returns a new instance of AsyncTransactionExecutorManager.
     *
     * <p>The commands must be prepared using a AsyncTransactionCreatorManager.
     *
     * @param samReader The reader to use to communicate with the SAM.
     * @param sam The SAM image.
     * @param samCommands A string containing the prepared commands.
     * @return A new instance of AsyncTransactionExecutorManager.
     * @throws IllegalArgumentException If an argument is null or invalid.
     * @since 0.3.0
     */
    virtual std::shared_ptr<AsyncTransactionExecutorManager> createAsyncTransactionExecutorManager(
        const std::shared_ptr<CardReader> samReader,
        const std::shared_ptr<LegacySam> sam,
        const std::string& samCommands)
        = 0;

    /**
     * Returns a new instance of KeyPairContainer.
     *
     * @return A new instance of KeyPairContainer.
     * @since 0.5.0
     */
    virtual std::shared_ptr<KeyPairContainer> createKeyPairContainer() = 0;

    /**
     * Returns a new instance of LegacyCardCertificateComputationData.
     *
     * @return A new instance of LegacyCardCertificateComputationData.
     * @since 0.5.0
     */
    virtual std::shared_ptr<LegacyCardCertificateComputationData>
    createLegacyCardCertificateComputationData() = 0;

    /**
     * Returns a new instance of BasicSignatureComputationData.
     *
     * @return A new instance of BasicSignatureComputationData.
     * @since 0.3.0
     */
    virtual std::shared_ptr<BasicSignatureComputationData> createBasicSignatureComputationData()
        = 0;

    /**
     * Returns a new instance of TraceableSignatureComputationData.
     *
     * @return A new instance of TraceableSignatureComputationData.
     * @since 0.3.0
     */
    virtual std::shared_ptr<TraceableSignatureComputationData>
    createTraceableSignatureComputationData() = 0;

    /**
     * Returns a new instance of BasicSignatureVerificationData.
     *
     * @return A new instance of BasicSignatureVerificationData.
     * @since 0.3.0
     */
    virtual std::shared_ptr<BasicSignatureVerificationData> createBasicSignatureVerificationData()
        = 0;

    /**
     * Returns a new instance of TraceableSignatureVerificationData.
     *
     * @return A new instance of TraceableSignatureVerificationData.
     * @since 0.3.0
     */
    virtual std::shared_ptr<TraceableSignatureVerificationData>
    createTraceableSignatureVerificationData() = 0;
};

} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
