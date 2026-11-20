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
        .binaryTarget(name: "DocuSignSDK", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.4.0/DocuSignSDK.zip", checksum: "26bd63d37a86a1ca5ad6f9fda67cad37d47818e285934763275a5bfc8d4328cc"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.4.0/DocuSignAPI.zip", checksum: "4b25054643c19404bc1c189fa7233579096895dfc7783739406e4905ff43ce78"),
        .binaryTarget(name: "DocusignNative", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.4.0/DocusignNative.zip", checksum: "4b4f30f169227bea3526a93844d1a61f8c19e9b5d44a1ca10f53a95c19f6d292"),
        ]
)
