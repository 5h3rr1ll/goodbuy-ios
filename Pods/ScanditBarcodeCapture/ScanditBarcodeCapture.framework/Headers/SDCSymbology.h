/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.0.0
 *
 * An enumeration of possible checksum algorithms. The enumeration only lists optional checksum algorithms; mandatory checksums that can’t be changed are not listed here. Use the values below to set optional checksums for a symbology. The exact implementation chosen depends on the symbology and checksum algorithm. Only a subset of algorithms is supported for each symbology. Check the symbology documentation to see which checksums are supported.
 */
typedef NS_OPTIONS(NSUInteger, SDCChecksum) {
/**
     * Added in version 6.0.0
     *
     * Checksum is calculated using modulo of 10.
     */
    SDCChecksumMod10 = 1 << 0,
/**
     * Added in version 6.0.0
     *
     * Checksum is calculated using modulo of 11.
     */
    SDCChecksumMod11 = 1 << 1,
/**
     * Added in version 6.0.0
     *
     * Checksum is calculated using modulo of 47.
     */
    SDCChecksumMod47 = 1 << 2,
/**
     * Added in version 6.0.0
     *
     * Checksum is calculated using modulo of 103.
     */
    SDCChecksumMod103 = 1 << 3,
/**
     * Added in version 6.0.0
     *
     * Checksum is calculated using two different modulo of 10 checksums.
     */
    SDCChecksumMod10AndMod10 = 1 << 4,
/**
     * Added in version 6.0.0
     *
     * Checksum is calculated using two checksums, one using modulo of 10 and one using modulo of 11.
     */
    SDCChecksumMod10AndMod11 = 1 << 5,
/**
     * Added in version 6.0.0
     *
     * Checksum is calculated using modulo of 43.
     */
    SDCChecksumMod43 = 1 << 6,
/**
     * Added in version 6.0.0
     *
     * Checksum is calculated using modulo of 16.
     */
    SDCChecksumMod16 = 1 << 7,
} NS_SWIFT_NAME(Checksum);

/**
 * Added in version 6.0.0
 *
 * An enumeration of barcode types (symbologies) supported by the Scandit Data Capture SDK.
 *
 * The availability of the symbology depends on the licensed features.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCSymbology) {
/**
     * Added in version 6.0.0
     *
     * EAN-13/UPC-12/UPC-A 1D barcode symbology.
     */
    SDCSymbologyEAN13UPCA NS_SWIFT_NAME(ean13UPCA),
/**
     * Added in version 6.0.0
     *
     * UPC-E 1D barcode symbology.
     */
    SDCSymbologyUPCE NS_SWIFT_NAME(upce),
/**
     * Added in version 6.0.0
     *
     * Ean8 1D barcode symbology.
     */
    SDCSymbologyEAN8 NS_SWIFT_NAME(ean8),
/**
     * Added in version 6.0.0
     *
     * Code39 1D barcode symbology.
     */
    SDCSymbologyCode39,
/**
     * Added in version 6.0.0
     *
     * Code93 1D barcode symbology.
     */
    SDCSymbologyCode93,
/**
     * Added in version 6.0.0
     *
     * Code128 1D barcode symbology.
     */
    SDCSymbologyCode128,
/**
     * Added in version 6.0.0
     *
     * Code11 1D barcode symbology.
     */
    SDCSymbologyCode11,
/**
     * Added in version 6.0.0
     *
     * Code25 1D barcode symbology.
     */
    SDCSymbologyCode25,
/**
     * Added in version 6.0.0
     *
     * Codabar 1D barcode symbology.
     */
    SDCSymbologyCodabar,
/**
     * Added in version 6.0.0
     *
     * Interleaved two of five (ITF) 1D barcode symbology.
     */
    SDCSymbologyInterleavedTwoOfFive,
/**
     * Added in version 6.0.0
     *
     * MSI-Plessey 1D barcode symbology.
     */
    SDCSymbologyMSIPlessey,
/**
     * Added in version 6.0.0
     *
     * QR Code 2D barcode symbology.
     */
    SDCSymbologyQR NS_SWIFT_NAME(qr),
/**
     * Added in version 6.0.0
     *
     * Data Matrix 2D barcode symbology.
     */
    SDCSymbologyDataMatrix,
/**
     * Added in version 6.0.0
     *
     * Aztec Code 2D barcode symbology.
     */
    SDCSymbologyAztec,
/**
     * Added in version 6.0.0
     *
     * MaxiCode 2D barcode symbology.
     */
    SDCSymbologyMaxiCode,
/**
     * Added in version 6.0.0
     *
     * Dot Code symbology.
     */
    SDCSymbologyDotCode,
/**
     * Added in version 6.0.0
     *
     * Royal Dutch TPG Post KIX.
     */
    SDCSymbologyKIX NS_SWIFT_NAME(kix),
/**
     * Added in version 6.0.0
     *
     * Royal Mail 4 State Customer Code (RM4SCC).
     */
    SDCSymbologyRM4SCC NS_SWIFT_NAME(rm4scc),
/**
     * Added in version 6.0.0
     *
     * GS1 DataBar 14 1D barcode symbology.
     */
    SDCSymbologyGS1Databar,
/**
     * Added in version 6.0.0
     *
     * GS1 DataBar Expanded 1D barcode symbology.
     */
    SDCSymbologyGS1DatabarExpanded,
/**
     * Added in version 6.0.0
     *
     * GS1 DataBarLimited 1D barcode symbology.
     */
    SDCSymbologyGS1DatabarLimited,
/**
     * Added in version 6.0.0
     *
     * PDF417 barcode symbology.
     */
    SDCSymbologyPDF417 NS_SWIFT_NAME(pdf417),
/**
     * Added in version 6.0.0
     *
     * MicroPDF417 barcode symbology.
     */
    SDCSymbologyMicroPDF417,
/**
     * Added in version 6.0.0
     *
     * MicroQR Code 2D barcode symbology.
     */
    SDCSymbologyMicroQR,
/**
     * Added in version 6.0.0
     *
     * Code32 1D barcode symbology.
     */
    SDCSymbologyCode32,
/**
     * Added in version 6.0.0
     *
     * Posi LAPA Reed Solomon 4-state code postal code symbology.
     */
    SDCSymbologyLapa4SC
} NS_SWIFT_NAME(Symbology);

/**
 * Added in version 6.0.0
 *
 * Gets the string representation for the provided symbology enum.
 */
SDC_EXTERN NSString *_Nonnull SDCSymbologyToString(SDCSymbology symbology) NS_SWIFT_NAME(getter:SDCSymbology.description(self:));

/**
 * Added in version 6.0.0
 *
 * Returns the list of all supported symbologies by the Scandit Data Capture SDK.
 */
SDC_EXTERN NSArray<NSNumber *> *_Nonnull SDCAllSymbologies(void);
