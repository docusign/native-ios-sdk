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
        .binaryTarget(name: "DocuSignSDK", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.3.0/DocuSignSDK.zip", checksum: "cee5facc466f795b6bccb03ce875cfec5ce41930032cedbb2604572a9160d133"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.3.0/DocuSignAPI.zip", checksum: "07c6cd3364009eabdaeb2bd76b43bae524adc95ecd329338950e9628e866bfd1"),
        .binaryTarget(name: "DocusignNative", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.3.0/DocusignNative.zip", checksum: "bf23a2830d948cc0251ff7d28cb820f7673baf0957b03a6e1d88bbe92b2af855"),
        ]
)
