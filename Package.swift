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
        .binaryTarget(name: "DocuSignSDK", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.1.0/DocuSignSDK.zip", checksum: "ec50f7bde32eb3b6f180e2a4e85e3d58f0f064297ecb154094fe5988f74fb75c"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.1.0/DocuSignAPI.zip", checksum: "11e33262bb09e969f987884890dddfdfbecb8f1eddc35cbe10b5c03e52e841e5"),
        .binaryTarget(name: "DocusignNative", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.1.0/DocusignNative.zip", checksum: "4ad60520154cc71bcc7bed73ac3bd6f125ccb3728569a40c3aeb388abe4186aa"),
        ]
)
