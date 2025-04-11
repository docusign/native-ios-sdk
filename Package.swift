// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Docusign",
    products: [
        .library(name: "DocuSignSDK", targets: ["DocuSignSDK"]),
        .library(name: "DocuSignAPI", targets: ["DocuSignAPI"]),
        .library(name: "DocusignNative", targets: ["DocusignNative"]),
        ],
    targets: [
        .binaryTarget(name: "DocuSignSDK", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.0.1/DocuSignSDK.zip", checksum: "0834d3764c18d9538288ac379778172451b1e13646608d47ffd8f6a54f91094e"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.0.1/DocuSignAPI.zip", checksum: "839c637dba1e11961b9c92073364505332019aa742711554685349c84cd1dd6d"),
        .binaryTarget(name: "DocusignNative", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.0.1/DocusignNative.zip", checksum: "1ae049dfc42973d4ae3de498b329dad8b5dd9987d0e79ef1ca1936de90acebb8"),
        ]
)
