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
        .binaryTarget(name: "DocuSignSDK", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.3.0/DocuSignSDK.zip", checksum: "25724bf87023da6b0c60741f1de70a95dc968d9a274f8d6c4789731b87a9969a"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.3.0/DocuSignAPI.zip", checksum: "091df294226237b026a141284a4416cc37f3d2b646692c26606df40219056999"),
        .binaryTarget(name: "DocusignNative", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.3.0/DocusignNative.zip", checksum: "40a322d31340e3bc4344c9e630b3a1c4d84fec3af81c6a17819e2aafd66d0c77"),
        ]
)
