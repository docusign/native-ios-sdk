// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Docusign",
    products: [
        .library(name: "DocuSignSDK", targets: ["DocuSignSDK"]),
        .library(name: "DocuSignAPI", targets: ["DocuSignAPI"]),
        ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .binaryTarget(name: "DocuSignSDK", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/3.5.0/DocuSignSDK.zip", checksum: "24e7dfb257b36986ff016333d68d9ad9387415f2623367522f55f87e8e188884"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/3.5.0/DocuSignAPI.zip", checksum: "894699791e49b43de165aac62874e27f2467392dcb210ef26c8a78191b8a7534"),
        ]
)
