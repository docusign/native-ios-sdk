#!/bin/sh

echo "Pre clone"

echo "printing env variable"
echo $MY_SECRET

# Install CocoaPods using Homebrew.
brew install cocoapods

# Install dependencies you manage with CocoaPods.
pod install
