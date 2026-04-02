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
        .binaryTarget(name: "DocuSignSDK", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.1.1/DocuSignSDK.zip", checksum: "2180ce9772226e13c282046c3f005987eb1fc131c602e78380f82261d672e76a"),
        .binaryTarget(name: "DocuSignAPI", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.1.1/DocuSignAPI.zip", checksum: "39d3f61aef12ef8fa210518c743652f430b3ce00c8a23c9b29e56a4796677471"),
        .binaryTarget(name: "DocusignNative", url: "https://docucdn-a.akamaihd.net/prod/docusigniossdk/4.1.1/DocusignNative.zip", checksum: "af597074b5554921d90510c8dcbe01bf85641834a3d62fdae0ebe1103a5ac4f3"),
        ]
)
