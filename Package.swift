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
        .binaryTarget(name: "DocuSignSDK", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.1.0/DocuSignSDK.zip", checksum: "ca5b46f08d093e48a1c02c17aa56cc64f754b5a8ffd0dca161a92f333621e868"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.1.0/DocuSignAPI.zip", checksum: "30a78abb9c1526b5c12821af6739e6b66b5965bf6b924cd2766e4503c478fc06"),
        .binaryTarget(name: "DocusignNative", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.1.0/DocusignNative.zip", checksum: "962a653d257a1abd0ddd5bbcf401341c3d176c0e9733cd199dabc3d2ddde3bc4"),
        ]
)
