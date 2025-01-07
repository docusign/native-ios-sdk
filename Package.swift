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
        .binaryTarget(name: "DocuSignSDK", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/3.5.0/DocuSignSDK.zip", checksum: "200a4c1245afe669ca04913e8d8c3494a64e9e9445302067d74fe9fb44a8a2eb"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/3.5.0/DocuSignAPI.zip", checksum: "e95bf8f205de1f6e68169207a995a29fd3e57c96a16daccd0de93558e19047cb"),
        ]
)
