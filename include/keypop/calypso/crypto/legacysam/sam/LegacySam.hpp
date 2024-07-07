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
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "keypop/calypso/crypto/legacysam/CounterIncrementAccess.hpp"
#include "keypop/calypso/crypto/legacysam/SystemKeyType.hpp"
#include "keypop/calypso/crypto/legacysam/sam/KeyParameter.hpp"
#include "keypop/reader/selection/spi/SmartCard.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace sam {

using keypop::reader::selection::spi::SmartCard;

/**
 * Extends the SmartCard interface of the "Keypop Reader API" to provide additional
 * functionality specific to Calypso legacy SAMs.
 *
 * <p>An instance of {@code LegacySam} is obtained by casting the SmartCard object from the
 * selection process defined by the "Keypop Reader API".
 *
 * <p>It is a dynamic view of the SAM's content, regularly updated from the selection stage to the
 * end of the transaction.
 *
 * @since 0.1.0
 */
class LegacySam : public SmartCard {
public:
    /**
     * All Calypso SAM products supported by this API.
     *
     * @since 0.1.0
     */
    enum class ProductType {
        /**
         * SAM C1
         *
         * @since 0.1.0
         */
        SAM_C1,

        /**
         * SAM C1 HSM
         *
         * @since 0.1.0
         */
        HSM_C1,

        /**
         * SAM S1E1
         *
         * @since 0.1.0
         */
        SAM_S1E1,

        /**
         * SAM S1Dx
         *
         * @since 0.1.0
         */
        SAM_S1DX,

        /**
         * Unidentified smart card.
         *
         * @since 0.1.0
         */
        UNKNOWN
    };

    /**
     * Returns the SAM product type.
     *
     * @return The identified product type.
     * @since 0.1.0
     */
    virtual ProductType getProductType() const = 0;

    /**
     * Returns a text description of the SAM.
     *
     * @return A non-null string.
     * @since 0.1.0
     */
    virtual const std::string& getProductInfo() const = 0;

    /**
     * Returns the SAM serial number as a byte array.
     *
     * @return A non-null byte array.
     * @since 0.1.0
     */
    virtual const std::vector<uint8_t>& getSerialNumber() const = 0;

    /**
     * Returns the platform identifier.
     *
     * @return A byte.
     * @since 0.1.0
     */
    virtual uint8_t getPlatform() const = 0;

    /**
     * Returns the application type.
     *
     * @return A byte.
     * @since 0.1.0
     */
    virtual uint8_t getApplicationType() const = 0;

    /**
     * Returns the application subtype.
     *
     * @return A byte.
     * @since 0.1.0
     */
    virtual uint8_t getApplicationSubType() const = 0;

    /**
     * Returns the software issuer identifier.
     *
     * @return A byte.
     * @since 0.1.0
     */
    virtual uint8_t getSoftwareIssuer() const = 0;

    /**
     * Returns the software version number.
     *
     * @return A byte.
     * @since 0.1.0
     */
    virtual uint8_t getSoftwareVersion() const = 0;

    /**
     * Returns the software revision number.
     *
     * @return A byte.
     * @since 0.1.0
     */
    virtual uint8_t getSoftwareRevision() const = 0;

    /**
     * Returns the value of a counter.
     *
     * @param counterNumber The number of the counter (in range [0..26]).
     * @return Null if the counter value is not set.
     * @since 0.1.0
     */
    virtual std::shared_ptr<int> getCounter(const int counterNumber) const = 0;

    /**
     * Returns the value of known counters in a sorted map where {@code key} is the counter number
     * and
     * {@code value} is the counter value.
     *
     * @return A non-null map.
     * @since 0.1.0
     */
    virtual const std::map<const int, const int>& getCounters() const = 0;

    /**
     * Returns the counter increment access mode.
     *
     * @param counterNumber The number of the counter being checked.
     * @return Null if the counter increment access is unknown.
     * @since 0.2.0
     */
    virtual CounterIncrementAccess getCounterIncrementAccess(const int counterNumber) const = 0;

    /**
     * Returns the value of a counter ceiling.
     *
     * @param counterNumber The number of the counter ceiling (in range [0..26]).
     * @return Null if the counter ceiling value is not set.
     * @since 0.1.0
     */
    virtual std::shared_ptr<int> getCounterCeiling(const int counterNumber) const = 0;

    /**
     * Returns the value of known counter ceilings in a sorted map where {@code key} is the ceiling
     * number and {@code value} is the ceiling value.
     *
     * @return A non-null map.
     * @since 0.1.0
     */
    virtual const std::map<const int, const int>& getCounterCeilings() const = 0;

    /**
     * Returns the parameters of the system key whose type is provided.
     *
     * @param systemKeyType The type of system key.
     * @return Null if there is no parameter available for the specified key type.
     * @since 0.2.0
     */
    virtual KeyParameter getSystemKeyParameter(const SystemKeyType systemKeyType) const = 0;

    /**
     * Gets the CA certificate retrieved from the SAM as a 384-byte byte array.
     *
     * @return null if the CA certificate is not available.
     * @see FreeTransactionManager#prepareGetData(GetDataTag)
     * @since 0.5.0
     */
    virtual const std::vector<uint8_t>& getCaCertificate() const = 0;
};

} /* namespace sam */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
