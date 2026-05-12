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
        .binaryTarget(name: "DocuSignSDK", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.2.0/DocuSignSDK.zip", checksum: "c666533f44f4a62a94fabafb9fe7100a6f8b94d0958b97b9c5ad6c8f6ca3e58c"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.2.0/DocuSignAPI.zip", checksum: "840c5d47ae4eeab1a203c5f016723a31b062f5f3807807da1f9a8e56de55ad9a"),
        .binaryTarget(name: "DocusignNative", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.2.0/DocusignNative.zip", checksum: "104b4c9136abf33b0c7ad7758bc7dbbfa93e04716981d2f2a47417cb04a4c03e"),
        ]
)
