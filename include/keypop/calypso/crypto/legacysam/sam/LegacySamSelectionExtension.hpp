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

#include "keypop/calypso/crypto/legacysam/sam/LegacySam.hpp"
#include "keypop/calypso/crypto/legacysam/spi/LegacySamDynamicUnlockDataProviderSpi.hpp"
#include "keypop/calypso/crypto/legacysam/spi/LegacySamStaticUnlockDataProviderSpi.hpp"
#include "keypop/reader/CardReader.hpp"
#include "keypop/reader/selection/spi/CardSelectionExtension.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace sam {

using keypop::calypso::crypto::legacysam::spi::LegacySamDynamicUnlockDataProviderSpi;
using keypop::calypso::crypto::legacysam::spi::LegacySamStaticUnlockDataProviderSpi;
using keypop::reader::CardReader;
using keypop::reader::selection::spi::CardSelectionExtension;

/**
 * Extends the CardSelectionExtension interface of the "Keypop Reader API" to provide means
 * to define optional commands to be executed during the selection phase such as the "Unlock"
 * command.
 *
 * <p>An instance of this interface can be obtained via the method
 * LegacySamApiFactory::createLegacySamSelectionExtension().
 *
 * <p>In the case where the SAM is locked, three options are proposed:
 *
 * <ul>
 *   <li>The application provides directly the 16-byte unlock value expected by the SAM in static
 *       mode (setUnlockData(const std::string&) and setUnlockData(String,LegacySam::ProductType)}).
 *   <li>The application implements a LegacySamStaticUnlockDataProviderSpi used to compute
 *       the 16-byte value expected byte the SAM in static mode (may diversified with the SAM serial
 *       number) (setStaticUnlockDataProvider(LegacySamStaticUnlockDataProviderSpi) and
 *       setStaticUnlockDataProvider(LegacySamStaticUnlockDataProviderSpi, CardReader)).
 *   <li>The application implements a LegacySamDynamicUnlockDataProviderSpi used to have the
 *       8-byte value expected by the SAM in dynamic mode computed by an origin SAM (
 *       setDynamicUnlockDataProvider(LegacySamDynamicUnlockDataProviderSpi) and
 *       setDynamicUnlockDataProvider(LegacySamDynamicUnlockDataProviderSpi, CardReader)).
 * </ul>
 *
 * All three methods are exclusive.
 *
 * <p>When the unlocking data is supplied by a provider, a CardReader is needed to perform
 * additional exchanges after the initial selection process. The reader can be provided either at
 * the time of the creation of the selection extension or later depending on the implementation (in
 * the case of dynamic SAM reader allocation for example).
 *
 * @since 0.3.0
 */
class LegacySamSelectionExtension : public CardSelectionExtension {
public:
    /**
     * Sets the unlock data to be used to unlock a SAM C1 (8 or 16 bytes) and schedules the
     * execution of the "Unlock data" command in the first position.
     *
     * <p>The "Unlock" command will be executed only after a successful filtering.
     *
     * @param unlockData Unlock data as a 32-character hexadecimal string.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided unlock data is null, malformed or out of
     *        range.
     * @throw IllegalStateException If an unlocking setting has already been set.
     * @since 0.1.0
     */
    virtual LegacySamSelectionExtension& setUnlockData(const std::string& unlockData) = 0;

    /**
     * Sets the unlock data to be used to unlock a SAM (8 or 16 bytes) and schedules the execution
     * of the "Unlock data" command in the first position.
     *
     * <p>The "Unlock" command will be executed only after a successful filtering.
     *
     * @param unlockData Unlock data as a 32-character hexadecimal string.
     * @param productType The targeted product type.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided unlock data or product type is null,
     *        malformed or out of range.
     * @throw IllegalStateException If an unlocking setting has already been set.
     * @since 0.3.0
     */
    virtual LegacySamSelectionExtension&
    setUnlockData(const std::string& unlockData, const LegacySam::ProductType productType)
        = 0;

    /**
     * Sets the unlock data provider to use for unlocking the SAM in static mode.
     *
     * <p>This method must be used when the card reader needed to communicate with the target SAM is
     * provided at a later point within the interface's implementation process.
     *
     * <p>The "Unlock" command is initiated once the filtering is successfully completed, followed
     * by a request to the provider to obtain the needed unlocking data.
     *
     * @param staticUnlockDataProvider An implementation of {@link
     *        LegacySamStaticUnlockDataProviderSpi}.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided argument is null.
     * @throw IllegalStateException If an unlocking setting has already been set.
     * @since 0.4.0
     */
    virtual LegacySamSelectionExtension& setStaticUnlockDataProvider(
        const std::shared_ptr<LegacySamStaticUnlockDataProviderSpi> staticUnlockDataProvider)
        = 0;

