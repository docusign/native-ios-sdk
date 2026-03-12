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
        .binaryTarget(name: "DocuSignSDK", url: "https://docutest-a.akamaihd.net/test/docusigniossdk/4.1.1/DocuSignSDK.zip", checksum: "8c5fa5c0ad84731f764e88acc0a4a7235f7890acfefe57908ea4a60a741fe54f"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docutest-a.akamaihd.net/test/docusigniossdk/4.1.1/DocuSignAPI.zip", checksum: "681beb85166fc567f80f715674c7f6920110f07860e30ccd1a1675e858e83209"),
        .binaryTarget(name: "DocusignNative", url: "https://docutest-a.akamaihd.net/test/docusigniossdk/4.1.1/DocusignNative.zip", checksum: "378ca031faa256f39f82e7a8c398e698e06d76b5a8db6c57503842bea2a11526"),
        ]
)
