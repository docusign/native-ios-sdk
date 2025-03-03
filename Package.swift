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
        .binaryTarget(name: "DocuSignSDK", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.0.0/DocuSignSDK.zip", checksum: "786b161ab3f03c44a4236feaa95b5ce7781f9eff071631ab8942e6c175bad5b3"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.0.0/DocuSignAPI.zip", checksum: "ebd4d38da5689c06d78dcac2dcc7cbfe73f470bfc032ebd9d8bffce0b5490f7a"),
        .binaryTarget(name: "DocusignNative", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.0.0/DocusignNative.zip", checksum: "7f90ce4e4de951fa71e956ebea30f14d38f16a4a6d82bdc9f69b5989c128f747"),
        ]
)