    /**
     * Sets the unlock data provider and the card reader to use for unlocking the SAM in static
     * mode.
     *
     * <p>This method must be used when the card reader is known at the time of creating the SAM
     * selection extension.
     *
     * <p>The "Unlock" command is initiated once the filtering is successfully completed, followed
     * by a request to the provider to obtain the needed unlocking data.
     *
     * @param staticUnlockDataProvider An implementation of {@link
     *     LegacySamStaticUnlockDataProviderSpi}.
     * @param targetSamReader The card reader used to communicate with the target SAM.
     * @return The current instance.
     * @throw IllegalArgumentException If one of the provided arguments is null.
     * @throw IllegalStateException If an unlocking setting has already been set.
     * @since 0.4.0
     */
    virtual LegacySamSelectionExtension& setStaticUnlockDataProvider(
        const std::shared_ptr<LegacySamStaticUnlockDataProviderSpi> staticUnlockDataProvider,
        const std::shared_ptr<CardReader> targetSamReader)
        = 0;

    /**
     * Sets the unlock data provider to use for unlocking the SAM in dynamic mode.
     *
     * <p>This method must be used when the card reader needed to communicate with the target SAM is
     * provided at a later point within the interface's implementation process.
     *
     * <p>The "Unlock" command is initiated once the filtering is successfully completed, followed
     * by a request to the provider to obtain the needed unlocking data.
     *
     * @param dynamicUnlockDataProvider An implementation of {@link
     *        LegacySamDynamicUnlockDataProviderSpi}.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided argument is null.
     * @throw IllegalStateException If an unlocking setting has already been set.
     * @since 0.4.0
     */
    virtual LegacySamSelectionExtension& setDynamicUnlockDataProvider(
        const std::shared_ptr<LegacySamDynamicUnlockDataProviderSpi> dynamicUnlockDataProvider)
        = 0;

    /**
     * Sets the unlock data provider and the card reader to use for unlocking the SAM in dynamic
     * mode.
     *
     * <p>This method must be used when the card reader is known at the time of creating the SAM
     * selection extension.
     *
     * <p>The "Unlock" command is initiated once the filtering is successfully completed, followed
     * by a request to the provider to obtain the needed unlocking data.
     *
     * @param dynamicUnlockDataProvider An implementation of {@link
     *        LegacySamDynamicUnlockDataProviderSpi}.
     * @param targetSamReader The card reader used to communicate with the target SAM.
     * @return The current instance.
     * @throw IllegalArgumentException If one of the provided arguments is null.
     * @throw IllegalStateException If an unlocking setting has already been set.
     * @since 0.4.0
     */
    virtual LegacySamSelectionExtension& setDynamicUnlockDataProvider(
        LegacySamDynamicUnlockDataProviderSpi dynamicUnlockDataProvider,
        CardReader targetSamReader);

    /**
     * Schedules the execution of a "Read Key Parameters" command for a system key.
     *
     * <p>Once this command is processed, the result is accessible with {@link
     * LegacySam#getSystemKeyParameter(SystemKeyType)}.
     *
     * @param systemKeyType The type of system key.
     * @return The current instance.
     * @throws IllegalArgumentException If the provided argument is null.
     * @since 0.3.0
     */
    LegacySamSelectionExtension prepareReadSystemKeyParameters(SystemKeyType systemKeyType);

    /**
     * Schedules the execution of a "Read Event Counter" and "Read Ceiling" commands to read the
     * status of a counter.
     *
     * <p>Note: the status of each counter of the record to which the targeted counter belongs will
     * be read. The number of commands actually transmitted to the SAM will be optimized before to
     * be transmitted.
     *
     * @param counterNumber The number of the counter whose status is to be read (in range [0..26]).
     * @return The current instance.
     * @throws IllegalArgumentException If the provided argument is out of range.
     * @since 0.3.0
     */
    LegacySamSelectionExtension prepareReadCounterStatus(int counterNumber);

    /**
     * Schedules the execution of a "Read Event Counter" and "Read Ceiling" commands to read the
     * status of all counters.
     *
     * @return The current instance.
     * @since 0.3.0
     */
    LegacySamSelectionExtension prepareReadAllCountersStatus();

    /**
     * Schedules the execution of a "Get Data" command for the specified tag.
     *
     * <p>Once this command is processed, data is accessible using dedicated getter methods, like
     * {@link LegacySam#getCaCertificate()}.
     *
     * @param tag The tag to retrieve the data for.
     * @return The current instance.
     * @throws IllegalArgumentException If tag is null.
     * @since 0.6.0
     */
    LegacySamSelectionExtension prepareGetData(GetDataTag tag);
};

} /* namespace sam */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
